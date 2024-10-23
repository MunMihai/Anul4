#include "filters.h"
#include "stdinout.h"

void showValues(int* values);
void move(int* values);


FilterData saltAndPepperData = {{0}, SAMPLES_NUM - 1, {1}};
FilterData weightedAvgData = {{0}, SAMPLES_NUM - 1, {0.1, 0.2, 0.3, 0.5, 0.7}};

double saltAndPapperFilter(double newValue) {
  saltAndPepperData.values[saltAndPepperData.index] = newValue;

  int sortedValues[SAMPLES_NUM];
  memcpy(sortedValues, saltAndPepperData.values, sizeof(saltAndPepperData.values));

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

  showValues(saltAndPepperData.values);
  move(saltAndPepperData.values);

  return sortedValues[SAMPLES_NUM / 2];
}

double weightedMovingAverageFilter(double newValue) {
  double weightedAverage = 0;
  double weightSum = 0;
  weightedAvgData.values[weightedAvgData.index] = newValue;

  for (int i = 0; i < SAMPLES_NUM; i++) {
    weightedAverage += weightedAvgData.values[i] * weightedAvgData.alpha[i];
    weightSum += weightedAvgData.alpha[i];
  }

  showValues(weightedAvgData.values);
  move(weightedAvgData.values);

  return weightedAverage / weightSum;
}

void showValues(int* values) {
  printf("[ ");
  for (int i = 0; i < SAMPLES_NUM; i++) {
    printf("%d ", values[i]);
  }
  printf("]");
}

void move(int* values) {
  for (int i = 0; i < SAMPLES_NUM - 1; i++) {
    values[i] = values[i + 1];
  }
}

