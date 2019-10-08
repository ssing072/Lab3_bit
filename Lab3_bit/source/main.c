/*	Author: ssing072
 *  Partner(s) Name: Neha Gupta
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
    DDRB = 0xFE; PORTB = 0x00;
    DDRD = 0x00; PORTD = 0x00;
    
    unsigned long personWeight = 0;
    unsigned char tempB = 0x00;
    
    while(1){
        personWeight = PIND + PINB;
        if(personWeight >= 70){
            tempB = 0x02;
        }
        else if(personWeight <= 5){
            tempB = 0x00;
        }
        else{
            tempB = 0x04;
        }
        PORTB = tempB;
    }
    return 1;
}
