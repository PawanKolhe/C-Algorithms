#include <stdio.h>

int interpolationSearch(int arr[], int n, int x){
    int low = 0, high = n-1;
    //For sorted array

    while (low <= high && x >= arr[low] && x <= arr[high]){
        if (low == high){
            if (x == arr[low]){
                return low;
            }
            return -1;
        }

        int pos = low + (((double)(high-low)/(arr[high]-arr[low]))*(x-arr[low]));
        if (x == arr[pos]){
            return pos;
        }
        if (x > arr[pos]){
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
    if (-1 != index) printf("Element found at index %d", index); 
    else printf("Element not found."); 
    return 0; 
}
