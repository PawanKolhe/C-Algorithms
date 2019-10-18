#include <stdio.h>

int main(int argc, char *argv[]) {
   long int a1,l1,a2,l2;
   long int c,x,y;
   long int w;
   long int tv,td,g,mitadVida,mitadAtaque,otroVida,otroAtack;
   
   scanf("%ld %ld %ld %ld",&a1,&l1,&a2,&l2);
   scanf("%ld %ld %ld",&c,&x,&y);
   tv=l1+c*y;
   td=a1+c*x;
  //probamos a repartir las moenedas en mitad si el residuo es cero y si no la repartimos 
  ((c%2)==0)?(mitadVida=(c*(0.5))*y+l1 , mitadAtaque=(c*(0.5))*x+a1):((c%3)==0?(mitadVida=(int)((c*0.33333333333)*y)+l1, mitadAtaque=(int)((c*0.666666667)*x)+a1):(mitadVida=l1,mitadAtaque=a1));
  //(mitadVida==l1)?(mitadVida):mitadVida
    
    (x<y)?(otroAtack=c*y+a1, otroVida=l1):(otroVida=c*y+l1, otroAtack=a1);
   ((1.0*l2/a1)<=(1.0*tv/a2))?g=1:((1.0*l2/td)<=(1.0*l1/a2)?(g=1):((1.0*l2/mitadAtaque)<=(1.0*mitadVida/a2)?(g=1):((1.0*l2/a1)<=(1.0*otroVida/a2)?(g=1):((1.0*l2/otroAtack)<=(1.0*l1/a2)?(g=1):(g=0)))));
   (1.0*l2/a1)<=(1.0*l1/a2)?g=1:g;
   (g==0)?(w=0):(w=1);
   
   
   printf("%ld",w);
   
    return 0;
}