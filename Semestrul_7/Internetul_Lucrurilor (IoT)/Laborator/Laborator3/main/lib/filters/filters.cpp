#include "filters.h"

void showValues();
void move();

int adcValues[SAMPLES_NUM] = {0}; // Stocarea mostrelor
int index = SAMPLES_NUM - 1 ; // Indexul mostrei curente
double alpha[SAMPLES_NUM] = {0.1, 0.2, 0.3, 0.5, 0.7};


double saltAndPapperFilter(double newValue) {
  adcValues[index] = newValue;

  int sortedValues[SAMPLES_NUM];
  memcpy(sortedValues, adcValues, sizeof(adcValues));

  // Folosim o sortare mai eficientă (Insertion Sort pentru liste mici)
  for (int i = 1; i < SAMPLES_NUM; i++) {
    int key = sortedValues[i];
    int j = i - 1;
    while (j >= 0 && sortedValues[j] > key) {
      sortedValues[j + 1] = sortedValues[j];
      j = j - 1;
    }
    sortedValues[j + 1] = key;
  }

  showValues();
  move();

  return sortedValues[SAMPLES_NUM / 2];
}


double weightedMovingAverageFilter(double newValue) {
  double weightedAverage = 0;
  double weightSum = 0;
  adcValues[index] = newValue;

  for (int i = 0; i < SAMPLES_NUM; i++) {
    weightedAverage += adcValues[i] * alpha[i];
    weightSum += alpha[i];
  }

  showValues();
  move();

  return weightedAverage / weightSum;
}

void showValues() {
  int len = sizeof(adcValues) / sizeof(adcValues[0]);
  Serial.print("[ ");
  for (int i = 0; i < len; i++) {
    Serial.print(adcValues[i]);
    Serial.print(" ");
  }
  Serial.print("]");
}

void move() {
  for (int i = 0; i < SAMPLES_NUM - 1; i++) {
    adcValues[i] = adcValues[i + 1];
  }
}