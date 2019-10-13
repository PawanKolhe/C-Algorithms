
#include <stdio.h>
#include<stdlib.h>

int arr[10];

int main()
{
    int size, tmp;
    
     printf("\nSize of the array: ");
     scanf(" %d", &size);
     
     printf("\nEnter element: ");
        for(int i = 0; i < size; i++)
            scanf(" %d",&arr[i]);
    
     printf("\nAfter Bubble sorting: ");
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(arr[i] < arr[j])
                {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        
        for(int i = 0; i < size; i++)
             printf(" %d",arr[i]);
    
    return 0;
}
