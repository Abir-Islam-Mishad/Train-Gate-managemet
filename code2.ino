#include <Servo.h>
Servo myservo1; 
Servo myservo2;
#define abir1 3
#define mishad1 2
#define abir2 6
#define mishad2 7
#define buzzer 6

//this code is developed by Abir Islam Mishad
// for any help +8801771465323
//or mail to abir.mishad.info@gmail.com

void setup() {
  
Serial.begin(9600);
 pinMode(abir1, OUTPUT);
 pinMode(mishad1, INPUT);
 pinMode(abir2, OUTPUT);
 pinMode(mishad2, INPUT);
 pinMode(buzzer, OUTPUT);
 
myservo1.attach(6);
myservo2.attach(9);
myservo1.write(0);
myservo2.write(0);

}

void loop() {

  long duration1, abirmishad1;
  digitalWrite(abir1, LOW);
  delayMicroseconds(2);
  digitalWrite(abir1, HIGH);
  delayMicroseconds(10);
  digitalWrite(abir1, LOW);
  duration1 = pulseIn(mishad1, HIGH);
  abirmishad1 = (duration1 / 2) / 29.1;
  
  long duration2, abirmishad2;
  digitalWrite(abir2, LOW);
  delayMicroseconds(2);
  digitalWrite(abir2, HIGH);
  delayMicroseconds(10);
  digitalWrite(abir2, LOW);
  duration2 = pulseIn(mishad2, HIGH);
  abirmishad2 = (duration2 / 2) / 29.1;
  
  Serial.println(abirmishad1);
  Serial.print("      ");
  Serial.print(abirmishad2);

if((abirmishad1 < 10)&&(abirmishad2 > 10)){
  myservo1.write(90);
  myservo2.write(90);
  digitalWrite(buzzer,HIGH);
  delay(500);
}

 else if((abirmishad2 < 10)&&(abirmishad1 > 10)){
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
