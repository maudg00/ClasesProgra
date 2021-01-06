#include "utilities.h"
void pedirString(char *string, float *numero);
void validarNumero(float numero, int *numeroEntero);
void factorialNumero(int numero);
int main()
{
    char string[10];
    float numero;
    int numeroEntero;
    pedirString(string, &numero);
    validarNumero(numero, &numeroEntero);
    factorialNumero(numeroEntero);
}
void pedirString(char *string, float *numero)
{
    printf("Dame un numero entero positivo: ");
    fgets(string, 10, stdin);
    utilitiesQuitarEnterString(string);
    sscanf(string, "%f", numero);
}
void validarNumero(float numero, int *numeroEntero)
{
    int bandera;
    bandera=utilitiesValidarEntero(numero);
    while(bandera==FALSE)
    {
        printf("Error: tu numero no es entero. Vuelve a intentar.\n");
        numero=utilitiesPedirFlotante();
        bandera=utilitiesValidarEntero(numero);
    }
    *numeroEntero=(int)numero;
    bandera=utilitiesValidarEnteroPositivo(*numeroEntero);
    while(bandera==FALSE)
    {
        printf("Error: tu numero no es positivo. Vuelve a intentar.\n");
        *numeroEntero=utilitiesPedirEntero();
        bandera=utilitiesValidarEnteroPositivo(*numeroEntero);
    }
}
void factorialNumero(int numero)
{
    int i;
    long factorial=1;
    for(i=numero; i>=1; i--)
    {
        factorial=factorial*i;
    }
    printf("El factorial es %ld.\n", factorial);
}