#include "led_function.h"
#define setup_LDR A7
#define setup_LED 13

void setup() {
  Serial.begin(2400);
}
void loop() {
  control_led(setup_LED, setup_LDR, ldr_bright);
  delay(700);

}

  //   CREDIT: RONALD JAVALDE