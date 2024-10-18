#include "NTC.h"

double get_temperature_directly(int16_t adcValue){
  return 1 / (log(1 / (ADC_MAX / adcValue - 1)) 
    / BETA + 1.0 / 298.15) - 273.15;
}

double adc_to_Voltage(int16_t adcValue){
  return (adcValue / ADC_MAX) * V_REF;
}

double calculate_ntc_resistance(double voltage) {
    return R_REF * (V_REF / voltage - 1);
}

double convert_to_Kelvin(double ntcResistance) {
    return 1.0 / (log( R_REF / ntcResistance  ) / BETA + 1.0 / 298.15);
}

double convert_to_Celsius(double ntcResistance) {
    return convert_to_Kelvin(ntcResistance) - 273.15;
}