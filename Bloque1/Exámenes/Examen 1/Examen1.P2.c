#include <stdio.h>
#include <math.h>
int Pedir_binario(int *binario);
void Contar_digitos(int binario, int *didgito, int *cuenta);
void Convertir_valor(int binario, int *digito2, int *potencia, int cuenta, int *conversionfinal);
int main()
{
    int binario, digito, digito2, potencia, cuenta=0, conversionfinal=0;
    Pedir_binario(&binario);
    Contar_digitos(binario, &digito, &cuenta);
    Convertir_valor(binario, &digito2, &potencia, cuenta, &conversionfinal);
}
int Pedir_binario(int *binario)
{
    float numero=0;
    do
    {
        printf("Escriba cualquier numero binario entero que desee convertir a decimal: ");
        scanf("%f", &numero);
        *binario=(int)numero;
        fflush(stdin);
        if((*binario-numero)!=0)
        {
            printf("El numero no es entero, favor de intentar de nuevo\n");
        }
        if (*binario<0)
        {
            printf("El numero no es positivo, favor de intentar de nuevo\n");
        }
    } while ((*binario-numero)!=0 || *binario<0);
    return *binario;
}
void Contar_digitos(int binario, int *digito, int *cuenta)
{
    while (binario!=0)
    {
        *digito=binario % 10;
        binario=binario / 10;
        *cuenta=*cuenta+1;
    }
}
void Convertir_valor(int binario, int *digito2, int *potencia, int cuenta, int *conversionfinal)
{
    int i=0;
    while (i<cuenta)
    {
        *potencia=pow(2,i);
        i=i+1;

        *digito2=binario % 10;
        binario=binario / 10;

        int multi;
        multi=(*potencia)*(*digito2);

        *conversionfinal=*conversionfinal+multi;
    }
    printf("El numero binario ingresado convertido a decimal es: \n\n%d\n\n", *conversionfinal);
}