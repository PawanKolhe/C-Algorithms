#include <stdio.h>

int interpolationSearch(int arr[], int n, int x){
    int low = 0, high = n-1;
    //For sorted array

    while (low <= high && x >= arr[low] && x <= arr[high]){
        if (lo == high){
            if arr[lo]==x{
                return low;
            }
            return -1;
        }

        int pos = low + (((double)(high-low)/(arr[high]-arr[low]))*(x-arr[low]));
        if arr[pos]==x{
            return pos;
        }
        if (arr[pos]<x){
            low = pos+1;
        }
        else {
            high = pos-1;
        }

    }

    return -1;

}

int main(){
    int arr[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 
                  24, 33, 35, 42, 47}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    int x = 18; // Element to be searched 
    int index = interpolationSearch(arr, n, x); 
  
    // If element was found 
    if (index != -1) 
        printf("Element found at index %d", index); 
    else
        printf("Element not found."); 
    return 0; 
}