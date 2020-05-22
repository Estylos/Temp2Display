#ifndef __DISPLAYCONTROLLER_H__
#define __DISPLAYCONTROLLER_H__

#include <stdint.h>


#define CATHODE_PORT PORTB
#define CATHODE_DDR DDRB

#define ANODE_PORT PORTD
#define ANODE_DDR DDRD
#define ANODE_P0 PD5
#define ANODE_P1 PD6
#define ANODE_P2 PD7


#define DISP_0          0xC0
#define DISP_1          0xF9
#define DISP_2          0xA4
#define DISP_3          0xB0
#define DISP_4          0x99
#define DISP_5          0x92
#define DISP_6          0x82
#define DISP_7          0xF8
#define DISP_8          0x80
#define DISP_9          0x90
#define DISP_A          0x88
#define DISP_B          0x83
#define DISP_C          0xC6
#define DISP_D          0xA1
#define DISP_E          0x86
#define DISP_F          0x8E
#define DISP_DASH       0xBF
#define DISP_DOT        0x7F
#define DISP_OFF        0xFF


void initDisplay(void);
void printOnDisplay(uint8_t cathodesState, uint8_t display, uint16_t delay);
void printOnTreeDisplays(uint8_t cathodesStateD1, uint8_t cathodesStateD2, uint8_t cathodesStateD3, uint16_t delay);
uint8_t asciiToCathodesState(uint8_t character);


#endif