#include "soil_functions.h"
#include "Arduino.h"
#include "HardwareSerial.h"

// Define kung kailan huling nag run 'yong soil sensor and kung gaano katagal
// 'yong delay
unsigned long prev_time_soil_sensor = millis();
const int DRY = 900;
const int WET = 250;
const int WET_THRESHOLD = 30;
const int DRY_THRESHOLD = 60;
unsigned long SOIL_SENSOR_DELAY = 800; // 800 ms

// Setup valve -> Digital pin
// Lagay Serial.begin kung need mag debug
void setup_moisture_control(int valve_pin, int soil_sensor1, int soil_sensor2) {
    pinMode(valve_pin, OUTPUT);
}

void read_moisture_control_valve(int valve_pin, int soil_sensor1,
                                 int soil_sensor2) {
    int soil_average =
        (analogRead(soil_sensor1) + analogRead(soil_sensor2)) / 2;
    int moisture_level =
        map(soil_average, WET, DRY, 100, 0); // 100% Wet and 0% dry

    unsigned long time_now = millis();

    if (time_now - prev_time_soil_sensor >= SOIL_SENSOR_DELAY) {
        if (moisture_level < DRY_THRESHOLD) {
           // Serial.println("The soil is dry :(");
           digitalWrite(valve_pin, HIGH);
        } else if ((moisture_level >= DRY_THRESHOLD) &&
                   (moisture_level <= WET_THRESHOLD)) {
            //Serial.println("Perfect <3");
            digitalWrite(valve_pin, LOW);

        } else {
            //Serial.println("The soil is too wet shet");
            digitalWrite(valve_pin, LOW);
        }

        prev_time_soil_sensor += SOIL_SENSOR_DELAY;
    }
}