#include <stdio.h>
#include <math.h>
void Pedir_Numero(float *coeficiente);
void Calcular_resultado(float a, float b, float c, float *Resultado_1, float *Resultado_2);
void Desplegar_resultado(float Resultado_1, float Resultado_2);
int main()
{
    float a=0, b=0, c=0, Resultado_1=0, Resultado_2=0; 
    Pedir_Numero(&a);
        while (a<=0)
        {
            printf("El valor del coeficiente a debe ser mayor que 0, ingrese otro valor: ");
            scanf("%f", &a);
        }
    Pedir_Numero(&b);
    Pedir_Numero(&c);
    Calcular_resultado(a, b, c, &Resultado_1, &Resultado_2);
    Desplegar_resultado(Resultado_1, Resultado_2);
}
void Pedir_Numero(float *coeficiente)
{
    printf("De la forma canonica de la ecuacion cuadratica (ax^2 + bx + c = 0), escriba el valor del coeficiente correspondiente, solamente si es mayor o igual a 0 (diferente de 0 para el valor del coeficiente a): ");
    scanf("%f", coeficiente);
    while (*coeficiente<0)
    {
        printf("El valor ingresado es menor a 0, favor de ingresar un valor mayor o igual a 0: ");
        scanf("%f", coeficiente);  
    }
}
void Calcular_resultado(float a, float b, float c, float *Resultado_1, float *Resultado_2)
{
    *Resultado_1=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
    *Resultado_2=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);
}
void Desplegar_resultado(float Resultado_1, float Resultado_2)
{
    printf("El resultado de la primera raiz es de: %f", Resultado_1);
    printf(", el resultado de la segunda raiz es de: %f", Resultado_2);
}