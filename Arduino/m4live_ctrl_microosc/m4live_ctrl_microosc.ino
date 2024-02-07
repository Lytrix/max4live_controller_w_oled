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
MicroOscSlip<1024> myMicroOsc(&Serial);  // CREATE AN INSTANCE OF MicroOsc FOR SLIP MESSAGES

unsigned long myChronoStart = 0;  // VARIABLE USED TO LIMIT THE SPEED OF THE loop() FUNCTION.
unsigned long timeCnt = 0;
const long SCREEN_TIMEOUT = 60000;

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
unsigned int tcaAddress[4][3][2] = {
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
unsigned int as5600_rotation[4][3];

// Store invert button 1 or 0 for each button
unsigned int invertButton[4][2];

// List of Multiplexer wire and channel number for each display
unsigned int tcaDisplayAddress[4][2] = {
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

const char initialDisplay[4][5] = {
  "MAX",
  "4",
  "LIVE",
  "CTRL"
};

const char oscPotentiometerAddress[4][3][9] = {
   {
    "/c/1/p/1", 
    "/c/1/p/2", 
    "/c/1/p/3"
  },
  {
    "/c/2/p/1", 
    "/c/2/p/2", 
    "/c/2/p/3"
  },
  {
    "/c/3/p/1", 
    "/c/3/p/2", 
    "/c/3/p/3"
  },
  {
    "/c/4/p/1", 
    "/c/4/p/2", 
    "/c/4/p/3"
  }
};

const char oscAddressButton[4][3][9]= {
  {
    "/c/1/b/1",
    "/c/1/b/2"
  },
  {
    "/c/2/b/1",
    "/c/2/b/2"
  },
  {
    "/c/3/b/1",
    "/c/3/b/2"
  },
  {
    "/c/4/b/1",
    "/c/4/b/2"
  }
};

// Lists of parameter values to store OSC message values as a buffer for storing and taking display values from.
volatile char displayTxtKnob[4][3][3][12];

// List of titles for each controller
volatile char displayTxtController[4][16];

// List of display values for each button
volatile char displayTxtButton[4][2][12];

// List for storing each received OSC message for setting the slider width
volatile float sliderValue[4][3];

// For creating OSC address to receive on
// char oscAddress[24];
// char oscParam[3][4] = {"/c", "/p", "/b"}; // controller, potentiometer, button
// char strDeviceNumber[3];
// char strParamNumber[3];

// Store old and new send value for each TCA channel in a list to reduce number of serial sends
unsigned int lastEncoderValue[4][3];

// Setup default display cursor positions to loop in updateDisplay function.
unsigned int displayPos[3][3][2] = {
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
byte buttonPin[4][2] = {
  {0, 1},
  {2, 3},
  {4, 5},
  {6, 7}
};

byte ledPin[4][2] = {
  {8, 9},
  {10, 11},
  {12, 15},
  {14, 21}  // rewired pin 13 to 21 due to also turning reset led on on teensy board when used
};

// Led, buttonstate variables
float ledState[4][2];
byte lastButtonState[4][2];
byte currentButtonState[4][2];

// display slider variables
int16_t sliderLength = 37;
int16_t sliderHeight = 5;
int16_t fillLength;

// Test variables
// int ledPinTeensy = 13;
// int analogPin = A0;  // potentiometer wiper (middle terminal) connected to analog pin 3
// int val = 0;         // variable to store the value read
// int pitch;


/***********************
  Functions
************************/

// Channel and Wire select on each Multiplexer via tcaAddress array
void tcaSelect(unsigned int tcaAddress[2]) {
  unsigned int wire = tcaAddress[0];
  unsigned int channel = tcaAddress[1];

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
void sendValueMagneticEncoder(const char *oscAddress, AS5600 &as5600_reference, unsigned int lastEncoderValue, unsigned int tcaAddress) {
  tcaSelect(tcaAddress);
  int currentEncoderValue = as5600_reference.readAngle();

  if (currentEncoderValue != lastEncoderValue) {  
      myMicroOsc.sendInt(oscAddress, currentEncoderValue);  // SEND MAGNETIC ENCODE
      lastEncoderValue = currentEncoderValue;
  }
}

// Offset Magnetic Encoder // If VST value is update via mouse input, recieve updated value to calculate new offset of magnetic encoder, so it does not jump.
void setOffsetMagneticEncoder(unsigned int deviceNumber, AS5600 &as5600_reference, unsigned int channel, unsigned int parameterOffset, unsigned int tcaAddress, unsigned int lastEncoderValue) {
  const char *oscAddress = oscPotentiometerAddress[deviceNumber][channel];

  tcaSelect(tcaAddress);
  unsigned int readAngle = as5600_reference.readAngle();
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
    unsigned int currentEncoderValue = as5600_reference.readAngle();
    if (currentEncoderValue != lastEncoderValue) {
      myMicroOsc.sendInt(oscAddress, currentEncoderValue);  // SEND MAGNETIC ENCODE
      lastEncoderValue = currentEncoderValue;
    }
  }
}

// // Parse all OSC addresses in a for loop by (1, "/name") equals: /param1/name
// void oscAddressParser(char oscDeviceName[4], int deviceNumber, char oscParamName[4], int parameterNumber, char oscAddressType[10]){
//   sprintf(strDeviceNumber, "/%d", deviceNumber+1);   // /1, /2, ...
//   sprintf(strParamNumber, "/%d", parameterNumber+1); // /1, /2, ...
 
//   strcpy(oscAddress, oscDeviceName);   // /c
//   strcat(oscAddress, strDeviceNumber); // /1
//   strcat(oscAddress, oscParamName);    // /p
//   strcat(oscAddress, strParamNumber);  // /1
//   strcat(oscAddress, oscAddressType);  // /value
//   // Serial.print("created OSCadress: ");
//   // Serial.println(oscAddress); // /c1/p1/value
// }

// OSC MESSAGE LISTENER
void myOnOscMessageReceived(MicroOscMessage& oscMessage) {
  
  // Recieve the main title for each controller 
  // No display update need, because update display is triggered by /name when selecting potentiometer 1
  // For example /title 1 2 "LMF"
  if (oscMessage.checkOscAddressAndTypeTags("/title", "is")) {  
    unsigned int ctrl = oscMessage.nextAsInt();
    char *title = oscMessage.nextAsString();
    strcpy(displayTxtController[ctrl], title); 
  } else 

  // Receive the selected 4 chars parameter name for each controller (1,2,3,4) and potentiometer (1,2,3)
  // Along with corresponding unit names, optionally with the set inverse of potentiometer
  // For example: /value 1 2 "FREQ" "kHz" 0
  if (oscMessage.checkOscAddressAndTypeTags("/name", "iissi")) { 

    unsigned int ctrl = oscMessage.nextAsInt();
    unsigned int pot = oscMessage.nextAsInt();
    char *name = oscMessage.nextAsString();
    char *units = oscMessage.nextAsString();
    unsigned int invert = oscMessage.nextAsInt(); 

    // copy values to display buffer
    strcpy(displayTxtKnob[ctrl][pot][0], name); 
    strcpy(displayTxtKnob[ctrl][pot][2], units);
      
    if (invert == 0) {  // 0 or 1 to inverse potentiometer direction
      as5600List[ctrl][pot][0].setDirection(AS5600_CLOCK_WISE);
    } else {
      as5600List[ctrl][pot][0].setDirection(AS5600_COUNTERCLOCK_WISE);
    }
    updateDisplay(displayList[ctrl][0], ctrl, tcaDisplayAddress[ctrl]); 
  } else
  
  // Receive string value and float to display real world value
  // and the 0-1 float value to set the slider width 
  // For example: /value 1 2 "12.0" 0.860321
  if (oscMessage.checkOscAddressAndTypeTags("/value", "iisi")) { 
    unsigned int ctrl = oscMessage.nextAsInt();
    unsigned int pot = oscMessage.nextAsInt();
    char *value = oscMessage.nextAsString();
    int sliderInt = oscMessage.nextAsInt();
    float slider = ((float)sliderInt/100) * sliderLength;
    Serial.println(slider);
    if (displayTxtKnob[ctrl][pot][1] != value) {
      strcpy(displayTxtKnob[ctrl][pot][1], value); // "12.0"
      sliderValue[ctrl][pot] = slider;               // 0.12345
      timeCnt = millis();                          // Reset time for screensaver 
    } 
    updateDisplay(displayList[ctrl][0], ctrl, tcaDisplayAddress[ctrl]);
  } else 
  
  // Sync encoder value to VST value by receiving VST value as new offset value as 0-4096 int
  // It will offset the encoder to the new value if the current value is less or more then 5 out of range.
  // For example: /offset 1 2 4096"
  if (oscMessage.checkOscAddressAndTypeTags("/offset", "iii")) { 
    unsigned int ctrl = oscMessage.nextAsInt();
    unsigned int pot = oscMessage.nextAsInt();
    unsigned int parameterOffset = oscMessage.nextAsInt();
    setOffsetMagneticEncoder(ctrl, as5600List[ctrl][pot][0], pot, parameterOffset, tcaAddress[ctrl][pot], lastEncoderValue[ctrl][pot]); // cntr 1, channel 0, offset 4096, instance as5600_0
  } else
  
  // Receive VST button state to set led state AND set led on/off
  // it uses floats as states to also cater for continuous values > or < 0.5
  // For example: /button 1 2 0. "Off"
  if (oscMessage.checkOscAddressAndTypeTags("/button", "iisii")) {  
    unsigned int ctrl = oscMessage.nextAsInt();
    unsigned int pot = oscMessage.nextAsInt();
    const char *buttonValue = oscMessage.nextAsString();
    byte state = oscMessage.nextAsInt(); // 1. or 0.
    byte invertState = oscMessage.nextAsInt();
    // invertButton[ctrl][pot] = invertState;
    strcpy(displayTxtButton[ctrl][pot], buttonValue);  // "IN" 
    updateDisplay(displayList[ctrl][0], ctrl, tcaDisplayAddress[ctrl]);
    timeCnt = millis(); // reset time for screensaver
    
    if (invertState == HIGH) {
      if (state == HIGH){
         digitalWrite(ledPin[ctrl][pot], LOW);
        //ledState[ctrl][pot]=LOW; 
      }  else  {
        digitalWrite(ledPin[ctrl][pot], HIGH);
        //ledState[ctrl][pot]=HIGH;
       
      }
    } else {
      if (state == HIGH ){
        digitalWrite(ledPin[ctrl][pot], HIGH);
        ledState[ctrl][pot]=LOW; 
      } else {
        digitalWrite(ledPin[ctrl][pot], LOW);
        ledState[ctrl][pot]=HIGH;
      }
      
    }
   
  }
 

  // Basic Test reset led on Teensy
  // if (oscMessage.checkOscAddressAndTypeTags("/led")) {  // IF THE ADDRESS IS /led
  //   int newValue = oscMessage.nextAsInt();   // GET NEW VALUE AS INT
  //   digitalWrite(ledPinTeensy, newValue);         // SET LED OUTPUT TO VALUE (DIGITAL: OFF/ON)
  //   Serial.write("led on");
  // }
}



// Clear and push display with updated values in void Loop()
void updateDisplay(Adafruit_SSD1306 &display, unsigned int c, unsigned int tcaDisplayAddress[2]) {
    tcaSelect(tcaDisplayAddress);

    display.clearDisplay();
    display.setTextSize(1);  // Draw 1X-scale text
    display.setTextColor(SSD1306_WHITE);
    
    // Generate 1 of 3 rows of display information using the prefilled array.
    //for (int row = 0; row <= 2; row++) { // loop over each display row
      //for (int col = 0; col <= 2; col++) { // loop over each display element
  // Controller 1  
    // Row 1
      // Column 1: Name 
        const char *name1 = displayTxtKnob[c][0][0];
        display.setCursor(displayPos[0][0][0], displayPos[0][0][1]);
        display.println(name1);
      // Column 3: Value  
        const char *value1 = displayTxtKnob[c][0][1];
        display.setCursor(displayPos[0][1][0], displayPos[0][1][1]);
        display.println(value1);
      // Column 4: Units
        const char *units1 = displayTxtKnob[c][0][2];
        display.setCursor(displayPos[0][2][0], displayPos[0][2][1]);
        display.println(units1);
      // Column 2: Slider
        float slide1 = sliderValue[c][0];
        display.drawRect(33, displayPos[0][0][1]+2, slide1, sliderHeight, SSD1306_WHITE);

    // Row 2
      // Column 1: Name  
       const char *name2 = displayTxtKnob[c][1][0];
        display.setCursor(displayPos[1][0][0], displayPos[1][0][1]);
        display.println(name2);
      // Column 3: Value  
        const char *value2 = displayTxtKnob[c][1][1];
        display.setCursor(displayPos[1][1][0], displayPos[1][1][1]);
        display.println(value2);
      // Column 4: Units
        const char *units2 = displayTxtKnob[c][1][2];
        display.setCursor(displayPos[1][2][0], displayPos[1][2][1]);
        display.println(units2);
      // Column 2: Slider
        float slide2 = sliderValue[c][1];
        display.drawRect(33, displayPos[1][0][1]+2, slide2, sliderHeight, SSD1306_WHITE);

    // Row 3
      // Column 1: Name  
        const char *name3 = displayTxtKnob[c][2][0];
        display.setCursor(displayPos[2][0][0], displayPos[2][0][1]);
        display.println(name3);
      // Column 3: Value  
        const char *value3 = displayTxtKnob[c][2][1];
        display.setCursor(displayPos[2][1][0], displayPos[2][1][1]);
        display.println(value3);
      // Column 4: Units
        const char *units3 = displayTxtKnob[c][2][2];
        display.setCursor(displayPos[2][2][0], displayPos[2][2][1]);
        display.println(units3);
      // Column 2: Slider
        float slide3 = sliderValue[c][2];
        display.drawRect(33, displayPos[2][0][1]+2, slide3, sliderHeight, SSD1306_WHITE);

    // Button 1 & 2 info
      const char *button1 = displayTxtButton[c][0];
      display.setCursor(2, 56);
      display.println(button1);
      
      const char *button2 = displayTxtButton[c][1];
      display.setCursor(75, 56);
      display.println(button2);
  
    // Variables for getTextBounds function to center text
    int16_t x1;
    int16_t y1;
    uint16_t width;
    uint16_t height;
    // center title text
    const char *title = displayTxtController[c];
    display.getTextBounds(title, 0, 0, &x1, &y1, &width, &height);
    display.setCursor((SCREEN_WIDTH - width) / 2, 0);
    display.println(title);
    
    display.display();
  }

// Button state function to send ledState update (0 or 1) to Max when Pin goes from High to Low. 
// The Led is turned on/off only via receiving OSCmessages to have one master being the VST itself.
void buttonState(const char *oscAddress, unsigned int ctrl, unsigned int btn) {
  lastButtonState[ctrl][btn] = currentButtonState[ctrl][btn];      // save the last state
  currentButtonState[ctrl][btn] = digitalRead(buttonPin[ctrl][btn]); // read new state

  if(lastButtonState[ctrl][btn] == HIGH && currentButtonState[ctrl][btn] == LOW) {
    // invert state of LED
    //ledState[ctrl][btn] = !ledState[ctrl][btn];
    myMicroOsc.sendInt(oscAddress, ledPin[ctrl][btn]);
    //myMicroOsc.sendFloat(oscAddress, ledState[ctrl][btn]);
  }
}

// Slicer function used to limit parameter names on display.
// void slice(const char* str, char* result, size_t start, size_t end) {
//     strncpy(result, str + start, end - start);
// }

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
    for (int t = 0; t <= 7; t++) {
      int tcaList[2] = {w, t};
      tcaSelect(tcaList);
      for (int addr = 0; addr <= 127; addr++) {
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
      currentButtonState[c][b] = digitalRead(buttonPin[c][b]);
      pinMode(ledPin[c][b], OUTPUT);          // set arduino pin to output mode
      ledState[c][b] = digitalRead(ledPin[c][b]);
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
    displayList[c][0].fillScreen(SSD1306_WHITE);
    displayList[c][0].setTextSize(5);  // Draw 1X-scale text
    displayList[c][0].setTextColor(SSD1306_BLACK);
    int16_t x1;
    int16_t y1;
    uint16_t width;
    uint16_t height;
    // center title text
    displayList[c][0].getTextBounds(initialDisplay[c], 0, 0, &x1, &y1, &width, &height);
    displayList[c][0].setCursor((SCREEN_WIDTH - width) / 2, 15);
    displayList[c][0].println(initialDisplay[c]);
    displayList[c][0].display(); // show initial display with white fill to test pixels.
  }
  delay(3000);
  for (int c = 0; c <= 3; c++) {  // For each 4 ctrl modules
    tcaSelect(tcaDisplayAddress[c]);
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
  if (millis() - myChronoStart >= 50 && Serial.availableForWrite() > 20) {
    // myMicroOsc.sendInt("/heartbeat", 1);
    // Loop over ctrl 1,2,3,4
    // Loop over magnectic encoder 1,2,3
    sendValueMagneticEncoder("/c/0/p/0", as5600List[0][0][0], lastEncoderValue[0][0], tcaAddress[0][0]); 
    sendValueMagneticEncoder("/c/0/p/1", as5600List[0][1][0], lastEncoderValue[0][1], tcaAddress[0][1]);
    sendValueMagneticEncoder("/c/0/p/2", as5600List[0][2][0], lastEncoderValue[0][2], tcaAddress[0][2]);

    sendValueMagneticEncoder("/c/1/p/0", as5600List[1][0][0], lastEncoderValue[1][0], tcaAddress[1][0]);
    sendValueMagneticEncoder("/c/1/p/1", as5600List[1][1][0], lastEncoderValue[1][1], tcaAddress[1][1]);
    sendValueMagneticEncoder("/c/1/p/2", as5600List[1][2][0], lastEncoderValue[1][2], tcaAddress[1][2]);

    sendValueMagneticEncoder("/c/2/p/0", as5600List[2][0][0], lastEncoderValue[2][0], tcaAddress[2][0]);
    sendValueMagneticEncoder("/c/2/p/1", as5600List[2][1][0], lastEncoderValue[2][1], tcaAddress[2][1]);
    sendValueMagneticEncoder("/c/2/p/2", as5600List[2][2][0], lastEncoderValue[2][2], tcaAddress[2][2]);

    sendValueMagneticEncoder("/c/3/p/0", as5600List[3][0][0], lastEncoderValue[3][0], tcaAddress[3][0]);
    sendValueMagneticEncoder("/c/3/p/1", as5600List[3][1][0], lastEncoderValue[3][1], tcaAddress[3][1]);
    sendValueMagneticEncoder("/c/3/p/2", as5600List[3][2][0], lastEncoderValue[3][2], tcaAddress[3][2]);
    
    // loop over button 1, 2 for each controller
    // buttonState("/c/0/b/0", 0, 0);
    // buttonState("/c/0/b/1", 0, 1);

    // buttonState("/c/1/b/0", 1, 0);
    // buttonState("/c/1/b/1", 1, 1);
    
    // buttonState("/c/2/b/0", 2, 0);
    // buttonState("/c/2/b/1", 2, 1);
    
    // buttonState("/c/3/b/0", 3, 0);
    // buttonState("/c/3/b/1", 3, 1);

    myChronoStart = millis(); // update delay
  } 
  // if (millis() > (timeCnt + SCREEN_TIMEOUT))
  // {
  //   // Activate Screensaver
  //   tcaSelect(tcaDisplayAddress[0]);
  //   displayList[0][0].clearDisplay();
  //   displayList[0][0].display();
    
  //   tcaSelect(tcaDisplayAddress[1]);
  //   displayList[1][0].clearDisplay();
  //   displayList[1][0].display();
    
  //   tcaSelect(tcaDisplayAddress[2]);
  //   displayList[2][0].clearDisplay();
  //   displayList[2][0].display();
    
  //   tcaSelect(tcaDisplayAddress[3]);
  //   displayList[3][0].clearDisplay();
  //   displayList[3][0].display();
    
  //   digitalWrite(ledPin[0][0], LOW);
  //   digitalWrite(ledPin[0][1], LOW);
  //   digitalWrite(ledPin[1][0], LOW);
  //   digitalWrite(ledPin[1][1], LOW);
  //   digitalWrite(ledPin[2][0], LOW);
  //   digitalWrite(ledPin[2][1], LOW);
  //   digitalWrite(ledPin[3][0], LOW);
  //   digitalWrite(ledPin[3][1], LOW);
  // }

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