#include "utilities.h"
int obtenerFilas(char *string);
void leerArchivo(int *Arreglo, int filas, char *nombreArch);
int main()
{
    int *Arreglo=NULL;
    int filas;
    char string[50];
    filas=obtenerFilas(string);
    utilitiesDeclararArregloEntero(&Arreglo, filas);
    leerArchivo(Arreglo, filas, string);
    utilitiesImprimirArregloEnteros(Arreglo, filas);
    free(Arreglo);
}
int obtenerFilas(char *string)
{
    FILE *Archivo;
    int numeroFilas=0;
    int numero;
    printf("Dime el nombre de tu archivo: ");
    fgets(string, 50, stdin);
    utilitiesQuitarEnterString(string);
    Archivo=fopen(string, "rb");
    while(Archivo==NULL)
    {
        printf("ERROR: no existe un archivo con ese nombre.\n");
        printf("Dime el nombre de tu archivo: ");
        fgets(string, 50, stdin);
        utilitiesQuitarEnterString(string);
        Archivo=fopen(string, "rb");
    }
    while(fread(&numero, sizeof(int), 1, Archivo)==1)
    {
        numeroFilas++;
    }
    fclose(Archivo);
    return numeroFilas;
}
void leerArchivo(int *Arreglo, int filas, char *nombreArch)
{
    FILE *Archivo;
    int i;
    int indice;
    Archivo=fopen(nombreArch, "rb");
    fread(Arreglo, sizeof(int), filas, Archivo);
    fclose(Archivo);
}