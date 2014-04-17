#include "mastermind.h"

int main()
{
  char password[PASSWORD_SIZE + 1] = "1234";
  char guess[PASSWORD_SIZE + 1] = "0000";
  char feedback[PASSWORD_SIZE + 1] = "????";

  init();
  readPassword(password);

  int i = 0;

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
