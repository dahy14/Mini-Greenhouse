#include "Arduino.h"
#include "soil_functions.h"

int read_soil_moisture(int soil_sensor1, int soil_sensor2, int threshold_dry, int threshold_wet) {
  // Get the two sensor and then average them.
  int soil_average = (analogRead(soil_sensor1) + analogRead(soil_sensor2))/2;

  int moisture_level = map(soil_average, 0, 1023, 100, 0); // 100% Wet and 0% dry

  return moisture_level;
}

void control_water_valve(int moisture_level, int threshold_dry, int threshold_wet) {
  // Conditionals pero may mali dito, mnay dapat baguhin
  if (moisture_level < threshold_dry) {
    Serial.println("Open the valve");
  } else {
    Serial.println("Close the valve");
  }
  if (moisture_level > threshold_wet) {
    Serial.println("Too much water");
  }
}

