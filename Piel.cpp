/*********************************************************************
 Class to interface with Piel
 Author: Teddy Robotics LLC
*********************************************************************/

#include "Piel.h"

Piel::Piel() {
}

void Piel::Initialize() {
    leds.Initialize();
}

void Piel::move_forward(int speed_percent) {
    int speed_8bit = speed_percent_to_8bit(speed_percent);
    motors.enable(speed_8bit, speed_8bit);
    motors.move_a_counterclockwise();
    motors.move_b_clockwise();
}

void Piel::move_back(int speed_percent) {
    int speed_8bit = speed_percent_to_8bit(speed_percent);
    motors.enable(speed_8bit, speed_8bit);
    motors.move_a_clockwise();
    motors.move_b_counterclockwise();
}

void Piel::move_left(int speed_percent) {
    int speed_8bit = speed_percent_to_8bit(speed_percent);
    motors.enable(speed_8bit, speed_8bit);
    motors.move_a_clockwise();
    motors.move_b_clockwise();
}

void Piel::move_right(int speed_percent) {
    int speed_8bit = speed_percent_to_8bit(speed_percent);
    motors.enable(speed_8bit, speed_8bit);
    motors.move_a_counterclockwise();
    motors.move_b_counterclockwise();
}

void Piel::stop() {
    motors.halt();
}

void Piel::set_cheeks_colors(String left_color, String right_color) {
    Colors l_color = leds.string_to_color(left_color);
    Colors r_color = leds.string_to_color(right_color);
    leds.SetColor(0, l_color);
    leds.SetColor(1, r_color);
}

void Piel::turn_off_cheeks() {
    leds.Enable(0, false);
    leds.Enable(1, false);
}

bool Piel::is_upside_down() {
    int filtered_reading = tilt_sensor.get_filtered_reading();
    return filtered_reading == 1023;
}

bool Piel::is_poking_head() {
    int filtered_reading = force_sensor.get_filtered_reading();
    return filtered_reading != 1023;
}
