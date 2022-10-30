#include <stdio.h>

void twoLargest(int *array, int size, int *largest, int *secondLargest)
{
    if (array[0] > array[1]) {
        *largest = array[0];
        *secondLargest = array[1];
    } else {
        *largest = array[1];
        *secondLargest = array[0];
    }
    for (int i = 2; i < size; i++) {
        if (array[i] > *largest) {
            *secondLargest = *largest;
            *largest = array[i];
        } else if (array[i] > *secondLargest) {
            *secondLargest = array[i];
        }
    }
}

int main(void)
{
    #define SIZE 10

    int array[SIZE] = {0};
    int i = 0;
    int largest = 0;
    int secondLargest = 0;

    for (i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    twoLargest(array, SIZE, &largest, &secondLargest);

    printf("Largest element in array: %d\n", largest);

    printf("Second largest element in array: %d\n", secondLargest);

    return 0;
}
