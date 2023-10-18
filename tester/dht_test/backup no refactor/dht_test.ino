/*****************************************************
 * name:Humiture Detection 
 * function:you can see the current value of humidity and temperature displayed on the I2C LCD1602.
 ******************************************************/

//include the libraries
#include "humidity_function.h"

dht DHT; 
Servo servo;

#define DHT11_PIN A2
#define MIST_PIN 6
#define SERVO_PIN 10


int thresh_low = 70;
int thresh_high = 80;

int i =0;
bool isOpen = false; 
bool prev_isOpen = false;



void setup()
{
  Serial.begin(9600);//initialize the serial monitor
  pinMode(MIST_PIN, OUTPUT);
  servo.attach(SERVO_PIN);
}

void loop()
{
  DHT.read11(DHT11_PIN); // don't delete <- even if int chk is not usable, it is the function for DHT.humidity 
  
  Serial.print(DHT.humidity, 1);

  if(DHT.humidity <= thresh_low) {
    Serial.println(" On the mist maker");
    digitalWrite(MIST_PIN, HIGH);
  } 
  else if ((DHT.humidity <= thresh_high) && (DHT.humidity > thresh_low ) ) {  
    Serial.println(" Normal");
    digitalWrite(MIST_PIN, LOW); 
    if  ((DHT.humidity < ((thresh_high + thresh_low) /2)))  {
      Serial.println( "Close the roof!");

      isOpen = false;

      if ( isOpen == false && prev_isOpen == true)  {
        servo.write(90);
        for ( i = 90; i >= 0; i -= 1) {
        servo.write(i);           
        delay(15);                     
        }
        prev_isOpen = false;
      }
    }
  }
  else if (DHT.humidity > thresh_high){ 
      Serial.println(" Open the roof");
      digitalWrite(MIST_PIN, LOW);
  
      isOpen = true;  
      if (isOpen == true && prev_isOpen == false) {
        servo.write(0); 
        for ( i = 0; i <= 90; i += 1) { 
          servo.write(i);           
          delay(15);                    
        }
      prev_isOpen = true;
      }
    }
    delay(800); 
}

