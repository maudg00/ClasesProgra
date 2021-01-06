#include <stdio.h>
long Pedir_numero(long *num);
void Contar_digitos(long num, int *res);
int main()
{
    long num; 
    int res;
    num=Pedir_numero(&num);
    Contar_digitos(num, &res);
}
long Pedir_numero(long *num)
{
    float numero=0;
    do
    {
        printf("Escriba cualquier numero entero que sea positivo: ");
        scanf("%f", &numero);
        *num=(long)numero;
        fflush(stdin);
        if((*num-numero)!=0)
        {
            printf("El numero no es entero, favor de intentar de nuevo \n");
        }
        if (*num<0)
        {
            printf("El numero no es positivo, favor de intentar de nuevo \n");
        }
    } while ((*num-numero)!=0 || *num<0);
    return *num;
}
void Contar_digitos(long num, int *res)
{
    int i, temp, cuenta=0;
    for (i=0; i<10; i++)
    {
        cuenta=0;
        for(temp=num; temp!=0; temp=temp/10)
        {
            *res=temp % 10;
            if (*res==i)
            {
                cuenta=cuenta+1;
            }
        }
        if(cuenta!=0)
        {
            printf("El digito %d aparece %ld veces.\n", i, cuenta);
        }
    }
}