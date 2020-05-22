#include <avr/io.h>
#include <math.h>
#include "displayController.h"
#include "thermistorController.h"

int main(void) {

    initDisplay();
    initThermistor();
    
    while(1) {

        float temperature = getTemperature(TEMP_IN_C); 

        float floatingIntegerPart;
        float decimalPart = modff(temperature, &floatingIntegerPart); // Decomposes a floating point value
        uint8_t firstDecimal = (uint8_t) (decimalPart * 10); // *10 : to get one decimal
        uint8_t integerPart = (uint8_t) floatingIntegerPart;

        uint8_t tenDigit = integerPart / 10;  // e.g. : 29 / 10 = 2
        uint8_t unitDigit = integerPart % 10; // e.g. : 29 % 10 = 9      

        printOnTreeDisplays(asciiToCathodesState(tenDigit + '0'),
                            asciiToCathodesState(unitDigit + '0') & DISP_DOT, // & DISP_DOT : to display the dot in addition to the value 
                            asciiToCathodesState(firstDecimal + '0'), 2);
    }

    return 0;
}