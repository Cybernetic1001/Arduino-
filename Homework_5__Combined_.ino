int potPosition;
int photoresistor = 0;
int threshold = 500;

void setup() //New setup

{
  setupPotentiometer();
  setupPhotoresistor();
}

void loop() //New loop
{
  loopPotentiometer();
  loopPhotoresistor();
}



void setupPotentiometer()
{
  Serial.begin(9600);       //start a serial connection with the computer

  pinMode(13, OUTPUT);      //set pin 13 as an output that can be set to HIGH or LOW
}

void loopPotentiometer()
{

  while (photoresistor > 500)
  {
    photoresistor = analogRead(A1);
    potPosition = analogRead(A0);    //set potPosition to a number between 0 and 1023 based on how far the knob is turned
    Serial.println(potPosition);     //print the value of potPosition in the serial monitor on the computer
    Serial.println(photoresistor);

    digitalWrite(13, HIGH);           // Turn on the LED
    delay(potPosition);
    digitalWrite(13, LOW);
    delay(potPosition);              // Turn off the L            // delay for as many miliseconds as potPosition (0-1023)

  }
}


void setupPhotoresistor()

{
  Serial.begin(9600);               //start a serial connection with the computer

  pinMode(13, OUTPUT);              //set pin 13 as an output that can be set to HIGH or LOW
}

void loopPhotoresistor()

{ potPosition = analogRead(A0);
  photoresistor = analogRead(A1);
  Serial.println(photoresistor);
  Serial.println(potPosition);
  while (photoresistor < 500)
  {
    digitalWrite(13, LOW);
    photoresistor = analogRead(A1);
    Serial.println(photoresistor);
  }
}
