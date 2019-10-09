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

unsigned char GetBit(unsigned char x, unsigned char k){
    return ((x & (0x01 << k)) != 0);
 }
        

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char i;
    unsigned char cnt = 0;
    unsigned char A = 0x00;
    unsigned char B = 0x00;
   

    /* Insert your solution below */
    while (1) {
       A = PINA;
       B = PINB;
       cnt = 0;
       for(i = 0; i < 8; i++){
           if(GetBit(A,i)){
               cnt++;
           }
           if(GetBit(B,i)){
               cnt++;
           }
        }
        PORTC =cnt; 
    }
    return 1;
}
