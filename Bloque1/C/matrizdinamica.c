#include <stdio.h>
#include <stdlib.h>
void inicializarMatriz(int ***Matriz, int *filas, int *columnas);
void llenarMatriz(int **Matriz, int filas, int columnas);
void imprimirMatriz(int **Matriz, int filas, int columnas);
int main()
{
    int **Matriz;
    int filas, columnas;
    int i;
    inicializarMatriz(&Matriz, &filas, &columnas);
    llenarMatriz(Matriz, filas, columnas);
    imprimirMatriz(Matriz, filas, columnas);
    for(i=0; i<filas; i++)
    {
        free(Matriz[i]);
    }
    free(Matriz);
}
void inicializarMatriz(int ***Matriz, int *filas, int *columnas)
{
    int i;
    printf("Dame tus filas: ");
    scanf("%d", filas);
    fflush(stdin);
    printf("Dame tus columnas: ");
    scanf("%d", columnas);
    fflush(stdin);
    *Matriz=malloc((*filas)*sizeof(int*));
    for(i=0; i<*columnas; i++)
    {
        *(*Matriz+i)=malloc((*columnas)*sizeof(int));
    }
}
void llenarMatriz(int **Matriz, int filas, int columnas)
{
    int i, j, numero;
    numero=1;
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            Matriz[i][j]=numero;
            numero++;
        }
    }
}
void imprimirMatriz(int **Matriz, int filas, int columnas)
{ // YA TIENE LAS SUMAS CONSIDERADAS
    int i, j, sumas;
    printf("Aqui esta tu matriz: \n");
    for(i=0; i<filas; i++) 
    {
        sumas = 0;
        printf("\t");
        for(j=0; j<columnas; j++)
        {
            printf("%03d ", Matriz[i][j]);
            sumas += Matriz[i][j];
        }
        printf("<– La suma de esta fila es: %d \n", sumas);
    }
}