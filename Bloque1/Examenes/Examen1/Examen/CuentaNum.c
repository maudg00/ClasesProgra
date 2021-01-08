#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")

void Descripcion(void), PedirNumero(int *num), SepararDigitos(int num);
void ShowCount(short int count, short int flag);
int NumIgual(short int num, int flag);

int main()
{
    int num = 0;
    Descripcion();
    PedirNumero(&num);
    SepararDigitos(num);
}

void Descripcion(void)
{
        clrscr();
    printf("El presente programa cuenta los dígitos de un número entero y los\n"
    "devuelve al usuario. Solamente valida que sea 0 o positivo, pero no que sea entero.\n"
    "Presione [Enter] para continuar.\n");
    getchar();
    fpurge(stdin);
    clrscr();
}


void PedirNumero(int *num)
{
    printf("Introduzca el número entero a contar dígitos:\t");
    scanf("%d",num);
    fpurge(stdin);
}
/* Separa los dígitos de un número entero en base 10, y devuelve cuáles existen.
* @params:
    int num: número a separar
* @returns:
*/
void SepararDigitos(int num)
{
    short int cuenta0=0,cuenta1=0,cuenta2=0,cuenta3=0,cuenta4=0;
    short int cuenta5=0,cuenta6=0,cuenta7=0,cuenta8=0,cuenta9=0;
    short int digito=0;
    while(num>0)
    {
        digito = num%10;
        num = num/10;
        cuenta0+=NumIgual(digito,0);
        cuenta1+=NumIgual(digito,1);
        cuenta2+=NumIgual(digito,2);
        cuenta3+=NumIgual(digito,3);
        cuenta4+=NumIgual(digito,4);
        cuenta5+=NumIgual(digito,5);
        cuenta6+=NumIgual(digito,6);
        cuenta7+=NumIgual(digito,7);
        cuenta8+=NumIgual(digito,8);
        cuenta9+=NumIgual(digito,9);
    }

    ShowCount(cuenta0,0);
    ShowCount(cuenta1,1);
    ShowCount(cuenta2,2);
    ShowCount(cuenta3,3);
    ShowCount(cuenta4,4);
    ShowCount(cuenta5,5);
    ShowCount(cuenta6,6);
    ShowCount(cuenta7,7);
    ShowCount(cuenta8,8);
    ShowCount(cuenta9,9);
    
}

int NumIgual(short int num, int flag)
{
    if(num==flag){ return 1;} 
    else { return 0; }
}

void ShowCount(short int count, short int flag)
{
    if(!(count==0))
    {
        printf("Dígito %d: se encontraron %hd dígitos.\n",flag,count);
    }
}