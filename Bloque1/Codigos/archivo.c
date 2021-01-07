#include "utilities.h"
void EscArchivo(int *arreglo, int tam);
int main()
{
    int *arreglo, tam;
    arreglo=NULL;
    tam=utilitiesPedirEntero();
    utilitiesDeclararArregloEntero(&arreglo, tam);
    utilitiesLlenarArregloEnteros(arreglo, tam);
    EscArchivo(arreglo,tam);
}
void EscArchivo(int *arreglo, int tam)
{
    FILE *Archivo1;
    char nomArch[30];
    int i;
    printf("Dime el nombre del archivo: ");
    fgets(nomArch, 28, stdin);
    utilitiesQuitarEnterString(nomArch);
    Archivo1=fopen(nomArch, "wt");
    for (i = 0; i < tam; i++)
    {
        fprintf(Archivo1, "Numero %d: %d \n", i+1, arreglo[i]);
    }
    fclose(Archivo1);
}