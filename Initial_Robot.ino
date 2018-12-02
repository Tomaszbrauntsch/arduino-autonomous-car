//Created by TomaszBrauntsch
//Servos
#include <Servo.h> //Sets up servo package in code
Servo myblueservo; //Initializes 1st servo
Servo mywhiteservo; //Initializes 2nd servo
//ultrasonic Pins
const int pingPin = 6; //Trigger pin = 6
const int echoPin = 5; // Echo pin = 5
const int LED_YL = 3;
const int LED_YR = 9;
const int LED_WL = 10;
const int LED_WR = 11;
const int buzzpin = 12;
void setup(){
  Serial.begin(9600);
  pinMode(LED_YL, OUTPUT);
  pinMode(LED_YR, OUTPUT);
  pinMode(LED_WL, OUTPUT);
  pinMode(LED_WR, OUTPUT);
}
void loop(){
//Ultrasonic Sensor settings
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

//Drive forward
if (inches > 24 ){
  myblueservo.attach(8);
  mywhiteservo.attach(7);
  myblueservo.write(160);
  mywhiteservo.write(20);
  digitalWrite(LED_YL, HIGH);
  tone(buzzpin,500,250);
  delay(250);
  digitalWrite(LED_YL, LOW);
  tone(buzzpin,600,250);
  digitalWrite(LED_YR, HIGH);
  tone(buzzpin,750,250);
  delay(250);
  tone(buzzpin,1000,250);
  digitalWrite(LED_YR, LOW);
}
//Drive Backwards and turns 90° Clockwise
else
  {
  mywhiteservo.write(160);
  myblueservo.write(20);
  digitalWrite(LED_WL,HIGH);
  tone(buzzpin,1500,250);
  digitalWrite(LED_WR,HIGH);
  tone(buzzpin,1500,250);
  delay(2550);
  digitalWrite(LED_WL,LOW);
  tone(buzzpin,1500,250);
  digitalWrite(LED_WR,LOW);
  tone(buzzpin,1500,250);
  myblueservo.detach();
  mywhiteservo.detach();
}
}
//Calculations for inches
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
//Calculations for centimeters
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
