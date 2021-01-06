/* pregunta 3 a la facilita*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
/*Encabezado */
long PedirNumeroValidar (long *numero);
void CalcularFactorial (long numero, long variable, long factorial, long *total);
void DesplegarNumero (long total);
//Main
int main ()
{
    //Declaracion de variables
   long numero;
   long bandera;
   long factorial;
   long variable;
   long total;
   bandera=PedirNumeroValidar(&numero);
   if(bandera==0)
   {
       printf("Ups: tu numero no es entero.\n");
       return 0;
   }
   else
   {
       printf("Yay: tu numero es entero.\n");
   }
   
    CalcularFactorial(numero, variable, factorial, &total);
    DesplegarNumero(total); 
}
//Desarrollo de funciones
long PedirNumeroValidar (long *numero)
{
    float numeroEquis=0;
    printf("Inserta un numero entero: ");
    scanf("%f", &numeroEquis);
    *numero=(long)numeroEquis;
    if((*numero-numeroEquis)!=0)
    {
        return false; 
    }
    else
    {
        return true;
    }
}
void CalcularFactorial (long numero, long variable, long factorial, long *total)
{
   int i=1;
   factorial=1;
        for (variable=numero; variable >=1; variable --)
        {
            factorial=factorial*variable;
        }  
        *total=factorial;   
}
void DesplegarNumero (long total)
{
    printf("Tu factorial es: %ld\n", total);
}


