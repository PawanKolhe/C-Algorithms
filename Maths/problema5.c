#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned long int r,n,m,x,y;
    scanf("%ld %ld %ld %ld", &n, &m, &x, &y);
    r = m/x>=n?n:((y*n+m)/(x+y));
    printf("%ld", r);

    return 0;
}