/*********************************************************************
 Class to interface with Geraldo's DC motors
 Teddy Robotics LLC 2019
*********************************************************************/

#include <Arduino.h>

#define bin1 10
#define bin2 5
#define ain1 12
#define ain2 23
#define pwma 6
#define pwmb 13
#define stby 1

class MotorsInterface {

  public:
    MotorsInterface();
    
    void halt();
    
    void enable(int speed1, int speed2);

    void move_a_clockwise();

    void move_a_counterclockwise();

    void move_b_clockwise();

    void move_b_counterclockwise();
};
