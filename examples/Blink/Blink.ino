#include <Piel.h>

Piel pielRobot;

void setup() {
  pielRobot.Initialize();
}

void loop() {
  // This simple program flips Piël's cheeks colors
  // between green and red individually every second.
  // set_cheeks_colors(left_cheek, right_cheek)
  pielRobot.set_cheeks_colors("red", "green");
  // 1000 ms = 1 second
  delay(1000);
  pielRobot.set_cheeks_colors("green", "red");
  // 1000 ms = 1 second
  delay(1000);
}
