#include "soil_functions.h"

#define SOIL_SENSOR1 A0
#define SOIL_SENSOR2 A1

void setup() {
  Serial.begin(115200);

}

void loop() {
  const int threshold_wet = 1;
  const int threshold_dry = 700;

  int moisture_level = read_soil_moisture(SOIL_SENSOR1, SOIL_SENSOR2, threshold_dry, threshold_wet);
  Serial.print("Soil Moisture Level: ");
  Serial.println(moisture_level);

  // Water pump
  control_water_valve(moisture_level, threshold_dry, threshold_wet);

  delay(1000);
}
