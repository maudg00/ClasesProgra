#include <stdio.h>
#include <stdlib.h>
void pedirTamano(int *tamano, int **Arreglo);
void pedirNumeros(int *Arreglo, int tamano);
void imprimirArreglo(int *Arreglo, int tamano);
int main()
{
    int *Arreglo, tamano;
    Arreglo=NULL;
    tamano=0;
    pedirTamano(&tamano, &Arreglo);
    pedirNumeros(Arreglo, tamano);
    imprimirArreglo(Arreglo, tamano);
    free(Arreglo);
}
void pedirTamano(int *tamano, int **Arreglo)
{
    do
    {
       printf("Dame el tamano del arreglo maximo 1000 elementos.\n");
       scanf("%d", tamano);
       fflush(stdin);
       if((*tamano<0 && *tamano>1000))
       {
           printf("ERROR: tamano invalido.\n");
       }
    } 
    while ((*tamano<0 && *tamano>1000));
    *Arreglo=malloc((*tamano)*sizeof(int));
}
void pedirNumeros(int *Arreglo, int tamano)
{
    int i;
    for(i=0; i<tamano; i++)
    {
        printf("Dame el elemento %d de tu arreglo: ", i);
        scanf("%d", &Arreglo[i]);
        fflush(stdin);
    }
}
void imprimirArreglo(int *Arreglo, int tamano)
{
    int i;
    for(i=0; i<tamano; i++)
    {
        printf("El elemento %d de tu arreglo es %d\n", i, *(Arreglo+i));
    }
}