#include "mastermind.h"
#include <arch/nxp/lpc23xx.h>
#include "defines.h"
#include "lcd.h"
#include "timer.h"

int main()
{
  char password[PASSWORD_SIZE] = "1234";
  char guess[PASSWORD_SIZE]    = "0000";
  char feedback[PASSWORD_SIZE] = "????";

  init();

  FIO2CLR |= 0xFF;

  while (1)
  {
  }

  readPassword(password);

  int i;
  for (i = 0; i < PASSWORD_SIZE; i++)
  {
    readPassword(guess);
    
    if (checkPassword(password, guess, feedback)) break;

    showFeedback(feedback);
  }

  if (i == TRIES)
  {
    loser();
  }
  else
  {
    winner();
  }

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
