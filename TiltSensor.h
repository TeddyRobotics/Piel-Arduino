/*********************************************************************
 Class to interface with Piel's tilt sensor
 Teddy Robotics LLC 2021
*********************************************************************/

#include <Arduino.h>

#define TILT_SENSOR_PIN 22 // A4
#define RUNNING_AVG_COUNT 10

class TiltSensor {

  public:
    TiltSensor();
    
    int get_filtered_reading();
    int get_raw_reading();
    
  private:
    int RunningAverageBuffer[RUNNING_AVG_COUNT];
    int NextRunningAverage;
};
