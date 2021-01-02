// vista.h
//
//
//  Created by Mauricio de Garay on 02/01/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef vista_h
#define vista_h
#ifndef vista_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif
/* Función del módulo. */
/*
* El módulo visra se encarga de tener funciones para la vista
*
*
*/


/* Function prototypes. */


/*
* La función vistaMenu  se encarga de desplegar el menu.
*
*
* @params
    
*
* @returns char op: la opcion seleccionada
*
*
*/
EXTERN char vistaMenu();
/*
* La función vistaEnter  se encarga de esperar un enter del usuario.
*
*
* @params
    
*
* @returns
*
*
*/
EXTERN char vistaEnter();

#undef vista_IMPORT
#undef EXTERN
#endif