#include <stdio.h>
#include <math.h>
void PedirNum(float *num, int *numE);
void CalcularBin(int numE);

int main()
{
    float num=0; int numE=0;
    PedirNum(&num, &numE);
    CalcularBin(numE);
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
void CalcularBin(int numE)
{
    int i=0, j, res, dig=0;
    printf("Tu numero binario en decimal es: ");
        for (j=numE; j>0; j=j/10)
        {
            res=j%10;
            dig=dig+(res*pow(2,i));
            i++;
        }
    printf("%d", dig);
}