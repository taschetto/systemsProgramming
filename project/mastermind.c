#include <arch/nxp/lpc23xx.h>
#include "mastermind.h"
#include "defines.h"
#include "lcd.h"

void init()
{
  initTimer();

  FIO4DIR = 0x00FF;		
  FIO4SET = 0xFF;

  LCDinit();

  LCDcommand(0x80);
  LCDputs("Mastermind by GT");
  LCDcommand(0xC0);
  LCDputs("SW1: begin");

  while (FIO4PIN & SW1)
  {
    while (!(FIO4PIN & SW1));
  }
}

void readPassword(char label[], char password[])
{
  LCDcommand(0x01);
  LCDcommand(0x80);
  LCDputs(&label[0]);

  while (1)
  {
    LCDcommand(0xC0);
    LCDputs(&password[0]);

    wait(100);

    if (!(FIO4PIN & SW1))
    {
      while (!(FIO4PIN & SW1));
      inc(&password[0]);
    }

    if (!(FIO4PIN & SW2))
    { 
      while (!(FIO4PIN & SW2));
      inc(&password[1]);
    }

    if (!(FIO4PIN & SW3))
    {
      while (!(FIO4PIN & SW3));
      inc(&password[2]);
    }

    if (!(FIO4PIN & SW4))
    {
      while (!(FIO4PIN & SW4));
      inc(&password[3]);
    }

    if (!(FIO4PIN & SW5))
    {
      while (!(FIO4PIN & SW5));
      break;
    }
  }
}

void inc(char* c)
{
  *c = *c + 1;
  if (*c > '9') *c = '0';
}

int checkPassword(char password[], char guess[], char feedback[2])
{
  int i, j;
  int result = 1;

  char certos = 0, errados = 0;
  
  for (i = 0; i < PASSWORD_SIZE; i++)
  {
    if (password[i] == guess[i])
      certos++;
    else
    {
      result = 0;
      for (j = 0; j < PASSWORD_SIZE; j++)
      {
        if (i == j) continue;

        if (password[i] == guess[j])
        {
          errados++;
          break;
        }
      }
    }
  }

  feedback[0] = certos;
  feedback[1] = errados;

  return result;
}

void showFeedback(char feedback[2])
{

  LCDcommand(0x80);
  LCDputs("Wrong! Press SW5.");

  int leds[] = { LED7, LED6, LED5, LED4 };
  int status = 0;
  int count = 0;

  char certos = feedback[0], errados = feedback[1];

  FIO4SET |= 0xFF;

  while (1)
  {
    if (count++ >= 50)
    {
      status = !status;
      count = 0;
    }

    int i;
    for (i = 0; i < certos; i++)
    { 
      FIO4CLR |= leds[i];
    }

    for (; i < certos + errados; i++)
    {
      if (status)
        FIO4CLR |= leds[i];
      else
        FIO4SET |= leds[i];
    }

    if (!(FIO4PIN & SW5))
    {
      while (!(FIO4PIN & SW5));
      break;
    }

    wait(10);
  }

  FIO4SET |= 0xFF;
}

void loser()
{
  LCDcommand(0x01);
  LCDcommand(0x80);
  LCDputs("You lose! :-(");
  LCDcommand(0xC0);
  LCDputs("SW1 to restart.");
  while (FIO4PIN & SW1);
}

void winner()
{
  LCDcommand(0x01);
  LCDcommand(0x80);
  LCDputs("You win! :-D");
  LCDcommand(0xC0);
  LCDputs("SW1 to restart.");

  int i;
  for (i = 0; i < 3; i++)
  {
    FIO4CLR |= 0xFF;
    wait(300);
    FIO4SET |= 0xFF;
    wait(300);
  }
}
