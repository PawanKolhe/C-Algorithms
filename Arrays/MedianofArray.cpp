#include<stdio.h>
#include<stdlib.h>

int comparator(const void *p, const void *q){
	int l = *(const int *)p; 
    int r = *(const int *)q;
    
    return l>r;
}

int main()
{
	int N;
	printf("Enter the size of the array: ");
	scanf("%d",&N);
	
	int arr[N];
	int i;
	for(i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	qsort((void*)arr, N, sizeof(arr[0]), comparator); 
	
	printf("%f is the median of the array",(float)(arr[(N-1)/2]+arr[(N/2)])/2);
}
