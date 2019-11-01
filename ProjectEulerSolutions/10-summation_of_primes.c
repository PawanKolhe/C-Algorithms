#include <stdio.h>

/**
 * Project Euler Problem 10
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 *
 * This implementation takes an input value and returns the correct value
 * for values over 5.
 */
int main()
{
    double sum = 5;
    int count, count2, prime, limit;
    printf("\n\nEnter upper limit : ");
    scanf("%d",&limit);
    getchar();

    for(count = 5; count < limit; count += 2)
    {
        prime = 0;
        for(count2 = 3 ;count2 < (count / count2 + 1); count2 += 2)
        {
            if(count % count2 == 0)
            {
                prime = 1;
                break;
            }
        }
        if(prime == 0) {
            sum += count;
        }
    }

    printf("\nThe sum of all prime numbers below %d is %.0f\n", limit, sum);
    return 0;
}