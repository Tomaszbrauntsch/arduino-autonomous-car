//Servos
#include <Servo.h>
Servo myblueservo;
Servo mywhiteservo;
//ultrasonic Pins
const int pingPin = 6; //Trigger pin = 6
const int echoPin = 5; // Echo pin = 5
const int LED_B = 3;
const int LED_R = 9;
void setup(){
  Serial.begin(9600);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_R, OUTPUT);
}
void loop(){
//Sensor
long duration, inches, cm;
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);
delay(100);
//END

if (inches > 24 ){
  myblueservo.attach(8);
  mywhiteservo.attach(7);
  myblueservo.write(160);
  mywhiteservo.write(20);
  digitalWrite(LED_B, HIGH);
  delay(250);
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_R, HIGH);
  delay(250);
  digitalWrite(LED_R, LOW);
}
else
  {
  mywhiteservo.write(160);
  myblueservo.write(20);
  delay(3500);
  myblueservo.detach();
  mywhiteservo.detach();
}
}
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
