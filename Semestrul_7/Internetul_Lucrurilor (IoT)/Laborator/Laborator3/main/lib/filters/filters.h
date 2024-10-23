#ifndef FILTERS_H
#define FILTERS_H

#include <string.h>
#include <Arduino.h>

#define SAMPLES_NUM 5

typedef struct {
    int values[SAMPLES_NUM];   // Valorile mostrelor
    int index;                 // Indexul curent pentru valori
    double alpha[SAMPLES_NUM]; // Ponderi pentru weighted moving average (dacă e necesar)
} FilterData;

double saltAndPapperFilter(double newValue);
double weightedMovingAverageFilter(double newValue);

#endif //FILTERS_H