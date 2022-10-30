#include <stdio.h>

int sum(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int main(void)
{
    #define SIZE 10

    int array[SIZE] = {0};
    int i = 0;

    for (i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    printf("Sum of elements in array: %d\n", sum(array, SIZE));

    return 0;
}
