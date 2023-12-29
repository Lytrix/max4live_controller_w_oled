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
  {1,6,0}, // main controller
  {4,5,6}  // satellite controller
};

// 1 is clockwise, 0 is counterclockwise
int as5600_rotation[2][3] = {
  {1,1,0},
  {1,1,0}
};

// Set Display information
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define I2C_BUSS &Wire  // $Wire, &Wire1, ..
#define I2C_SPEED 900000
// #define I2C_BUSS2 &Wire1  // $Wire, &Wire1, ..

// Create an instance for each display
Adafruit_SSD1306 display_1(SCREEN_WIDTH, SCREEN_HEIGHT, I2C_BUSS, OLED_RESET, I2C_SPEED);
Adafruit_SSD1306 display_2(SCREEN_WIDTH, SCREEN_HEIGHT, I2C_BUSS, OLED_RESET, I2C_SPEED);

// Create a reference list to loop over
Adafruit_SSD1306 *displayList[2]= {&display_1, &display_2};

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
char title[24];

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

float parameterSliderValue1 = 0.0;
float parameterSliderValue2 = 0.0;
float parameterSliderValue3 = 0.0;
float parameterSliderValue4 = 0.0;
float parameterSliderValue5 = 0.0;
float parameterSliderValue6 = 0.0;

// List of parameter values to iterate over in OSC addresses
char *displayTxtKnob[2][3][3]= {
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

// List of parameter values to iterate over in OSC addresses
char *displayTxtButton[2][2]= {
  {buttonValue1, buttonValue2},
  {buttonValue3, buttonValue4}
};


float sliderValue[2][3]= {
  {parameterSliderValue1, parameterSliderValue2, parameterSliderValue3},
  {parameterSliderValue4, parameterSliderValue5, parameterSliderValue6},  
};

// For creating OSC address to receive on
char oscAddress[24];
char oscParam[2][7]= {"/p", "/b"};
char strNumber[2];

// For creating OSC address to send values
char OSCaddress[5];
char potmeterNumber[2];

// Store old and new send value for each TCA channel in a list to reduce number off serial sends
int oldValue[2];
int newValue[2];

// Setup default display cursor positions to loop in updateDisplay function.
int displayPos[3][3][2]= {
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

// Button and led Variables
const int buttonPin[4] = {0,1,2,3}; // Teensy pin connected to button's pin
const int ledPin[4] = {8,9,10,11};  // Teensy pin connected to LED's pin

// variables will change:
int ledState[4]= {LOW, LOW, LOW, LOW};           // the current state of LED
int lastButtonState[4]= {LOW, LOW, LOW, LOW};    // the previous state of button
int currentButtonState[4]= {LOW, LOW, LOW, LOW}; // the current state of button

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
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << bus);
  Wire.endTransmission();
}

// Send OSC message when moving potentiometer for each AS5600 magnetic encoder
void sendValueMagneticEncoder(AS5600 &as5600_reference, int channel, char* oscName, int tcaAddress) {
  itoa(channel+1, potmeterNumber, 10);
  strcpy(OSCaddress, oscName);
  strcat(OSCaddress, potmeterNumber);
  tcaSelect(tcaAddress);
  delayMicroseconds(1);
  newValue[channel] = as5600_reference.readAngle();
  if (newValue[channel] != oldValue[channel]) {  
      myMicroOsc.sendInt(OSCaddress, newValue[channel]);  // SEND MAGNETIC ENCODE
      oldValue[channel] = newValue[channel];
  }
}

// Offset Magnetic Encoder // If VST value is update via mouse input, recieve updated value to calculate new offset of magnetic encoder, so it does not jump.
void setOffsetMagneticEncoder(AS5600 &as5600_reference, int channel, int parameterOffset, int tcaAddress, char oscParam[2]) {
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
    itoa(channel+1, potmeterNumber, 10);
    strcpy(OSCaddress, oscParam);
    strcat(OSCaddress, potmeterNumber);
    newValue[channel] = as5600_reference.readAngle();
    if (newValue[channel] != oldValue[channel]) {
      myMicroOsc.sendInt(OSCaddress, newValue[channel]);  // SEND MAGNETIC ENCODE
      oldValue[channel] = newValue[channel];
    }

    //newValue[channel] = as5600_reference.readAngle();
  }
}

// Parse all OSC addresses in a for loop by (1, "/name") equals: /param1/name
void oscMessageParser(char oscParam[2], int parameterNumber, char oscAddressType[10]){
  itoa(parameterNumber+1, strNumber, 10);

  strcpy(oscAddress, oscParam);
  strcat(oscAddress,strNumber);
  strcat(oscAddress, oscAddressType);
}

// OSC MESSAGE LISTENER
void myOnOscMessageReceived(MicroOscMessage& oscMessage) {

  // Loop over displayTxt and as5600List for each parameter osc address and as5600 instance.  // Loop over displayTxt and as5600List for each parameter osc address and as5600 instance.
  for (int x = 0; x <= 0; x++)  { // Loop over each /c controller
    for (int i = 0; i <= 2; i++)  { // Loop over each /p oscAddress
      oscMessageParser(oscParam[0], i, "/offset");
      if (oscMessage.checkOscAddress(oscAddress)) {
        int parameterOffset = oscMessage.nextAsInt();
        //Serial.print("parameterOffset: ");
        //Serial.print(oscAddress);
        //Serial.print(": ");
        //Serial.println(parameterOffset);
        setOffsetMagneticEncoder(as5600List[0][i][0], i, parameterOffset, tcaAddress[x][i], oscParam[0]); //channel 0, instance as5600_0
      }

      oscMessageParser(oscParam[0], i, "/value"); 
      if (oscMessage.checkOscAddress(oscAddress)) {
        strcpy(displayTxtKnob[x][i][1], oscMessage.nextAsString());
      }

      oscMessageParser(oscParam[0], i, "/slidervalue");
      if (oscMessage.checkOscAddress(oscAddress)) {
        sliderValue[x][i]=oscMessage.nextAsFloat(); 
      }

      oscMessageParser(oscParam[0], i, "/name");
      if (oscMessage.checkOscAddress(oscAddress)) { 
        strcpy(displayTxtKnob[x][i][0], oscMessage.nextAsString());
      }
      
      oscMessageParser(oscParam[0], i, "/type");
      if (oscMessage.checkOscAddress(oscAddress)) { 
        strcpy(displayTxtKnob[x][i][2], oscMessage.nextAsString());
      }
    }
  }
  if (oscMessage.checkOscAddress("/p1/title")) {  
    strcpy(title, oscMessage.nextAsString());
  }
  
  // Receive VST button state to set led state AND set led on/off
  for (int i = 0; i <= 1; i++)  { 

    oscMessageParser(oscParam[1], i, "/value");
    if (oscMessage.checkOscAddress(oscAddress)) {  // IF THE ADDRESS IS /b1/value
      strcpy(displayTxtButton[0][i], oscMessage.nextAsString());
    }

    oscMessageParser(oscParam[1], i, "/state");
    // Serial.println(oscAddress);
    if (oscMessage.checkOscAddress(oscAddress)) {  // IF THE ADDRESS IS /b1/state
     
      int newValue = oscMessage.nextAsInt(); 
       // Serial.println(newValue);
      //ledState[i] = newValue;
      if (newValue == 1){
        digitalWrite(ledPin[i], HIGH);
        //lastButtonState[i] = HIGH;
        //currentButtonState[i]= HIGH;
        ledState[i]=HIGH;
      }
      if (newValue == 0){
        digitalWrite(ledPin[i], LOW);
        //lastButtonState[i] = HIGH;  
        //currentButtonState[i]= HIGH;
        ledState[i]=LOW; 
      }
      //digitalWrite(ledPin[i], ledState[i]); 
    }
  
  // Test reset led/button function
  // if (oscMessage.checkOscAddress("/btn1")) {  // IF THE ADDRESS IS /led
  //   int newValue = oscMessage.nextAsInt();   // GET NEW VALUE AS INT
  //   digitalWrite(btn1, newValue);          // SET LED OUTPUT TO VALUE (DIGITAL: OFF/ON)
  // }
  }

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
void updateDisplay(Adafruit_SSD1306 &display_reference, int channel) {
  tcaSelect(channel);
  
  // center title text
  length = sizeof(title)/sizeof(char);
  center = SCREEN_WIDTH/2 - round(length/2);

  display_reference.clearDisplay();
  
  // Generate 1 of 3 rows of display information using the prefilled array.
  for (int x = 0; x <= 2; x++) {
    for (int i = 0; i <= 2; i++) { // loop over each display element
      display_reference.setCursor(displayPos[x][i][0], displayPos[x][i][1]);
      display_reference.println(displayTxtKnob[0][x][i]);
    }
    display_reference.drawRect(33, displayPos[x][0][1]+2, round(sliderValue[0][x] * sliderLength), sliderHeight, SSD1306_WHITE);
  }

  // Button 1 & 2 info
  for (int i = 0; i<=1; i++) {
    display_reference.setCursor(displayPos[0][i][0], 56);
    display_reference.print(displayTxtButton[0][i]);
  }

  display_reference.setCursor(center, 2);
  display_reference.println(title);

  display_reference.display();
}

// Slicer function used to limit parameter names on display.

void buttonState(int item, char *oscAddress) {
  lastButtonState[item] = currentButtonState[item];      // save the last state
  currentButtonState[item] = digitalRead(buttonPin[item]); // read new state

  if(lastButtonState[item] == HIGH && currentButtonState[item] == LOW) {
    
    Serial.print("Button");
    Serial.print(item);
    Serial.println(" is pressed");
    
    // invert state of LED
    ledState[item] = !ledState[item];
    
    // convert int to char and adding + 1 to create /b1 as oscAddress
    int num = item + 1;
    char cStr[2];
    char buff[16];  
    itoa(num, cStr, 10);
    strcpy(buff,oscAddress);
    strcat(buff,cStr);
    
    myMicroOsc.sendInt(buff, ledState[item]);
   
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
  Serial.begin(115200);

  for (int i = 0; i < 2; i++) {
    pinMode(buttonPin[i], INPUT_PULLUP); // set arduino pin to input pull-up mode
    pinMode(ledPin[i], OUTPUT);          // set arduino pin to output mode
    currentButtonState[i] = digitalRead(buttonPin[i]);
  }


  Wire.begin();

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
  for (int i = 0; i <= 2; i++) {
    tcaSelect(tcaAddress[0][i]);
    as5600List[0][i][0].begin();
    
    if (as5600_rotation[0][i] == 1) {
      as5600_2.setDirection(AS5600_CLOCK_WISE);
    } else {
      as5600_2.setDirection(AS5600_COUNTERCLOCK_WISE);
    }
    Serial.print("Connect cntrl");
    Serial.print(0+1);
    Serial.print(" as5600_");
    Serial.print(i);
    Serial.println(as5600List[0][i][0].isConnected() ? "true" : "false");
  }

  // tcaSelect(0);
  // as5600_2.begin();  //  set direction pin.

  // Serial.print("Connect as5600_2: ");
  // Serial.println(as5600_2.isConnected() ? "true" : "false");

  // // Initiate Magnectic Encoder 0
  // tcaSelect(1);
  // as5600_0.begin();  //  set direction pin.
  // as5600_0.setDirection(AS5600_CLOCK_WISE);
  // Serial.print("Connect as5600_0: ");
  // Serial.println(as5600_0.isConnected() ? "true" : "false");

  // // Initiate Magnectic Encoder 1
  // tcaSelect(6);
  // as5600_1.begin();  //  set direction pin.
  // as5600_1.setDirection(AS5600_CLOCK_WISE);
  // Serial.print("Connect as5600_1: ");
  // Serial.println(as5600_1.isConnected() ? "true" : "false");


  tcaSelect(7);
  delayMicroseconds(10);
  if (!display_1.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display_1.setTextSize(1);
  display_1.setTextColor(SSD1306_WHITE);
  // Clear the buffer
  //display.clearDisplay();

  // display.setTextSize(1);  // Draw 1X-scale text
  // display.setTextColor(SSD1306_WHITE);
  // display.setFont(&fixed_bold10x15);
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

int x;
int i;

/***********************
  Main Loop
************************/
void loop() { 
   // print display lines from param1, etc...
  updateDisplay(displayList[0][0], 7);

  // receive all osc messages
  myMicroOsc.onOscMessageReceived(myOnOscMessageReceived);  // TRIGGER OSC RECEPTION
  
  // Loop over button states 
  for (int i = 0; i <= 1; i++) {
    buttonState(i, "/b");
  }
  
  // Loop over as5600 instances and /pot1, /pot2, ...
  if (millis() - myChronoStart >= 50) {                     // IF 50 MS HAVE ELLAPSED
    for (int i = 0; i <= 2; i++){
      sendValueMagneticEncoder(as5600List[0][i][0], i, oscParam[0], tcaAddress[0][i]);
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