#include "soil_functions.h"
#include "led_function.h"

// Define pinout
#define SOIL_SENSOR1 A0
#define SOIL_SENSOR2 A1
#define VALVE 11 

#define setup_LDR 7
#define setup_LED 13


void setup() {
    setup_moisture_control(VALVE, SOIL_SENSOR1, SOIL_SENSOR2);
    Serial.begin(9600);
}

void loop() {
    read_moisture_control_valve(VALVE, SOIL_SENSOR1, SOIL_SENSOR2);
    control_LED(setup_LED, setup_LDR);
}