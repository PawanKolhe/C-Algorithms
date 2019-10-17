#include <stdio.h>
#include <stdlib.h>

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += arr[i];
    }

    float mean = (float)sum/n;

    printf("mean: %.2f\n", mean);

    return 0;
}
