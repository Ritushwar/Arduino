#include <SoftwareSerial.h> 
#include <Servo.h>
Servo servo;
Servo esc;
int bttx = 10;
int btrx = 11;
SoftwareSerial bluetooth(bttx,btrx);
void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  esc.attach(8);
  Serial.begin(9600);
  bluetooth.begin(9600);
  servo.write(90); //at initial position
  esc.write(10);     //calibrate the motor
  esc.write(50);
}

void loop() {
  if(bluetooth.available()>0){
    int data = bluetooth.read();
    Serial.println(data);
    /*if(data>=0 && data<=255){  //speed control of motor
      Serial.println("speed of motor");
      esc.write(data);
    }
    if(data==257){   //stopping the bot
      esc.write(0);
      servo.write(90);
      Serial.print("Stopping");
      }
    if(data==258){  //right turn
      esc.write(70);
      servo.write(45);
      Serial.println("Right turn");
      }
    if(data==259){  //left turn
      esc.write(70);
      servo.write(135);
      Serial.println("Left turn");
      }
    if(data==260){  //long right
      esc.write(70);
      servo.write(0);
      Serial.println("Sharp right turn");
      }
    if(data==261){  //long left
      esc.write(70);
      servo.write(170);
      Serial.println("Sharp left turn");
      } */
    }
    
  // put your main code here, to run repeatedly:
}
