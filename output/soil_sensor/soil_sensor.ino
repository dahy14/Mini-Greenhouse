#include "soil_functions.h"

#define SOIL_SENSOR1 A0
#define SOIL_SENSOR2 A1
#define VALVE 11
        
void setup() {
  Serial.begin(115200);
  //pinMode(VALVE, OUTPUT);
  //digitalWrite(VALVE, HIGH);
}

void loop() {
  
  control_water_valve(SOIL_SENSOR1, SOIL_SENSOR2, VALVE);
}
