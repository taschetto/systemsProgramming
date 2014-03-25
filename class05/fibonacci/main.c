#include <stdio.h>

int fibo(int n)
{
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibo(n - 1) + fibo(n - 2);
}

int main()
{
  int k;
  for (k = 0; k < 32; k++)
  {
    printf("%d %10d\n", k, fibo(k));
  }

  return 0;
}
