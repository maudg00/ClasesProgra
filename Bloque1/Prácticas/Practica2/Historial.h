// Historial.h
//
//
//  Created by Jose Luis Aguilar, Tania Cesin on 13/01/2021.
//
#include "utilities.h"
#ifndef Historial_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif
/* Function prototypes. */


/**
* La función HistorialAppendArchivo se encarga de llenar el historial
*
*
* @param char* Attempt: intento para agregar al historial de jugadas.
* 
*
* @returns
*
*
*/
EXTERN void HistorialAppendArchivo(char * Attempt);

/**
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
EXTERN char HistorialLeerArchivo();