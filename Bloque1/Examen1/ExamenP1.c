#include <stdio.h>
#include <math.h>
void PedirNum(float *num, int *numE);
void ContarDig(int numE);

int main()
{
    float num=0; int numE=0;
    PedirNum(&num, &numE);
    ContarDig(numE);
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
void ContarDig(int numE)
{
    int i, j, res, cont;
    for(i=0; i<10; i++)
    {
        cont=0;
        for (j=numE; j>0; j=j/10)
        {
            res=j%10;
            if (res==i)
            {
                cont++;
            }
        }
        if (cont!=0)
        {
            printf("El digito %d se repite %d veces. \n", i, cont);
        }
    }
}