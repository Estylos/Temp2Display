#include <avr/io.h>
#include <math.h>
#include "thermistorController.h"

void initThermistor(void) {

    ADMUX |= 1 << REFS0; // Voltage reference to AVCC
    ADCSRA |= (1 << ADPS0) | (1 << ADPS1); // ADC prescaler to /8 (125 kHz with F_CPU = 1 MHz)

    ADMUX |= THERMISTOR_PIN; // Setup the analog input

    ADCSRA |= 1 << ADEN; // ADC enable
}

float getTemperature(uint8_t unit) {

    ADCSRA |= 1 << ADSC; // ADC start converstion (single conversion mode)
    while ( ADCSRA & (1 << ADSC) ); // Wait for the ADSC bit to return to 0 

    float thermistorResistor = RESISTOR2_VALUE * ( 1023.0 / (float) ADC - 1.0 ); // Voltage divider equation

    /* 
        One of the multiple equations that we can use to get the temperature : T = 1 / ( ln(RT / R0) / B + 1 / T0 )
        See https://create.arduino.cc/projecthub/Marcazzan_M/how-easy-is-it-to-use-a-thermistor-e39321 
        for more information on measuring a temperature with an NTC thermistor 
    */
    
    float temperatureK = 1 / (
                        log( thermistorResistor / RT_AT_ROOM_TEMP ) / BETA +
                        1 / ROOM_TEMP );

    if (!unit)
        return temperatureK;
    else if (unit == 1) 
        return temperatureK - 273.15; // Temp in °C
    else if (unit == 2) 
        return 1.8 * ( temperatureK - 273.0 ) + 32.0; // Temp in °F
    else
        return 0;
}