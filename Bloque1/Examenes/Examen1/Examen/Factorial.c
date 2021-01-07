#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")

void PedirNumero(int *num), Description(void);
void MostrarFactorial(int num, long long int res);
long long int Factorial(int num);

int main()
{
    int num = -1;
    long long int res = 0;
    Description();
    do
    {
        PedirNumero(&num);
        if(num<0)
        {
            printf("Introduzca un número válido.\n");
            fpurge(stdin);
        }
    }
    while(num<0);
    res = Factorial(num);
    MostrarFactorial(num,res);
    return 0;
}

void Description(void)
{
    clrscr();
    printf("El presente programa encuentra el resultado del factorial de un\n"
    "número entero. Solamente valida que sea 0 o positivo, pero no que sea entero.\n"
    "Presione [Enter] para continuar.\n");
    getchar();
    fpurge(stdin);
    clrscr();
}

void PedirNumero(int *num)
{
    printf("Introduzca el número a operar:\n");
    scanf("%d", num);
}
/* Calcula el factorial de un número entero dado. 
* @params
    int num: entero positivo
* @returns: res: factorial.
*/
long long int Factorial(int num)
{
    long long int res = 1;
    if( num==0 ){ return 1; }
    while(num>0)
    {
        res *= num;
        num--;
    }
    return res;
}

void MostrarFactorial(int num, long long int res)
{
    printf("El factorial de %d es %lld\n", num,res);
}