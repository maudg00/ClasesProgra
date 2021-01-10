#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#ifndef cuadroMagico_h
#define cuadroMagico_h
#ifndef cuadroMagico_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif
#define clrscr() printf("\e[1;1H\e[2J")

/*
* La función recibe un número impar y devuelve un cuadro mágico con las
* dimensiones especificadas.
*
* @param int num: tamaño del cuadro mágico
* @returns cuadro mágico impreso en la terminal.
*/
EXTERN void CuadroMagico(int num);

/* Método para llamar la función cuadro mágico a la terminal con instrucciones. */
EXTERN void callCuadroMagico();



#undef cuadroMagico_IMPORT
#undef EXTERN
#endif