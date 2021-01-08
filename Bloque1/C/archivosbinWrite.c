#include "utilities.h"
void Escribir_Archivo(int *Arreglo, int tamanio);
int main()
{
    int *Arreglo, tamanio;
    Arreglo=NULL;
    tamanio=utilitiesPedirEntero();
    utilitiesDeclararArregloEntero(&Arreglo, tamanio);
    utilitiesLlenarArregloEnteros(Arreglo, tamanio);
    Escribir_Archivo(Arreglo, tamanio);
    free(Arreglo);
}
void Escribir_Archivo(int *Arreglo, int tamanio)
{
    FILE *Archivo1;
    char nombrearch[30];
    int i;
    printf("Dime el nombre del archivo: ");
    fgets(nombrearch, 28, stdin);
    utilitiesQuitarEnterString(nombrearch);
    Archivo1=fopen(nombrearch, "wb");
    fwrite(Arreglo, sizeof(int), tamanio, Archivo1);
    fclose(Archivo1);
}