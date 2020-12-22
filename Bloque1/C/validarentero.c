// validarentero.c
//
// Creado por Mauricio de Garay el 22/12/2020.
// Este archivo se encarga de pedir un numero entero, validar que sea entero y si no lo es, imprimir "hola, mundo" en la pantalla.
#include <stdio.h>
#define true 1
#define false 0
/* Function prototypes */
/*
* La función pedirYValidarNum  se encarga de oedir un numero y validar que sea entero.
*
*
* @params
    int * num: un apuntador de memoria de tipo entero donde se guardará el resultado entero que se lea.
*
* @returns
      1/true si es entero
      0/false si no lo es

*/
int pedirYValidarNum(int *num);
/*
* La función holamundo  se encarga de imprimir "hola mundo" a la pantalla.
*
*
* @params
*
* @returns
*/
void holamundo();
int main()
{
    int num;
    int bandera;
    bandera=pedirYValidarNum(&num);
    if(bandera==0)//eslo mismo que poner if (bandera==false)
    {
        printf("Tu numero no es entero.\n");
        holamundo();
        return 0;
    }
    else
    {
        printf("Gracias por tu numero entero.\n");
    }
    
}
int pedirYValidarNum(int *num)
{
    float numeroDummy=0;
    printf("Dame un numero entero: ");
    scanf("%f", &numeroDummy);
    *num=(int)numeroDummy;
    if((*num-numeroDummy)!=0)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}
void holamundo()
{
    printf("Hola, mundo.");
}