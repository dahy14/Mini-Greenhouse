#include "HardwareSerial.h"
#include "Arduino.h"
#include "led_function.h"

void control_led(int setup_LED, int setup_LDR, int ldr_bright = 30) {
  pinMode(setup_LED, OUTPUT);
  int LDR = analogRead(setup_LDR);
  int brightness = map(LDR, 0, 1023, 100, 0);
  Serial.print("Brightness: ");
  Serial.println(brightness);

  // Conditionals
  if (brightness < ldr_bright) {
    Serial.println("Lumos");
    digitalWrite(setup_LED, HIGH);
  } else {
    Serial.println("Nox");
    digitalWrite(setup_LED, LOW);
  }
}
