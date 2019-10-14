#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return (a>b)?a:b;
}

int main(){

    printf("Enter the array size: ");

    int n;
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);

    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i < n;i++){
        scanf("%d", &arr[i]);
    }

    int a = arr[0];
    int b = arr[1];
    int first = max(a, b);
    int second = a+b-first;

    for(int i = 2;i < n;i++){
        if (arr[i] > first){
            second = first;
            first = arr[i];
        }
        else second = max(second, arr[i]);
    }

    printf("First max: %d\nSecond max: %d\n", first, second);

    return 0;
}
