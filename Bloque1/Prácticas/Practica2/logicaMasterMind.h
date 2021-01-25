#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#ifndef logicaMasterMind_h
#define logicaMasterMind_h
#ifndef logicaMasterMind_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

/**
*
* Recibe una semilla y devuelve un número aleatorizado módulo a
*
* @param long seed: número del cual se genera el número aleatorio.
*
* @returns long int aleatorizado.
*
*/
unsigned long int LCG(unsigned long int seed);

/**
*
* Toma un valor entre 0 y 6
*
* @param long seed: número del cual se genera el número aleatorio.
*
* @returns long int aleatorizado.
*
*/
char AssignValuePWD(unsigned short int value);

/**
*
* Crea un password de 7 tipos de caracteres distintos usando un algoritmo de
* generación lineal, dado un seed y una longitud de contraseña. 
*
* @param long seed: idealmente basada en el tiempo en que se toma.
* @param int length: Longitud de la contraseña.
*
* @returns char * password: contraseña de 7 valores posibles {R,A,Y,M,B,N,C}. 
* Pueden encontrarse repetidos. 
*
*/
char * crearPasswordRepeated(unsigned long int seed, int length);

/**
*
* Crea un password de 7 tipos de caracteres distintos usando un algoritmo de
* generación lineal, dado un seed y una longitud de contraseña. 
*
* @param long seed: idealmente basada en el tiempo en que se toma.
* @param int length: Longitud de la contraseña.
*
* @returns char * password: contraseña de 7 valores posibles {R,A,Y,M,B,N,C}. 
* Pueden encontrarse repetidos. 
*
*/
char * crearPassword(unsigned long int seed, int length);

/** Revisa cuántos dígitos coinciden en posición con la contraseña.
* 
* @param char* Pwd: Contraseña contra la que se compara
* @param char* Attempt: contraseña intentada
*
* @returns Número de dígitos que coinciden en posición con la contraseña.
*
*/
int CheckPositionPWD(char * Pwd, char * Attempt);

// ! NOTA JL: Tengo la impresión que es muy optimizable esta función
/** 
* Revisa cuántos colores coinciden con la contraseña sin importar posición
*
* @param char* Pwd: Contraseña contra la que se compara
* @param char* Attempt: Intento contra el que se compara
*
* @returns Número de colores que coinciden.
*
*/
int CheckColorsPWD(const char* Pwd, char* Attempt);

/**
*
* Revisa un password introducido contra un patrón.
*
* @param number int length - Longitud de la contraseña.
* @param char* Pwd: Contraseña patrón.
* @param char* Attempt: Contraseña intentada.
*
* @returns int: 0 si es correcta, -1 si es incorrecta. 
*
*/
int CheckPassword(char * Pwd, char * Attempt);


#undef utilities_IMPORT
#undef EXTERN
#endif