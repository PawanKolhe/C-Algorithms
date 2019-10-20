#include <stdio.h>

/**
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n => n/2 (n is even)
 * n => 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 => 40 => 20 => 10 => 5 => 16 => 8 => 4 => 2 => 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains
 * 10 terms. Although it has not been proved yet (Collatz Problem), it is thought
 * that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */
int main()
{
    int longest = 0;
    int terms = 0;
    int i;
    unsigned long j;

    for (i = 1; i <= 1000000; i++)
    {
        j = (unsigned long)i;
        int this_terms = 1;

        while (j != 1)
        {
            this_terms++;

            if (this_terms > terms)
            {
                terms = this_terms;
                longest = i;
            }

            j = (j % 2 == 0)
                    ? j / 2
                    : 3 * j + 1;
        }
    }

    printf("number under 1,000,000 producing the longest chain: %d (%d terms)\n", longest, terms);
    return 0;
}