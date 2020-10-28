#include <stdio.h>
#include <stdlib.h>

/*
    Compute factorial using iteration

    e.g Factorial of 3:
    3 * 2 * 1;
*/

int factorial(int n){
    unsigned long fact = 1;
    if (n < 0){
        printf("Factorial of a negative number doesn't exist.");
        exit(0);
    }else {
        for (int i = 1; i <= n; ++i) {
            fact *= i;
        }
        return fact;
    }
}

int main() {
    int n;
    unsigned long x;
    
    printf("Enter an integer: ");
    scanf("%d", &n);
    x = factorial(n);
    printf("Factorial of %d = %lu", n, x);
    

    return 0;
}