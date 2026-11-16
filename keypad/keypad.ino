#include <Keypad.h>

const byte ROWS = 4;  // Four rows
const byte COLS = 4;  // Four columns

// Define the symbols on the buttons of the keypad
char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 9, 8, 7, 6 };  // Connect to the row pinouts of the keypad
byte colPins[COLS] = { 5, 4, 3, 2 };  // Connect to the column pinouts of the keypad

// Initialize an instance of class Keypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    Serial.println(customKey);  // Print the pressed key to the Serial Monitor
  }
}
