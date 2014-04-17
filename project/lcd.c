#include <arch/nxp/lpc23xx.h>
#include "defines.h"
#include "lcd.h"
#include "timer.h"

void LCDcommand(int c)
{
  FIO3DIR |= LCD_D;
  FIO3PIN |= c;
  FIO2CLR |= LCD_RS;		
  FIO2SET |= LCD_EN;
  wait(20);
  FIO2CLR |= LCD_EN;
  wait(20);
}

void LCDputchar(int c)
{
  FIO3DIR |= LCD_D;
  FIO3PIN = c;
  FIO2SET = LCD_RS;
  FIO2SET = LCD_EN;
  wait(20);
  FIO2CLR = LCD_EN;
  wait(20);
}

void LCDinit(void)
{
  FIO2DIR |= LCD_EN | LCD_RS;
  FIO2CLR |= LCD_EN;
  wait(20);
  LCDcommand(0x38);
  LCDcommand(0x01);
  LCDcommand(0x0C);
  LCDcommand(0x80);
}

void LCDputs(char *s)
{
  while (*s)
	  LCDputchar(*s++);
}
