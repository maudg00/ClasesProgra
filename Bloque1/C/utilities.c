#include "utilities.h"
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
int utilitiesPedirEntero()
{
    int num;
    printf("Dame Entero: ");
    scanf("%d", &num);
    fflush(stdin);
    return num;
}
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
float utilitiesPedirFlotante()
{
    float num;
    printf("Dame flotante: ");
    scanf("%f", &num);
    fflush(stdin);
    return num;
}
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
int utilitiesValidarEntero(float numero)
{
    int numeroEntero=(int)numero;
    if(numeroEntero-numero!=0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
    
}
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
int utilitiesValidarEnteroPositivo(int numero)
{
    if(numero<=0)
    {
        return FALSE;
    }
    return TRUE;
}
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
void utilitiesEnter()
{
    char enter;
    printf("Presiona <enter> para continuar... ");
    scanf("%c", &enter);
    fflush(stdin);
}
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
void utilitiesQuitarEnterString(char * string)
{
    string[strlen(string)-1]=0;
}
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
void utilitiesStringToUpper(char *string)
{
    int tamano=(int)strlen(string);
    for(int i=0; i<tamano; i++)
    {
        string[i]=toupper(string[i]);
    }
}
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
void utilitiesStringToLower(char *string)
{
    int tamano=(int)strlen(string);
    for(int i=0; i<tamano; i++)
    {
        string[i]=tolower(string[i]);
    }
}
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
void utilitiesDeclararArregloEntero(int **arreglo, int tamano)
{
    *arreglo=malloc((tamano)*sizeof(int));
}
void utilitiesLlenarArregloEnteros(int * arreglo, int tamano)
{
    for(int i=0; i<tamano; i++)
    {
        printf("Dame el valor %d del arreglo: ", (i+1));
        scanf("%d", arreglo+i);
        fflush(stdin);
    }
}
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
void utilitiesImprimirArregloEnteros(int * arreglo, int tamano)
{
    for(int i=0; i<tamano; i++)
    {
        printf("Arreglo[%d]=%d", (i+1), arreglo+i);
    }
}
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
void utilitiesDeclararMatrizEnteros(int ***Matriz, int filas, int columnas)
{
    int i;
    *Matriz=malloc((filas)*sizeof(int*));
    for(i=0; i<columnas; i++)
    {
        *(*Matriz+i)=malloc((columnas)*sizeof(int));
    }
}