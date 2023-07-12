#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 16

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

uint32_t red = strip.Color(255, 0, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t green = strip.Color(0, 255, 0);
uint32_t yellow = strip.Color(255, 255, 0);
uint32_t white = strip.Color(255, 255, 255);

int sine[] = {1, 3, 5, 7, 9, 11, 13, 15};

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(20);
}

void loop(){
//rybg();
//strobe();
fan();
}

void rybg(){
  for (int i = 0; i < 16; i++){
    if (i % 2 == 0){
    strip.setPixelColor(i, green);
    } else {
      strip.setPixelColor(i, blue);
      } 
    strip.show();
    delay(60);
  }
  for (int j = 0; j < 16; j++){
    if (j % 2 == 0){
    strip.setPixelColor(j, red);
    } else {
      strip.setPixelColor(j, yellow);
    }
    strip.show();
    delay(60);
    
  }
}

void strobe(){
  int j = 16;
  for (int i = 0; i < 16; i++){
      strip.setPixelColor(i, white);
      strip.setPixelColor(j, red);
    strip.show();
 delay(60);
 j--;
  }
  int i = 0;
 for (int j = 16; j >= 0; j--){
   strip.setPixelColor(j, white);
   strip.setPixelColor(i, red);
   strip.show();
 delay(60);
 i++;
 }
 
}

bool firstrev = false;

void fan(){
  if (!firstrev){
  for (int i = 0; i < 16; i++){
    strip.setPixelColor(i, white);
    strip.show();
    delay(60);
  }
  firstrev = true;
  }
  for (int j = 0; j <= 16; j++){
    strip.setPixelColor(j, yellow);
    strip.show();
    delay(60);

    if (j != 0){
      strip.setPixelColor(j - 1, white);
      strip.show();
      delay(60);
    } 
  }
}