/*****************************************************
 * name:Humiture Detection 
 * function:you can see the current value of humidity and temperature displayed on the I2C LCD1602.
 ******************************************************/

//include the libraries
#include "humidity_function.h"

dht DHT;//create a variable type of dht
Servo servo;

#define DHT11_PIN A2
#define MIST_PIN 6
#define SERVO_PIN 10

int thresh_low = 70;
int thresh_high = 80;

int close_angle = 10;
int angle_incr = 10;
int open_angle = 90;

int current_angle = 10;
void setup()
{
  Serial.begin(9600);//initialize the serial monitor
  pinMode(MIST_PIN, OUTPUT);
  servo.attach(SERVO_PIN);
  servo.write(current_angle);
  
}

void loop()
{
  
  int chk = DHT.read11(DHT11_PIN);//read the value returned from sensor
  // just for error handling, don't care
  switch (chk)
  {
  case DHTLIB_OK:  
    //Serial.println("OK!"); 
    break;
  case DHTLIB_ERROR_CHECKSUM: 
    //Serial.print("Checksum error,\t"); 
    break;
  case DHTLIB_ERROR_TIMEOUT: 
    //Serial.print("Time out error,\t"); 
    break;
  default: 
    //Serial.print("Unknown error,\t"); 
    break;
  }
  // DISPLAY DATA
  
  Serial.print(DHT.humidity, 1);

  if(DHT.humidity < thresh_low) {
    Serial.println(" On the mist maker");
    digitalWrite(MIST_PIN, HIGH);
  } 
  else if ((DHT.humidity < thresh_high) && (DHT.humidity > thresh_low ) ) {  
    Serial.println(" Normal");
    digitalWrite(MIST_PIN, LOW); 
    if  ((DHT.humidity < ((thresh_high + thresh_low) /2)))  {
      Serial.println( "Close the roof!");
      for(angle_incr = 10; current_angle < close_angle; angle_incr++) {                                  
      servo.write(current_angle -= angle_incr);               
      delay(15);                   
      } 
    }
  }
  else   { 
      Serial.println(" Open the roof");
      digitalWrite(MIST_PIN, LOW);

      for(angle_incr = 10; current_angle > open_angle; angle_incr++) {                                  
      servo.write(current_angle += angle_incr);               
      delay(15);                   
      } 

    
    }


    delay(800); //wait a while 
  

}
