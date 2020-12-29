#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void pedirPalabra(char *palabra1);
void quitarEspacios(char * palabraSinEspacios, char *palabra1);
void voltearPalabra(char * palabraVolteada, char * palabraSinEspacios);
void determinarPalindromo(char * palabraSinEspacios, char *palabraVolteada);
int main()
{
    char palabra1[100];
    char palabraSinEspacios[100];
    char palabraVolteada[100];
    pedirPalabra(palabra1);
    quitarEspacios(palabraSinEspacios, palabra1);
    voltearPalabra(palabraVolteada, palabraSinEspacios);
    determinarPalindromo(palabraSinEspacios, palabraVolteada);
}
void pedirPalabra(char *palabra1)
{
    printf("Dame tu oracion y te dire si es palindromo: ");
    fgets(palabra1, 100, stdin);
    palabra1[strlen(palabra1)-1]=0;
}
void quitarEspacios(char * palabraSinEspacios, char *palabra1)
{
    char *token;
    token=strtok(palabra1, " ");
    palabraSinEspacios[0]=0;
    while(token!=NULL)
    {
        strcat(palabraSinEspacios, token);
        token=strtok(NULL, " ");
    }
    
}
void voltearPalabra(char * palabraVolteada, char * palabraSinEspacios)
{
    int i, j;
    palabraVolteada[0]=0;
    j=strlen(palabraSinEspacios)-1;
    for(i=0; i<strlen(palabraSinEspacios); i++)
    {
        palabraVolteada[i]=palabraSinEspacios[j];
        j--;
    }
    palabraVolteada[i]=0;
    
}
void determinarPalindromo(char * palabraSinEspacios, char *palabraVolteada)
{
    if((strcasecmp(palabraSinEspacios, palabraVolteada))==0)
    {
        printf("Si es palindromo.\n");
    }
    else
    {
        printf("No lo es.\n");
    }
    
}