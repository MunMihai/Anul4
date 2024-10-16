#include "keypad_utils.h"


String getEnteredCode(uint8_t code_length) {
  String code = "";
  while (code.length() < code_length) {
    char key = keypad.getKey();
    if (key != NO_KEY) {
      code += key;
      lcd.setCursor(code.length() + 5, 1);
      lcd.write(key);
    }
  }
  return code;
}
