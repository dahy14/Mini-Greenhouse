#include "Arduino.h"
#include "HardwareSerial.h"
#include "led_function.h"

unsigned long prev_time_led = millis();
const int LDR_BRIGHT_THRESHOLD = 30;
const int LED_MAX_VALUE = 1023;
unsigned long LED_DELAY = 31;

void control_LED(int setup_LED, int setup_LDR) {
    pinMode(setup_LED, OUTPUT);
    int LDR = digitalRead(setup_LDR);
    // Serial.println(LDR);
    unsigned long time_now = millis();
    if (time_now - prev_time_led >= LED_DELAY) {
        if (LDR == 1) {
            // Serial.println("Lumos");
            digitalWrite(setup_LED, HIGH);

        } else {
            // Serial.println("Nox");
            digitalWrite(setup_LED, LOW);
            
        }
      
        prev_time_led += LED_DELAY;
    }
}

