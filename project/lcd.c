/*
  Guilherme Taschetto (c) 2014

  All rights reserved.
*/

#include "lcd.h"

void wait(unsigned int t)
{
  unsigned int tf;
  tf = T0TC + t;
  while (tf != T0TC);
}

void LCDcommand(int c)
{
  FIO3PIN0 = c;
  FIO4CLR = LCD_RS;		
  FIO4SET = LCD_E;
  FIO4CLR = LCD_E;
  wait(20);
}

void LCDputchar(int c)
{
  FIO3PIN0 = c;
  FIO4SET = LCD_RS;
  FIO4SET = LCD_E;
  FIO4CLR = LCD_E;
  wait(8);
}

void LCDinit(void)
{
  FIO3DIR |= 0xff;
  FIO4DIR |= LCD_E | LCD_RS;
  wait(20);
  LCDcommand(0x38);
  LCDcommand(1);
  LCDcommand(0x0c);
}

void LCDputs(char *txt)
{
  while (*txt)
	  LCDputchar(*txt++);
}

void initTimer()
{
    PCONP |= 2;
    PCLKSEL0 = (PCLKSEL0 & (~0x0c)) | 0x04;
    T0TCR = 0;
    T0PR = CCLK / 1000 - 1;
    T0TCR = 2;
    T0TCR = 1;
}

