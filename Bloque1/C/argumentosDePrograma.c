#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void imprimirNombres(int argc, char *argv[]);
int main(int argc, char *argv[])
{
    if(argc==1)
    {
        printf("Bienvenido! Ingresa hola/adios y una lista de nombres en los comandos para que te salude :).\n");
        return 1;
    }
    if((strcmp("hola", argv[1]))!=0 && (strcmp("adios", argv[1]))!=0)
    {
        printf("%s\n", argv[1]);
        printf("Tu primer argumento es erroneo.\n");
        return 1;
    }
    imprimirNombres(argc, argv);
}
void imprimirNombres(int argc, char *argv[])
{
    printf("%s: ", argv[1]);
    for(int i=2; i<argc; i++)
    {
        if(i==argc-1)
        {
            printf("%s.\n", argv[i]);
        }
        else
        {
            printf("%s, ", argv[i]);
        }
    }
}
