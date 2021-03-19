#include "utilities2.h"
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
* @param
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
* @param {float} [numero]: un numero flotante.
* 
*
* @return {int}: 0 (FALSE) si no es entero, 
* @return {int}: 1 (TRUE) si sí es entero.
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
* @param int numero: numero entero a validar.
* 
*
* @return int: 0 (FALSE) si no es positivo, 1 (TRUE) si sí lo es.
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
* @param
* 
*
* @return
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
* @param {char*} [string]: string al que le quitaremos el enter.
* 
* @return
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
* @param char* string: el string a convertir.
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
* @param char* string: el string a convertir.
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
* La función utilitiesDeclararArreglo se encarga de declarar dinamicamente un arreglo.
*
*
* @param size_t tamano, el tamano del arreglo en bytes.
* 
* @return
*
*
*/
void * utilitiesDeclararArreglo(size_t tamano)
{
    void * arreglo;
    arreglo=malloc(tamano);
    return arreglo;
}
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
* @param int* arreglo, el arreglo de enteros.
* @param int tamano, el tamano del arreglo
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
        printf("Arreglo[%d]=%d\n", (i+1), *(arreglo+i));
    }
}
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
void ** utilitiesDeclararMatriz(int columnas, size_t tamanoFilas, size_t tamanoColumnas)
{
    void **Matriz;
    int i;
    Matriz=malloc(tamanoFilas);
    for(i=0; i<columnas; i++)
    {
        *(Matriz+i)=malloc(tamanoColumnas);
    }
    return Matriz;
}
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
void utilitiesLiberarMatriz(void **Matriz, int filas, int columnas)
{
    for(int i=0; i<filas; i++)
    {
        void *Actual=Matriz[i];
        free(Actual);
    }
    free(Matriz);
}