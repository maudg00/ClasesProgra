#include <stdio.h>
#include <math.h>
#define clrscr() printf("\e[1;1H\e[2J")

void Descripcion(void), PedirNumero(int *num), MostrarNum(int num, int res);
int ConvertirBinADec(int num);

int main()
{
    int numero = 0, resultado = 0;
    Descripcion();
    PedirNumero(&numero);
    resultado = ConvertirBinADec(numero);
    MostrarNum(numero,resultado);
}

void PedirNumero(int *numero)
{
    printf("Introduzca el número en binario a convertir:\n");
    scanf("%d", numero);
}

void Descripcion(void)
{
    clrscr();
    printf("El presente programa convierte un número binario a decimal.\n"
    "No valida si el número introducido es binario, por lo que es necesario \n"
    "revisar que la entrada sea válida. Presione [Enter] para continuar.\n");
    getchar();
    fpurge(stdin);
    clrscr();
}
/* Convierte números enteros binarios a decimales. No valida la entrada. 
 *  
 *  @params:
 *  num: número binario.
 *  @returns:
 *  res: Número convertido a decimal.
 */
int ConvertirBinADec(int num)
{
    int res = 0;
    for(int i = 0; num!=0; i++)
    {
        res += ( num%10 ) * pow(2,i);
        num = num/10;
    }   
    return res;
}

void MostrarNum(int num, int res)
{
    printf("El número binario %d en convertido a decimal es %d\n", num, res);
}