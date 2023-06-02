/*
*   Author: Chet Udell, 2023
*   Example calculates MIDI pitch frequencies for playback on speaker
*   Uses Arrays to store C Major and C minor scale MIDI pitch sequences
*   Example plays linearly through the Major and minor scale arrays
*   
*  
*   https://www.w3schools.com/cpp/cpp_arrays.asp
*   https://www.arduino.cc/reference/en/language/functions/random-numbers/randomseed/
*   https://www.arduino.cc/reference/en/language/functions/random-numbers/random/
*/

#include <Adafruit_CircuitPlayground.h>

float midi[127];
int A_four = 440;  // a is 440 hz...

// Arrays to store Scale MIDI pitch sequence
int c_major[8] = { 60, 62, 64, 65, 67, 69, 71, 72 };  // c_major scale on C4
int c_minor[8] = { 60, 62, 63, 65, 67, 68, 70, 72 };  // c_minor scale on C4

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  generateMIDI();  // Custom function for calculating and storing the frequency value associated for each MIDI pitch number
  randomSeed(analogRead(0));
}

void loop() {

  // Step through c_major array, linearly
  for (int i = 0; i < sizeof(c_major) / sizeof(int); i++)  // Calculate how many rows are in the array using: sizeof(array) / sizeof(datatype)
  {
    CircuitPlayground.playTone(midi[c_major[i]], 200);
    Serial.println(midi[c_major[i]]);
    delay(1);
  }

  delay(500);  // End of Phrase

  // Add code here to step through c_minor array, linearly
  for (int i = 0; i < sizeof(c_minor) / sizeof(int); i++) {
    CircuitPlayground.playTone(midi[c_minor[i]], 200);
    Serial.println(midi[c_minor[i]]);
    delay(1);
  }

  // Add delay of 500ms for End of Phrase
  delay(500);

  // Later,
  // Add a for loop that plays 8 random notes from the Major scale array
  for (int i = 0; i < 8; i++) {
    int randomPitch = random(8);
    //CircuitPlayground.playTone(midi[c_major[randomPitch]], 200);
    CircuitPlayground.playTone(midi[c_minor[randomPitch]], 200);
    delay(1);
  }
  // delay 500 ms

  // Add a for loop that plays 8 random notes from the minor scale array

  // delay 500 ms
}

void generateMIDI() {
  for (int x = 0; x < 127; ++x) {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}