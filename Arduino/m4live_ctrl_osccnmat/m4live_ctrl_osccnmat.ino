#include <Wire.h>
#include <AS5600.h>
#include <MicroOscSlip.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdio.h>
#include <string.h>
//#ifdef BOARD_HAS_USB_SERIAL
#include <SLIPEncodedSerial.h>
#include <SLIPEncodedUSBSerial.h>
#include <OSCBundle.h>
#include <OSCBoards.h>

SLIPEncodedUSBSerial SLIPSerial(thisBoardsSerialUSB);
//#else
//#include <SLIPEncodedSerial.h>
//SLIPEncodedSerial SLIPSerial(Serial1); // Change to Serial1 or Serial2 etc. for boards with multiple serial ports that don’t have Serial
//#endif

/// Screen refresh rates
const uint32_t REFRESH_RATE  = 30000;	  /// Refresh screen portion every REFRESH_RATE usec
const uint32_t REFRESH_RATE2 = 20000; /// Refresh text screen portion every REFRESH_RATE2 usec

/// OSC definitions
const uint32_t OSCINTERVAL = 50000;
OSCBundle bundleIN;

// #include "ADS1X15.h"
// #include "MIDIUSB.h"
// #include <Smoothed.h>

// THE NUMBER 128 BETWEEN THE < > SYMBOLS  BELOW IS THE MAXIMUM NUMBER OF BYTES RESERVED FOR INCOMMING MESSAGES.
// MAKE SURE THIS NUMBER OF BYTES CAN HOLD THE SIZE OF THE MESSAGE YOUR ARE RECEIVING IN ARDUINO.
// OUTGOING MESSAGES ARE WRITTEN DIRECTLY TO THE OUTPUT AND DO NOT NEED ANY RESERVED BYTES.
// MicroOscSlip<128> myMicroOsc(&Serial);  // CREATE AN INSTANCE OF MicroOsc FOR SLIP MESSAGES

OSCBundle bundleOUT;
bool oscMessageMatch = false;
unsigned long myChronoStart = 0;  // VARIABLE USED TO LIMIT THE SPEED OF THE loop() FUNCTION.
//Display refresh
unsigned long disptimer = 0;

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
int as5600_rotation[4][3] = {
  {1,1,0},
  {1,1,0},
  {1,1,1},
  {1,1,0}
};

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

char parameterName7[36]="";
char parameterValue7[10]="";
char parameterType7[3]="";

char parameterName8[36]="";
char parameterValue8[10]="";
char parameterType8[3]="";

char parameterName9[36]="";
char parameterValue9[10]="";
char parameterType9[3]="";

char parameterName10[36]="";
char parameterValue10[10]="";
char parameterType10[3]="";

char parameterName11[36]="";
char parameterValue11[10]="";
char parameterType11[3]="";

char parameterName12[36]="";
char parameterValue12[10]="";
char parameterType12[3]="";

char buttonValue1[16]="";
char buttonValue2[16]="";

char buttonValue3[16]="";
char buttonValue4[16]="";

char buttonValue5[16]="";
char buttonValue6[16]="";

char buttonValue7[16]="";
char buttonValue8[16]="";

char displayTitle1[36]="";
char displayTitle2[36]="";
char displayTitle3[36]="";
char displayTitle4[36]="";

// double parameterSliderValue1 = 0.0;
// double parameterSliderValue2 = 0.0;
// double parameterSliderValue3 = 0.0;

// double parameterSliderValue4 = 0.0;
// double parameterSliderValue5 = 0.0;
// double parameterSliderValue6 = 0.0;

// double parameterSliderValue7 = 0.0;
// double parameterSliderValue8 = 0.0;
// double parameterSliderValue9 = 0.0;

// double parameterSliderValue10 = 0.0;
// double parameterSliderValue11 = 0.0;
// double parameterSliderValue12 = 0.0;

// List of parameter values to iterate over in OSC addresses
char *displayTxtKnob[4][3][3] = {
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
  {
    {parameterName7, parameterValue7, parameterType7},
    {parameterName8, parameterValue8, parameterType8},
    {parameterName9, parameterValue9, parameterType9}
  },
  {
    {parameterName10, parameterValue10, parameterType10},
    {parameterName11, parameterValue11, parameterType11},
    {parameterName12, parameterValue12, parameterType12}
  }
};

char *displayTxtController[4] = {
  displayTitle1, 
  displayTitle2,
  displayTitle3,
  displayTitle4
  };

// List of parameter values to iterate over in OSC addresses
char *displayTxtButton[4][2] = {
  {buttonValue1, buttonValue2},
  {buttonValue3, buttonValue4},
  {buttonValue5, buttonValue6},
  {buttonValue7, buttonValue8}
};


double sliderValue[4][3];

// For creating OSC address to receive on
char oscAddress[24];
char oscParam[3][4] = {"/c", "/p", "/b"}; // controller, potentiometer, button
char strDeviceNumber[3];
char strParamNumber[13];

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
int ledState[4][2] = {
  {LOW, LOW}, 
  {LOW, LOW}, 
  {LOW, LOW},
  {LOW, LOW}
};           // the current state of LED
int lastButtonState[4][2] = {
  {LOW, LOW}, 
  {LOW, LOW}, 
  {LOW, LOW},
  {LOW, LOW}
};    // the previous state of button
int currentButtonState[4][2] = {
  {LOW, LOW}, 
  {LOW, LOW}, 
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

// Channel and Wire select on each Multiplexer via tcaAddress array
void tcaSelect(int tcaAddress[2]) {
  int wire = tcaAddress[0];
  int channel = tcaAddress[1];

  // if (channel > 7) return;
  if (wire == 0) {
    Wire.setClock(1000000);
    Wire1.setClock(1000000);
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

void LEDcontrol(OSCMessage &msg)
{
    if (msg.isInt(0))
    {
         pinMode(LED_BUILTIN, OUTPUT);
         digitalWrite(LED_BUILTIN, (msg.getInt(0) > 0)? HIGH: LOW);
         Serial.println("Led signal recieved");
    }
    else if(msg.isString(0))
    {
         int length=msg.getDataLength(0);
         if(length<5)
         {
           char str[length];
           msg.getString(0,str,length);
           if((strcmp("on", str)==0)|| (strcmp("On",str)==0))
           {
                pinMode(LED_BUILTIN, OUTPUT); 
                digitalWrite(LED_BUILTIN, HIGH);
           }
           else if((strcmp("Of", str)==0)|| (strcmp("off",str)==0))
           {
                pinMode(LED_BUILTIN, OUTPUT); 
                digitalWrite(LED_BUILTIN, LOW);
           }
         }
    }
}

// Send OSC message when moving potentiometer for each AS5600 magnetic encoder
void sendValueMagneticEncoder(OSCBundle &bndl, char oscDevice[4], int deviceNumber, AS5600 &as5600_reference, int channel, char oscParamName[4], int tcaAddress) {
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
      bndl.add(oscAddress).add(newValue[channel]);
      // myMicroOsc.sendInt(oscAddress, newValue[channel]);  // SEND MAGNETIC ENCODE
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
    double previous_difference = as5600_reference.getOffset();
    double new_difference = (((double(parameterOffset) - double(readAngle)) / 4096.) * 360.) + previous_difference;
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
      //myMicroOsc.sendInt(oscAddress, newValue[channel]);  // SEND MAGNETIC ENCODE
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


int displayControlInt;
double displayControlDouble;
char displayControlText[10];

// OSC MESSAGE LISTENER
void myOnOscMessageReceived(OSCBundle& bundleIN) {

  // Loop over displayTxt and as5600List for each parameter osc address and as5600 instance.  // Loop over displayTxt and as5600List for each parameter osc address and as5600 instance.
  for (int c = 0; c <= 3; c++)  { // Loop over each of the 4 /c controllers
    for (int p = 0; p <= 2; p++)  { // Loop over each of 3 /p oscAddresses
      oscAddressParser(oscParam[0], c, oscParam[1], p, "/offset");
      bundleIN.dispatch(oscAddress, displayControl);
      if (oscMessageMatch == true){
        setOffsetMagneticEncoder(oscParam[0], c, as5600List[c][p][0], p, displayControlInt, tcaAddress[c][p], oscParam[1]); //channel 0, instance as5600_0
      }
      // oscAddressParser(oscParam[0], c, oscParam[1], p, "/value"); 
      // bundleIN.dispatch(oscAddress, displayControl);
      // if (oscMessageMatch == true){
      //   displayTxtKnob[c][p][1] = displayControlText;
      // }
      oscAddressParser(oscParam[0], c, oscParam[1], p, "/slidervalue");
      bundleIN.dispatch(oscAddress, displayControl);
      if (oscMessageMatch == true){
        sliderValue[c][p] = displayControlDouble; 
      }
      oscAddressParser(oscParam[0], c, oscParam[1], p, "/name");
      bundleIN.dispatch(oscAddress, displayControl);
      if (oscMessageMatch == true){
        strcpy(displayTxtKnob[c][p][0], displayControlText);
      }
      oscAddressParser(oscParam[0], c, oscParam[1], p, "/type");
      bundleIN.dispatch(oscAddress, displayControl);
      if (oscMessageMatch == true){
        strcpy(displayTxtKnob[c][p][2], displayControlText);
      }
    }
    
    // Select name from first magnetic encoder parameter /p (i=0)
    oscAddressParser(oscParam[0], c, oscParam[1], 0, "/title");
    bundleIN.dispatch(oscAddress, displayControl);  
    if (oscMessageMatch == true){
      strcpy(displayTxtController[c], displayControlText);
    }
    // Receive VST button state to set led state AND set led on/off
    for (int b = 0; b <= 1; b++)  { 
      oscAddressParser(oscParam[0], c, oscParam[2], b, "/value");
      bundleIN.dispatch(oscAddress, displayControl);  // IF THE ADDRESS IS /b1/value
       if (oscMessageMatch == true){
        strcpy(displayTxtButton[c][b], displayControlText);
       }

      oscAddressParser(oscParam[0], c, oscParam[2], b, "/state");
      // Serial.println(oscAddress);
      bundleIN.dispatch(oscAddress, displayControl); // IF THE ADDRESS IS /b1/state
      if (oscMessageMatch == true){
        int newValue = displayControlInt; 
        // Serial.println(newValue);
        //ledState[i] = newValue;
        if (newValue == 1){
          digitalWrite(ledPin[c][b], HIGH);
          //lastButtonState[i] = HIGH;
          //currentButtonState[i]= HIGH;
          ledState[c][b]=HIGH;
        }
        if (newValue == 0){
          digitalWrite(ledPin[c][b], LOW);
          //lastButtonState[i] = HIGH;  
          //currentButtonState[i]= HIGH;
          ledState[c][b]=LOW; 
        }
      }
    }   
  }

  // Basic Test reset led on Teensy
  // if (oscMessage.checkOscAddress("/led")) {  // IF THE ADDRESS IS /led
  //    int newValue = oscMessage.nextAsInt();   // GET NEW VALUE AS INT
  //    digitalWrite(ledPinTeensy, newValue);         // SET LED OUTPUT TO VALUE (DIGITAL: OFF/ON)
  //    Serial.write("led on");
  // }
}

double sliderLength = 37;
int16_t sliderHeight = 5;
int16_t fillLength;
int16_t length = 0;
int16_t center = 0;


// Clear and push display with updated values in void Loop()
void updateDisplay(Adafruit_SSD1306 &display, int displayArray, int tcaDisplayAddress[2]) {
  long microsdisp = micros ();
  if (microsdisp - disptimer >= REFRESH_RATE) {
    tcaSelect(tcaDisplayAddress);
    
    display.clearDisplay();
    display.setTextSize(1);  // Draw 1X-scale text
    display.setTextColor(SSD1306_WHITE);
    
    // Generate 1 of 3 rows of display information using the prefilled array.
    for (int row = 0; row <= 2; row++) { // loop over each display row
      for (int col = 0; col <= 2; col++) { // loop over each display element
        display.setCursor(displayPos[row][col][0], displayPos[row][col][1]);
        display.println(displayTxtKnob[displayArray][row][col]);
        // display.println(sliderValue[displayArray][row]); // test one value
      }
      display.drawRect(33, displayPos[row][0][1]+2, round(sliderValue[displayArray][row] * sliderLength), sliderHeight, SSD1306_WHITE);
    }

    // Button 1 & 2 info
    for (int b = 0; b<=1; b++) {
      display.setCursor(displayPos[0][b][0], 56);
      display.println(displayTxtButton[displayArray][b]);
    }

    // center title text
    length = sizeof(displayTxtController[displayArray])/sizeof(char);
    center = SCREEN_WIDTH/2 - round(length/2);
    display.setCursor(center, 0);
    display.println(displayTxtController[displayArray]);

    display.display();
    disptimer = microsdisp;
  }
}

// Button state function to send ledState update (0 or 1) to Max when Pin goes from High to Low. 
// The Led is turned on/off only via receiving OSCmessages to have one master being the VST itself.
void buttonState(OSCBundle &bndl, char oscDevice[4], int deviceNumber, char oscParam[4], int parameterNumber) {
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
 
    //myMicroOsc.sendInt(oscButtonAddress, ledState[deviceNumber][parameterNumber]);
    bndl.add(oscButtonAddress).add(ledState[deviceNumber][parameterNumber]);

    // control LED arccoding to the toggled state
    //digitalWrite(ledPin[item], ledState[item]); 
    //Serial.print("Ledstate: ");
    //Serial.println(ledState[item]);   
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
  //Serial.begin(9600);
  //SLIPSerial.begin(9600); 
  Serial.begin(115200);
  // Serial.setTimeout(1);
  SLIPSerial.begin(115200); 
  
  Serial.println(__FILE__);
  Serial.print("AS5600_LIB_VERSION: ");
  Serial.println(AS5600_LIB_VERSION);
  
  // Check which channel is connected to TCA on wire and wire1
  Serial.println("\nTCAScanner ready");
  for (int w = 0; w <=1; w++) {
    for (uint8_t t = 0; t <= 7; t++) {
      int tcaList[2] = {w, t};
      tcaSelect(tcaList);
      for (uint8_t addr = 0; addr <= 127; addr++) {
        if (addr == TCAADDR) continue;
        if (w == 0) {
          Wire.beginTransmission(addr);
          if (!Wire.endTransmission()) {
            Serial.print("Wire ");
            Serial.print(w);
            Serial.print(", Chn ");
            Serial.print(t);
            Serial.print(", I2C 0x");
            Serial.println(addr, HEX);
          }
        }
        if (w == 1) {
          Wire1.beginTransmission(addr);
          if (!Wire1.endTransmission()) {
            Serial.print("Wire ");
            Serial.print(w);
            Serial.print(", Channel ");
            Serial.print(t);
            Serial.print(", Found I2C 0x");
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
      
      if (as5600_rotation[c][i] == 1) {
        as5600List[c][i][0].setDirection(AS5600_CLOCK_WISE);
      } else {
        as5600List[c][i][0].setDirection(AS5600_COUNTERCLOCK_WISE);
      }
      Serial.print("Ctrl ");
      Serial.print(c+1);
      Serial.print(", as5600_");
      Serial.print(i);
      Serial.print(": ");
      Serial.println(as5600List[c][i][0].isConnected() ? "true" : "false");
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
    delay(10);
    displayList[c][0].clearDisplay();
  }
  
  // For testing
  pinMode(ledPinTeensy, OUTPUT);  // LED: DIGITAL OUTPUT
  
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

// dtoa(fVal,cVal,4); Serial.println (String(cVal));

  //arguments... 
  // float-double value, char array to fill, precision (4 is .xxxx)
  //and... it rounds last digit

char* dtoa(double dN, char *cMJA, int iP) {
  char *ret = cMJA; long lP=1; byte bW=iP;
  while (bW>0) { lP=lP*10;  bW--;  }
  long lL = long(dN); double dD=(dN-double(lL))* double(lP); 
  if (dN>=0) { dD=(dD + 0.5);  } else { dD=(dD-0.5); }
  long lR=abs(long(dD));  lL=abs(lL);  
  if (lR==lP) { lL=lL+1;  lR=0;  }
  if ((dN<0) & ((lR+lL)>0)) { *cMJA++ = '-';  } 
  ltoa(lL, cMJA, 10);
  if (iP>0) { while (*cMJA != '\0') { cMJA++; } *cMJA++ = '.'; lP=10; 
  while (iP>1) { if (lR< lP) { *cMJA='0'; cMJA++; } lP=lP*10;  iP--; }
  ltoa(lR, cMJA, 10); }  return ret; }

void displayControl(OSCMessage &msg)
{   
  int p = oscAddress[7];
  int c = oscAddress[3];
  for (int i; i <= 2; i++){
    if(msg.isString(i)) // Get Value represenation
    {
      msg.getString(i, displayTxtKnob[c][p][i], 10);  
    }
  }
  if(msg.isDouble(0))
  { // Get 0-1 value for slider calculation
    sliderValue[c][p] = msg.getDouble(0); 
    dtoa(msg.getDouble(0), displayTxtKnob[0][1][0], 10); 
  }
  if(msg.isInt(0))
  {
    displayControlInt = msg.getInt(0);
    setOffsetMagneticEncoder(oscParam[0], c, as5600List[c][p][0], p, displayControlInt, tcaAddress[c][p], oscParam[1]); //channel 0, instance as5600_0
  }

}


/***********************
  Main Loop
************************/
void loop() {   
  // Receive all osc messages
  //myMicroOsc.onOscMessageReceived(myOnOscMessageReceived);  // TRIGGER OSC RECEPTION
  
  // Loop over button states and display for each controller. displays are split to address wire, wire1 
 
  
  //OSCMessage msg1("/c/1/p/1/value");
  //match will return 0 if it did not reach the end or a '/'
 
  //} else {
    // RECIEVE MESSAGES //



  
  //if (!SLIPSerial.available()) {
  // SEND MESSAGES //
 
    // OSCBundle's add' returns the OSCMessage so the message's 'add' can be composed together
    // if (digitalRead(0)==LOW) {
    //   bndl.add("/digital/0").add((digitalRead(0)==LOW));
    // }
    // if (digitalRead(0)==HIGH) {
    //   bndl.add("/digital/0").add((digitalRead(0)==HIGH));
    // }
    // // bndl.add("/analog/1").add((int32_t)analogRead(1));
    // bndl.add("/digital/5").add((digitalRead(5)==HIGH));
  
  // TEST VCMC setup:


  
  //static long microsOSC = 0;
  //if (micros () - microsOSC > OSCINTERVAL && Serial.availableForWrite () > 20) {
  
  // Loop over as5600 instances and /pot1, /pot2, ...
  if (micros() - myChronoStart > 50 && Serial.availableForWrite () > 20) {   // IF 50 MS HAVE ELLAPSED
    for (int c = 0; c <= 3; c++){         // Loop over ctrl 1,2,3,4
      for (int i = 0; i <= 2; i++){       // Loop over magnectic encoder 1,2,3
        sendValueMagneticEncoder(bundleOUT, oscParam[0], c, as5600List[c][i][0], i, oscParam[1], tcaAddress[c][i]);
      }
      for (int i = 0; i <= 1; i++) { // Loop over button 1,2 of each module
        buttonState(bundleOUT, oscParam[0], c, oscParam[2], i);
      }
    }
    //myChronoStart = micros(); // update delay
   SLIPSerial.beginPacket();
      bundleOUT.send(SLIPSerial); // send the bytes to the SLIP stream
    SLIPSerial.endPacket(); // mark the end of the OSC Packet
    
    bundleOUT.empty(); // empty the bundle to free room for a new one

  } else {
    if (SLIPSerial.available()) {
      bundleIN.fill(SLIPSerial.read());
    }
    
    // int size;
    //Serial.println(sliderValueTemp);
    
      // if( (size =SLIPSerial.available()) > 0)
      // {
      //   while(size--)
      //       bundleIN.fill(SLIPSerial.read());
      // }
    if (SLIPSerial.endofPacket()) {
      if(!bundleIN.hasError()) {
        bundleIN.route("/led", LEDcontrol);
        bundleIN.route("/val", displayControl);
        bundleIN.route("/par", displayControl);
        // myOnOscMessageReceived(bundleIN);
        bundleIN.route("/c/1/p/1", displayControl);
        bundleIN.route("/c/1/p/2", displayControl);
        bundleIN.route("/c/1/p/3", displayControl);

        //oscAddressParser(oscParam[0], c, oscParam[1], p, "/value"); 
        // bundleIN.dispatch(oscAddress, displayControl);
        // if (oscMessageMatch == true){
        //   displayTxtKnob[c][p][1] = displayControlText;
        // }

        bundleIN.empty();
      } else {
        Serial.println("Error Slip");
      }
    }
  for (int c = 0; c <= 3; c++){    // Loop over ctrl module 1,2,3,4
    updateDisplay(displayList[c][0], c, tcaDisplayAddress[c]);
  } 
  }


  



  // bundleIN.dispatch("/c/1/p/1/value", parameterSliderValue1);
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