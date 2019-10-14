# include <stdio.h>
# include <stdlib.h>

void radix_sort(int[], int);
 
int main(){
	int a[50], n, i;
	printf("How many elements? ");
	scanf("%d", &n);
	printf("\nEnter array elements: ");
	
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	radix_sort(a, n);
	printf("\nArray after sorting: ");
	
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	
	printf("\n");
	return 0;		
}
 
void radix_sort(int a[], int size){
	int i;
	int *b;
	int bigger = a[0];
	int exp = 1;

	b = (int *)calloc(size, sizeof(int));

	for(i = 0; i < size; i++){
		if(a[i] > bigger) bigger = a[i];
	}

	while(bigger/exp > 0){
		int bucket[10] = { 0 };
		for(i = 0; i < size; i++) bucket[(a[i]/exp) % 10]++;
		for(i = 1; i < 10; i++) bucket[i] += bucket[i - 1];
		for(i = size - 1; i>= 0; i--) b[--bucket[(a[i] / exp) % 10]] = a[i];
		for(i = 0; i < size; i++) a[i] = b[i];
		exp *= 10;
	}
	free(b);
}
