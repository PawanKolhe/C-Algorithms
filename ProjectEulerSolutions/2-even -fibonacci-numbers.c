#include <stdio.h>
/*

Task:Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2,
the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million,
find the sum of the even-valued terms.

*/

long long even_fibonacci_sum(){
    int first_f = 1;
    int second_f = 2;

    int next_f;
    long long sum = second_f;
    while(1){
        next_f = first_f + second_f;
        if(next_f > 4000000)
            break;
        first_f = second_f;
        second_f = next_f;
        //equivalent to if (next_f % 2 == 0) sum += next_f
        sum += (next_f % 2 == 0) * next_f;
    }
    return sum;
    //4613732
}

int main(){
    printf("%ld\n", even_fibonacci_sum());
    return 0;
}