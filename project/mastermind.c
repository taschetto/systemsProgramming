#include <stdio.h>
#include "mastermind.h"

void readPassword(byte password[])
{
  int i;
  for (i = 0; i < PASSWORD_SIZE; i++)
  {
    printf("password[%d]: ", i);
    scanf(" %c", &password[i]);
  }
}

int check(byte password[], byte guess[], char feedback[])
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
