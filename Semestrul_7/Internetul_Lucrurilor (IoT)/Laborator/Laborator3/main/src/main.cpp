#include <Arduino.h>
#include "NTC.h"
#include "ultrasonic.h"
#include "filters.h"

void NTC_task();
void Ultrasonic_task();

char buffer[20];

void setup()
{
    Serial.begin(9600);
    setup_ultrasonic();

    printf("All done. Start meassuring:\n");
}

void loop()
{

    printf("\n");
    NTC_task();
    printf("\n");
    Ultrasonic_task();

    delay(2000);
}

void NTC_task()
{
    int16_t adcValue = analogRead(ANALOG_PIN);

    double voltage = adc_to_Voltage(adcValue);
    dtostrf(voltage, 5, 2, buffer);
    printf("Voltage: %sV\n", buffer);

    double resistance = calculate_ntc_resistance(voltage);
    dtostrf(resistance, 5, 2, buffer);
    printf("Resistance: %sOhms\n", buffer);

    double temperature = convert_to_Celsius(resistance);

    // double filtered = saltAndPapperFilter(temperature);
    // double filtered = weightedMovingAverageFilter(temperature);

    dtostrf(temperature, 5, 2, buffer); // foloseste filtred în loc de temperatura pentru a efectua afișare cu filtre
    printf("Temperature: %s°C\n", buffer);
}

void Ultrasonic_task()
{
    int distance_CM = get_distance_CM();
    dtostrf(distance_CM, 5, 2, buffer);
    printf("Distance in CM: %s\n", buffer);

    int distance_inches = get_distance_inches();
    dtostrf(distance_inches, 5, 2, buffer);
    printf("Distance in inches: %s\n", buffer);
}
