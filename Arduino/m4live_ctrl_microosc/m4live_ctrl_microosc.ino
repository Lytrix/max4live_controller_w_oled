#include <Wire.h>
#include <AS5600.h>
#include <MicroOscSlip.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// #include "ADS1X15.h"
// #include "MIDIUSB.h"
// #include <Smoothed.h>

// THE NUMBER 128 BETWEEN THE < > SYMBOLS  BELOW IS THE MAXIMUM NUMBER OF BYTES RESERVED FOR INCOMMING MESSAGES.
// MAKE SURE THIS NUMBER OF BYTES CAN HOLD THE SIZE OF THE MESSAGE YOUR ARE RECEIVING IN ARDUINO.
// OUTGOING MESSAGES ARE WRITTEN DIRECTLY TO THE OUTPUT AND DO NOT NEED ANY RESERVED BYTES.
MicroOscSlip<512> myMicroOsc(&Serial);  // CREATE AN INSTANCE OF MicroOsc FOR SLIP MESSAGES

unsigned long myChronoStart = 0;  // VARIABLE USED TO LIMIT THE SPEED OF THE loop() FUNCTION.

// Set address of first and second I2C multiplexer
#define TCAADDR 0x70

// Create instance for Magnetic Readers ctrl module 1 first i2c
AS5600 as5600_0(&Wire);
AS5600 as5600_1(&Wire);
AS5600 as5600_2(&Wire);
// Create instance for Magnetic Readers ctrl module 2 first i2c
AS5600 as5600_3(&Wire);
AS5600 as5600_4(&Wire);
AS5600 as5600_5(&Wire);
// Create instance for Magnetic Readers ctrl module 3 second i2c
AS5600 as5600_6(&Wire1);
AS5600 as5600_7(&Wire1);
AS5600 as5600_8(&Wire1);
// Create instance for Magnetic Readers ctrl module 4 second i2c
AS5600 as5600_9(&Wire1);
AS5600 as5600_10(&Wire1);
AS5600 as5600_11(&Wire1);

// Reference list of classes Used to iterate over in the OSC address offset
AS5600 *as5600List[4][3]= {
  {&as5600_0, &as5600_1, &as5600_2},
  {&as5600_3, &as5600_4, &as5600_5},
  {&as5600_6, &as5600_7, &as5600_8},
  {&as5600_9, &as5600_10, &as5600_11}
}; 

// List of Multiplexer wire and channel number for each magnetic encoder
int tcaAddress[4][3][2] = {
    {
      {0,1},
      {0,6},
      {0,0}
    }, // main controller, 7 is oled
    {
      {0,3},
      {0,4},
      {0,5}
    },  // satellite controller, 2 is oled
    {
      {1,1},
      {1,6},
      {1,7}
    },  // satellite controller with tca multiplexer, 0 is oled
    {
      {1,3},
      {1,4},
      {1,5}
    }   // satellite controller with tca multiplexer, 2 is oled
};

// Encoder direction per controller, per magnetic encoder. 1 is clockwise, 0 is counterclockwise
int as5600_rotation[4][3];

// Store invert button 1 or 0 for each button
int invertButton[4][2];

// List of Multiplexer wire and channel number for each display
int tcaDisplayAddress[4][2] = {
  {0, 7},
  {0, 2}, // ctrl1, ctrl2 on wire (=0)
  {1, 0},
  {1, 2}  // ctrl3, ctrl4 on wire1 (=1)
};  

// Set Display information
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define I2C_SPEED 400000
#define I2C_BUSS1 &Wire  
#define I2C_BUSS2 &Wire1

// Create an instance for each display for each hardware i2c
Adafruit_SSD1306 display1_2(SCREEN_WIDTH, SCREEN_HEIGHT, I2C_BUSS1, OLED_RESET, I2C_SPEED);
Adafruit_SSD1306 display3_4(SCREEN_WIDTH, SCREEN_HEIGHT, I2C_BUSS2, OLED_RESET, I2C_SPEED);

// Reference list of classes Used to iterate over in the OSC address offset
Adafruit_SSD1306 *displayList[4]= {
  &display1_2, &display1_2,   //wire
  &display3_4, &display3_4    //wire1
}; 

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

// Lists of parameter values to store OSC message values as a buffer for storing and taking display values from.
char displayTxtKnob[4][3][3][12];

// List of titles for each controller
char displayTxtController[5][16];

// List of display values for each button
char displayTxtButton[4][2][16];

// List for storing each received OSC message for setting the slider width
float sliderValue[4][3];

// For creating OSC address to receive on
char oscAddress[24];
char oscParam[3][4] = {"/c", "/p", "/b"}; // controller, potentiometer, button
char strDeviceNumber[3];
char strParamNumber[3];

// Store old and new send value for each TCA channel in a list to reduce number off serial sends
int oldValue[2];
int newValue[2];

// Setup default display cursor positions to loop in updateDisplay function.
int displayPos[3][3][2] = {
  { // display row 2
    {2, 12},
    {75,12},
    {105,12}
  },
  { // display row 3
    {2, 27},
    {75,27},
    {105,27}
  },
  { // display row 4
    {2, 42},
    {75,42},
    {105,42}
  }
};

// Button and led pin numbers per ctrl module 
const int buttonPin[4][2] = {
  {0, 1},
  {2, 3},
  {4, 5},
  {6, 7}
};

const int ledPin[4][2] = {
  {8, 9},
  {10, 11},
  {12, 15},
  {14, 21}  // rewired pin 13 to 21 due to also turning reset led on on teensy board when used
};

// Led, buttonstate variables
float ledState[4][2];
int lastButtonState[4][2];
int currentButtonState[4][2];


// Test variables
// int ledPinTeensy = 13;
// int analogPin = A0;  // potentiometer wiper (middle terminal) connected to analog pin 3
// int val = 0;         // variable to store the value read
// int pitch;


/***********************
  Functions
************************/

// Channel and Wire select on each Multiplexer via tcaAddress array
void tcaSelect(int tcaAddress[2]) {
  int wire = tcaAddress[0];
  int channel = tcaAddress[1];

  // if (channel > 7) return;
  if (wire == 0) {
    Wire.beginTransmission(TCAADDR);
    Wire.write(1 << channel);
    Wire.endTransmission();
  }
  if (wire == 1) {
    Wire1.beginTransmission(TCAADDR);
    Wire1.write(1 << channel);
    Wire1.endTransmission();
  }
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
void setOffsetMagneticEncoder(int deviceNumber, AS5600 &as5600_reference, int pot, int parameterOffset, int tcaAddress) {
  int channel = pot -1;
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
      sprintf(strDeviceNumber, "/%d", deviceNumber);  
      sprintf(strParamNumber, "/%d", pot);
  
      strcpy(oscAddress, "/c");
      strcat(oscAddress, strDeviceNumber);
      strcat(oscAddress, "/p");
      strcat(oscAddress, strParamNumber);
      myMicroOsc.sendInt(oscAddress, newValue[channel]);  // SEND MAGNETIC ENCODE
      oldValue[channel] = newValue[channel];
    }
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
char *temp;
// OSC MESSAGE LISTENER
void myOnOscMessageReceived(MicroOscMessage& oscMessage) {
  
  // Recieve the main title for each controller 
  // No display update need, because update display is triggered by /name when selecting potentiometer 1
  // For example /title 1 2 "LMF"
  if (oscMessage.checkOscAddress("/title", "iis")) {  
    int ctrl = oscMessage.nextAsInt();
    int pot = oscMessage.nextAsInt();
    strcpy(displayTxtController[ctrl-1], oscMessage.nextAsString()); 
  } else 

  // Receive the selected 4 chars parameter name for each controller (1,2,3,4) and potentiometer (1,2,3)
  // Along with corresponding unit names, optionally with the set inverse of potentiometer
  // For example: /value 1 2 "FREQ" "kHz" 0
  if (oscMessage.checkOscAddress("/name", "iissi")) { 
    int ctrl = oscMessage.nextAsInt();
    int pot = oscMessage.nextAsInt();
    char *name = oscMessage.nextAsString();
    char *units = oscMessage.nextAsString();
    int invert = oscMessage.nextAsInt(); 

    // copy values to display buffer
    strcpy(displayTxtKnob[ctrl-1][pot-1][0], name); 
    strcpy(displayTxtKnob[ctrl-1][pot-1][2], units);
      
    if (invert == 0) {  // 0 or 1 to inverse potentiometer direction
      as5600List[ctrl-1][pot-1][0].setDirection(AS5600_CLOCK_WISE);
    } else {
      as5600List[ctrl-1][pot-1][0].setDirection(AS5600_COUNTERCLOCK_WISE);
    }
    updateDisplay(displayList[ctrl-1][0], ctrl-1, tcaDisplayAddress[ctrl-1]); 
  } else
  
  // Receive string value and float to display real world value
  // and the 0-1 float value to set the slider width 
  // For example: /value 1 2 "12.0" 0.860321
  if (oscMessage.checkOscAddress("/value", "iisf")) { 
    int ctrl = oscMessage.nextAsInt();
    int pot = oscMessage.nextAsInt();
    char *value = oscMessage.nextAsString();
    float slider = oscMessage.nextAsFloat();

    strcpy(displayTxtKnob[ctrl-1][pot-1][1], value); // "12.0"
    sliderValue[ctrl-1][pot-1] = slider;               // 0.12345
    updateDisplay(displayList[ctrl-1][0], ctrl-1, tcaDisplayAddress[ctrl-1]); 
  } else 
  
  // Sync encoder value to VST value by receiving VST value as new offset value as 0-4096 int
  // It will offset the encoder to the new value if the current value is less or more then 5 out of range.
  // For example: /offset 1 2 4096"
  if (oscMessage.checkOscAddress("/offset", "iii")) { 
    int ctrl = oscMessage.nextAsInt();
    int pot = oscMessage.nextAsInt();
    int parameterOffset = oscMessage.nextAsInt();
    setOffsetMagneticEncoder(ctrl, as5600List[ctrl-1][pot-1][0], pot, parameterOffset, tcaAddress[ctrl-1][pot-1]); // cntr 1, channel 0, offset 4096, instance as5600_0
  } else
  
  // Receive VST button state to set led state AND set led on/off
  // it uses floats as states to also cater for continuous values > or < 0.5
  // For example: /button 1 2 0. "Off"
  if (oscMessage.checkOscAddress("/button", "iisfi")) {  
    int ctrl = oscMessage.nextAsInt();
    int pot = oscMessage.nextAsInt();
    char *value = oscMessage.nextAsString();
    int state = oscMessage.nextAsInt(); // 1. or 0.
    invertButton[ctrl-1][pot-1] = oscMessage.nextAsInt();

    strcpy(displayTxtButton[ctrl-1][pot-1], value);  // "IN" 
    updateDisplay(displayList[ctrl-1][0], ctrl-1, tcaDisplayAddress[ctrl-1]);
    if (invertButton[ctrl-1][pot-1] == 1) {
      if (state > 0.5){
        digitalWrite(ledPin[ctrl-1][pot-1], LOW);
        ledState[ctrl-1][pot-1]=HIGH; 
      }
      if (state < 0.5){
        digitalWrite(ledPin[ctrl-1][pot-1], HIGH);
        ledState[ctrl-1][pot-1]=LOW;
      }
    } else  {
      if (state > 0.5){
        digitalWrite(ledPin[ctrl-1][pot-1], HIGH);
        ledState[ctrl-1][pot-1]=HIGH;
      }  else {
        digitalWrite(ledPin[ctrl-1][pot-1], LOW);
        ledState[ctrl-1][pot-1]=LOW; 
      }  
    }
    
  }
 

  // Basic Test reset led on Teensy
  // if (oscMessage.checkOscAddress("/led")) {  // IF THE ADDRESS IS /led
  //   int newValue = oscMessage.nextAsInt();   // GET NEW VALUE AS INT
  //   digitalWrite(ledPinTeensy, newValue);         // SET LED OUTPUT TO VALUE (DIGITAL: OFF/ON)
  //   Serial.write("led on");
  // }
}

int16_t sliderLength = 37;
int16_t sliderHeight = 5;
int16_t fillLength;

// Clear and push display with updated values in void Loop()
void updateDisplay(Adafruit_SSD1306 &display, int c, int tcaDisplayAddress[2]) {
  //if (millis() - displayStart >= 50) {
  tcaSelect(tcaDisplayAddress);

  display.clearDisplay();
  display.setTextSize(1);  // Draw 1X-scale text
  display.setTextColor(SSD1306_WHITE);
  
  // Generate 1 of 3 rows of display information using the prefilled array.
  for (int row = 0; row <= 2; row++) { // loop over each display row
    for (int col = 0; col <= 2; col++) { // loop over each display element
      display.setCursor(displayPos[row][col][0], displayPos[row][col][1]);
      display.println(displayTxtKnob[c][row][col]);
    }
    display.drawRect(33, displayPos[row][0][1]+2, round(sliderValue[c][row] * sliderLength), sliderHeight, SSD1306_WHITE);
  }

  // Button 1 & 2 info
  for (int b = 0; b<=1; b++) {
    display.setCursor(displayPos[0][b][0], 56);
    display.println(displayTxtButton[c][b]);
  }

  // Variables for getTextBounds function to center text
  int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;
  // center title text
  display.getTextBounds(displayTxtController[c], 0, 0, &x1, &y1, &width, &height);
  display.setCursor((SCREEN_WIDTH - width) / 2, 0);
  display.println(displayTxtController[c]);

  display.display();
}

// Button state function to send ledState update (0 or 1) to Max when Pin goes from High to Low. 
// The Led is turned on/off only via receiving OSCmessages to have one master being the VST itself.
void buttonState(char oscDevice[4], int deviceNumber, char oscParam[4], int parameterNumber) {
  lastButtonState[deviceNumber][parameterNumber] = currentButtonState[deviceNumber][parameterNumber];      // save the last state
  currentButtonState[deviceNumber][parameterNumber] = digitalRead(buttonPin[deviceNumber][parameterNumber]); // read new state

  if(lastButtonState[deviceNumber][parameterNumber] == HIGH && currentButtonState[deviceNumber][parameterNumber] == LOW) {
    char oscButtonAddress[24];
    //Serial.print("Button");
    //Serial.print(parameterNumber);
    //Serial.println(" is pressed");
    
    // invert state of LED
    ledState[deviceNumber][parameterNumber] = !ledState[deviceNumber][parameterNumber];
    
    // convert int to char and adding + 1 to create /b1 as oscAddress
    sprintf(strDeviceNumber, "/%d", deviceNumber+1);  
    sprintf(strParamNumber, "/%d", parameterNumber+1);
 
    strcpy(oscButtonAddress, oscDevice); // /c
    strcat(oscButtonAddress, strDeviceNumber); // /1
    strcat(oscButtonAddress, oscParam); // /b
    strcat(oscButtonAddress, strParamNumber); // /1
 
    myMicroOsc.sendFloat(oscButtonAddress, (float)ledState[deviceNumber][parameterNumber]);
   
    // control LED arccoding to the toggled state
    // digitalWrite(ledPin[item], ledState[item]); 
    // Serial.print("Ledstate: ");
    // Serial.println(ledState[item]);   
  }
}

// Slicer function used to limit parameter names on display.
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
  Wire.begin();  //i2c for tca on main board
  Wire1.begin(); //i2c for tca on satellite board
  
  //Wire.setClock(1000000);
  //Wire1.setClock(1000000);

  Serial.begin(115200);
 
  Serial.println(F(__FILE__));
  Serial.print(F("AS5600_LIB_VERSION: "));
  Serial.println(F(AS5600_LIB_VERSION));
  
  // Check which channel is connected to TCA on wire and wire1
  Serial.println(F("\nTCAScanner ready"));
  for (int w = 0; w <=1; w++) {
    for (uint8_t t = 0; t <= 7; t++) {
      int tcaList[2] = {w, t};
      tcaSelect(tcaList);
      for (uint8_t addr = 0; addr <= 127; addr++) {
        if (addr == TCAADDR) continue;
        if (w == 0) {
          Wire.beginTransmission(addr);
          if (!Wire.endTransmission()) {
            Serial.print(F("Wire "));
            Serial.print(w);
            Serial.print(F(", Chn "));
            Serial.print(t);
            Serial.print(F(", I2C 0x"));
            Serial.println(addr, HEX);
          }
        }
        if (w == 1) {
          Wire1.beginTransmission(addr);
          if (!Wire1.endTransmission()) {
            Serial.print(F("Wire "));
            Serial.print(w);
            Serial.print(F(", Channel "));
            Serial.print(t);
            Serial.print(F(", Found I2C 0x"));
            Serial.println(addr, HEX);
          }
        }
      }
    }
  }

  // Initiate Magnectic Encoders
  for (int c = 0; c <= 3; c++) {  // For each 4 ctrl modules
    for (int i = 0; i <= 2; i++) {  // for each of 3 magnetic encoders
      tcaSelect(tcaAddress[c][i]);
      as5600List[c][i][0].begin();
      
      Serial.print(F("Ctrl "));
      Serial.print(c+1);
      Serial.print(F(", as5600_"));
      Serial.print(i);
      Serial.print(F(": "));
      Serial.println(as5600List[c][i][0].isConnected() ? F("true") : F("false"));
    }
    
    for (int b = 0; b <= 1; b++) {
      pinMode(buttonPin[c][b], INPUT_PULLUP); // set arduino pin to input pull-up mode
      pinMode(ledPin[c][b], OUTPUT);          // set arduino pin to output mode
      currentButtonState[c][b] = digitalRead(buttonPin[c][b]);
    }

    tcaSelect(tcaDisplayAddress[c]);
    if (!displayList[c][0].begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
      Serial.print(F("Ctrl"));
      Serial.print(c);
      Serial.println(F(" SSD1306 allocation failed"));
      for (;;)
        ;  // Don't proceed, loop forever
    }
    displayList[c][0].clearDisplay();
    displayList[c][0].display(); // show empty display, else noise will show.
  }
  
  // For testing
  // pinMode(ledPin, OUTPUT);  // LED: DIGITAL OUTPUT
  
  // ADS.begin();

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
  myMicroOsc.onOscMessageReceived(myOnOscMessageReceived);  // TRIGGER OSC RECEPTION and updat Display if parameter value or button state is updated
  
  // Loop over as5600 instances and /pot1, /pot2, ...
  if (millis() - myChronoStart >= 50 && Serial.availableForWrite() > 10) {
    for (int c = 0; c <= 3; c++){         // Loop over ctrl 1,2,3,4
      for (int i = 0; i <= 2; i++){       // Loop over magnectic encoder 1,2,3
        sendValueMagneticEncoder(oscParam[0], c, as5600List[c][i][0], i, oscParam[1], tcaAddress[c][i]);
      }
      for (int i = 0; i <= 1; i++) { // Loop over button 1,2 of each module
        buttonState(oscParam[0], c, oscParam[2], i);
      }
    }
    myChronoStart = millis(); // update delay
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