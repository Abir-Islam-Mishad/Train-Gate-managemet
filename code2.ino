#include <Servo.h>
Servo myservo1; 
Servo myservo2;
#define trigPin1 7
#define echoPin1 8
#define trigPin2 9
#define echoPin2 10

#define buzzer 6

//this code is developed by Abir Islam Mishad
// for any help +8801771465323
//or mail to abir.mishad.info@gmail.com

void setup() {
  
Serial.begin(9600);
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 pinMode(buzzer, OUTPUT);
 
myservo1.attach(6);
myservo2.attach(9);
myservo1.write(0);
myservo2.write(0);

}

void loop() {

  long duration1, distance1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) / 29.1;
  
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;
  
  Serial.println(distance1);
  Serial.print("      ");
  Serial.print(distance2);

if((distance1 < 10)&&(distance2 > 10)){
  myservo1.write(90);
  myservo2.write(90);
  digitalWrite(buzzer,HIGH);
  delay(500);
}

 else if((distance2 < 10)&&(distance1 > 10)){
  myservo1.write(0);
  myservo2.write(0);
  digitalWrite(buzzer,LOW);
  delay(500);
 }
 else{
  myservo1.write(0);
  myservo2.write(0);
  digitalWrite(buzzer,LOW);
  delay(10);
 }

}
