/*********************************************************************
 Class to interface with our cool LEDs
 Teddy Robotics LLC
*********************************************************************/

#include "LEDsInterface.h"

void LEDsInterface::Initialize() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    cached_leds[i] = Colors::BLACK;
  }
  FastLED.show();
}

void LEDsInterface::Toggle(int index) {
  LEDS_INDEX_CHECK(index)
  if (cached_leds[index] != Colors::BLACK) {
    leds[index] = CRGB::Black;
  } else {
    leds[index] = cached_leds[index];
  }
  FastLED.show();
}

void LEDsInterface::SetColor(int index, Colors color) {
  LEDS_INDEX_CHECK(index)
  cached_leds[index] = color;
  switch (color) {
    case Colors::BLACK:
      leds[index] = CRGB::Black;
      break;
    case Colors::WHITE:
      leds[index] = CRGB::White;
      break;
    case Colors::RED:
      leds[index] = CRGB::Red;
      break;
    case Colors::GREEN:
      leds[index] = CRGB::Green;
      break;
    case Colors::BLUE:
      leds[index] = CRGB::Blue;
      break;
    case Colors::YELLOW:
      leds[index] = CRGB::Yellow;
      break;
  }
  FastLED.show();
}

void LEDsInterface::SetColors(Colors color) {
  switch (color) {
    case Colors::BLACK:
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      break;
    case Colors::WHITE:
      leds[0] = CRGB::White;
      leds[1] = CRGB::White;
      break;
    case Colors::RED:
      leds[0] = CRGB::Red;
      leds[1] = CRGB::Red;
      break;
    case Colors::GREEN:
      leds[0] = CRGB::Green;
      leds[1] = CRGB::Green;
      break;
    case Colors::BLUE:
      leds[0] = CRGB::Blue;
      leds[1] = CRGB::Blue;
      break;
    case Colors::YELLOW:
      leds[0] = CRGB::Yellow;
      leds[1] = CRGB::Yellow;
      break;
  }
  FastLED.show();
}

void LEDsInterface::Enable(int index, bool enable) {
  LEDS_INDEX_CHECK(index)
  if (enable) {
    leds[index] = cached_leds[index];
  } else {
    leds[index] = CRGB::Black;
  }
  FastLED.show();
}
