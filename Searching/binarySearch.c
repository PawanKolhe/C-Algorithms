#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int binarySearch(int value, int values[], int n);

int main (int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./binarySearch value\n");
        return 1;
    }
    
    int value = atoi(argv[1]);
    
    int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    if (binarySearch(value, array, ARRAY_SIZE))
    {
        printf("Found!\n");
        return 0;
    }
    else
    {
        printf("Not found!\n");
        return 2;
    }
    
    return 0;
}

int binarySearch(int needle, int values[], int size)
{
    int begin = 0;
    int end = size - 1;
    
    while(begin <= end)
    {
        int midpoint = (end + begin) / 2;
        
        if(needle == values[midpoint])
        {
            return 1;
        }
        
        if(needle < values[midpoint])
        {
            end = midpoint - 1;
        }
        if(needle > values[midpoint])
        {
            begin = midpoint + 1;
        }
    }
    return 0;
}
