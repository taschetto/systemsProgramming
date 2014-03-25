#include <stdio.h>

void functionLargSmall(int* larg, int* small);

void functionLargSmall(int* larg, int* small) {
    int num, i;
    for(i=0; i<10; i++) {
        printf("Type a number:");
        scanf("%d", &num);
        if (i==0) *larg = *small = num;
        else {
            if(num>*larg) *larg = num;
            else if(num<*small) *small = num;
        }
    }
}

int main() {
    int largest, smallest;
    functionLargSmall(&largest, &smallest);
    printf("Largest: %d, smallest: %d\n", largest,
       smallest);
}

