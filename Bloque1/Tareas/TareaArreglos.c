#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *Array = NULL, tamano = 0;

    PedirTamano(&Array, &tamano);
    PedirNumeros(Array);
    CalcularyMostrarEstadisticos(*Array);
    





    return 0;
}

void PedirTamano(int **Array, int *tamano)
{
    do{
        printf("Escriba cuántos valores va a introducir. (Máximo 20)\n");
        scanf("%d",tamano);
    }while(!(*tamano<0 && *tamano>20));

}