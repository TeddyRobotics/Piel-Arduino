/*********************************************************************
 Class to interface with Piel's DC tilt sensor
 Author: Teddy Robotics LLC
*********************************************************************/

#include "TiltSensor.h"

TiltSensor::TiltSensor() {
}

int TiltSensor::get_filtered_reading() {
    int val = analogRead(TILT_SENSOR_PIN);
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

int TiltSensor::get_raw_reading() {
    return analogRead(TILT_SENSOR_PIN);
}
