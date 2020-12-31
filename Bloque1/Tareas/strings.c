#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

void leerStrings(char string1[20], char string2[20], int *tamano1, int *tamano2);
void voltear_e_imprimir(char string1[20],char string2[20], int tamano1, int tamano2);
void CompararStrings(char str1[20], char str2[20]);
void QuitarEspacios(char *string);

int main()
{
    char string1[20], string2[20];
    int size1 = 0, size2 = 0;
    leerStrings(string1,string2, &size1, &size2);
    voltear_e_imprimir(string1,string2, size1, size2);
    CompararStrings(string1,string2);
    QuitarEspacios(string1);
    return 0;
}


void leerStrings(char string1[20], char string2[20], int *tamano1, int *tamano2)
{
    printf("Dame tu primer palabra :)\n");
    fgets(string1, 20, stdin);
    *tamano1 = strlen(string1)-1;
    string1[*tamano1]=0;
    fpurge(stdin);
    printf("Dame tu segunda palabra :)\n");
    fgets(string2, 20, stdin);
    *tamano2 = strlen(string2)-1;
    string2[*tamano2]=0;
    fpurge(stdin);
}
void voltear_e_imprimir(char string1[20],char string2[20], int tamano1, int tamano2)
{
    printf("Tu primera palabra volteada: ");
    for(int i = tamano1; i>=0; --i)
    {
        printf("%c",string1[i]);
    }
    printf(".\n");
    printf("Tu segunda palabra volteada: ");
    for(int i = tamano2; i>=0; --i)
    {
        printf("%c",string2[i]);
    }
    printf(".\n");
}
void CompararStrings(char str1[20], char str2[20])
{
    int compare = strcmp(str1,str2); // strcmp y strcasecmp; strcasecmp compara sin considerar mayúsculas.
    if(compare==0)
    {
        printf("Son iguales\n");
    } else
    {
        printf("NEL COMPADRE\n");
    }
    // BUSCAR STRTOK; strcat concatena strings
}

void QuitarEspacios(char *str)
{
    char * token = strtok(str, " ");
    while(token!=NULL)
    {
        printf("%s",token);
        token = strtok(NULL, " ");
    }
    printf("\n"); 
}
