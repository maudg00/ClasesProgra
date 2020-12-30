#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define true 1
#define false 0
void pedirPalabra(char * string1);
int obtenerCoeficientes(char* string1, float * a, float* b, char* simbolo);
void calcularResultado(float a, float b, char simbolo, float *resultado);
int main()
{
    char string1[100];
    float a,b, resultado;
    char simbolo;
    int bandera;
    pedirPalabra(string1);
    bandera=obtenerCoeficientes(string1, &a, &b, &simbolo);
    if(bandera==0)
    {
        printf("Me ingresaste algo mal.\n");
        return 1;
    }
    calcularResultado(a,b,simbolo,&resultado);
}
void pedirPalabra(char * string1)
{
    printf("Dame tu operacion de la forma a+b, a-b, a/b o a*b: ");
    fgets(string1, 100, stdin);
    string1[strlen(string1)-1]=0;
}
int obtenerCoeficientes(char* string1, float * a, float* b, char* simbolo)
{
    int valoresLeidos=0;
    valoresLeidos=sscanf(string1, "%f%c%f",a,simbolo,b);
    if(valoresLeidos!=3)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void calcularResultado(float a, float b, char simbolo, float *resultado)
{
    if(simbolo=='+')
    {
        *resultado=a+b;
    }
    if(simbolo=='-')
    {
        *resultado=a-b;
    }
    if(simbolo=='/')
    {
        *resultado=a/b;
    }
    if(simbolo=='*')
    {
        *resultado=a*b;
    }
    printf("El resultado es: %f\n", *resultado);
}