#include <stdio.h>

int linearSearch(int arr[], int x, int n){
    int i;
    for (i=0;i<n;i++){
        if (arr[i]==x){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr = {2,35,54,6,89,45,65};
    int x = 6;
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = linearSearch(arr,x,n);
    printf("%d", i);
}