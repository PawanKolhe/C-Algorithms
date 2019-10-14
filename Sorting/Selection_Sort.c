#include <stdio.h>

int main()  {
  int array[50], n, i, j, min_id, swap;

  printf("Enter the number of elements: \n");
  scanf("%d", &n);

  for (i = 0; i < n; i++);
  scanf("%d", &array[i]);

  for (i = 0; i < (n-1); i++) {
    min_id = i;
    for (j = i + 1; j < n; j++) {
      if (array[mid_id] > array[j])
        mid_id = j;  
    }
    if (mid_id != i)  {
      swap = array[i];
      array[i] = array[mid_id];
      array[mid_id] = swap;
    }


}

  printf("Sorted list in ascending order:\n");

  for (i = 0; i < n; i++)
    printf("%d\n", array[i]);
  return 0;


}
