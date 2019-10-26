#include<stdio.h>
#include<stdlib.h>

#define Ndigits 8

int CheckPalindrome(int num)
{
    int i=0,n1=0,n2=num;
    while(num!=0)
    {
        n1=n1*10+num%10;
        num=num/10;
    }
    if(n1==n2)
        return 1;
    return 0;

}

void main()
{
    int mn=900,i,j,num;
    for(mn=900;mn>=0;mn=mn-100)
    {
        for(i=99;i>=0;i--)
        {
            for(j=i;j>=0;j--)
            {
                num=mn*mn+mn*(i+j)+i*j;
                if(CheckPalindrome(num))
                {
                    printf("The Largest Possible Palindrome is %d \n",num);
                    printf("The two multiples are %d and %d.\n",mn+i,mn+j);
                    exit(0);
                }
            }
        }
    }
}



