#include <stdio.h>

void multiply(int* x);

void multiply(int* x) {
    *x = *x * *x;
}

int main() {
    int t = 10;
    printf("address of t: %p\n", &t);
    multiply(&t);
    printf("%d\n", t); // output: 100
}
