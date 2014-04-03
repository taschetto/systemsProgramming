/************************************************
* LCD test
*
*************************************************/
#include "lcd.h"

int main()
{
    initTimer();

    FIO4DIR = 0x0FF;		
    FIO4SET = 0xFF;

    LCDinit();
    LCDputs("LCD test");
    LCDcommand(0xc0);
    LCDputs("Line 2");

    int sw;

    // Flashes LEDs 3x
    for (sw = 0; sw < 4; sw++) {
    	FIO4CLR = 0xFF;		// light all
    	wait(100);		// wait 100 ms
    	FIO4SET = 0xFF;		// all off
    	wait(100);		// wait 100 ms
    }
    LCDcommand(1);		// clears LCD
    LCDputs("OK!");
    
    wait(4000);

    return 0;
}


void UNDEF_Routine()
{
}

void SWI_Routine()
{
}

void FIQ_Routine()
{
}
