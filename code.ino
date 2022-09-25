#include <Servo.h>
Servo myservo1; 
Servo myservo2;
int sensor;

//this code is developed by Abir Islam Mishad
// for any help +8801771465323
//or mail to abir.mishad.info@gmail.com

void setup() {
  
Serial.begin(9600);
myservo1.attach(6);
myservo2.attach(9);
myservo1.write(0);
myservo2.write(0);

}

void loop() {

 sensor = analogRead(A0);

if(sensor > 400){

  myservo1.write(90);
  myservo2.write(90);
  delay(1000);
}

 else{
  myservo1.write(0);
  myservo2.write(0);
  delay(10);
 }

}
