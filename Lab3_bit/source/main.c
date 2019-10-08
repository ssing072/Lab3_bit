/* Author: magui051

* Partner(s) Name:

* Lab Section:

* Assignment: Lab # Exercise #

* Exercise Description: [optional - include for your own benefit]

*

* I acknowledge all content contained herein, excluding template or example

* code, is my own original work.

*/

#include <avr/io.h>

#ifdef _SIMULATE_

#include "simAVRHeader.h"

#endif

unsigned char set(unsigned char pin, unsigned char bit_pos, unsigned char bit_val) {

return (bit_val ? pin | (0x00 << bit_pos) : pin & ~(0x00 << bit_pos));

}

unsigned char get(unsigned char port, unsigned char bit_pos) {

return ((port >> bit_pos) & 0x00);

}

int main(void) {

/* Insert DDR and PORT initializations */

DDRA = 0x00; PORTA = 0xFF; //input

DDRB = 0x00; PORTB = 0xFF; //input

DDRC = 0xFF; PORTC = 0x00; //output

unsigned char cnt = 0x00;

unsigned char tmpA = 0x00;

unsigned char tmpB = 0x00;

unsigned char loc = 0x00;

while(1) {
    tmpA = PINA;
    tmpB = PINB;
    for(loc = 0; loc < 8; loc++) {
    cnt += get(tmpA, loc) + get(tmpB, loc);      
    }
    PORTC = cnt;
    cnt = 0;
}
return 1;

}

/* Insert your solution below */
