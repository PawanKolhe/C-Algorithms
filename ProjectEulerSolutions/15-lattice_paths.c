#include <stdio.h>
#define MATRIX_SIZE 21

/**
 * Starting in the top left corner of a 2×2 grid, and only being able to move to the
 * right and down, there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 */
int main() {
    long long int matrix[MATRIX_SIZE][MATRIX_SIZE];

    for(int i=0; i<=MATRIX_SIZE-1; i++)
    {
        matrix[MATRIX_SIZE-1][i]=1;
        matrix[i][MATRIX_SIZE-1]=1;
    }

    for(int i=MATRIX_SIZE-2; i>=0; i--) {
        for (int j = MATRIX_SIZE - 2; j >= 0; j--) {
            matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
        }
    }

    printf("Number of routes is: %lld\n", matrix[0][0]);
}