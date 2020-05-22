#ifndef __THERMISTORCONTROLLER_H__
#define __THERMISTORCONTROLLER_H__

#include <stdint.h>


#define THERMISTOR_PIN      PC0
#define RESISTOR2_VALUE     10000  // Value of the 2nd resistance of the voltage divider

// Constants specific to each thermistor (see the Steinhart–Hart equation)
#define BETA                3950
#define ROOM_TEMP           298.15 // 25°C In K
#define RT_AT_ROOM_TEMP     10000  // Resistance at 25°C


#define TEMP_IN_K           0
#define TEMP_IN_C           1
#define TEMP_IN_F           2


float getTemperature(uint8_t unit);
void initThermistor(void);


#endif