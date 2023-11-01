#include "led_function.h"

#define setup_LDR A7
#define setup_LED 13
#define LDR_BRIGHT_THRESHOLD 30

void setup() {
  Serial.begin(2400);
}
void loop() {
  control_LED(setup_LED, setup_LDR, LDR_BRIGHT_THRESHOLD);
}

