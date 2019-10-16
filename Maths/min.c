#include <stdio.h>
 
int main()
{
  int arr[100], min, size, i, loc;
 
  printf("Enter the size of array\n");
  scanf("%d", &size);
  printf("Enter %d integers\n", size);
  for (i = 0; i < size; i++)
    scanf("%d", &arr[i]);
  min = arr[0];
  loc = 1;
  for (i = 1; i < size; i++)
  {
    if (arr[i] < min)
    {
       min  = arr[i];
       loc = i+1;
    }
  }
  printf("minimum element is %d and it is at position %d\n", min, loc);
  return 0;
}