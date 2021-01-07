#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")

void PedirNumero(int *num), Description(void);
void MostrarFibonacci(int num, long long int res);
long long int fibonacci(int num);

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
    res = fibonacci(num);
    MostrarFibonacci(num,res);
    return 0;
}

void Description(void)
{
    clrscr();
    printf("El presente programa encuentra el número de fibonacci de un\n"
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
/* Calcula el número de la serie de fibonacci de un número entero dado. 
* @params
    int num: entero positivo
* @returns: res: número de fibonacci.
*/
long long int fibonacci(int num)
{
    long long int res = 0, anterior = 1, otro = 0;
    if ( num==0 ) { return 0; }
    else if ( num==1 ) { return 1; }

    for(int i=1; i<num; i++)
    {
        res = anterior+otro;
        otro = anterior;
        anterior = res;
    }
    return res;
}

void MostrarFibonacci(int num, long long int res)
{
    printf("El número de fibonacci %d es %lld\n", num,res);
}