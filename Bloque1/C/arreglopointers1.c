#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
char Menu();
void Enter();
void inicializarArreglo(int *Arreglo);
void llenarArreglo(int *Arreglo, int * tamano);
void recorrerArreglo(int *Arreglo, int tamano);
int main()
{
    char opcion;
    int Arreglo[20], tamano;
    int bandera=false;
    inicializarArreglo(Arreglo);
    do
    {
        system("cls");
        opcion=Menu(); 
        switch(opcion)
        {
            case '1':
                llenarArreglo(Arreglo, &tamano);
                Enter();
                bandera=true;
            break;
            case '2':
                if(bandera==false)
                {
                    printf("Error: el arreglo esta vacio.\n");
                }
                else
                {
                    recorrerArreglo(Arreglo, tamano);
                    
                }
                Enter();
                
            break;
            case '3':
                printf("Gracias por usar el programa. Adios.\n");
                Enter();
            break;
            default:
                printf("Opcion invalida.\n");
                Enter();
            break;
        }
    }
    while(opcion!='3');
} 

char Menu()
{
    char opcion;
    printf("Bienvenido!\n");
    printf("\tOpcion 1: llenar un arreglo.\n");
    printf("\tOpcion 2: ver el arreglo.\n");
    printf("\tOpcion 3: salir.\n");
    printf("Dame tu opcion: ");
    scanf("%c", &opcion);
    fflush(stdin);
    return opcion;
}
void Enter()
{
    char enter;
    printf("Presiona <enter> para continuar... ");
    scanf("%c", &enter);
    fflush(stdin);
}
void llenarArreglo(int *Arreglo, int * tamano)
{
    int i;
    do
    {
        printf("Dame el tamanio del arreglo entre 1 y 20: ");
        scanf("%d", tamano);
        fflush(stdin);
        if(!(*tamano>0 && *tamano<21))
        {
            printf("Dimension invalida, vuelva a intentar.\n");
        }
    } while (!(*tamano>0 && *tamano<21));
    for(i=0; i<*tamano; i++)
    {
        printf("Dame el elemento %d de tu arreglo: ", i);
        scanf("%d", Arreglo+i);
        fflush(stdin);
    }
    
}
void recorrerArreglo(int *Arreglo, int tamano)
{
    int i;
    for(i=0; i<tamano; i++)
    {
        printf("El elemento %d de tu arreglo tiene de direccion 0x%p y su contenido es %d.\n", i, (Arreglo+i), *(Arreglo+i));
    }
}
void inicializarArreglo(int *Arreglo)
{
    int i;
    for(i=0; i<20; i++)
    {
        Arreglo[i]=0;
    }
}