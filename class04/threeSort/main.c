#include <stdio.h>

void sort2(int* a, int* b);
void sort3(int* a, int* b, int* c);

int main()
{
  int a, b, c;
  printf("A: ");
  scanf("%d", &a);
  printf("B: ");
  scanf("%d", &b);
  printf("C: ");
  scanf("%d", &c);
  sort3(&a, &b, &c);
  printf("%d %d %d\n", a, b, c);
  return 0;
}

void sort2(int* a, int* b)
{
  if (*a > *b)
  {
    int swap = *b;
    *b = *a;
    *a = swap;
  }
}

void sort3(int* a, int* b, int* c)
{
  sort2(a, b);
  sort2(b, c);
  sort2(a, b);
}
