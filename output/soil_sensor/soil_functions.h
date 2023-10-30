#ifndef SOIL_FUNCTIONS_H
#define SOIL_FUNCTIONS_H

// Code Here

void control_water_valve(int soil_sensor1, int soil_sensor2, int pin_valve, int dry = 900, int wet = 250,
                         int thresh_dry = 30, int thresh_wet = 60);

#endif