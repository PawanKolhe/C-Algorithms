#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Target value = (sum(1...100))^2 - sum(1^2..100^2)

*/
int main()
{
    int suma_squared = 0,squared_suma = 0,i;
    for (i = 1; i <= 100; i++){

        suma_squared += i;
        squared_suma += i*i;

    }

    printf("%d\n",abs(suma_squared*suma_squared-squared_suma));
    return 0;
}
