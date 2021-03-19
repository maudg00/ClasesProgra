// utilities2.h
//
//
//  Created by Mauricio de Garay, Francisco Rodríguez, Tania Cesin, Kirya Hernandez, Jose Luis on 06/01/2021.
//  Welcome to the remix.
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
* @returns int que se leyo del usuario.
*
*
*/
EXTERN int utilitiesPedirEntero();
/*
* La función utilitiesPedirFlotante  se encarga de pedir un numero flotante al usuario
*
*
* @param
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
* @param float numero: un numero flotante.
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
* @param int numero: numero entero a validar.
* 
*
* @return int: 0 (FALSE) si no es positivo, 1 (TRUE) si sí lo es.
*
*
*/
EXTERN int utilitiesValidarEnteroPositivo(int numero);
/*
* La función utilitiesEnter  se encarga de esperar a que el usuario ingrese <enter> para continuar.
*
*
* @param
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
* @param char* string: string al que le quitaremos el enter.
* 
*
* @return
*
*
*/
EXTERN void utilitiesQuitarEnterString(char * string);
/*
* La función utilitiesStringToUpper se encarga de convertir todos los caracteres de un string a mayúsculas.
*
*
* @param char* string: el string a convertir.
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
* @param char* string: el string a convertir.
* 
*
* @returns
*
*
*/
EXTERN void utilitiesStringToLower(char *string);
/*
* La función utilitiesDeclararArreglo se encarga de declarar dinamicamente un arreglo.
*
*
* @param size_t tamano, el tamano del arreglo en bytes.
* 
* @return
*
*
*/
EXTERN void * utilitiesDeclararArreglo(size_t tamano);
/*
* La función utilitiesLlenarArregloEnteros se encarga de llenar un arreglo.
*
*
* @param int * arreglo, el arreglo de enteros.
* @param int tamano, el tamano del arreglo
* 
*
* @return
*
*
*/
EXTERN void utilitiesLlenarArregloEnteros(int * arreglo, int tamano);
/*
* La función utilitiesImprimirArregloEnteros se encarga de imprimir un arreglo de enteros
*
*
* @params
*   @param int* arreglo, el arreglo de enteros.
*   @param int tamano, el tamano del arreglo
* 
*
* @returns
*
*
*/
EXTERN void utilitiesImprimirArregloEnteros(int * arreglo, int tamano);
/*
* La función utilitiesDeclararMatriz se encarga de declarar una matriz dinámica.
*
*
* @params
*   @param int columnas, el numero de columnas que hay
*   @param size_t tamanoFilas, el tamaño en bytes de las filas.
*   @param size_t tamanoFilas, el tamaño en bytes de las columnas.
* 
*
* @returns
*
*
*/
EXTERN void ** utilitiesDeclararMatriz(int columnas, size_t tamanoFilas, size_t tamanoColumnas);
/*
* La función utilitiesLiberarMatriz se encarga de liberar una matriz que fue inicializada dinámicamente.
*
*
* @params
*   @param void** Matriz, la matriz a liberar.
*   @param int filas, las filas de la matriz.
*   @param int columnas, las columnas de la matriz.
* 
*
* @returns
*
*
*/
EXTERN void utilitiesLiberarMatriz(void **Matriz, int filas, int columnas);
#undef utilities_IMPORT
#undef EXTERN
#endif