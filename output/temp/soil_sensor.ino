#include "soil_functions.h"

#define SOIL_SENSOR1 A0
#define SOIL_SENSOR2 A1
#define VALVE 11
        
void setup() {
  setup_moisture_control(VALVE, SOIL_SENSOR1, SOIL_SENSOR2);
}

void loop() {
  read_moisture_control_valve(VALVE, SOIL_SENSOR1, SOIL_SENSOR2);
}
