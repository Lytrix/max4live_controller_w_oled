# Max4Live Magnetic Encoder controller with oled screen 

4 magnetic encoders with oled screen to control your plugins or midi devices.


Teensy                        MaxMSP
                            | Serial Communication                           | Parameter Instance         
AnalogRead1 -> Serial.Print | Serial IN -> List -> | ASCII > UTF-8 > FLOATS  | Value list item -> Select Parameter index number -> Scale values -> Send key/value pair -> | VST plugin | -> Send Parameter/Value Strings -> Add Parameter Name -> UTF8>ASCI -> Add separators -> Serial OUT 


Hardware

### Hardware ###
- Teensy 4.0
- NeoPixel library
- 2020RGB 2mm controlable SMD Leds, type [SK6812B](https://jlcpcb.com/partdetail/Xinglight-XL_2020RGBCSK6812B/C5349956) or [WS2812B](https://jlcpcb.com/partdetail/Xinglight-XL_4020RGBCWS2812B/C3647024)
![Image](4-1-2-led-midi-encoder.png)

### Installers ###

Installing Micropython on Teensy 40:
https://micropython.org/download/TEENSY40/
Quickstart micropython on Teensy (mimxrt)
https://docs.micropython.org/en/v1.19.1/mimxrt/quickref.html
Alternative Font types:
https://www.youtube.com/watch?v=YogBioKLrh4
Midi CC
https://learn.adafruit.com/grand-central-usb-midi-controller-in-circuitpython/code-usb-midi-in-circuitpython
### Documentation ###

Not all addressable LEDs are NeoPixels. “NeoPixel” is Adafruit’s brand for individually-addressable RGB color pixels and strips based on the WS2812, WS2811 and SK6812 LED/drivers, using a single-wire control protocol.

- [NeoPixel](https://learn.adafruit.com/adafruit-neopixel-uberguide?view=all)
- Arduino to Ableton Basic in/out example via Max4Live: https://www.youtube.com/watch?v=pBRe2xz7dgQ

### Test files ###
test_fit.fpd
test_fit.bak
3cm led ring.png

Max4Live using more than 1 instance fix: add r --- to create random unique numbers
https://cycling74.com/forums/multiple-max4live-instances



### Examples ###
Serial input Teensy to MaxMSP
https://www.youtube.com/watch?v=6bT3G4Mep7E
Serial output MaxMSP to Teensy
https://www.youtube.com/watch?v=68L-WHh3Ows


MaxMSP scaling log
https://cycling74.com/forums/vst-plugin-parameter-scaling-problem

Dynamically load bpatchers:
https://cycling74.com/forums/dynamically-created-sub-patchersbpatches

Dummy virtual Serial
https://arduino.stackexchange.com/questions/9857/can-i-make-the-arduino-ignore-serial-print

Best example with many displays
https://www.youtube.com/watch?v=XFh9ZhL0jhE

Control Surface library struggle
https://github.com/tttapa/Control-Surface/issues/286
Good example to start with, also using 4 displays and using MCU:
https://projecthub.arduino.cc/criusdigitalstudio/diy-usb-midi-daw-controller-ecdcf6

good example of display fader
https://github.com/yilmazyurdakul/ArduinoOledMidiController
https://github.com/yilmazyurdakul/ArduinoOledMidiController/blob/main/ArduinoFile.ino

4 rotary encoders with midi control
http://little-scale.blogspot.com/2017/04/teensy-36-basicsusing-rotary-encoders.html

2 displays
https://www.brainy-bits.com/post/two-is-better-than-one-how-to-connect-two-spi-oled-displays

4 displays with Arduino
https://www.youtube.com/watch?v=MO6hbQcX8fE

4 displays and 4 encoders with visuals
https://projecthub.arduino.cc/yilmazyurdakul/arduino-midi-controller-with-encoder-oled-display-eeprom-311960

### Libraries ###
display https://www.pjrc.com/teensy/td_libs_SSD1306.html
encoder https://www.pjrc.com/teensy/td_libs_Encoder.html
endless potentiometer: https://github.com/juanlittledevil/EndlessPotentiometer
noise reducer analog signal: https://github.com/dxinteractive/ResponsiveAnalogRead

scroll text example:
https://stackoverflow.com/questions/40564050/scroll-long-text-on-oled-display

midi https://github.com/tttapa/Control-Surface

## LCD suggestions ###
http://midibox.org/forums/topic/29225-modul-box-ng-v2/?do=findComment&comment=199453

Oled display <25mm height
https://www.winstar.com.tw/products/oled-module/graphic-oled-display/sh1106-oled.html


multiplexer met tutorial (zie ook youtube filmpje)
https://www.tinytronics.nl/shop/nl/communicatie-en-signalen/io-converters/i2c-multiplexer-tca9548a

128 pulse encoder (too expensive)
https://nl.mouser.com/datasheet/2/54/ace-777357.pdf

1024 to 256 midi values with 10 bit nano:
https://forum.arduino.cc/t/potentiometer-send-midi-cc/142766/7

analog potentiometer Kore2:
https://hackaday.io/project/171841-driveralgorithm-for-360-deg-endless-potentiometer
with: https://nl.mouser.com/ProductDetail/Alpha-Taiwan/RV112FF-40B3N22F0B10K?qs=Znm5pLBrcAJwOGngbhkPgg%3D%3D

more examples:
https://diyelectromusic.wordpress.com/2021/09/28/arduino-midi-rotary-encoder-controller/

magnetic encoder:
https://curiousscientist.tech/blog/as5600-magnetic-position-encoder
working magnetic encoder example
https://www.youtube.com/watch?v=1UmqNF65rck


Bourns dail 20 turn
https://www.zendamateur-marktplaats.nl/componenten/componenten-anders/bourns-dial-model-h-46-36496.html


potential bigger potentiometer:
https://www.gear4music.com/Guitar-and-Bass/Emerson-Custom-CTS-250K-Short-Split-Shaft-Pro-Potentiometer/1GAA


Encoder example fast/slow relative unsigned bit:
https://remotify.io/community/question/absolute-14-bit

OSC
https://github.com/CNMAT/OSC/blob/master/examples/SerialOscuinowithMessages/SerialOscuinowithMessages.ino
https://www.ableton.com/en/packs/connection-kit/

https://github.com/thomasfredericks/MicroOsc


https://forum.arduino.cc/t/slipserial-and-osc-but-generally-reading-serial-across-loop-s/563369
