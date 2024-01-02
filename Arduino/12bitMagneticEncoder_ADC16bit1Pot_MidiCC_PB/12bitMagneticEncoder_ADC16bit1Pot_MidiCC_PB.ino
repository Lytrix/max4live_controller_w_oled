#include <Wire.h>
#include <AS5600.h>
#include <MicroOscSlip.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdio.h>
#include <string.h>

// #include "ADS1X15.h"
// #include "MIDIUSB.h"
// #include <Smoothed.h>

// THE NUMBER 128 BETWEEN THE < > SYMBOLS  BELOW IS THE MAXIMUM NUMBER OF BYTES RESERVED FOR INCOMMING MESSAGES.
// MAKE SURE THIS NUMBER OF BYTES CAN HOLD THE SIZE OF THE MESSAGE YOUR ARE RECEIVING IN ARDUINO.
// OUTGOING MESSAGES ARE WRITTEN DIRECTLY TO THE OUTPUT AND DO NOT NEED ANY RESERVED BYTES.
MicroOscSlip<128> myMicroOsc(&Serial);  // CREATE AN INSTANCE OF MicroOsc FOR SLIP MESSAGES

unsigned long myChronoStart = 0;  // VARIABLE USED TO LIMIT THE SPEED OF THE loop() FUNCTION.

// Set address of first I2C multiplexer
#define TCAADDR 0x70

// Create instance for Magnetic Readers ctrl 1
AS5600 as5600_0(&Wire);
AS5600 as5600_1(&Wire);
AS5600 as5600_2(&Wire);
// Create instance for Magnetic Readers ctrl 2
AS5600 as5600_3(&Wire);
AS5600 as5600_4(&Wire);
AS5600 as5600_5(&Wire);

// Reference list of classes Used to iterate over in the OSC address offset
AS5600 *as5600List[2][3]= {
  {&as5600_0, &as5600_1, &as5600_2},
  {&as5600_3, &as5600_4, &as5600_5}
}; 

// List of Multiplexer channel numbers for each magnetic encoder
int tcaAddress[2][3] = {
  {1,6,0}, // main controller, 7 is oled
  {3,4,5}  // satellite controller, 2 is oled
};

// Encoder direction per controller, per magnetic encoder. 1 is clockwise, 0 is counterclockwise
int as5600_rotation[2][3] = {
  {1,1,0},
  {1,1,0}
};

int tcaDisplayAddress[2] = {7, 2}; //ctrl1, ctrl2

// Set Display information
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define I2C_BUSS &Wire  // $Wire, &Wire1, ..
#define I2C_SPEED 1000000
// #define I2C_BUSS2 &Wire1  // $Wire, &Wire1, ..

// Create an instance for each display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, I2C_BUSS, OLED_RESET, I2C_SPEED);

// Analog Potentiometer reader 16 bit:
// ADS1115 ADS(0x48);

// Set smoothing data type
// Smoothed <int16_t> mySensor;

// Setting for 14bit midi CC
// #define LOWCC1 1
// #define HIGHCC1 LOWCC1 + 32


/***********************
     Set Variables
************************/
char parameterName1[36] ="";
char parameterValue1[10]="";
char parameterType1[3] ="";

char parameterName2[36]="";
char parameterValue2[10]="";
char parameterType2[3]="";

char parameterName3[36]="";
char parameterValue3[10]="";
char parameterType3[3]="";

char parameterName4[36] ="";
char parameterValue4[10]="";
char parameterType4[3] ="";

char parameterName5[36]="";
char parameterValue5[10]="";
char parameterType5[3]="";

char parameterName6[36]="";
char parameterValue6[10]="";
char parameterType6[3]="";

char buttonValue1[16]="";
char buttonValue2[16]="";
char buttonValue3[16]="";
char buttonValue4[16]="";

char displayTitle1[36]="";
char displayTitle2[36]="";

float parameterSliderValue1 = 0.0;
float parameterSliderValue2 = 0.0;
float parameterSliderValue3 = 0.0;
float parameterSliderValue4 = 0.0;
float parameterSliderValue5 = 0.0;
float parameterSliderValue6 = 0.0;

// List of parameter values to iterate over in OSC addresses
char *displayTxtKnob[2][3][3] = {
  {
    {parameterName1, parameterValue1, parameterType1},
    {parameterName2, parameterValue2, parameterType2},
    {parameterName3, parameterValue3, parameterType3}
  },
  {
    {parameterName4, parameterValue4, parameterType4},
    {parameterName5, parameterValue5, parameterType5},
    {parameterName6, parameterValue6, parameterType6}
  },
};

char *displayTxtController[2] = {displayTitle1, displayTitle2};

// List of parameter values to iterate over in OSC addresses
char *displayTxtButton[2][2] = {
  {buttonValue1, buttonValue2},
  {buttonValue3, buttonValue4}
};


float sliderValue[2][3] = {
  {parameterSliderValue1, parameterSliderValue2, parameterSliderValue3},
  {parameterSliderValue4, parameterSliderValue5, parameterSliderValue6},  
};

// For creating OSC address to receive on
char oscAddress[24];
char oscParam[3][4] = {"/c", "/p", "/b"};
char strDeviceNumber[3];
char strParamNumber[3];

// Store old and new send value for each TCA channel in a list to reduce number off serial sends
int oldValue[2];
int newValue[2];

// Setup default display cursor positions to loop in updateDisplay function.
int displayPos[3][3][2] = {
    { // row 2
      {2, 12},
      {75,12},
      {105,12}
    },
    { // row 3
      {2, 27},
      {75,27},
      {105,27}
    },
        { // row 4
      {2, 42},
      {75,42},
      {105,42}
    }
};

// Button and led pin numbers
const int buttonPin[2][2] = {
  {0,1},
  {2,3}
}; // Teensy pin connected to button's pin
const int ledPin[2][2] = {
  {8,9},
  {10,11}
};  // Teensy pin connected to LED's pin

// Led, buttonstate variables
int ledState[2][2] = {
  {LOW, LOW}, 
  {LOW, LOW}
};           // the current state of LED
int lastButtonState[2][2] = {
  {LOW, LOW}, 
  {LOW, LOW}
};    // the previous state of button
int currentButtonState[2][2] = {
  {LOW, LOW}, 
  {LOW, LOW}
}; // the current state of button

// Test variables
int ledPinTeensy = 13;
// int analogPin = A0;  // potentiometer wiper (middle terminal) connected to analog pin 3
// int val = 0;         // variable to store the value read
// int pitch;


/***********************
  Functions
************************/

// Multiplexer select channel
void tcaSelect(uint8_t bus) {
  if (bus > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << bus);
  Wire.endTransmission();

}

// Send OSC message when moving potentiometer for each AS5600 magnetic encoder
void sendValueMagneticEncoder(char oscDevice[4], int deviceNumber, AS5600 &as5600_reference, int channel, char oscParamName[4], int tcaAddress) {
  sprintf(strDeviceNumber, "/%d", deviceNumber+1);  
  strcpy(oscAddress, oscDevice);
  strcat(oscAddress, strDeviceNumber);

  sprintf(strParamNumber, "/%d", channel+1);
  strcat(oscAddress, oscParamName);
  strcat(oscAddress, strParamNumber);

  tcaSelect(tcaAddress);
  delayMicroseconds(1);
  newValue[channel] = as5600_reference.readAngle();
  if (newValue[channel] != oldValue[channel]) {  
      myMicroOsc.sendInt(oscAddress, newValue[channel]);  // SEND MAGNETIC ENCODE
      oldValue[channel] = newValue[channel];
  }
}

// Offset Magnetic Encoder // If VST value is update via mouse input, recieve updated value to calculate new offset of magnetic encoder, so it does not jump.
void setOffsetMagneticEncoder(char oscDeviceName[4], int deviceNumber, AS5600 &as5600_reference, int channel, int parameterOffset, int tcaAddress, char oscParamName[4]) {
  tcaSelect(tcaAddress);
  int readAngle = as5600_reference.readAngle();
  // Serial.print("instance");
  // Serial.println(readAngle);
  // Serial.print("parameterOffset");
  // Serial.println(parameterOffset);
  if (readAngle != parameterOffset) {
    float previous_difference = as5600_reference.getOffset();
    float new_difference = (((float(parameterOffset) - float(readAngle)) / 4096.) * 360.) + previous_difference;
    if (new_difference > 360.) {
      new_difference = new_difference - 360.;
    }
    if (new_difference < -360.) {
      new_difference = new_difference + 360.;
    }
    as5600_reference.setOffset(new_difference);

    // to do: fix the code below as existing void. it currenty hangs if I put it in.
    // char *oscName = "/p"; 
    newValue[channel] = as5600_reference.readAngle();
    if (newValue[channel] != oldValue[channel]) {
      sprintf(strDeviceNumber, "/%d", deviceNumber+1);  
      sprintf(strParamNumber, "/%d", channel+1);
  
      strcpy(oscAddress, oscDeviceName);
      strcat(oscAddress, strDeviceNumber);
      strcat(oscAddress, oscParamName);
      strcat(oscAddress, strParamNumber);
      myMicroOsc.sendInt(oscAddress, newValue[channel]);  // SEND MAGNETIC ENCODE
      oldValue[channel] = newValue[channel];
    }

    //newValue[channel] = as5600_reference.readAngle();
  }
}

// Parse all OSC addresses in a for loop by (1, "/name") equals: /param1/name
void oscAddressParser(char oscDeviceName[4], int deviceNumber, char oscParamName[4], int parameterNumber, char oscAddressType[10]){
  sprintf(strDeviceNumber, "/%d", deviceNumber+1);   // /1, /2, ...
  sprintf(strParamNumber, "/%d", parameterNumber+1); // /1, /2, ...
 
  strcpy(oscAddress, oscDeviceName);   // /c
  strcat(oscAddress, strDeviceNumber); // /1
  strcat(oscAddress, oscParamName);    // /p
  strcat(oscAddress, strParamNumber);  // /1
  strcat(oscAddress, oscAddressType);  // /value
  // Serial.print("created OSCadress: ");
  // Serial.println(oscAddress); // /c1/p1/value
}

// OSC MESSAGE LISTENER
void myOnOscMessageReceived(MicroOscMessage& oscMessage) {

  // Loop over displayTxt and as5600List for each parameter osc address and as5600 instance.  // Loop over displayTxt and as5600List for each parameter osc address and as5600 instance.
  for (int x = 0; x <= 1; x++)  { // Loop over each /c controller
    
    for (int i = 0; i <= 2; i++)  { // Loop over each /p oscAddress
      oscAddressParser(oscParam[0], x, oscParam[1], i, "/offset");
      if (oscMessage.checkOscAddress(oscAddress)) {
        int parameterOffset = oscMessage.nextAsInt();
        //Serial.print("parameterOffset: ");
        //Serial.print(oscAddress);
        //Serial.print(": ");
        //Serial.println(parameterOffset);
        setOffsetMagneticEncoder(oscParam[0], x, as5600List[x][i][0], i, parameterOffset, tcaAddress[x][i], oscParam[1]); //channel 0, instance as5600_0
      }

      oscAddressParser(oscParam[0], x, oscParam[1], i, "/value"); 
      if (oscMessage.checkOscAddress(oscAddress)) {
        strcpy(displayTxtKnob[x][i][1], oscMessage.nextAsString());
      }

      oscAddressParser(oscParam[0], x, oscParam[1], i, "/slidervalue");
      if (oscMessage.checkOscAddress(oscAddress)) {
        sliderValue[x][i]=oscMessage.nextAsFloat(); 
      }

      oscAddressParser(oscParam[0], x, oscParam[1], i, "/name");
      if (oscMessage.checkOscAddress(oscAddress)) { 
        strcpy(displayTxtKnob[x][i][0], oscMessage.nextAsString());
      }
      
      oscAddressParser(oscParam[0], x, oscParam[1], i, "/type");
      if (oscMessage.checkOscAddress(oscAddress)) { 
        strcpy(displayTxtKnob[x][i][2], oscMessage.nextAsString());
      }
    }
    
    // Select name from first magnetic encoder parameter /p (i=0)
    oscAddressParser(oscParam[0], x, oscParam[1], 0, "/title");
    if (oscMessage.checkOscAddress(oscAddress)) {  
      strcpy(displayTxtController[x], oscMessage.nextAsString());
    }

    // Receive VST button state to set led state AND set led on/off
    for (int i = 0; i <= 1; i++)  { 
      oscAddressParser(oscParam[0], x, oscParam[2], i, "/value");
      if (oscMessage.checkOscAddress(oscAddress)) {  // IF THE ADDRESS IS /b1/value
        strcpy(displayTxtButton[x][i], oscMessage.nextAsString());
      }

      oscAddressParser(oscParam[0], x, oscParam[2], i, "/state");
      // Serial.println(oscAddress);
      if (oscMessage.checkOscAddress(oscAddress)) {  // IF THE ADDRESS IS /b1/state
      
        int newValue = oscMessage.nextAsInt(); 
        // Serial.println(newValue);
        //ledState[i] = newValue;
        if (newValue == 1){
          digitalWrite(ledPin[x][i], HIGH);
          //lastButtonState[i] = HIGH;
          //currentButtonState[i]= HIGH;
          ledState[x][i]=HIGH;
        }
        if (newValue == 0){
          digitalWrite(ledPin[x][i], LOW);
          //lastButtonState[i] = HIGH;  
          //currentButtonState[i]= HIGH;
          ledState[x][i]=LOW; 
        }
      }
    }
   
  }
  // Test reset led/button function
  // Basic tester
  if (oscMessage.checkOscAddress("/led")) {  // IF THE ADDRESS IS /led
    int newValue = oscMessage.nextAsInt();   // GET NEW VALUE AS INT
    digitalWrite(ledPinTeensy, newValue);         // SET LED OUTPUT TO VALUE (DIGITAL: OFF/ON)
    Serial.write("led on");
  }
}

int16_t sliderLength = 37;
int16_t sliderHeight = 5; // larger values cause flickering screen :(
int16_t fillLength;
int16_t length = 0;
int16_t center = 0;

// Clear and push display with updated values in void Loop()
void updateDisplay(int displayArray, int channel) {
  tcaSelect(channel);
  
  display.clearDisplay();
  display.setTextSize(1);  // Draw 1X-scale text
  display.setTextColor(SSD1306_WHITE);
  
  // Generate 1 of 3 rows of display information using the prefilled array.
  for (int x = 0; x <= 2; x++) {
    for (int i = 0; i <= 2; i++) { // loop over each display element
      display.setCursor(displayPos[x][i][0], displayPos[x][i][1]);
      display.println(displayTxtKnob[displayArray][x][i]);
    }
    display.drawRect(33, displayPos[x][0][1]+2, round(sliderValue[displayArray][x] * sliderLength), sliderHeight, SSD1306_WHITE);
  }

  // Button 1 & 2 info
  for (int i = 0; i<=1; i++) {
    display.setCursor(displayPos[0][i][0], 56);
    display.println(displayTxtButton[displayArray][i]);
  }

 // center title text
  length = sizeof(displayTxtController[displayArray])/sizeof(char);
  center = SCREEN_WIDTH/2 - round(length/2);
  display.setCursor(center, 0);
  display.println(displayTxtController[displayArray]);

  display.display();
}

// Slicer function used to limit parameter names on display.

void buttonState(char oscDevice[4], int deviceNumber, char oscParam[4], int parameterNumber) {
  lastButtonState[deviceNumber][parameterNumber] = currentButtonState[deviceNumber][parameterNumber];      // save the last state
  currentButtonState[deviceNumber][parameterNumber] = digitalRead(buttonPin[deviceNumber][parameterNumber]); // read new state

  if(lastButtonState[deviceNumber][parameterNumber] == HIGH && currentButtonState[deviceNumber][parameterNumber] == LOW) {
    char oscButtonAddress[24];
    Serial.print("Button");
    Serial.print(parameterNumber);
    Serial.println(" is pressed");
    
    // invert state of LED
    ledState[deviceNumber][parameterNumber] = !ledState[deviceNumber][parameterNumber];
    
    // convert int to char and adding + 1 to create /b1 as oscAddress
    sprintf(strDeviceNumber, "/%d", deviceNumber+1);  
    sprintf(strParamNumber, "/%d", parameterNumber+1);
 
    strcpy(oscButtonAddress, oscDevice); // /c
    strcat(oscButtonAddress, strDeviceNumber); // /1
    strcat(oscButtonAddress, oscParam); // /b
    strcat(oscButtonAddress, strParamNumber); // /1
 
    myMicroOsc.sendInt(oscButtonAddress, ledState[deviceNumber][parameterNumber]);
   
    // control LED arccoding to the toggled state
    // digitalWrite(ledPin[item], ledState[item]); 
    // Serial.print("Ledstate: ");
    // Serial.println(ledState[item]);   
  }
}

void slice(const char* str, char* result, size_t start, size_t end) {
    strncpy(result, str + start, end - start);
}

// void myPitchChange(byte channel, int pitch) {
//   digitalWrite(ledPin, HIGH);
  
// void controlChange(byte channel, byte control, byte value) {
//   midiEventPacket_t event = { 0x0B, 0xB0 | channel, control, value };
//   MidiUSB.sendMIDI(event);
// }


/****************
  SETUP
*****************/
void setup() {
  Wire.begin();
  Serial.begin(115200);
  
  Serial.println(__FILE__);
  Serial.print("AS5600_LIB_VERSION: ");
  Serial.println(AS5600_LIB_VERSION);
  
  // Check which channel is connected to TCA
  Serial.println("\nTCAScanner ready");
  for (uint8_t t = 0; t < 8; t++) {
   tcaSelect(t);
  //for QAS5600_COUNTERCLOCK_WISE   Serial.print("TCA Port #");
   Serial.println(t);

    for (uint8_t addr = 0; addr <= 127; addr++) {
      if (addr == TCAADDR) continue;
      Wire.beginTransmission(addr);
      if (!Wire.endTransmission()) {
        Serial.print("Found I2C 0x");
        Serial.println(addr, HEX);
      }
    }
  }
  // Initiate Magnectic Encoders
  for (int x = 0; x <= 1; x++) {  // For each cntrl
    for (int i = 0; i <= 2; i++) {  // for each of 3 magnetic encoders
      tcaSelect(tcaAddress[x][i]);
      as5600List[x][i][0].begin();
      
      if (as5600_rotation[x][i] == 1) {
        as5600List[x][i][0].setDirection(AS5600_CLOCK_WISE);
      } else {
        as5600List[x][i][0].setDirection(AS5600_COUNTERCLOCK_WISE);
      }
      Serial.print("Connected ctrl");
      Serial.print(x+1);
      Serial.print(" as5600_");
      Serial.print(i);
      Serial.println(as5600List[x][i][0].isConnected() ? "true" : "false");
    }
    
    for (int i = 0; i <= 1; i++) {
      pinMode(buttonPin[x][i], INPUT_PULLUP); // set arduino pin to input pull-up mode
      pinMode(ledPin[x][i], OUTPUT);          // set arduino pin to output mode
      currentButtonState[x][i] = digitalRead(buttonPin[x][i]);
    }

    // initiate displays for each controller
    // tcaSelect(tcaDisplayAddress[x]);
    // delayMicroseconds(10);
    // if (!displayList[x][0].begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    //   Serial.print(F("Cntrl_"));
    //   Serial.print(x);
    //   Serial.println(F(" SSD1306 allocation failed"));
    //   for (;;)
    //     ;  // Don't proceed, loop forever
    // }
    // displayList[x][0].setTextSize(1);
    // displayList[x][0].setTextColor(SSD1306_WHITE);
    // delayMicroseconds(10);
  }

  tcaSelect(2);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.print(F("Ctrl2"));
    Serial.println(F(" SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  delay(2000);
  display.clearDisplay();
  
  tcaSelect(7);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.print(F("Ctrl1"));
    Serial.println(F(" SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  delay(2000);
  display.clearDisplay();

  // For testing
  // pinMode(ledPin, OUTPUT);  // LED: DIGITAL OUTPUT
  
  // ADS.begin();

  //Wire.setClock(3400000);
  //Wire1.setClock(3400000);

  // Set number of readings to smooth
  // mySensor.begin(SMOOTHED_AVERAGE, 5);
  
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  //display.display();
  //delay(1000); // Pause for 1 second
  //display.clearDisplay();

  //           GAIN
  //  0  =  +- 6.144V  default
  //  1  =  +- 4.096V
  //  2  =  +- 2.048V
  //  4  =  +- 1.024V
  //  8  =  +- 0.512V
  //  16 =  +- 0.256V
  // ADS.setGain(8);

  // Datarate	ADS111x	Notes
  // 0          8	    slowest
  // 1	       16
  // 2	       32
  // 3	       64
  // 4	      128	    default
  // 5	      250
  // 6	    	475
  // 7	    	860	    fastest
  // ADS.setDataRate(7);

  //usbMIDI.setHandlePitchChange(myPitchChange);
  //myPitchChange(2,0);
}

/***********************
  Main Loop
************************/
void loop() { 
  // updateDisplay(0, 7); // display cntrl 2, dusplayvalues array 1, channel 2
  // updateDisplay(1, 2); // display cntrl 1, displayvalues array 0, channel 7
   
  // Loop over button states and display for each controller 
  for (int x = 0; x <= 1; x++){    // cntrl 1,2
    updateDisplay(x, tcaDisplayAddress[x]);
    for (int i = 0; i <= 1; i++) { // button 1,2
      buttonState(oscParam[0], x, oscParam[2], i);
    }
  }

  // Receive all osc messages
  myMicroOsc.onOscMessageReceived(myOnOscMessageReceived);  // TRIGGER OSC RECEPTION
  

  // Loop over as5600 instances and /pot1, /pot2, ...
  if (millis() - myChronoStart >= 50) {   // IF 50 MS HAVE ELLAPSED
    for (int x = 0; x <= 1; x++){         // Loop over ctrl 1,2
      for (int i = 0; i <= 2; i++){       // Loop over magnectic encoder 1,2,3
        sendValueMagneticEncoder(oscParam[0], x, as5600List[x][i][0], i, oscParam[1], tcaAddress[x][i]);
      }
    }
    myChronoStart = millis(); 
  }   
  
  //Example send single osc message without loop
  //sendValueMagneticEncoder(as5600_0, 0, "/pot1");
  
  // Read a sensor value from analogue pin 0 of 16 bit ADC
  //int16_t raw = ADS.readADC(0);
  //Serial.println(raw);
  //mySensor.add(raw);

  // Output the smoothed sensor value to the serial
  //Serial.println(mySensor.get());
  
  //while (Serial.available()) {
  //  Serial.println(parameterName);
  
  // Convert incoming ASCI bytes to Strings and Monitor them.
  // String parameterValue = Serial.readStringUntil(10);
  // String parameterName = Serial.readStringUntil(10);
  // String parameterType = Serial.readStringUntil(10);
  //  delay(100);
  //  display.setCursor(0, 26);
  //  display.println(parameterName);
  //  display.setCursor(80, 26);
  //  display.println(String(parameterValue));
  //  display.setCursor(110, 26);
  //  display.println(String(parameterType));
  // display.display();
  //}

  //  myMicroOsc.sendInt("/pot", analogRead(myPotPin) );  // SEND POTENTIOMETER
  // Serial.println(analogRead(myPotPin));

  // myMicroOsc.sendInt("/photo", analogRead(myPhotoPin) );  // SEND PHOTOCELL

  // myMicroOsc.sendInt("/button", digitalRead(myButtonPin));  // SEND BUTTON

  //val = analogRead(analogPin);  // read the input pin
  //Serial.println(val);          // debug value

  // Serial.println(myPitchChange);
  // usbMIDI.sendPitchBend((raw -8192), 1);
  // delay(50);

  // usbMIDI.sendPitchBend((raw -8192), 2);
  // usbMIDI.read();
  // Serial.print("getData: ");
  // usbMIDI.getData2();
  // usbMIDI.PitchBend
  // usbMIDI.getType(6);
  // controlChange(0, HIGHCC1, raw << 2 & 0x7F);
  // controlChange(0, LOWCC1, (raw >> 7) & 0x7F);

  // Serial.print("Sending CC, value: ");
  // Serial.println(raw);
  // Serial.println();
  // MidiUSB.flush();
} // -- End of void Loop --