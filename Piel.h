/*********************************************************************
 Class to interface with Piel's DC motors
 Author: Teddy Robotics LLC
*********************************************************************/

#include "MotorsInterface.h"
#include "LEDsInterface.h"

class Piel {
public:
    Piel();
    void Initialize();
    void move_forward(int speed);
    void move_back(int speed);
    void move_left(int speed);
    void move_right(int speed);
    void stop();
    void set_cheeks_colors(String left_color, String right_color);
    void turn_off_cheeks();
    
private:
    inline int speed_percent_to_8bit(int percent) {
            if (percent < 0)
                percent = 0;
            if (percent > 100)
                percent = 100;
            return float(percent/100) * 255;
    }

    MotorsInterface motors;
    LEDsInterface leds;
};
