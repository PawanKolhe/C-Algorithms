#include <stdio.h>

int main(int argc, char *argv[]) {
   long int a,b,s,n,r;
   scanf("%ld %ld %ld %ld", &a, &b, &s, &n);
   
   (n*b<=s || n*a<=s)?(r=(s-n*b)/(a-b)):(r=-1);
   printf("%ld", r);
    return 0;
}