#ifndef NTC_H
#define NTC_H

#include <stdint.h>
#include <math.h>

#define BETA 3950 // valoarea BETA a termistorului NTC
#define ANALOG_PIN A0 //pinul analogic de conexiune
#define V_REF 5.0 // tensiunea de referință utilizată de ADC
#define R_REF 10000.0 // rezistența de referință utilizată în divizorul de tensiune
#define ADC_MAX 1023.0 // valoarea maximă pe care o poate avea un ADC de 10 biți


double get_temperature_directly(int16_t adcValue);
double adc_to_Voltage(int16_t adcValue);
double calculate_ntc_resistance(double voltage);
double convert_to_Kelvin(double ntcResistance);
double convert_to_Celsius(double ntcResistance);

#endif //NTC_h