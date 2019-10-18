#include <stdio.h>
#include <stdlib.h>
/*

Find 10001. prime number ---> regard 2 as first prime

*/

int isPrime(int x){

    int i,prime = 1;
    for (i = 2; i < x && prime; i++)
        if (!(x%i)) prime = 0;
    return prime;



}
int findPrime(){
    int num = 2, primeNum = 0;
    while (primeNum < 10001){

        if (isPrime(num)) primeNum++;
        num++;

    }
    return --num;
}

int main()
{
    printf("Result = %d\n",findPrime());
    return 0;
}
