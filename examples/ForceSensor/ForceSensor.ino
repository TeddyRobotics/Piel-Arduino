#include <Piel.h>

Piel pielRobot;

void setup() {
  pielRobot.Initialize();
}

void loop() {
  if (pielRobot.is_poking_head())
    pielRobot.set_cheeks_colors("red", "red");
  else
    pielRobot.set_cheeks_colors("green", "green");
  delay(100);
}
