#include <stdio.h>
#include <stdlib.h>

void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);

int main(){

    printf("Enter the size of the array: ");

    int n;
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);

    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i < n;i++){
        scanf("%d", &arr[i]);
    }

    // Sorting
    mergesort(arr, 0, n-1);

    float median;
    if (n%2 == 0) median = (arr[n/2]+arr[n/2-1])/2.;
    else median = arr[n/2];

    printf("The median of array is: %.2f\n", median);

    return 0;
}

void mergesort(int a[],int i,int j)
{
	int mid;

	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);		//left recursion
		mergesort(a,mid+1,j);	//right recursion
		merge(a,i,mid,mid+1,j);	//merging of two sorted sub-arrays
	}
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[50];	//array used for merging
	int i,j,k;
	i=i1;	//beginning of the first list
	j=i2;	//beginning of the second list
	k=0;

	while(i<=j1 && j<=j2)	//while elements in both lists
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}

	while(i<=j1)	//copy remaining elements of the first list
		temp[k++]=a[i++];

	while(j<=j2)	//copy remaining elements of the second list
		temp[k++]=a[j++];

	//Transfer elements from temp[] back to a[]
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}
