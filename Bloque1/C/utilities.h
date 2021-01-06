// utilities.h
//
//
//  Created by Mauricio de Garay, Tania Cesin, Kirya Hernandez, Jose Luis on 06/01/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#ifndef utilities_h
#define utilities_h
#ifndef utilities_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif
/* Function prototypes. */


/*
* La función utilitiesPedirEntero  se encarga de pedir un numero entero al usuario
*
*
* @params 
* 
*
* @returns un int que se leyo del usuario.
*
*
*/
EXTERN int utilitiesPedirEntero();
/*
* La función utilitiesPedirFlotante  se encarga de pedir un numero flotante al usuario
*
*
* @params 
* 
*
* @returns un float que se leyo del usuario.
*
*
*/
EXTERN float utilitiesPedirFlotante();
/*
* La función utilitiesValidarEntero  se encarga de  validar si un numero es entero (no tiene ningún valor después del punto decimal)
*
*
* @params float numero: un numero flotante.
* 
*
* @returns int: 0 (FALSE) si no es entero, 1 (TRUE) si sí es entero.
*
*
*/
EXTERN int utilitiesValidarEntero(float numero);
/*
* La función utilitiesValidarEnteroPositivo  se encarga de validar que un numero entero sea positivo mayor a 0.
*
*
* @params int numero: numero entero a validar.
* 
*
* @returns int: 0 (FALSE) si no es positivo, 1 (TRUE) si sí lo es.
*
*
*/
EXTERN int utilitiesValidarEnteroPositivo(int numero);
/*
* La función utilitiesEnter  se encarga de esperar a que el usuario ingrese <enter> para continuar.
*
*
* @params
* 
*
* @returns
*
*
*/
EXTERN void utilitiesEnter();
/*
* La función utilitiesQuitarEnterString se encarga de quitar el caracter '\n' a un string que lo tenga al final.
*
*
* @params char * string: string al que le quitaremos el enter.
* 
*
* @returns
*
*
*/
EXTERN void utilitiesQuitarEnterString(char * string);
/*
* La función utilitiesStringToUpper se encarga de convertir todos los caracteres de un string a mayúsculas.
*
*
* @params char * string: el string a convertir.
* 
*
* @returns
*
*
*/
EXTERN void utilitiesStringToUpper(char *string);
/*
* La función utilitiesStringToLower se encarga de convertir todos los caracteres de un string a minúsculas.
*
*
* @params char * string: el string a convertir.
* 
*
* @returns
*
*
*/
EXTERN void utilitiesStringToLower(char *string);
/*
* La función utilitiesDeclararArregloEntero se encarga de declarar dinamicamente un arreglo entero.
*
*
* @params
*   int ** arreglo, la direccion de memoria del arreglo a declarar.
*   int tamano, el tamano del arreglo.
* 
*
* @returns
*
*
*/
EXTERN void utilitiesDeclararArregloEntero(int **arreglo, int tamano);
/*
* La función utilitiesLlenarArregloEnteros se encarga de llenar un arreglo.
*
*
* @params
*   int * arreglo, el arreglo de enteros.
*   int tamano, el tamano del arreglo
* 
*
* @returns
*
*
*/
EXTERN void utilitiesLlenarArregloEnteros(int * arreglo, int tamano);
/*
* La función utilitiesImprimirArregloEnteros se encarga de imprimir un arreglo de enteros
*
*
* @params
*   int * arreglo, el arreglo de enteros.
*   int tamano, el tamano del arreglo
* 
*
* @returns
*
*
*/
EXTERN void utilitiesImprimirArregloEnteros(int * arreglo, int tamano);
/*
* La función utilitiesDeclararMatrizEnteros se encarga de declarar una matriz dinámica.
*
*
* @params
*   int *** matriz, la dirección de memoria de la matriz.
*   int filas, las filas de la matriz.
*   int columnas, las columnas de la matriz.
* 
*
* @returns
*
*
*/
EXTERN void utilitiesDeclararMatrizEnteros(int ***Matriz, int filas, int columnas);
#undef utilities_IMPORT
#undef EXTERN
#endif