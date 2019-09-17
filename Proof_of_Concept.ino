const int trigPin = 11;           //connects to the trigger pin on the distance sensor
const int echoPin = 12;           //connects to the echo pin on the distance sensor

const int redPin = 3;             //pin to control the red LED 
const int bluePin = 6;            //pin to control the blue LED 

float distance = 0;               //stores the distance measured by the distance sensor

#include <Servo.h>          //include the servo library

/;
float servoPosition;         //the servo will move to this position

Servo myservo;              //create a servo object

void setup()
{
  myservo.attach(9);        //tell the servo object that its servo is plugged into pin 9
  Serial.begin (9600);        //set up a serial connection with the computer

  pinMode(trigPin, OUTPUT);   //the trigger pin will output pulses of electricity
  pinMode(echoPin, INPUT);    //the echo pin will measure the duration of pulses coming back from the distance sensor


  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}




void loop()//New
{
  
   

    servoPosition = map(distance, 0,20,0,180); 
    servoPosition = constrain(servoPosition, 0, 180);                                               
    myservo.write(servoPosition);                       //move the servo
  

  distance = getDistance();   //variable to store the distance measured by the sensor

  Serial.print(servoPosition);     //print the distance that was measured
  Serial.println(" in");      //print units after the distance

  if (distance <= 10) {                       //if the object is close

    
    analogWrite(redPin, 255);
    analogWrite(bluePin, 0);

  } else if (10 < distance && distance < 20) { //if the object is a medium distance

   
    analogWrite(redPin, 255);
    analogWrite(bluePin, 50);

  } else {                                    //if the object is far away

    
    analogWrite(redPin,0);
    analogWrite(bluePin, 255);
  }

  delay(50);      //delay 50ms between each reading
}

float getDistance()
{
  float echoTime;                   //variable to store the time it takes for a ping to bounce off an object
  float calculatedDistance;         //variable to store the distance calculated from the echo time

  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH); v
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);      //use the pulsein command to see how long it takes for the
  //pulse to bounce back to the sensor

  calculatedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)

  return calculatedDistance;              //send back the distance that was calculated
}
