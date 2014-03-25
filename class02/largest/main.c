#include <stdio.h>
#include <stdlib.h>

int largest(int arr[], int size);

int largest(int arr[], int size) {
    int m = arr[0];
    int i;
    for(i=1; i<size; i++)
    {
        printf("at %d\n", i); // this is just to check where it will crash if we send an incorrect size
        if(arr[i] > m) m = arr[i];
    }
    return m;
}

int main()
{
    int nums[10] = {5, 7, 80, 12, 30, 9, 4, 1, 10, 3};
    int larg = largest(nums, 10); // or 100, or 1000... the compiler won't check it, careful!
    printf("Largest: %d\n", larg);
    return 0;
}
