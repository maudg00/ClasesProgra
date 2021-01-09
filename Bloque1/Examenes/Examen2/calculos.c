/*calculos.c 

@author Jose Luis Aguilar Charfen <aguilarch.joseluis@gmail.com>
8 de enero de 2021

*/

#include "calculos.h"
/* Calcula el término indicado de la serie de Fibonacci. Utiliza un método
* recursivo. No se recomienda usar este método para términos mayores a n = 40.
* 
* @param int num: término N de la serie de Fibonacci.
*
* @returns double: valor del enésimo término de la serie de Fibonacci. 
*/
double Fibonacci(int num)
{
    if(num==0){return 0;}
    else if(num==1){return 1;}
    else { return Fibonacci(num-1)+Fibonacci(num-2); }
}

/* Calcula el factorial del número indicado. Utiliza un método 
* recursivo. Otorga valores correctos mientras el número introducido sea menor
* a 170.
* 
* @param int num: número a obtener su factorial
* @returns factorial: valor del factorial del número.
*/
double Factorial(int num)
{
    double value = num;
    if( num==0 ){ return 1; }
    value *=Factorial(num-1);
    return value;
}