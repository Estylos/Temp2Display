#include <avr/io.h>
#include <util/delay.h>
#include "displayController.h"

static inline void disp_delay_ms(uint16_t count) {
    while(count--) {
        _delay_ms(1);
    }
}

void initDisplay(void) {

    CATHODE_DDR = 0xff; // Setup cathodes (one per segments) in output mode
    ANODE_DDR |= (1 << ANODE_P0) | (1 << ANODE_P1) | (1 << ANODE_P2); // Setup anodes (one per display) in output mode

    CATHODE_PORT = 0xff; // Turn off all segments
    ANODE_PORT &=  ~( (1 << ANODE_P0) | (1 << ANODE_P1) | (1 << ANODE_P2) ); // Turn off all displays
}

void printOnDisplay(uint8_t cathodesState, uint8_t display, uint16_t delay) {
    
    ANODE_PORT |= 1 << display; // Turn on the display
    CATHODE_PORT = cathodesState; // Turn on the segments

    if(!delay)
        return;
            
    disp_delay_ms(delay); // Wait some time (for pov)

    CATHODE_PORT = 0xff; // Turn off the segments
    ANODE_PORT &= 0 << display; // Turn off the display
}

void printOnTreeDisplays(uint8_t cathodesStateD1, uint8_t cathodesStateD2, uint8_t cathodesStateD3, uint16_t delay) {

    printOnDisplay(cathodesStateD1, ANODE_P0, delay);
    printOnDisplay(cathodesStateD2, ANODE_P1, delay);
    printOnDisplay(cathodesStateD3, ANODE_P2, delay);

}

uint8_t asciiToCathodesState(uint8_t character) {

    switch (character){
        case '0': return DISP_0; break;
        case '1': return DISP_1; break;
        case '2': return DISP_2; break;
        case '3': return DISP_3; break;
        case '4': return DISP_4; break;
        case '5': return DISP_5; break;
        case '6': return DISP_6; break;
        case '7': return DISP_7; break;
        case '8': return DISP_8; break;
        case '9': return DISP_9; break;
        case 'A': return DISP_A; break;
        case 'B': return DISP_B; break;
        case 'C': return DISP_C; break;
        case 'D': return DISP_D; break;
        case 'E': return DISP_E; break;
        case 'F': return DISP_F; break;
        case '-': return DISP_DASH; break;
        case '.': return DISP_DOT; break;
        default:  return 0; break;
    }
}