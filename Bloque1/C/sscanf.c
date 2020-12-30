#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define true 1
#define false 0
void pedirPalabra(char * string1);
int obtenerCoeficientes(char* string1, float * a, float* b, float* c);
void calcularResultado(float a, float b, float c, float *x1, float *x2);
int main()
{
    char string1[100];
    float a,b,c,x1,x2;
    int bandera;
    pedirPalabra(string1);
    bandera=obtenerCoeficientes(string1, &a, &b, &c);
    if(bandera==0)
    {
        printf("Me ingresaste algo mal.\n");
        return 1;
    }
    calcularResultado(a,b,c,&x1,&x2);
}
void pedirPalabra(char * string1)
{
    printf("Dame tus coeficientes a, b, c de la forma ax2+bx+c: ");
    fgets(string1, 100, stdin);
    string1[strlen(string1)-1]=0;
}
int obtenerCoeficientes(char* string1, float * a, float* b, float* c)
{
    int valoresLeidos=0;
    valoresLeidos=sscanf(string1, "%fx2+%fx+%f", a,b,c);
    if(valoresLeidos!=3)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void calcularResultado(float a, float b, float c, float *x1, float *x2)
{
    *x1=-b+sqrt(pow(b,2)-4*a*c);
    *x1=*x1/2;
    *x2=-b-sqrt(pow(b,2)-4*a*c);
    *x2=*x2/2;
    printf("Los resultados son: %f y %f.\n", *x1, *x2);
}