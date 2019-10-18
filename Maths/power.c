#include <stdio.h>
#include <math.h>
float funPow(float a, float b);
int main(int argc, char*argv[]){

    float a,b, res=0;
    printf("Enter the number\n");
    scanf("%f",&a);
    printf("Enter the power\n");
    scanf("%f",&b);
    res = funPow(a,b);
    printf("The number %f at pow %f is %f: ",a,b,res);

}

float funPow(float a, float b){
    return pow(a,b);
}
