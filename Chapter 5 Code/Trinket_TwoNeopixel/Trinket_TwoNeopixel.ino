/* Getting Started with Trinket - Two Neopixel Program */

#include <Adafruit_NeoPixel.h>  // Add in the Adafruit Neopixel library

#define PIN       0  // Neopixel signal output pin
#define NUMPIXELS 2  // How many pixels we will use

// Set the Neopixel data structures and operation
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();  // This sets up Neopixels for use
  strip.show();   // Initialize all pixels to 'off'
}

void loop() {
    int16_t i;
    for(i=0; i<256; i++) {
       // Cycle the first Neopixel up in Blue, second down in red
       strip.setPixelColor(0,strip.Color(    0,0,i)); 
       strip.setPixelColor(1,strip.Color(255-i,0,0)); 
       strip.show();
       delay(6);
    }
    delay(100);
    for(i=255; i>=0; i--) {
       // Cycle the first Neopixel down in blue, second up in red
       strip.setPixelColor(0,strip.Color(    0,0,i)); 
       strip.setPixelColor(1,strip.Color(255-i,0,0));
       strip.show();
       delay(5);
    }
   delay(100);
}

