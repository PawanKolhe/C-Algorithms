#include<stdio.h> 
int interpolationSearch(int arr[], int n, int x) 
{ 
    
    int lo = 0, hi = (n - 1); 
 
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) 
    { 
        if (lo == hi){ 
            if (arr[lo] == x) return lo; 
            return -1; 
        } 
    int pos = lo + (((double)(hi-lo) / (arr[hi]-arr[lo]))*(x - arr[lo])); 
  
       
        if (arr[pos] == x) 
            return pos; 
  
        if (arr[pos] < x) 
            lo = pos + 1; 
  
        else
            hi = pos - 1; 
    } 
    return -1; 
} 
int main(){
     int arr[] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
     int n = 10;
     int key = 7;
     int idx = interpolationSearch(arr,n,key);      
     if(idx !=-1)
     printf("Key is Found at index %d\n", idx);
     else
     printf("Key is Not Found\n");     
}