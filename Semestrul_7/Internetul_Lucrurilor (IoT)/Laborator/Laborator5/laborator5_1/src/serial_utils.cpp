#include "serial_utils.h"


void initializeSerial(int64_t baud){
  Serial.begin(baud);
  printf("Serial is rady!\n");
}

int16_t getNumericValue() {
  char input[10];  // Șir pentru a stoca inputul utilizatorului
  int16_t speed = 0;
  bool valid = false;

  while (!valid) {
    // Citim inputul ca un șir de caractere
    scanf("%s", input);

    // Verificăm dacă inputul este numeric și poate începe cu '-' sau '+'
    valid = true;  // Presupunem că este valid până la dovada contrară
    int i = 0;
    if (input[0] == '-' || input[0] == '+') {
      i = 1;  // Dacă începe cu '-' sau '+', începem verificarea de la următorul caracter
    }

    // Verificăm restul caracterelor să fie doar cifre
    for (; input[i] != '\0'; i++) {
      if (input[i] < '0' || input[i] > '9') {
        valid = false;
        break;
      }
    }

    // Dacă inputul este valid, convertim la număr și verificăm intervalul
    if (valid) {
      speed = atoi(input);  // Convertim șirul la număr întreg
      
    } else {
      printf("Invalid input. Please enter a numeric value.\n");
    }
  }
  return speed;  // Returnăm valoarea introdusă
}
