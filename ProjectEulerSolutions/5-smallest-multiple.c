#include <stdio.h>
#include <stdlib.h>

/*
Find minimum number evenly divisible with every number from [1..20]
*/
int main()
{
    long num = 20; int found = 0,i,divisible = 1;
    while (!found){

        for(i = 1; i <= 20 && divisible; i++){
            if (num % i != 0) divisible = 0;
        }
        if (divisible){
            found = divisible;
        } else{

         num++;
         divisible = 1;

        }
    }
    printf("%ld\n",num);
    return 0;
}
