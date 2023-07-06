#include <Servo.h>

Servo rightLeg;
Servo leftLeg;
Servo rightFoot;
Servo leftFoot;
Servo rightHand;
Servo leftHand;
Servo countersink;

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
  leftHand.attach(11);
  countersink.attach(12);

  rightFoot.write(90);  // 90
  rightLeg.write(0); // 0
  leftLeg.write(0);
  leftFoot.write(99);  // 99
  leftHand.write(20);
  rightHand.write(140); // 140-80
  countersink.write(180);
} 

void loop() {

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
  // Tính khoảng cách đến vật.
  distance = int(duration / 2 / 29.412); 
  attack(distance);
  //welcome();
  //refuse();
}

void welcome(){
  leftHand.write(180);
  delay(1000);
  leftHand.write(80);
  delay(1000);
}

void refuse(){
  leftHand.write(180);
  
  countersink.write(180); 
  delay(200);
  countersink.write(0);
  delay(200);
}

void attack(int distance){
  if(distance < 15){
    rightHand.write(80);
    leftHand.write(110);
    rightLeg.write(30);
    leftLeg.write(30);
    countersink.write(0);
    leftFoot.write(99+10);
    rightFoot.write(90-10);
    delay(700);  
    countersink.write(180); 
    rightLeg.write(0);
    leftLeg.write(0);
    leftFoot.write(99-10);
    rightFoot.write(90+10);
    delay(700);
  }
  else{
    rightFoot.write(90);  // 90
    rightLeg.write(0); // 0
    leftLeg.write(0);
    leftFoot.write(99);  // 99
    leftHand.write(20);
    rightHand.write(140); // 140-80
    countersink.write(180);
    delay(500);
  }
}

