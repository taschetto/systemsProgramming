#include <stdio.h>
#include "lcd.h"
#include "mastermind.h"
#include "defines.h"

int main()
{
  init();

  char password[] = "1234";
  char guess[]    = "0000";
  char feedback[2];

  readPassword("Set password:", password);

  int win = 0, i;
  for (i = 0; i < TRIES; i++)
  {
    readPassword("Guess:", guess);
    
    if (checkPassword(password, guess, feedback)) { win = 1; break; }

    showFeedback(feedback);
  }

  if (win)
  {
    winner();
  }
  else
  {
    loser();
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
