#include <stdio.h>
#include <stdlib.h>

void sort2(int* x, int* y);
void sort3(int* a, int* b, int* c);

void sort2(int* x, int* y)
{
    if(*x > *y)
    {
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }
}

void sort3(int*a, int* b, int* c)
{
    // Manual bubble-sorting...
    sort2(a,b);
    sort2(b,c);
    sort2(a,b);
}

int main()
{
    int v1 = 10;
    int v2 = 5;
    int v3 = 1;
    sort3(&v1, &v2, &v3);
    printf("v1=%d, v2=%d, v3=%d\n", v1, v2, v3);
}
