
int potPosition;


void setup() {

  Serial.begin(9600);


  pinMode(13, OUTPUT);      // Set pin 13 to output
  pinMode (12, OUTPUT);    // Set pin 12 to output
}



void loop()
{
  potPosition = analogRead(A0); // Pot set to analog A0
  Serial.println(potPosition); // Read values for photoresistor 


 for (int 13 = 0; 13 < 10; 13++)
  {
    digitalWrite(13, LOW); // Off
  }

  else // Conditional Statement in one scope for the rest of code
  {
    potPosition = analogRead(A0); // Store Value 
    
    if (potPosition < 250) // Conditional Statement 
    {
      digitalWrite(13, HIGH); // On
      digitalWrite(12, LOW); // Off
      digitalWrite(11, LOW); // On 
    }
    
    if (250 <= potPosition &&  potPosition <= 500) // Conditional Statement 
    {
      digitalWrite(13, LOW); // Off
      digitalWrite(12, HIGH); // On
      digitalWrite(11, LOW); // Off 
    }
    
    if (501 <= potPosition && potPosition < 750) // Conditonal Statement 
    {
      digitalWrite(13, LOW); // Off 
      digitalWrite(12, LOW); // Off
      digitalWrite(11, HIGH); // On
    }
    
    potPosition = analogRead(A0);
    
    if (potPosition > 750) // Conditional Statement 
    {
      digitalWrite(13, HIGH); // All on 
      digitalWrite (12, HIGH);
      digitalWrite (!1, HIGH);
    }
  }
}
