/*	Author: Jeana Tijerina
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 2  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
//    unsigned char tmpB = 0x00;
    unsigned char tmp1; //= PINA & 0X01;
    unsigned char tmp2; // = PINA & 0x02;
    unsigned char tmp3;
    unsigned char tmp4;
    unsigned char cntavail;
 //   unsigned short count = 0;

    while (1) {
	tmp4 = PINA & 0x08;
	tmp3 = PINA & 0x04;
	tmp2 = PINA & 0x02;
	tmp1 = PINA & 0x01;
	cntavail = 0x00;

	if (tmp4 == 0x00) {
		cntavail++;
	}
	if (tmp3 == 0x00) {
		cntavail++;
	}
	if (tmp2 == 0x00) {
		cntavail++;
	}
	if (tmp1 == 0x00) {
		cntavail++;
	}
//	PORTC = cntavail;
    
    	if (cntavail == 0x00) {
		PORTC = cntavail | 0x80;
	}
	else {
		PORTC = cntavail;
	}
    
    }
    return 1;
}
