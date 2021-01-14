/* Historial.c
* Funciones para llevar el historial de partidas
*
* @author José Luis Aguilar 
* @author Tania Cesin 
*
* January 14 2021
*/

// todo: Funciones de Leaderboard, vaciar archivo


#include "Historial.h"


/*
* La función HistorialAppendArchivo se encarga de llenar el historial
*
*
* @param char* Attempt: Contraseña intentada.
* 
* 
* @returns
*
*
*/
void HistorialAppendArchivo(char *Attempt) 
{   // ? deberíamos agregar posición y colores correctos?
    FILE * Archivo;
    Archivo=fopen("Historial.txt", "at");
    fprintf(Archivo, "%s. \n", Attempt);
    fclose(Archivo);
}
/*
* La función HistorialLeerArchivo se encarga de leer el historial
*
*
* @param
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
* @param char* nomArch: Nombre del archivo con extensión del archivo.
* 
*
* @returns
*
*
*/
void HistorialVaciar(char * nomArch)
{
    FILE * Archivo;
    Archivo = fopen(nomArch,'wt');
    fprintf(Archivo,'\0');
    fclose(Archivo);
}
