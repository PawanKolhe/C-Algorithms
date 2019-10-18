#include <stdio.h>

int main(int argc, char *argv[]) {
   long int a,s,k,x,y,r;
   scanf("%ld %ld %ld %ld %ld", &a, &s, &k, &x, &y);
   r=(s+k*y-a)/(x+y);
   ((a+r*x)==(s+(k-r)*y))?r:(r=-1);
   
   printf("%ld", r);
    return 0;
}