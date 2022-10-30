#include <stdio.h>

void twoSmallest(int *array, int size, int *smallest, int *secondSmallest)
{
    if (array[0] < array[1]) {
        *smallest = array[0];
        *secondSmallest = array[1];
    } else {
        *smallest = array[1];
        *secondSmallest = array[0];
    }
    for (int i = 2; i < size; i++) {
        if (array[i] < *smallest) {
            *secondSmallest = *smallest;
            *smallest = array[i];
        } else if (array[i] < *secondSmallest) {
            *secondSmallest = array[i];
        }
    }
}

int main(void)
{
    #define SIZE 10

    int array[SIZE] = {0};
    int i = 0;
    int smallest = 0;
    int secondSmallest = 0;

    for (i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    twoSmallest(array, SIZE, &smallest, &secondSmallest);

    printf("Smallest element in array: %d\n", smallest);

    printf("Second smallest element in array: %d\n", secondSmallest);

    return 0;
}
