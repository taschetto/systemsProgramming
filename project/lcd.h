/*
  Guilherme Taschetto (c) 2014

  All rights reserved.
*/

#ifndef __LCD_H__
#define __LCD_H__

#include <arch/nxp/lpc23xx.h>

#define CCLK 12000000
#define LCD_E	(1<<24)
#define LCD_RS	(1<<25)

void wait(unsigned int t);
void LCDcommand(int c);
void LCDputchar(int c);
void LCDinit(void);
void LCDputs(char *txt);
void initTimer();

#endif // __LCD_H__
