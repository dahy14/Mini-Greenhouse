#ifndef SOIL_FUNCTIONS_H
#define SOIL_FUNCTIONS_H

void setup_moisture_control(int valve_pin, int soil_sensor1, int soil_sensor2); // Valve 
void read_moisture_control_valve(int valve_pin, int soil_sensor1, int soil_sensor2);

#endif