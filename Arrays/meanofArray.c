#include<stdio.h>

int main()
{
	int N;
	printf("enter the size of the array: ");
	scanf("%d",&N);
	int i;
	long int sum = 0;
	for(i=0;i<N;i++)
	{
		int x;
		scanf("%d",&x);
		sum+=x;
	}
	float mean = sum/N;
	printf("%f is the mean of the array",mean);
}
