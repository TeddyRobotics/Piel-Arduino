/*********************************************************************
 Class to interface with our cool LEDs
 Teddy Robotics LLC
*********************************************************************/

#include <FastLED.h>

#define NUM_LEDS 2
#define DATA_PIN 0

enum Colors {
  BLACK,
  WHITE,
  RED,
  GREEN,
  BLUE
};

#define LEDS_INDEX_CHECK(index)      \
if (index > NUM_LEDS || index < 0) \
  return;                          \


class LEDsInterface {

  public:
    void Initialize();
    void Toggle(int index);
    void SetColor(int index, Colors color);
    void SetColors(Colors color);
    void Enable(int index, bool enable);
    inline Colors string_to_color(String str_color) {
        str_color.toLowerCase();
        if (str_color == "black")
            return Colors::BLACK;
        if (str_color == "white")
            return Colors::WHITE;
        if (str_color == "red")
            return Colors::RED;
        if (str_color == "green")
            return Colors::GREEN;
        if (str_color == "blue")
            return Colors::BLUE;
        return Colors::BLACK;
    }
    
    CRGB leds[NUM_LEDS];
    Colors cached_leds[NUM_LEDS];
};
