#include "soil_functions.h"
#include "led_function.h"

// Define pinout
#define SOIL_SENSOR1 A0
#define SOIL_SENSOR2 A1
#define VALVE 11 

#define setup_LDR A7
#define setup_LED 13
#define LDR_BRIGHT_THRESHOLD 30

void setup() {
    setup_moisture_control(VALVE, SOIL_SENSOR1, SOIL_SENSOR2);
}

void loop() {
    read_moisture_control_valve(VALVE, SOIL_SENSOR1, SOIL_SENSOR2);
    control_LED(setup_LED, setup_LDR, LDR_BRIGHT_THRESHOLD);
}