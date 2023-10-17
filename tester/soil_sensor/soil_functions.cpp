#include "HardwareSerial.h"
#include "Arduino.h"
#include "soil_functions.h"

void control_water_valve(int soil_sensor1, int soil_sensor2, int pin_valve, int dry = 900, int wet = 250, int thresh_dry = 30, int thresh_wet = 60) {
  // Get the two sensor and then average them.
  int soil_average = (analogRead(soil_sensor1) + analogRead(soil_sensor2)) / 2;
  int moisture_level = map(soil_average, wet, dry, 100, 0);  // 100% Wet and 0% dry

  if (moisture_level < thresh_dry) {
    Serial.println("The soil is dry :(");
    digitalWrite(pin_valve, HIGH);
  } else if ((moisture_level >= thresh_dry) && (moisture_level <= thresh_wet)) {
    Serial.println("Perfect <3");
    digitalWrite(pin_valve, LOW);

  } else {
    Serial.println("The soil is too wet shet");
    digitalWrite(pin_valve, LOW);
  }

  delay(1000);
}