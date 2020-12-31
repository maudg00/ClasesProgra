#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void PedirTamano(int *tamano);
void PedirNumeros(int Array[20], int size);

int main()
{
    int Array[20]={0}, tamano = 0;

    PedirTamano(&tamano);
    PedirNumeros(Array,tamano);
    CalcularyMostrarEstadisticos(Array,tamano);
    





    return 0;
}

void PedirTamano(int *tamano)
{
    do{
        printf("Escriba cuántos valores va a introducir. (Máximo 20)\n");
        scanf("%d",tamano);
        fpurge(stdin);
    }while(!(*tamano<0 && *tamano>20));
}
void PedirNumeros(int Array[20], int size)
{
    for(int i = 0; i<size; i++)
    {
        printf("Inserte el elemento &d del arreglo: ", i);
        scanf("&d", &Array[i]);
    }
}
void CalcularyMostrarEstadisticos(int Array[20],int size)
{
    double residue[20], average = 0, SumsOfSquares = 0;
    double STDev = 0;
    int Repetitions[20];
    for(int i = 0; i<size; i++)
    {
        average += Array[i]/size;
    }
    for(int i = 0; i<size; i++)
    {
        residue[i] = Array[i]-average;
        SumsOfSquares += residue[i]*residue[i];
    }
    STDev = sqrt( SumsOfSquares / size );
    printf("Los estadísticos calculados son los siguientes:\n"
    "\tMedia = &f\n"
    "\tModa = &f\n"
    "\tDesviacion Estandar = &f\n",average,mode,STDev);

}

// Para calcular la moda: 
// Revisar elemento por elemento. Si un elemento es igual a otro que ya está en 
// la lista, entonces no lo escribimos. Si no es igual, se agrega al fondo el 
// elemento. Después, debemos escribir cuántas veces se encuentra cada número
// en el arreglo, y que quede algo del estilo para el número X hay Y repeticiones
// Una vez dado esto, la moda es en el que haya más repeticiones. 
