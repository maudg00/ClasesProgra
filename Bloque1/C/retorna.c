#include <stdio.h>
#define true 1
#define false 0
int pedirNumero();
int pedirCoeficientes(int *a, int *b, int *c);
int main()
{
    //Parte 1: pido 3 numeros utilizando returns
    int num1, num2, num3;
    int a, b, c, banderaValidacion;
    num1=pedirNumero();
    num2=pedirNumero();
    num3=pedirNumero();
    printf("El numero 1 es: %d.\n", num1);
    printf("El numero 2 es: %d.\n", num2);
    printf("El numero 3 es: %d.\n", num3);
    //Parte 2: pido coeficientes de la forma "ax2+bx+c" y checo que se ingresen correctamente con los valores de return de scanf()
    banderaValidacion=pedirCoeficientes(&a,&b,&c);

    if(banderaValidacion==false) // es lo mismo que poner if(banderaValidacion==0)
    {   
        printf("No se leyeron bien todos los valores :(.\n");
    }
    else
    {
        printf("Se leyeron bien los valores, y estos son:\n\ta=%d.\n\tb=%d.\n\tc=%d.\n", a,b,c);
    }
    
}
int pedirNumero()
{
    int num;
    printf("Dame un numero \n");
    scanf("%d", &num);
    return num;
}
int pedirCoeficientes(int *a, int *b, int *c)
{
    int valoresLeidosCorrectamente=0;
    printf("Dame tus coeficientes de la forma ax2+bx+c (Ejemplo: ingresa 3x2+7x+8): ");
    valoresLeidosCorrectamente=scanf("%dx2+%dx+%d", a,b,c);
    printf("Se leyeron bien %d valores.\n", valoresLeidosCorrectamente);
    if(valoresLeidosCorrectamente!=3)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}