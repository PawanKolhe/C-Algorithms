#include <stdio.h>

int largest(int *array, int size)
{
    int largest = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }
    return largest;
}

int main(void)
{
    #define SIZE 10

    int array[SIZE] = {0};
    int i = 0;

    for (i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    printf("Largest element in array: %d\n", largest(array, SIZE));

    return 0;
}
