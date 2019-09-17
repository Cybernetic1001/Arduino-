
const int buzzerPin = 9;    // connect the buzzer to pin 9
const int songLength = 18;  // sets the number of notes of the song

char notes[songLength] = {
  'c', 'd', 'f', 'd', 'a', ' ', 'a', 'g', ' ', 'c', 'd', 'f', 'd', 'g', ' ', 'g', 'f', ' '}; 

int beats[songLength] = {
  1, 1, 1, 1, 1, 1, 4, 4, 2, 1, 1, 1, 1, 1, 1, 4, 4, 2};

int tempo = 113;  // The tempo is how fast to play the song (beats per second).

void setup() 
{
  pinMode(buzzerPin, OUTPUT);  // sets the  buzzer pin as an OUTPUT
}


void loop() 
{
  int i, duration; //

  for (i = 0; i < songLength; i++) // for loop is used to index through the arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms

    if (notes[i] == ' ')          // is this a rest? 
      delay(500);            // then pause for a moment
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(500);
    }
    delay(tempo/10);              // brief pause between notes
  }
}

int frequency(char note) 
{
  int i;
  const int numNotes = 8;  // number of notes we're storing
  char names[numNotes] = { 
    'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'    };
  int frequencies[numNotes] = {
    262, 294, 330, 349, 392, 440, 494, 523    };


  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         
    {
      return(frequencies[i]);     
    }
  }
  return(0); 
}
