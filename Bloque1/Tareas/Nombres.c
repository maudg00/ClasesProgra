#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>
#define true 1
#define false 0
#define clrscr() printf("\e[1;1H\e[2J")

int pedirNumeroNombres(void);
void pedirNombres(int num, char names[10][25]);
void ordenarAlfabetico(int num, char names[10][25]);
void MostrarNombres(int num, char names[10][25]);

int main()
{
    clrscr();
    char names[10][25];
    int num = pedirNumeroNombres();
    pedirNombres(num,names);
    ordenarAlfabetico(num,names);
    MostrarNombres(num,names);
}

int pedirNumeroNombres(void)
{
    int num = 0;
    while(true)
    {
        printf("Inserte el número de nombres que va a introducir (máximo 10):\n");
        scanf("%d",&num);
        fpurge(stdin);
        if( num<=10 && num>0 ) { break; } 
        else 
        {
            clrscr(); 
            printf("Introduzca un número válido.\n"); 
        }
    }
    
    return num;
}

void pedirNombres(int num, char names[10][25])
{
    printf("Inserte los %d nombres: \n", num);
    for(int i = 0; i<num;i++)
    {
        fgets(names[i],20,stdin);
        names[i][strlen(names[i])-1]=0;
    }
}

void ordenarAlfabetico(int num, char names[10][25])
{
    char inter[25];
    int comparison = 0;
    for(int i=0; i<num; i++)
    {
        comparison=0;
        inter[0]=0;
        for(int j=0; j<num; j++)
        {
            comparison = strcasecmp(names[i],names[j]);
            if(comparison<0)
            {
                strcpy(inter,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],inter);
            }
        }
    }
}

void MostrarNombres(int num, char names[10][25])
{
    printf("Los nombres ordenados alfabéticamente son los siguientes:\n");
    for(int i=0;i<num;i++)
    {
        printf("%s\n",names[i]);
    }
}