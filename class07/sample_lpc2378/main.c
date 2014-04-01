/************************************************
  Simple example: flashes the LEDs and controls
  direction with switches 1 and 2
*************************************************/
#include <arch/nxp/lpc23xx.h>
#define CCLK 12000000

// Wait for t ms
void wait(unsigned int t)
{
    unsigned int tf;
    tf = T0TC + t;		// tf = Future value of T0TC
    while (tf != T0TC);		// wait until tf == T0TC
}

void initTimer()
{
    PCONP |= 2;			// Turns on Timer 0
    PCLKSEL0 = (PCLKSEL0 & (~0x0c)) | 0x04;	// Divide CCLK by 1 on T0
    T0TCR = 0;			// Disables T0
    T0PR = CCLK / 1000 - 1;	// Sets T0TC increment as 1000 times/s
    T0TCR = 2;			// Inits T0
    T0TCR = 1;			// Enables T0
}


int main (void)
{
    // Inits timer 0 (needed for the LCD funcions and for the waiting function)
    initTimer();
    FIO4DIR = 0xff;    // Bits 0 to 7 will be set: LEDs as outputs

    int mask, dir;
    mask = 1;          // Sets bit 0 (turns on LED 1)
    dir = 0;
    do
    {
        wait(100);                    // Wastes time...
        if(!(FIO4PIN & 0x100)) dir=1; // SW1: will set direction to the right
        if(!(FIO4PIN & 0x200)) dir=0; // SW2: will set direction to the left
        FIO4SET = 0xff;               // Turns off all LEDs
        FIO4CLR = mask;               // Turns on the current LED in the sequence
        if(dir)    {
            mask >>= 1;               // Shifts lit LED to the right
            if(!mask) mask = 0x80;    // Finished? Reset to last LED (bit 7)
        }
        else    {
            mask <<= 1;               // Shifts lit LED to the left
            if(mask & 0x100) mask=1;  // Finished? Reset to first LED (bit 1)
        }
    } while(1);
    return 0;
}

/* These routines are called by crt.S
They must exist, but won't be used */
void UNDEF_Routine(){}
void SWI_Routine(){}
void FIQ_Routine(){}
