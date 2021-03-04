/*********************************************************************
 Class to interface with Piel's force sensor
 Teddy Robotics LLC 2021
*********************************************************************/

#include <Arduino.h>

#define FORCE_SENSOR_PIN 18 // A0
#define RUNNING_AVG_COUNT 10

class ForceSensor {

  public:
    ForceSensor();
    
    int get_filtered_reading();
    int get_raw_reading();
    
  private:
    int RunningAverageBuffer[RUNNING_AVG_COUNT];
    int NextRunningAverage;
};
