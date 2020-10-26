#include <Piel.h>

Piel pielRobot;

void setup() {
  pielRobot.Initialize();
}

void loop() {
  pielRobot.set_cheeks_colors("red", "green");
  delay(1);
  pielRobot.set_cheeks_colors("green", "red");
  delay(1);
}
