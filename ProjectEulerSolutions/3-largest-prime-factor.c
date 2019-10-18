#include <stdio.h>
#include <stdlib.h>

/*

Find maximum prime factor of number num

*/
int isPrime(int x){

    int i,prime = 1;
    for (i = 2; i < x && prime; i++){
        if (!(x%i)) prime = 0;
    }
    return prime;
}

int main()
{
    long num = 600851475143;
    int max_prime = 0;

    int i = 3;
    while (num != 1){
        if (!(num % i) && isPrime(i)){
            num /= i;
            if (i > max_prime) max_prime = i;
        }
        i++;

    }
    printf("%d\n",max_prime);
    return 0;
}
