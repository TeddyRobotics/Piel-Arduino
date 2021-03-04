/*********************************************************************
 Class to interface with Piel's DC tilt sensor
 Author: Teddy Robotics LLC
*********************************************************************/

#include "ForceSensor.h"

ForceSensor::ForceSensor() {
}

int ForceSensor::get_filtered_reading() {
    int val = analogRead(FORCE_SENSOR_PIN);
    RunningAverageBuffer[NextRunningAverage++] = val;
    if (NextRunningAverage >= RUNNING_AVG_COUNT)
    {
      NextRunningAverage = 0;
    }
    int RunningAverageReading = 0;
    for(int i=0; i< RUNNING_AVG_COUNT; ++i)
    {
      RunningAverageReading += RunningAverageBuffer[i];
    }
    RunningAverageReading /= RUNNING_AVG_COUNT;
    return RunningAverageReading;
}

int ForceSensor::get_raw_reading() {
    return analogRead(FORCE_SENSOR_PIN);
}
