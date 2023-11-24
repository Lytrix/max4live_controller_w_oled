#include <AS5600.h>
#include <Wire.h>
#include <MicroOscSlip.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdio.h>
#include <string.h>

// #include "SSD1306Ascii.h"

// #include <Fonts/fixed_bold10x15.h>

// #include "ADS1X15.h"
// #include "MIDIUSB.h"
// #include <Smoothed.h>

// THE NUMBER 128 BETWEEN THE < > SYMBOLS  BELOW IS THE MAXIMUM NUMBER OF BYTES RESERVED FOR INCOMMING MESSAGES.
// MAKE SURE THIS NUMBER OF BYTES CAN HOLD THE SIZE OF THE MESSAGE YOUR ARE RECEIVING IN ARDUINO.
// OUTGOING MESSAGES ARE WRITTEN DIRECTLY TO THE OUTPUT AND DO NOT NEED ANY RESERVED BYTES.
MicroOscSlip<64> myMicroOsc(&Serial);  // CREATE AN INSTANCE OF MicroOsc FOR SLIP MESSAGES

unsigned long myChronoStart = 0;  // VARIABLE USED TO LIMIT THE SPEED OF THE loop() FUNCTION.

// Set address of first I2C multiplexer
#define TCAADDR 0x70

// Create instance for Magnetic Readers
AS5600 as5600_0(&Wire);
AS5600 as5600_1(&Wire);
AS5600 as5600_2(&Wire);

// Set Display information
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define I2C_BUSS &Wire1  // $Wire, &Wire1, ..
// #define I2C_SPEED 1000000

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, I2C_BUSS, OLED_RESET); //, I2C_SPEED);

// choose your sensor
// ADS1013 ADS(0x48);
// ADS1014 ADS(0x48);
// ADS1015 ADS(0x48);
// ADS1113 ADS(0x48);
// ADS1114 ADS(0x48);

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

char parameterName1[36];
char parameterValue1[10];
char parameterType1[3];

char parameterName2[36];
char parameterValue2[10];
char parameterType2[3];

char parameterName3[36];
char parameterValue3[10];
char parameterType3[3];

float parameterSliderValue1;
float parameterSliderValue2;
float parameterSliderValue3;

// List of parameter values to iterate over in OSC addresses
char *displayTxt[3][3]= {
  {parameterName1, parameterValue1, parameterType1},
  {parameterName2, parameterValue2, parameterType2},
  {parameterName3, parameterValue3, parameterType3}
};

float sliderValue[3]= {
  parameterSliderValue1, parameterSliderValue2, parameterSliderValue3
};


// Reference list of classes Used to iterate over in the OSC address offset
AS5600 *as5600List[3]= {&as5600_0, &as5600_1, &as5600_2}; 

// For creating OSC address to receive on
char oscAddress[24];
char oscParam[7] = "/p";
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
      {0, 16},
      {80,16},
      {110,16}
    },
    { // row 3
      {0, 36},
      {80,36},
      {110,36}
    },
        { // row 4
      {0, 56},
      {80,56},
      {110,56}
    }
};

// Test variables
int ledPin = 13;

// int analogPin = A0;  // potentiometer wiper (middle terminal) connected to analog pin 3
// int val = 0;         // variable to store the value read
// int pitch;


/***********************
  Functions
************************/

// Multiplexer select channel
void tcaSelect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

// Send OSC message when moving potentiometer for each AS5600 magnetic encoder
void sendValueMagneticEncoder(AS5600 &as5600_reference, int channel, char* oscName) {
  itoa(channel+1, potmeterNumber, 10);
  strcpy(OSCaddress, oscName);
  strcat(OSCaddress, potmeterNumber);
  
  tcaSelect(channel);
  newValue[channel] = as5600_reference.readAngle();
  if (newValue[channel] != oldValue[channel]) {
    myMicroOsc.sendInt(OSCaddress, newValue[channel]);  // SEND MAGNETIC ENCODE
    oldValue[channel] = newValue[channel];
  }
}

// Offset Magnetic Encoder // If VST value is update via mouse input, recieve updated value to calculate new offset of magnetic encoder, so it does not jump.
void setOffsetMagneticEncoder(AS5600 &as5600_reference, int channel, int parameterOffset) {
  tcaSelect(channel);
  int readAngle = as5600_reference.readAngle();
  Serial.print("instance");
  Serial.println(readAngle);
  Serial.print("parameterOffset");
  Serial.println(parameterOffset);
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
    char *oscName = "/pot"; 
    itoa(channel+1, potmeterNumber, 10);
    strcpy(OSCaddress, oscName);
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
void oscMessageParser(int parameterNumber, char oscAddressType[10]){
  itoa(parameterNumber+1, strNumber, 10);

  strcpy(oscAddress, oscParam);
  strcat(oscAddress,strNumber);
  strcat(oscAddress, oscAddressType);
}

// OSC MESSAGE LISTENER
void myOnOscMessageReceived(MicroOscMessage& oscMessage) {
  
  // Loop over displayTxt and as5600List for each parameter osc address and as5600 instance.
  for (int i = 0; i <= 2; i++)  { 
    oscMessageParser(i, "/offset");
    if (oscMessage.checkOscAddress(oscAddress)) {
      int parameterOffset = oscMessage.nextAsInt();
      Serial.print("parameterOffset: ");
      Serial.print(oscAddress);
      Serial.print(": ");
      Serial.println(parameterOffset);
      setOffsetMagneticEncoder(as5600List[i][0], i, parameterOffset); //channel 0, instance as5600_0
    }

    oscMessageParser(i, "/value");
    if (oscMessage.checkOscAddress(oscAddress)) {
      strcpy(displayTxt[i][1], oscMessage.nextAsString());
    }

    oscMessageParser(i, "/slidervalue");
    if (oscMessage.checkOscAddress(oscAddress)) {
      sliderValue[i]=oscMessage.nextAsFloat();
    }

    oscMessageParser(i, "/name");
    if (oscMessage.checkOscAddress(oscAddress)) { 
      strcpy(displayTxt[i][0], oscMessage.nextAsString());
    }
    
    oscMessageParser(i, "/type");
    if (oscMessage.checkOscAddress(oscAddress)) { 
      strcpy(displayTxt[i][2], oscMessage.nextAsString());
    }
  }

  if (oscMessage.checkOscAddress("/title")) { 
    strcpy(title, oscMessage.nextAsString());
  }

  // Basic tester
  if (oscMessage.checkOscAddress("/led")) {  // IF THE ADDRESS IS /led
    int newValue = oscMessage.nextAsInt();   // GET NEW VALUE AS INT
    digitalWrite(ledPin, newValue);          // SET LED OUTPUT TO VALUE (DIGITAL: OFF/ON)
    Serial.write("led on");
  }

}


int sliderLength = 42;
int sliderHeight = 8;
int fillLength;
int length = sizeof(title)/sizeof(char);
int center = SCREEN_WIDTH/2 - (length/2);

// Clear and push display with updated values in void Loop()
void updateDisplay(int channel) {

  display.clearDisplay();
  //tcaSelected(channel);
  display.setCursor(center,0);
  display.println(title);
  for (int x = 0; x <= 2; x++) { // loop over each display line
    for (int i = 0; i <= 2; i++) { // loop over each display element
      display.setCursor(displayPos[x][i][0], displayPos[x][i][1]);
      char fixedLength[6] = "";
      slice(displayTxt[x][i], fixedLength, 0, 5);
      //strcat(fixedLength,0);
      display.println(fixedLength);
    }
    fillLength = round(sliderValue[x] * sliderLength);
    display.drawRect(32, displayPos[x][0][1], sliderLength, sliderHeight, SSD1306_WHITE);
    display.fillRect(32, displayPos[x][0][1], fillLength, sliderHeight, SSD1306_WHITE);
  }
 
  // Old setup
  //display.setCursor(0, 26);
  //display.println(parameterName1);
  //display.setCursor(80, 26);
  //display.println(parameterValue);
  //display.setCursor(110, 26);
  //display.println(parameterType);
  display.display();
  //delay(1);

}

// Slicer function used to limit parameter names on display.
void slice(const char* str, char* result, size_t start, size_t end)
{
    strncpy(result, str + start, end - start);
}

// void myPitchChange(byte channel, int pitch) {
//   digitalWrite(ledPin, HIGH);
//   delay(250);
//   digitalWrite(ledPin, LOW);
//  //Serial.print("Pitchbend range: ");
// Serial.println(pitch);
// }

// void controlChange(byte channel, byte control, byte value) {
//   midiEventPacket_t event = { 0x0B, 0xB0 | channel, control, value };
//   MidiUSB.sendMIDI(event);
// }


/****************
  SETUP
*****************/
void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println(__FILE__);
  Serial.print("AS5600_LIB_VERSION: ");
  Serial.println(AS5600_LIB_VERSION);
  
  // Check which channel is connected to TCA
  Serial.println("\nTCAScanner ready");
  for (uint8_t t = 0; t < 8; t++) {
   tcaSelect(t);
   Serial.print("TCA Port #");
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
  
  // Initiatie Magnectic Encoder 0
  tcaSelect(0);
  as5600_0.begin();  //  set direction pin.
  as5600_0.setDirection(AS5600_CLOCK_WISE);
  Serial.print("Connect as5600_0: ");
  Serial.println(as5600_0.isConnected() ? "true" : "false");

// tcaSelected(0);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.setTextSize(1);  // Draw 1X-scale text
  display.setTextColor(SSD1306_WHITE);
  // display.setFont(&fixed_bold10x15);
  // For testing
  pinMode(ledPin, OUTPUT);  // LED: DIGITAL OUTPUT
  
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
   // print display lines from param1, etc...
  updateDisplay(0);

  // receive all osc messages
  myMicroOsc.onOscMessageReceived(myOnOscMessageReceived);  // TRIGGER OSC RECEPTION
  
  if (millis() - myChronoStart >= 50) {                     // IF 50 MS HAVE ELLAPSED
    myChronoStart = millis();                               // RESTART CHRONO
  }
  
  // Loop over as5600 instances and /pot1, /pot2, ...
  for (int i = 0; i <= 2; i++) {
    sendValueMagneticEncoder(as5600List[i][0], i, "/pot");
    // Serial.print("offset:" (i));
    //Serial.println(as5600List[i][0].getOffset());
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