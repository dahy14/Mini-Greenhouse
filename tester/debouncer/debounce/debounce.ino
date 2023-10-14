#include "dbnc.h"
const int buttonPin = 7;  // the number of the pushbutton pin
int counter = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int btt = debounce(buttonPin);
  if (btt == HIGH) {
    counter +=1;
    Serial.println("Button has been pressed: " + String(counter) + " times!");
  }
}
