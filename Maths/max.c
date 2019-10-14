#include <stdio.h>
 
int main()
{
  int arr[100], max, size, i, loc;
 
  printf("Enter the size of array\n");
  scanf("%d", &size);
  printf("Enter %d integers\n", size);
  for (i = 0; i < size; i++)
    scanf("%d", &arr[i]);
  max = arr[0];
  loc = 1;
  for (i = 1; i < size; i++)
  {
    if (arr[i] > max)
    {
       max  = arr[i];
       loc = i+1;
    }
  }
  printf("Maximum element is %d and it is at position %d\n", max, loc);
  return 0;
}