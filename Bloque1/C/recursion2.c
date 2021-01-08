#include "utilities.h"
void pedirString(char *string);
void imprimirString(char *string, int i);
int main()
{
    char string[50];
    pedirString(string);
    imprimirString(string, (int)strlen(string));
}
void pedirString(char *string)
{
    printf("Dame tu palabra: ");
    fgets(string, 48, stdin);
    utilitiesQuitarEnterString(string);
}
void imprimirString(char *string, int i)
{
    if(i>0)
    {
        imprimirString(string, i-1);
    }
    if(i!=strlen(string))
    {
        printf("%c", string[i]);
    }
    
}