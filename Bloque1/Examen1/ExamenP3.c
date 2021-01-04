#include <stdio.h>

void PedirNum(float *num, int *numE);
void CalcularFac(int numE, int *Fac);
void DesplegarFac(int numE, int Fac);

int main()
{
    float num=0; int numE=0, Fac=1;
    PedirNum(&num, &numE);
    CalcularFac(numE, &Fac);
    DesplegarFac(numE, Fac);
}
void PedirNum(float *num, int *numE)
{
    int flag=0;
    while (flag==0)
    {
        printf("dame un mumero: ");
        scanf("%f", num);
        if (*num>0)
        {
            *numE=(int)*num;
            if (*num-*numE==0)
            {
                flag=1;
            }
        }
        else
        {
            flag=0;
        }
        if (flag==0)
        {
            printf("Tu numero no es correcto. \n");
        }
    }
}
void CalcularFac(int numE, int *Fac)
{
    int i;
    if (numE==0)
    {
        *Fac=1;
    }
    else
    {
        for (i=1; i <= numE; i++)
        {
            *Fac=i*(*Fac);
        }  
    }   
}
void DesplegarFac(int numE, int Fac)
{
    printf("Tu factorial de %d es: %d \n", numE, Fac);
}