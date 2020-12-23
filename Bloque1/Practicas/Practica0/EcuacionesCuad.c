#include <stdio.h>
#include <math.h>
void PedirABC(int *a, int *b, int *c);
void CalcularRaices(int a, int b, int c, float *raiz1, float *raiz2);
void DesplegarRaices(float raiz1, float raiz2);
//main
int main()
{
    int a=0, b=0, c=0;
    float raiz1=0, raiz2=0;
    PedirABC(&a, &b, &c);
    CalcularRaices(a, b, c, &raiz1, &raiz2);
    DesplegarRaices(raiz1, raiz2);
}
//funciones
void PedirABC(int *a, int *b, int *c)
{
   while (*a<1)
   {
        printf("Dame a: ");
        scanf("%d", a);
        if (*a<1)
        {
            printf("Numero no valido. \n");
        }
   }
   while (*b<1)
   {
        printf("Dame b: ");
        scanf("%d", b);
        if (*b<1)
        {
            printf("Numero no valido. \n");
        }
   }
   while (*c<1)
   {
        printf("Dame c: ");
        scanf("%d", c);
        if (*c<1)
        {
            printf("Numero no valido. \n");
        }
   }
}
void CalcularRaices(int a, int b, int c, float *raiz1, float *raiz2)
{
    *raiz1=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
    *raiz2=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);
}
void DesplegarRaices(float raiz1, float raiz2)
{
    printf("Tus raices son: %f, %f.", raiz1, raiz2);
}