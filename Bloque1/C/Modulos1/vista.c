// vista.h
//
//
//  Created by Mauricio de Garay on 02/01/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
char vistaMenu()
{
    char opcion;
    printf("Bienvenido!\n");
    printf("\tOpcion 1: imprimir 'Hola mundo'.\n");
    printf("\tOpcion 2: imprimir 'Adios mundo'.\n");
    printf("\tOpcion 3: salir.\n");
    printf("Dame tu opcion: ");
    scanf("%c", &opcion);
    fflush(stdin);
    return opcion;
}
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
char vistaEnter()
{
    char enter;
    printf("Presiona <enter> para continuar... ");
    scanf("%c", &enter);
    fflush(stdin);
}

