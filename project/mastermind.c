#include "mastermind.h"
#include "lcd.h"

void init()
{
  initTimer();

  FIO4DIR = 0xFF;
  FIO4CLR = 0xFF;

  LCDinit();
  LCDcommand(0x80);
  LCDputs("Mastermind by GT");
  LCDcommand(0xC4);
  LCDputs("SW1: begin");

  for (;;)  
  {
    wait(50);
    if (!(FIO4PIN & 0x100))
      break;
  }
}

void readPassword(char password[])
{
  LCDcommand(0x01);
  LCDcommand(0x80);
  LCDputs("Password:");

  for (;;)
  {
    wait(50);
    LCDcommand(0xC0);
    LCDputs(password);

    if (!(FIO4PIN) & 0x500)
      break;
  }

/*    if (!(FIO4PIN) & 0x200)
    {
      password[1]++;
      if (password[1] > '9')
        password[1] = '9';
    }

    if (!(FIO4PIN) & 0x300)
    {
      password[2]++;
      if (password[2] > '9')
        password[2] = '9';
    }

    if (!(FIO4PIN) & 0x400)
    {
      password[3]++;
      if (password[3] > '9')
        password[3] = '9';
    }

    if (!(FIO4PIN) & 0x500)
    {
      break;
    }*/
}

int checkPassword(char password[], char guess[], char feedback[])
{
  return 1;
}

void showFeedback(char feedback[])
{
}

void loser()
{
}

void winner()
{
}
