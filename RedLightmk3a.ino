// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN1        6 // On Trinket or Gemma, suggest changing this to 1
#define PIN2        7 // On Trinket or Gemma, suggest changing this to 1
#define PIN3        8 //

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS1 14 // Popular NeoPixel ring size
#define NUMPIXELS2 16 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.

Adafruit_NeoPixel pixel1(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel2(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 180 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
//#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  //clock_prescale_set(clock_div_1);
//#endif
  // END of Trinket-specific code.

  pixel1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    pixel2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {

colorWipe(0xFF,0x00,0x00, 100);
  colorWipe(0x00,0x00,0x00, 100);
 BlueLights();
// CylonBounce(0xff, 0, 0, 1, 150, 100); 
  
}


void colorWipe(byte red, byte green, byte blue, int SpeedDelay) {
  for(uint16_t i=NUMPIXELS2; i>0; i--) {
      pixel2.setPixelColor(i, red, green, blue);
      pixel2.show();
      delay(SpeedDelay);
  }
}

void BlueLights (){
   // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  
 for(int i=0; i<NUMPIXELS1; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright blue color:
   
 
       pixel1.setPixelColor(i, pixel1.Color(0, 181, 255));
    

    pixel1.show();   // Send the updated pixel colors to the hardware.

    
}
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUMPIXELS2; i++ ) {
    pixel2.setPixelColor(i, red, green, blue);
  }
  pixel2.show();
}
