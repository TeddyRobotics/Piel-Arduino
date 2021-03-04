#include <Piel.h>

Piel pielRobot;

void setup() {
  pielRobot.Initialize();
}

void loop() {
  if (pielRobot.is_upside_down())
    pielRobot.set_cheeks_colors("red", "red");
  else
    pielRobot.set_cheeks_colors("green", "green");
  delay(100);
}
