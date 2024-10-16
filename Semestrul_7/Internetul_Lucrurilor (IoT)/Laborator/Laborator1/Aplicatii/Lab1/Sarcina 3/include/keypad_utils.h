#ifndef KEYPAD_UTILS_H
#define KEYPAD_UTILS_H

#include <Keypad.h>
#include "lcd_utils.h"

#define ROWS 4
#define COLS 4

const char KEYPAD_KEYS[ROWS][COLS] = {
  { '1', '2', '3', '4' },
  { 'Q', 'W', 'E', 'R' },
  { 'A', 'S', 'D', 'F' },
  { 'Z', 'X', 'C', 'V' }
};

const uint8_t COL_PINS[COLS] = { A3, A2, A1, A0 };
const uint8_t ROW_PINS[ROWS] = { 5, 4, 3, 2 };

extern Keypad keypad;

String getEnteredCode(uint8_t codeLength);

#endif // KEYPAD_UTILS_H
