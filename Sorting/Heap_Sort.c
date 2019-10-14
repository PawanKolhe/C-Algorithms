# include <stdio.h>

void heap_sort(int[], int);
 
int main(){
	int a[50], n, i;
	printf("How many elements? ");
	scanf("%d", &n);
	printf("\nEnter array elements: ");
	
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	heap_sort(a, n);
	printf("\nArray after sorting: ");
	
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	
	printf("\n");
	return 0;		
}
 
void heap_sort(int a[], int size){
	int i = size / 2, root, child, t;
	while(1){
		if(i > 0){
			i--;
			t = a[i];
		} else{
			size--;
			if(size <= 0) return;
			t = a[size];
			a[size] = a[0];
		}
		root = i;
		child = i * 2 + 1;
		while(child < size){
			if((child + 1 < size) && (a[child + 1] > a[child]))
				child++;
			if(a[child] > t){
				a[root] = a[child];
				root = child;
				child = root * 2 + 1;
			} else
				break;
		}
		a[root] = t;
	}
}
