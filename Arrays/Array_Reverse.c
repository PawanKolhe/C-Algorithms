#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of elements in array\n");
    scanf("%d", &n);

    int a[n];
    printf("Enter array elements\n");

    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    // swap array elements in one array with math!

    for(int i=0, c=n-1; i<n/2; i++, c--){
                              // consider a = 2 , b = 3
        a[i] += a[c];         //  a = a + b -> a = 5
        a[c] = a[i] - a[c];   //  b = a - b -> b = 2
        a[i] -= a[c];         //  a = a - b -> a = 3
    }

    printf("Reverse array is\n");

    for(int i=0; i<n; i++)
        printf("%d\n", a[i]);

    return 0;
}
