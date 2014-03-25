#include <stdio.h>

int main()
{
  int amount = 0;

  while (amount <= 0)
  {
    printf("Amount (R$): ");
    scanf("%d", &amount); 
  }

  int n100, n50, n10, n5, n1;

  n100 = amount / 100;
  n50  = amount % 100 / 50;
  n10  = amount % 50 / 10;
  n5   = amount % 10 / 5;
  n1   = amount % 5;

  printf("R$ 100: %d\n R$ 50: %d\n R$ 10: %d\n  R$ 5: %d\n  R$ 1: %d\n", n100, n50, n10, n5, n1);

  return 0;
}

