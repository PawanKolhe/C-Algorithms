#include <stdio.h>

int smallest(int *array, int size)
{
    int smallest = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }
    return smallest;
}

int main(void)
{
    #define SIZE 10

    int array[SIZE] = {0};
    int i = 0;

    for (i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    printf("Smallest element in array: %d\n", smallest(array, SIZE));

    return 0;
}
