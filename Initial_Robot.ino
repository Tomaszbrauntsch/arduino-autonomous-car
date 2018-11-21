//Servos
#include <Servo.h> //Sets up servo package in code
Servo myblueservo; //Initializes 1st servo
Servo mywhiteservo; //Initializes 2nd servo
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
  digitalWrite(LED_B, HIGH);
  delay(250);
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_R, HIGH);
  delay(250);
  digitalWrite(LED_R, LOW);
}
//Drive Backwards and turns 90° Clockwise
else
  {
  mywhiteservo.write(160);
  myblueservo.write(20);
  delay(3500);
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
