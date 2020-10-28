#include <stdio.h>
#include <stdlib.h>
/*
    Print the absolute difference between the sums of the matrix's  two diagonals

    Sample input:
    3
    11  2   4
    4   5   6
    10  8  -12

    Expected output:
    15

    Explanation:
    The first line of input contains a single integer, n , which represents
    the number of rows and columns in the matrix

    Each of the next (n) lines describes a row, arr[i], and consists of (n) 
    '/n' separated integers arr[i][j].

*/

int diagonalDifference(int n,int** arr){
    int primaryDiag[n]; 
    int secondaryDiag[n];

    // Get integers in primary diagonal
    for(int i = 0; i < n; i++){
        primaryDiag[i] = arr[i][i];
    }
    int i = 0;
    int j = n-1;

    // Get integers in secondary diagonal 
    while(i < n){
        secondaryDiag[i] = arr[i][j];
        i++;
        j--;
    }

    int mainSum = 0;
    int subSum = 0;

    // Sum primary diagonal
    for(int i = 0; i < n; i++){
        mainSum += primaryDiag[i];
    }

    // Sum secondary diagonal
    for(int i = 0; i < n; i++){
        subSum += secondaryDiag[i];
    }

    int diff = mainSum - subSum;

    if(diff < 0){ // If negative multiply by -1 to get absolute value
        diff *= -1 ;
    }

    return diff;
}

int main(){
    int n; // 
    scanf("%d",&n);

    // Initialize an array of pointers to represent matrix
    int** matrix = (int**) malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++){
        matrix[i] = (int *) malloc(n*sizeof(int*));
    }

    // Populate array with input
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            scanf("%d",&matrix[i][k]);
        }
    }

    int diff = diagonalDifference(n,matrix);

    // Print diff
    printf("diagonal difference = %d\n",diff);

    return 1;
}