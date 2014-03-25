#include <stdio.h>

void squares(); // prototype

int main()
{
  squares(); // function call
}

void squares() // no return value/params
{ // function body
  int k;
  for (k=1; k<=10; k++)
    printf("%d - %d\n", k, k*k);
}
