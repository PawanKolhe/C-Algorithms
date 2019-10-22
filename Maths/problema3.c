#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[]){
    int a,b,res;
    scanf("%d %d", &a, &b);
    b=(int)sqrt(b);
    a=(int)sqrt(a-1);
    res=b-a;
    printf("%d",res);
    
}
