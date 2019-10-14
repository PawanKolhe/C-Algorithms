#include <stdio.h>
#define MAX 100005

long long int arr[MAX];

double meanOfArr(long long int A[], long long int N) {
    double m = 0;
    for(long long int i = 0 ; i < N ; i++) {
        m += A[i];
    }
    m /= N;
    return m;
}

int main() {
    long long int N;
    int f = 0;
    printf("\nEnter number of elements of array: ");
    f = scanf("%lld", &N);
    if(!f)
        return -1;
    printf("\nEnter elements of array: ");
    for(long long int i = 0 ; i < N ; i++) {
        scanf("%lld", &arr[i]);
    }
    double mean = meanOfArr(arr, N);
    printf("\nMean of the given array = %0.2lf", mean);
    return 0;
}
