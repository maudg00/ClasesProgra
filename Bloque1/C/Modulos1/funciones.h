// funciones.h
//
//
//  Created by Mauricio de Garay on 02/01/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef funciones_h
#define funciones_h
#ifndef funciones_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif
/* Función del módulo. */
/*
* El módulo funciones se encarga de hacer lo que pide el programa
*
*
*/


/* Function prototypes. */


/*
* La función funcionesHolaMundo  se encarga de imprimir hola mundo
*
*
* @params
    
*
* @returns
*
*
*/
EXTERN char funcionesHolaMundo();

/*
* La función funcionesAdiosMundo  se encarga de imprimir adios mundo
*
*
* @params
    
*
* @returns
*
*
*/
EXTERN char funcionesAdiosMundo();

#undef funciones_IMPORT
#undef EXTERN
#endif