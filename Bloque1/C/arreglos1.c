#include <stdio.h>
#include <stdlib.h>
void pedirNumeros(int arreglo[100], int *tamanio);
void desplegarNumeros(int arreglo[100], int tamanio);
int main()
{
    int arreglo[100], tamanio;
    pedirNumeros(arreglo, &tamanio);
    desplegarNumeros(arreglo, tamanio);
}
void pedirNumeros(int arreglo[100], int *tamanio)
{
    int i;
    do
    {
        printf("Dime cuantos numeros quieres ingresar, minimo 1 maximo 99: ");
        scanf("%d", tamanio);
        fflush(stdin);
        if(!(*tamanio>0 && *tamanio<100))
        {
            printf("ERROR: el tamanio debe de estar entre 1 y 99. Vuelve a intentar.\n");
        }
    } while (!(*tamanio>0 && *tamanio<100));
    
    printf("Te pedire %d numeros.\n", *tamanio);
    for(i=0; i<*tamanio; i++)
    {
        printf("Dame el elemento %d: ", i);
        scanf("%d", &arreglo[i]);
        fflush(stdin);
    }
}
void desplegarNumeros(int arreglo[100], int tamanio)
{
    int i;
    for(i=0; i<tamanio; i=i+1)
    {
        printf("El elemento %d es %d\n", i, arreglo[i]);
    }
}