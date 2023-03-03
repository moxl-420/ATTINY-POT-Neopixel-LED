
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN_NP        1 //1 physical pin 6
#define PIN_POT       A1 //2 physical pin 7


// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 24   //24
int prevvalue = 0;

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN_NP, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

void setup() {
  pinMode(PIN_POT, INPUT);   
  
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
     for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

  
    pixels.setPixelColor(i, pixels.Color(150, 150, 150));

    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(100);
    
       }//for
  
}

void loop() {
  //pixels.clear(); // Set all pixel colors to 'off'
  int LED_STRENGTH = map(analogRead(PIN_POT), 0, 1023, 0, 255);


  if (prevvalue != LED_STRENGTH){
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
     for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

  
    pixels.setPixelColor(i, pixels.Color(LED_STRENGTH, LED_STRENGTH, LED_STRENGTH));

    pixels.show();   // Send the updated pixel colors to the hardware.
    prevvalue = LED_STRENGTH;
    
       }//for
  }//if
  delay(DELAYVAL); // Pause before next pass through loop
}
