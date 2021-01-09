#ifndef calculos_h
#define calculos_h
#ifndef calculos_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Calcula el término indicado de la serie de Fibonacci. Utiliza un método
* recursivo. No se recomienda usar este método para términos mayores a n = 40.
* 
* @param int num: término N de la serie de Fibonacci.
*
* @returns double: valor del enésimo término de la serie de Fibonacci. 
*/
EXTERN double Fibonacci(int num);

/* Calcula el factorial del número indicado. Utiliza un método 
* recursivo. Otorga valores correctos mientras el número introducido sea menor
* a 170.
* 
* @param int num: número a obtener su factorial
* @returns factorial: valor del factorial del número.
*/
EXTERN double Factorial(int num);

#undef calculos_IMPORT
#undef EXTERN
#endif