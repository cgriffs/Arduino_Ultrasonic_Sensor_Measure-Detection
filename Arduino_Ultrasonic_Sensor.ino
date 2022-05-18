/*
Caleb Griffin
V00934910

Credit for help on implementation
Ahmed Djebali - on use of how ultrasonic sensors work
onatto22 - on initializing LCD 
*/
#include <LiquidCrystal.h>            //Adding Liquid Crystal Library
LiquidCrystal LCD(11,10,9,2,3,4,5);  

#define trig 13 //Sensor Setup
#define echo 12 

void setup() 
{  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  LCD.begin(16,2);               //Turns on LCD
  LCD.setCursor(0,0);            //Set LCD cursor to upper left corner
  LCD.print("Distance Level:");  
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;     //cm conversion

  if (distance>20){ .                // Setting max bounds to 20cm (can be changed)
    distance = 20;
  }

  Serial.println(distance);
  
  LCD.setCursor(0,1);  
  LCD.print("                "); 
  LCD.setCursor(0,1);   
  LCD.print(distance); 
  LCD.print("cm to front"); 
  delay(250);

}
