#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>
#define true 1
#define false 0

void pedirPalabra(char *str);
void calcularResultado(char *str, float a, float b, float c, float *x1, float *x2);
int obtenerCoeficientes(char *str, float *a, float *b, float *c);

int main()
{
    char str1[100];
    float a,b,c, x1,x2;
    int flag=0;

    pedirPalabra(str1);
    flag = obtenerCoeficientes(str1,&a,&b,&c);
    if(flag==0)
    {
        printf("Los datos fueron ingresados incorrectamente. Intente de nuevo.\n");
        return 1;
    }
    calcularResultado(str1,a,b,c,&x1,&x2);
    return 0;
}

void pedirPalabra(char *str)
{
    printf("Introduzca los coeficientes de la forma siguiente:\n"
        "ax2+bx+c\n");
    fgets(str, 100, stdin);
    str[strlen(str)-1]=0;
}

int obtenerCoeficientes(char *str, float *a, float *b, float *c)
{
    int valoresLeidos = sscanf(str,"%fx2+%fx+%f",a,b,c); 
    /* Puede introducirse cualquier serie de símbolos. de forma general los 
    símbolos intermedios pueden ponerse como %c */
    if(valoresLeidos!=3) { return false; }
    else { return true; }
}

void calcularResultado(char *str, float a, float b, float c, float *x1, float *x2)
{
    *x1 = (-b+sqrt(b*b-4*a*c))/2;
    *x2 = (-b-sqrt(b*b-4*a*c))/2;
    printf("Las raíces son las siguientes:\nx1 = %f\nx2 = %f",*x1,*x2);
}