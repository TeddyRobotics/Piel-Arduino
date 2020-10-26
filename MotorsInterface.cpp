/*********************************************************************
 Class to interface with Piel's DC motors
 Author: Teddy Robotics LLC
*********************************************************************/

#include "MotorsInterface.h"

MotorsInterface::MotorsInterface() {
  pinMode(bin1, OUTPUT);
  pinMode(bin2, OUTPUT);
  pinMode(ain1, OUTPUT);
  pinMode(ain2, OUTPUT);
  pinMode(pwma, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(stby, OUTPUT);
}

void MotorsInterface::halt() {
  digitalWrite(stby, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
}

void MotorsInterface::enable(int speed1, int speed2) {
  if (speed1 > 255)
    speed1 = 255;
  if (speed1 < 0)
    speed1 = 0;
  if (speed2 > 255)
    speed2 = 255;
  if (speed2 < 0)
    speed2 = 0;
  digitalWrite(stby, HIGH);
  analogWrite(pwma, speed1);
  analogWrite(pwmb, speed2);
}

void MotorsInterface::move_a_clockwise() {
  digitalWrite(ain1, LOW);
  digitalWrite(ain2, HIGH);
}

void MotorsInterface::move_a_counterclockwise() {
  digitalWrite(ain1, HIGH);
  digitalWrite(ain2, LOW);
}

void MotorsInterface::move_b_clockwise() {
  digitalWrite(bin1, HIGH);
  digitalWrite(bin2, LOW);
}

void MotorsInterface::move_b_counterclockwise() {
  digitalWrite(bin1, LOW);
  digitalWrite(bin2, HIGH);
}
