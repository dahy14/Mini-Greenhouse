#include "Arduino.h"
#include "HardwareSerial.h"
#include "led_function.h"

unsigned long prev_time_led = millis();
const int LDR_BRIGHT_THRESHOLD = 30;
const int LED_MAX_VALUE = 1023;
unsigned long LED_DELAY = 800;

void control_LED(int setup_LED, int setup_LDR, int LDR_BRIGHT_THRESHOLD) {
    pinMode(setup_LED, OUTPUT);
    int LDR = read_LDR(setup_LDR);
    int brightness = map(LDR, 0, LED_MAX_VALUE, 100, 0);

    unsigned long time_now = millis();
    if (time_now - prev_time_led >= LED_DELAY) {
        if (brightness < LDR_BRIGHT_THRESHOLD) {
            Serial.println("Lumos");
            digitalWrite(setup_LED, HIGH);
        } else {
            Serial.println("Nox");
            digitalWrite(setup_LED, LOW);
        }
      
        prev_time_led += LED_DELAY;
    }
}


int read_LDR(int setup_LDR) { return analogRead(setup_LDR); }