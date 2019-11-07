#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial ardui(2,3);
Servo servo;

void setup() {
  servo.attach(10);
  servo.write(0);
  Serial.begin(9600);
  ardui.begin(115200);
}

void loop() {
//  Serial.println("im here");
//  servo.write(20);
//  delay(1000);
//  servo.write(0);
//  delay(10000);
  String text = "";
  while(ardui.available()>0){
    text = ardui.readString();
    servo.write(25);
    delay(1000);
    servo.write(0);
    Serial.println("Received: " + text);
    ardui.println("Message from ardui");
    }
}
