#ifndef FILTERS_H
#define FILTERS_H

#include <string.h>
#include <Arduino.h>

#define SAMPLES_NUM 5

double saltAndPapperFilter(double newValue);
double weightedMovingAverageFilter(double newValue);

#endif //FILTERS_H