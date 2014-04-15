#include <stdio.h>

#define TRIES 10

int main()
{
  setPassword();
  
  int i;
  for (i = 0; i < TRIES; i++)
  {
    tryPassword();
    if (checkPassword())
    {
      break;
    } 
  }

  return 0;
}
