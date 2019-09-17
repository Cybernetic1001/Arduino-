const int min = 4;
const int max = 13;
int led;
int pot;


void setup()
{
  Serial.begin(9600);
  pot = analogRead(A0);
  {
    for (led = min; led <= max; led++)
    {
      pinMode(led, OUTPUT);
    }
  }
}

void loop() {
  pot = analogRead(A0);
  Serial.println(pot);

  while (pot < 300)
  {
    {

      pot = analogRead(A0);
      Serial.println(pot);
      for (led; led >= min; led--)

      {
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led + 1, LOW);
        pot = analogRead(A0);
        Serial.println(pot);

      }
      pot = analogRead(A0);
      Serial.println(pot);
      for (led; led <= max; led++)
      {
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led - 1, LOW);
        pot = analogRead(A0);
        Serial.println(pot);

      }
    }
  }
  while (pot > 400 && pot < 700)
  {
    pot = analogRead(A0);
    Serial.println(pot);
    for (led; led >= min; led -= 2)
    {
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
      pot = analogRead(A0);
      Serial.println(pot);

    }
    pot = analogRead(A0);
    Serial.println(pot);
    for (led; led <= max; led += 2)
    {
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
      pot = analogRead(A0);
      Serial.println(pot);
    }
    digitalWrite(13, LOW);
  }
  while (pot >= 700 && pot < 1000)
  {
    pot = analogRead(A0);
    Serial.println(pot);
    for (led; led >= min; led--)
    {
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led + 2, LOW);
      pot = analogRead(A0);
      Serial.println(pot);

    }
    pot = analogRead(A0);
    Serial.println(pot);
    for (led; led <= max; led++);
    {
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led - 2, LOW);
      pot = analogRead(A0);
      Serial.println(pot);
    }
  }
  while (pot > 1000)
  {
    {
      pot = analogRead(A0);
      Serial.println(pot);
      for (led; led <= max; led++)
      {
        digitalWrite(led, HIGH);
        pot = analogRead(A0);
        Serial.println(pot);
      }
      for (led; led >= min; led--)
      {
        digitalWrite(led, LOW);
      }
    }
  }
}
