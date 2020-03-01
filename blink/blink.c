/*
 * blink.c
 *
 * Created: 2020-02-12 10:35:10 AM
 *  Author: abdullah
 */ 
#include "blink.h"

void blink(int bit) {
	Disable_Interrupt();
	// set PORTA as output
	DDRA = 0x0FF;
	
	PORTA &= (0<< bit); // OFF
	PORTA |= (1<<bit);	// ON
	// Without NOP 0.25 us, with 2 NOP 0.5 us
	NoOperation();
	NoOperation();
	PORTA &= (0<< bit); // OFF
	Enable_Interrupt();
}
