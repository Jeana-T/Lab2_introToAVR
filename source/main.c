/*	Author: Jeana Tijerina
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 2  Exercise challenge
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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
//    unsigned char tmpB = 0x00;
    unsigned char tmpA; //= PINA & 0X01;
    unsigned char tmpB; // = PINA & 0x02;
    unsigned char tmpC;
    unsigned char tmpD;
    unsigned char totalWeight;
    unsigned char difference;

    while (1) {
	tmpA = PINA; // & 0x08;
	tmpB = PINB; // & 0x04;
	tmpC = PINC; // & 0x02;
	totalWeight = tmpA + tmpB + tmpC;
	tmpD = totalWeight >> 2;
	tmpD = tmpD & 0xFC;

	if (totalWeight > 140) {
		tmpD = tmpD | 0x01; //0000001
	}

	if (tmpA > tmpC) {
		difference = tmpA - tmpC; //00000010
	}
	else {
		difference = tmpC - tmpA;
	}


	if (difference > 80) {
		tmpD = tmpD | 0x02;
	}
	
//	totalWeight = totalWeight >> 2;

	PORTD = tmpD | totalWeight;    
    }
    return 1;
}
