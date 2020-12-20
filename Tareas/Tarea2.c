
/* Este es el pseudocódigo para elevar un número entero al cubo, usando como 
método la suma iterada. No se busca que sea un método eficiente. 
Abajo se encuentra descrito: */
#include <stdio.h>
#include <time.h>

int main()
{
    void PedirNumero(int *num),
    Cubo(int num, long long unsigned int *resultado), 
    Desplegar(long long unsigned int resultado);
    int num=0; 
    long long unsigned int resultado = 0;

    PedirNumero(&num);
    Cubo(num,&resultado); 
    Desplegar(resultado); 
    return 0;
}
void PedirNumero(int *num)
{
    printf("Escriba el número a elevarse al cubo:\n");
    scanf("%d", num); 

}

void Cubo(int num, long long unsigned int *resultado) 
{
    int ValorCuadrado = 0;

    clock_t begin = clock();

    for(int i=0; i<num; i++)
    {
        ValorCuadrado = ValorCuadrado+num;
    }

    for(int j=0; j<num; j++) //3.2.i+1.j+1
    {    
        *resultado = *resultado + ValorCuadrado; 
    }	

    clock_t end = clock();

    printf("Le tomó %lu clock counts llegar al resultado.\n", (end-begin));
}

void Desplegar(long long unsigned int resultado)
{
    printf("El resultado es de %llu\n",resultado);
}


