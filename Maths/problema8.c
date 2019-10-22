#include <stdio.h>

int main(int argc, char *argv[]) {
   long int n,r,k,min,max;
   scanf("%ld %ld %ld ",&n , &r, &k);
   (k<=r)?(min=r-k):(min=k-r);
   
   
   //((k<=r))?(max=(n-k)+1):(max=r+k);
   
   ((n-r)>k)?(max=r+k):(max=n-(k-(n-r)));
  
    printf("%ld %ld",min, max);
   
    return 0;
}