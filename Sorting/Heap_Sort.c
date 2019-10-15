#include <stdio.h>

void heapSort(int *unsorted, int n);

void heapify(int *unsorted, int index, int heap_size) {
    int temp;
    int largest = index;
    int left_index = 2 * index;
    int right_index = 2 * index + 1;

    if (left_index < heap_size && *(unsorted + left_index) > *(unsorted + largest)) {
        largest = left_index;
    }

    if (right_index < heap_size && *(unsorted + right_index) > *(unsorted + largest)) {
        largest = right_index;
    }

    if (largest != index) {
        temp = *(unsorted + largest);
        *(unsorted + largest) = *(unsorted + index);
        *(unsorted + index) = temp;
        heapify(unsorted, largest, heap_size);
    }
}

void heapSort(int *unsorted, int n) {
    int temp;
    for (int i = n / 2 - 1; i > -1; i--) {
        heapify(unsorted, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        temp = *(unsorted);
        *(unsorted) = *(unsorted + i);
        *(unsorted + i) = temp;
        heapify(unsorted, 0, i);
    }
}

int main() {
    int a[30],n,i;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter array elements:");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    heapSort(a, i);

    printf("\nSorted array is :");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
