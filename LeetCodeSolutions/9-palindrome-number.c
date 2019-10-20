#include<stdio.h>
#include<limits.h>

int isPalindrome(int x){
    int ReversedInteger=0,remainder,OriginalInteger;
    long num;

    OriginalInteger = x;

    while(x != 0){

        remainder = x%10;

        //check for integer overflow
        if(num*10 + remainder>INT_MAX||num*10 + remainder<INT_MIN){
            ReversedInteger = 0;
            break;
        }
        else{
            ReversedInteger = ReversedInteger*10 + remainder;
            num = ReversedInteger;
        }
        x /= 10;
    }
    if(OriginalInteger == ReversedInteger && OriginalInteger >= 0 )
        return 1;
    else
        return 0;
}

int main(){

    int inputNum;
    printf("Input: ");
    scanf("%d",&inputNum);

    if(isPalindrome(inputNum)==1)
      printf("Output: %d is a Palindrome Number",inputNum);
    else
      printf("Output: %d is not a Palindrome Number",inputNum);

    return 0;
}
