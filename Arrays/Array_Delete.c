#include<stdio.h>
#define MAX 100

void delete(int arr[], int n, int index);
void display(int arr[], int n);

main(){
    int arr[MAX], i, n, item, pos;

    // Input
    printf("Enter size of array: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter position at which to insert: ");
    scanf("%d", &pos);
    if(pos <= n){
        delete(arr, n, pos-1);
        n--;
        printf("\nNew Array: ");
        display(arr, n);
    }
    else{
        printf("\nINVALID INPUT! Position more than size of array.");
    } 
}

void delete(int arr[], int n, int index){
    int i;
    for(i = index; i < n; i++){
        arr[i] = arr[i+1];
    }
}

void display(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}