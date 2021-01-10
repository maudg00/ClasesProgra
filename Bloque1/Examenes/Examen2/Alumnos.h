/* Alumnos.h

@author Jose Luis Aguilar Charfen <aguilarch.joseluis@gmail.com>
8 de enero de 2021

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#ifndef Alumnos_h
#define Alumnos_h
#ifndef Alumnos_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

EXTERN struct Definicion_Alumno
{
    char Nombre[50];
    int grado;
    float califNumer;
    char Letra;
};
EXTERN typedef struct Definicion_Alumno Alumno;

/*                       function prototypes                        */

EXTERN void AlumnosDeclarar(int *tamano, Alumno **ListaAlumnos);

EXTERN void AlumnosLlenar(int tamano, Alumno **Alumnos);

EXTERN void AlumnosArchivo(int tamano, Alumno **Alumnos);


#undef Alumnos_IMPORT
#undef EXTERN
#endif