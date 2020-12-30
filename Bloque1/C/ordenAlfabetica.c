#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void pedirLista(char Matriz[10][20], int *tamano);
void ordenarLista(char Matriz[10][20], int tamano);
void desplegarLista(char Matriz[10][20], int tamano);
int main()
{
    char Matriz[10][20];
    int tamano=0;
    pedirLista(Matriz, &tamano);
    ordenarLista(Matriz, tamano);
    desplegarLista(Matriz, tamano);
}
void pedirLista(char Matriz[10][20], int *tamano)
{
    int i;
    do
    {
        printf("Dime cuantos nombres vas a meter: ");
        scanf("%d", tamano);
        fflush(stdin);
    } 
    while(!(*tamano>0 && *tamano<=10));
    for(i=0; i<*tamano; i++)
    {
        printf("Dame el nombre %d: ", (i+1));
        fgets(Matriz[i], 18, stdin);
        Matriz[i][strlen(Matriz[i])-1]=0;
    }
}
void ordenarLista(char Matriz[10][20], int tamano)
{  
    int i, j;
    char temp[20];
    int valorcomp;
    for(i=0; i<tamano; i++)
    {
        temp[0]=0;
        valorcomp=0;
        for(j=0; j<tamano; j++)
        {
            valorcomp=strcmp(Matriz[i], Matriz[j]);
            if(valorcomp<0)
            {
                strcpy(temp,Matriz[i]);
                strcpy(Matriz[i], Matriz[j]);
                strcpy(Matriz[j], temp);
            }
        }
    }
}
void desplegarLista(char Matriz[10][20], int tamano)
{
    int i;
    printf("Tu lista ordenada es: \n");
    for(i=0; i<tamano; i++)
    {
        printf("%s\n", Matriz[i]);
    }
}