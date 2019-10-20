#include<stdio.h>
#include<limits.h>

int reverse(int x){

    int ReversedInteger=0,remainder;
    long num;

    while(x != 0){

        remainder = x%10;

        //check for integer overflow
        if(num*10 + remainder>INT_MAX|num*10 + remainder<INT_MIN){
            ReversedInteger = 0;
            break;
        }
        else{
            ReversedInteger = ReversedInteger*10 + remainder;
            num = ReversedInteger;
        }
        x /= 10;
    }
    return ReversedInteger;
}

int main(){

    int OriginalInteger;
    printf("Input: ");
    scanf("%d",&OriginalInteger);

    printf("Output: %d",reverse(OriginalInteger));

    return 0;
}
