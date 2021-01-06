#include <stdio.h>
int Pedir_numero(int *num);
void Calcular_factorial(int num, long long *factorial);
int main()
{
    int num;
    long long factorial=1;
    Pedir_numero(&num);
    Calcular_factorial(num, &factorial);
}
int Pedir_numero(int *num)
{
     float numero=0;
    do
    {
        printf("Escriba cualquier numero entero que sea positivo: ");
        scanf("%f", &numero);
        *num=(int)numero;
        fflush(stdin);
        if((*num-numero)!=0)
        {
            printf("El numero no es entero, favor de intentar de nuevo \n");
        }
        if (*num<0)
        {
            printf("El numero no es positivo, favor de intentar de nuevo \n");
        }
        if (*num==0)
        {
            printf("El factorial de %d es: 1", *num);
        }   
    } while ((*num-numero)!=0 || *num<0);
    return *num;
}
void Calcular_factorial(int num, long long *factorial)
{
    int i;
    for (i=1; i<=num; i++)
    {
        *factorial=*factorial*i;
    }
    printf("El factorial de %d es: %llu\n", num, *factorial);
}