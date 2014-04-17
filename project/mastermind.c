#include <arch/nxp/lpc23xx.h>
#include "mastermind.h"
#include "defines.h"
#include "lcd.h"
#include "timer.h"

void init()
{
  FIO4MASK = 0x00000000;
  FIO3MASK = 0x00000000;
  FIO2MASK = 0x00000000;

  FIO4DIR |= 0xFF;   // LEDs -> saída
  FIO3DIR |= 0xFF;   // LCD  -> saída
  FIO2DIR |= 0x00;   // SWs  -> entrada
  FIO2DIR |= LCD_EN
          |  LCD_RS; // LCD control -> saída

  TIMERinit();
  LCDinit();

  LCDcommand(0x80);
  LCDputs("Mastermind by GT");
  LCDcommand(0xC0);
  LCDputs("SW1: begin");
}

void readPassword(char password[])
{
  LCDcommand(0x01);
  LCDcommand(0x80);
  LCDputs("Password:");

  for (;;)
  {
    wait(100);

    if (!(FIO2PIN & SW1)) inc(&password[0]);
    if (!(FIO2PIN & SW2)) inc(&password[1]);
    if (!(FIO2PIN & SW3)) inc(&password[2]);
    if (!(FIO2PIN & SW4)) inc(&password[3]);
    if (!(FIO2PIN & SW5)) break;
  }
}

void inc(char* c)
{
  *c = *c + 1;
  if (*c > '9') *c = '0';
}

int checkPassword(char password[], char guess[], char feedback[])
{
  int i, j;
  int result = 1;
  
  for (i = 0; i < PASSWORD_SIZE; i++)
  {
    if (password[i] != guess[i])
      result = 0;

    for (j = 0; j < PASSWORD_SIZE; j++)
    {
      if (guess[i] == password[j])
      {
        if (i == j)
          feedback[i] = '*';
        else
          feedback[i] = '?';

        break;
      }
      else
        feedback[i] = 'X';
    }
  }

  return result;
}

void showFeedback(char feedback[])
{
}

void loser()
{
  LCDcommand(0x01);
  LCDcommand(0x80);
  LCDputs("You lose!");
  LCDcommand(0xC0);
  LCDputs(":-( :-( :-(");
}

void winner()
{
  LCDcommand(0x01);
  LCDcommand(0x80);
  LCDputs("You win!");
  LCDcommand(0xC0);
  LCDputs(":-D :-D :-D");
}
