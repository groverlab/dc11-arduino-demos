#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

const int ROWS = 8;
const int COLS = 12;
const int SPEED_MS = 120; // Lower value = faster movement

uint8_t frame[ROWS][COLS] = {0};

int x, y;
int dx, dy;

void setup() {
  matrix.begin();

  // Seed randomness from a floating analog pin so each reset takes a different path
  randomSeed(analogRead(A0));
  x = random(1, COLS - 1);
  y = random(1, ROWS - 1);
  dx = (random(0, 2) == 0) ? 1 : -1;
  dy = (random(0, 2) == 0) ? 1 : -1;
}

void loop() {
  // Erase the ball's previous position
  frame[y][x] = 0;

  // Reverse direction before hitting a wall
  if (x + dx < 0 || x + dx >= COLS) {
    dx = -dx;
  }
  if (y + dy < 0 || y + dy >= ROWS) {
    dy = -dy;
  }

  // Move and draw the ball
  x += dx;
  y += dy;
  frame[y][x] = 1;
  matrix.renderBitmap(frame, ROWS, COLS);

  // Blink twice whenever the ball hits an exact corner
  if ((x == 0 || x == COLS - 1) && (y == 0 || y == ROWS - 1)) {
    for (int i = 0; i < 2; i++) {
      delay(80);
      frame[y][x] = 0;
      matrix.renderBitmap(frame, ROWS, COLS);
      delay(80);
      frame[y][x] = 1;
      matrix.renderBitmap(frame, ROWS, COLS);
    }
  }

  delay(SPEED_MS);
}