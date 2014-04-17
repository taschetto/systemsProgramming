#include <stdio.h>
#include "mastermind.h"

int main()
{
  byte password[PASSWORD_SIZE] = { 0 };
  readPassword(password);

  byte guess[PASSWORD_SIZE] = { 0 };
  char feedback[PASSWORD_SIZE] = { '?' };
  int i;
  for (i = 0; i < TRIES; i++)
  {
    printf(" -- Try #%d -- \n", i + 1);
    readPassword(guess);
    if (check(password, guess, feedback))
    {
      break;
    }
    else
    {
      int j = 0;
      for (j = 0; j < PASSWORD_SIZE; j++)
      {
        printf("%c", feedback[j]);
      }
      printf("\n");
    }
  }

  if (i == TRIES)
  {
    printf("Você perdeu!\n");
  }
  else
  {
    printf("Você ganhou!\n");
  }

  return 0;
}
