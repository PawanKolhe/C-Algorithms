
#include <stdio.h>

int main()
{
    int j, num, isP;
    isP = 1; 

    printf("Enter any number to check prime: ");
    scanf("%d", &num);

    for(j=2; j<=num/2; j++)
    {
        if(num%j==0)
  	{
            isP = 0;
            break;
        }
    }

    if(isP == 1)
    {
        printf("%d is prime number", num);
    }
    else
    {
        printf("%d is composite number", num);
    }

    return 0;
}