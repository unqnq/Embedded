#include <Adafruit_NeoPixel.h>

int led_pin = 13;
int num_leds = 59;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(num_leds, led_pin, NEO_GRB + NEO_KHZ800);
int time_delay = 100;
uint32_t my_color = strip.Color(0, 0, 255);
uint32_t off_color = strip.Color(0, 0, 0);
bool is_reverse = false;

void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(100);
  randomSeed(analogRead(A0)); 
}

void loop() {
  on_leds(change_color(), is_reverse);
  is_reverse = !is_reverse;
  on_leds(change_color(), is_reverse);
  is_reverse = !is_reverse;
}

//БЛИМАННЯ ОДНОГО СВІТЛОДІОДУ ПЕВНУ К_ТЬ РАЗІВ
void blinked(int pin, int count_blinks, uint32_t color) {
  for (int j = 0; j < count_blinks; j++) {
    strip.setPixelColor(pin, color);
    strip.show();
    delay(time_delay);
    strip.setPixelColor(pin, color);
    strip.show();
    delay(time_delay);
  }
}

//БІГАЮЧИЙ СВІТЛОДІОД
void run_led(uint32_t color) {
  for (int i = 0; i < num_leds; i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(time_delay);
    strip.setPixelColor(i, off_color);
  }
  delay(time_delay);
  for (int i = num_leds; i >= 0; i--) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(time_delay);
    strip.setPixelColor(i, off_color);
  }
}

//ВКЛЮЧИТИ-ВИКЛЮЧИТИ ПО ЧЕРЗІ
void on_off(uint32_t color, bool reverse_on, bool reverse_off) {
  on_leds(color, reverse_on);
  delay(time_delay);
  off_leds(reverse_off);
}

void on_leds(uint32_t color, bool reverse) {
  if (reverse) {
    for (int i = num_leds; i >= 0; i--) {
      strip.setPixelColor(i, color);
      strip.show();
      delay(time_delay);
    }
  } else {
    for (int i = 0; i < num_leds; i++) {
      strip.setPixelColor(i, color);
      strip.show();
      delay(time_delay);
    }
  }
}

void off_leds(bool reverse) {
  if (reverse) {
    for (int i = num_leds; i >= 0; i--) {
      strip.setPixelColor(i, off_color);
      strip.show();
      delay(time_delay);
    }
  } else {
    for (int i = 0; i < num_leds; i++) {
      strip.setPixelColor(i, off_color);
      strip.show();
      delay(time_delay);
    }
  }
}


uint32_t change_color() {
  int r = random(0, 256);
  int g = random(0, 256);
  int b = random(0, 256);
  
  return strip.Color(r, g, b);
}