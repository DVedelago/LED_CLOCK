///PORCODDIO
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN 4

// How many NeoPixels are attached to the Arduino?

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
#define Serial SerialUSB
#endif

// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
//SDA pin 2, SCL pin 3
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;



void setup() {
  // put your setup code here, to run once:
  #ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();
  Serial.begin(9600);
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }   
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    
 pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  // put your main code here, to run repeatedly:
  
  pixels.clear();
  DateTime now = rtc.now();
  int sec = int(now.second());
  Serial.println(sec);
  pixels.setPixelColor(8, pixels.Color(0, 55, 30));
  pixels.setPixelColor(12, pixels.Color(28, 13, 0));
  pixels.show();
  delay(1);
}
