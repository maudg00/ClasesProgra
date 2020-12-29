#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void leerStrings(char string1[20], char string2[20], int *tamanio1, int *tamanio2);
void voltearEImprimir(char string1[20], char string2[20], int tamanio1, int tamanio2);
int main()
{
    char string1[20], string2[20];
    int tamanio1, tamanio2;
    leerStrings(string1, string2, &tamanio1, &tamanio2);
    voltearEImprimir(string1, string2, tamanio1, tamanio2);
}
void leerStrings(char string1[20], char string2[20], int *tamanio1, int *tamanio2)
{
    int i;
    printf("Empecemos con la primer palabra :).\n");
    printf("Dame tu primer palabra: ");
    fgets(string1, 20, stdin);
    *tamanio1=strlen(string1);
    printf("%d\n", *tamanio1);
    string1[*tamanio1-1]=0;
    printf("Ahora la segunda palabra :).\n");
    printf("Dime cuantos caracteres tiene tu palabra: ");
    scanf("%d", tamanio2);
    fflush(stdin);
    for(i=0; i<*tamanio2; i++)
    {
        printf("Dime la letra %d: ", (i+1));
        scanf("%c", string2+i);
        fflush(stdin);
    }
    string2[i]=0;
    printf("La primer palabra es: %s. La segunda es: %s.\n", string1, string2);
    int comparacion=strcmp(string1, string2);
    if(comparacion==0)
    {
        printf("Son iguales!\n");
    }
    else
    {
        printf("No son iguales :(\n");
    }
    printf("Tu palabra 1 sin espacios: ");
    char * token=strtok(string1, " ");
    while(token!=NULL)
    {
        printf("%s", token);
        token=strtok(NULL, " ");
    }
    printf("\n");
    printf("Tu palabra 1 y 2 pegadas: \n");
    char palabra3[100];
    palabra3[0]=0;
    strcat(palabra3, string1);
    strcat(palabra3, string2);
    printf("%s\n", palabra3);
}
void voltearEImprimir(char string1[20], char string2[20], int tamanio1, int tamanio2)
{
    int i;
    printf("Tu primer palabra al reves: \n");
    for(i=tamanio1-1; i>=0; i--)
    {
        printf("%c", string1[i]);
    }
    printf(".\n");
    printf("Tu segunda palabra al reves: \n");
    for(i=tamanio2-1; i>=0; i--)
    {
        printf("%c", string2[i]);
    }
    printf(".\n");
    printf("Gracias :)\n");
}