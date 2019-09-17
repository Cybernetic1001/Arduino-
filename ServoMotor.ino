

#include <Servo.h>          //include the servo library
int servoPosition;         //the servo will move to this position
const int Rbutton = 13;         //Assign Redbutton


Servo myservo;              //create a servo object

  void Setupservo()
{
  pinMode(13,INPUT_PULLUP);
  myservo.attach(9);        //tell the servo object that its servo is plugged into pin 9
}
  void loopservo()
  {

  boolean Rbutton = digitalRead(13);
  
  if(Rbutton == LOW)
  {
  myservo.write(0);
}

  if(Rbutton == HIGH)
  {
myservo.write(10); //setting servo1 to 10 degrees
myservo.write(170); //setting servo2 to 170 degrees
delay(1000); //wait one second   

myservo.write(170); //setting servo1 to 170 degrees
myservo.write(10); //setting servo2 to 10 degrees
delay(1000); //wait one second
  }
  }
