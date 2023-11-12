#include "soil_functions.h"
#include "led_function.h"
#include "Servo.h"
#include "dht.h"
// Define pinout
#define SOIL_SENSOR1 A0
#define SOIL_SENSOR2 A1
#define VALVE 11 

#define setup_LDR 7
#define setup_LED 3

#define DHT11_PIN A2
#define MIST_PIN 6
#define SERVO_PIN 10

dht DHT; 
Servo servo;

int thresh_low = 50;
// get the readings, change the values to open the roof, 
int thresh_high = 70;

int i =0;
bool isOpen = false; 
bool prev_isOpen = false;


void setup() {
    setup_moisture_control(VALVE, SOIL_SENSOR1, SOIL_SENSOR2);
    pinMode(MIST_PIN, OUTPUT);
    Serial.begin(9600);

    servo.attach(SERVO_PIN);
    servo.write(0);   
      
 



}

void loop() {
  read_moisture_control_valve(VALVE, SOIL_SENSOR1, SOIL_SENSOR2);
  control_LED(setup_LED, setup_LDR);


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
        servo.write(180);
        for ( i = 1800; i >= 0; i -= 1) {
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
        for ( i = 0; i <= 180; i += 1) { 
          servo.write(i);           
          delay(15);                    
        }
      prev_isOpen = true;
      }
    }
    delay(800); 
}