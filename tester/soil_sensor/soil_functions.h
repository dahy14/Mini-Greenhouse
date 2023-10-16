#ifndef SOIL_FUNCTIONS_H
#define SOIL_FUNCTIONS_H

// Code Here

int read_soil_moisture(int soil_sensor1, int soil_sensor2, int threshold_dry, int threshold_wet);
void control_water_valve(int moisture_level, int threshold_dry, int threshold_wet);

#endif