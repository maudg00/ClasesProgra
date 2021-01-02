#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Definicion_Numeros
{
    float real;
    float imaginario;
};
typedef struct Definicion_Numeros Complex;
void pedirNumeros(Complex *num1, Complex *num2, char *operacion);
void hacerOperacion(Complex num1, Complex num2, Complex *resultado, char operacion);
void ensenarResultado(Complex num1, Complex num2, Complex resultado, char operacion);
int main()
{
    Complex num1, num2, resultado;
    char operacion;
    pedirNumeros(&num1, &num2, &operacion);
    hacerOperacion(num1, num2, &resultado, operacion);
    ensenarResultado(num1, num2, resultado, operacion);
}
void pedirNumeros(Complex *num1, Complex *num2, char *operacion)
{
    char string[50];
    int valoresLeidos=0;
    printf("Dame tu operacion de la forma a+bi +/-/*// c+di. Ejemplo: 3+5i * 4-3i.\n");
    
    do
    {
        fgets(string, 50, stdin);
        string[strlen(string)-1]=0;
        valoresLeidos=sscanf(string, "%f+%fi %c %f+%fi", &num1->real, &num1->imaginario, operacion, &num2->real, &num2->imaginario);
        if(valoresLeidos!=5)
        {
            printf("ERROR: formato erroneo. Vuelve a intentar\n");
        }
    } while (valoresLeidos!=5);
    
    

}
void hacerOperacion(Complex num1, Complex num2, Complex *resultado, char operacion)
{
    if(operacion=='+')
    {
        resultado->real=num1.real+num2.real;
        resultado->imaginario=num1.imaginario+num2.imaginario;
    }
    if(operacion=='-')
    {
        resultado->real=num1.real-num2.real;
        resultado->imaginario=num1.imaginario-num2.imaginario;
    }
    if(operacion=='/')
    {   
        resultado->real=(num1.real*num2.real)+(num1.imaginario+num2.imaginario);
        resultado->imaginario=(num2.real*num2.real)+(num2.imaginario*num2.imaginario);
    }
    if(operacion=='*')
    {
        resultado->real=(num1.real*num2.real)-(num1.imaginario*num2.imaginario);
        resultado->imaginario=(num1.real*num2.imaginario)+(num1.imaginario*num2.real);
    }
}
void ensenarResultado(Complex num1, Complex num2, Complex resultado, char operacion)
{
    printf("%.02f+%.03fi %c %.02f+%.02fi = %.02f+%.02fi\n", num1.real, num1.imaginario, operacion, num2.real, num2.imaginario, resultado.real, resultado.imaginario);
}