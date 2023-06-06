#include <Servo.h>

Servo rightLeg;
Servo leftLeg;
Servo rightFoot;
Servo leftFoot;
Servo rightHand;
Servo leftHand;

const int trig = 8; // chân trig
const int echo = 9; // chân echo

void setup() {
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  rightLeg.attach(5);
  leftLeg.attach(6);
  rightFoot.attach(3);
  leftFoot.attach(2);
  rightHand.attach(10);
  //leftHand.attach(11);

  rightFoot.write(80);  // 80
  rightLeg.write(0);
  leftLeg.write(0);
  leftFoot.write(99);  // 96
  //leftHand.write(90);
  rightHand.write(140); // 140-80
} 

void loop() {
  int rotateRightLeg = 0;
  int rotateLeftLeg = 0;
  int rotateRightFoot = 0;
  int rotateLeftFoot = 0;

  unsigned long duration; // thời gian
  int distance; // khoảng cách
  // Phát xung
  digitalWrite(trig, 0); // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trig, 1); // phát xung từ chân trig
  delayMicroseconds(5); // xung có độ dài 5 microSeconds
  digitalWrite(trig, 0); // tắt chân trig
  // Tính toán thời gian
  // Đo độ rộng xung HIGH ở chân echo.
  duration = pulseIn(echo, HIGH);
  // Tính khoảng cách đến vật..
  distance = int(duration / 2 / 29.412); 
  if(distance <= 15){
    rightHand.write(80);
    delay(700);
  }
  else{
    rightHand.write(140);
  }
}
