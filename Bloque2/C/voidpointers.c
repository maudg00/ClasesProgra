#include <stdlib.h>
#include <stdio.h>
#include "utilities.h"
void arregloEntero();
void arregloChar();
void MatrizEntero();
void MatrizChar();

int main()
{
    
    arregloEntero();
    arregloChar();
    MatrizEntero();
    MatrizChar();
    
}
void arregloEntero()
{
    int tamanoEntero;
    tamanoEntero=8;
    //Si quiero hacer un arreglo de 8 enteros.
    int *arregloEnteros=utilitiesDeclararArreglo(tamanoEntero*sizeof(int));
    utilitiesLlenarArregloEnteros(arregloEnteros, tamanoEntero);
    utilitiesImprimirArregloEnteros(arregloEnteros, tamanoEntero);
    free(arregloEnteros);
}
void arregloChar()
{
    int tamanoChar;
    tamanoChar=10;
    //Si quiero hacer un arreglo de 10 caracteres.
    char *arregloCaracter=utilitiesDeclararArreglo(tamanoChar*sizeof(char));
    strcpy(arregloCaracter, "holaM.");
    printf("%s\n", arregloCaracter);
    free(arregloCaracter);
}
void MatrizEntero()
{
    int columnasEntero=5,filasEntero=4;
    //Si quiero una matriz int [4][5]
    int **matrizEntero=(int**)utilitiesDeclararMatriz(columnasEntero, filasEntero*sizeof(int*), columnasEntero*sizeof(int));
    for(int i=0; i<filasEntero; i++)
    {
        for(int j=0; j<columnasEntero; j++)
        {
            printf("Dime el numero[%d][%d]: ", i, j);
            scanf("%d", &matrizEntero[i][j]);
            fflush(stdin);
        }
        
    }
    printf("\n");
    for(int i=0; i<filasEntero; i++)
    {
        for(int j=0; j<columnasEntero; j++)
        {
            printf("El numero[%d][%d]: %d\n ", i,j,matrizEntero[i][j]);
        }
        
    }
    utilitiesLiberarMatriz((void**)matrizEntero, filasEntero, columnasEntero);
}
void MatrizChar()
{
    int filasChar=5;
    int columnasChar=10;
    char **matrizChar=(char**)utilitiesDeclararMatriz(columnasChar, filasChar*sizeof(char*), columnasChar*sizeof(char));
    for(int i=0; i<filasChar; i++)
    {
        printf("Dime la palabra %d: ", i);
        fgets(matrizChar[i], 10, stdin);
        utilitiesQuitarEnterString(matrizChar[i]);
        fflush(stdin);
        
    }
    printf("\n");
    for(int i=0; i<filasChar; i++)
    {
        printf("%s", matrizChar[i]);
        printf("\n");
    }
    utilitiesLiberarMatriz((void**)matrizChar, filasChar, columnasChar);
}