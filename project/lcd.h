#ifndef __LCD_H__
#define __LCD_H__

#include <arch/nxp/lpc23xx.h>

#define CCLK 12000000

// Defines for LCD control bits
#define LCD_E	(1<<24)
#define LCD_RS	(1<<25)

void wait(unsigned int t);
void LCDcommand(int c);
void LCDputchar(int c);
void LCDinit(void);
void LCDputs(char *txt);
void initTimer();

#endif // __LCD_H__
