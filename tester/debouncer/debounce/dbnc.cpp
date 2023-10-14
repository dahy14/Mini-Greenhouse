#include "dbnc.h"

unsigned long lastDebounceTime = 0; 
int buttonState ;            // the current reading from the input pin
int lastButtonState = 0;  // the previous reading from the input pin

int debounce(int buttonPin, unsigned long debounceDelay = 100) {

  int reading = digitalRead(buttonPin);
  int res;

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        return 1;
      } else {return 0;}
    }
  }

  lastButtonState = reading;
  return res;
}
