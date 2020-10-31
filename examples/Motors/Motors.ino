#include <Piel.h>

Piel pielRobot;

void setup() {
  pielRobot.Initialize();
}

void loop() {
  // 0-100%
  int speed = 50;
  pielRobot.move_forward(speed);
  //pielRobot.move_back(speed);
  //pielRobot.move_left(speed);
  //pielRobot.move_right(speed);
  delay(5000);
  pielRobot.stop();
  delay(1000);
}
