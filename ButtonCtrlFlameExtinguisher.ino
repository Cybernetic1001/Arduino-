#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int angle = 0;    // initial angle  for servo
int angleStep = 10;

void setup() {
  Serial.begin(9600);          //  setup serial
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(13, INPUT_PULLUP);
  Serial.println("Value");
}

void loop() {
  while (digitalRead(13) == LOW) {
    // change the angle for next time through the loop:
    angle = angle + angleStep;

    // reverse the direction of the moving at the ends of the angle:
    if (angle <= 0 || angle >= 180) {
      angleStep = -angleStep;
    }
    myservo.write(angle); // move to desired angle
    Serial.print("Moved to:");
    Serial.print(angle);   // print the angle
    Serial.println(" degree");
    delay(100); // waits for the servo to get there
  }


}
