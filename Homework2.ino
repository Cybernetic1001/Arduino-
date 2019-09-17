 int button1Pin = 2;  // pushbutton 1 pin
 int button2Pin = 3; // pushbutton A5 pin
 int ledR = 13;       // LED pin
 int ledY = 12;       // LED pin
 int ledG = 11;       // LED pin 
 int ledB = 10;       // LED pin 

int button1State, button2State;  // variables to hold the pushbutton states


void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT); // Has a Resistor attached
  pinMode(button2Pin, INPUT); // Has a resistor attached 


  // Set up the LED pin to be an output:
  pinMode(13, OUTPUT);      
  
  pinMode (12, OUTPUT);
  
  pinMode (11, OUTPUT);
  
  pinMode (10, OUTPUT);
  
}




void loop()
{
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  Serial.println(button1State);
  Serial.print(button2State);
 
  // if button1 or button 2 are pressed (but not both)
  if (((button1State == LOW) && (button2State == LOW)) || ((button1State == HIGH) && (button2State == HIGH)))
  {
    digitalWrite (ledR, HIGH);  // turn the LED on
    digitalWrite (ledY, HIGH);
    digitalWrite (ledG, HIGH);
    digitalWrite (ledB, HIGH);
    }
  else
  {
    digitalWrite (ledR, LOW);  // turn the LED off
    digitalWrite (ledY, LOW);
    digitalWrite (ledG, LOW); 
    digitalWrite (ledB, LOW); 
  }
  
}
