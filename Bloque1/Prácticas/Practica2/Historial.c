#include "Historial.h"
/*
* La función HistorialAppendArchivo se encarga de llenar el historial
*
*
* @param char Attempt
* 
*
* @returns
*
*
*/
void HistorialAppendArchivo(char *Attempt)
{
    FILE * Archivo;
    Archivo=fopen("Historial.txt", "at");
    fprintf(Archivo, "%s. \n", Attempt);
    fclose(Archivo);
}
/*
* La función HistorialLeerArchivo se encarga de leer el historial
*
*
* @params 
* 
*
* @returns contenido del historial
*
*
*/
char HistorialLeerArchivo()
{
    FILE * Archivo;
    char hist;
    int i=0;
    Archivo=fopen("Historial.txt", "rt");
    while ((fscanf(Archivo, "%c. \n", &hist))==1)
    {
        printf("%c", hist);
    }
    
}
/*
* La función HistorialVaciar archivo se encarga de limpiar el historial
*
*
* @params 
* 
*
* @returns
*
*
*/
void HistorialVaciar(char * nomArch)