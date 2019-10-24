#include <stdio.h>

#define MAXLEN 50

void counting_sort(int[], int, int);

int main()
{
	int input_array[MAXLEN], n, i, max = 0;
	printf("How many elements? ");
	scanf("%d",&n);
	printf("\nEnter input_arrayay elements: ");
	
	/* read all elements */
	for(i=0; i<n; i++) {
		scanf("%d", &input_array[i]);
		if (input_array[i] > max)
			max = input_array[i];
	}

	counting_sort(input_array, n, max);

	printf("\nArray after counting sort: ");	
	
	for(i=0; i<n; i++)
		printf("%d ",input_array[i]);
	
	printf("\n");
	return 0;		
}


void counting_sort(int input_array[], int n, int max)
{
	int counted_array[MAXLEN] = {0}, i, j, counter = 0;
	
	/* count the number of each elements occurance and save in counted_array */
	for (i = 0; i < n; ++i)
		counted_array[input_array[i]] = counted_array[input_array[i]] + 1;

	/* regenrate the array based on the counting */
	for (i = 0; i <= max; ++i)
		for (j = 1; j <= counted_array[i]; ++j) 
			input_array[counter++] = i;
}
