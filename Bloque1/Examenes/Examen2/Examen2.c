#include "utilities.h"
#include "cuadroMagico.h"
#include "Alumnos.h"
#include "calculos.h"
#define hline "--------------------------------------------------------------------------------\n"
#define clrscr() printf("\e[1;1H\e[2J")

char MenuExamen(void);
void DescripcionExamen();
int ControlExamen(char option);
void Quit();



int main()
{
    char opcion;
    DescripcionExamen();
    do
    {
        opcion=MenuExamen();
        ControlExamen(opcion);
    }
    while(opcion!=5);
    return 0;
}

char MenuExamen(void)
{
    char option;
    printf(hline"\n" 
        "Menú:\n"
        "\t1. Cuadro mágico\n"
        "\t2. Alumnos\n"
        "\t3. Fibonacci\n"
        "\t4. Factorial\n"
        "\t5. Salir\n"hline);
    scanf("%c",&option);
    fpurge(stdin);
    return option;
}

void DescripcionExamen(void)
{
    clrscr();
    printf(hline"\n\n\n"
"Este es el examen de Jose Luis Aguilar de la clase de programacion en C. \n"
"A continuación se le mostrará un menú.\n\n\n"hline"\n");
    utilitiesEnter();
    clrscr();
}

int ControlExamen(char option)
{
    switch (option)
    {
    case '1':
        callCuadroMagico();
        return 0;
    break;
    case '2':
        callAlumnos();
        return 0;
    break;
    case '3':
        callFibonacci();
        return 0;
    break;
    case '4':
        callFactorial();
        return 0;
    break;
    case '5':
        clrscr();
        Quit();
        return 0;
    break;
    default:
        clrscr();
        printf(hline"\n\nIntroduzca una opción válida.\n\n\n"hline);
        utilitiesEnter();
        clrscr();
        return 1;
    break;
    }
}

void Quit(void)
{
    printf(hline "\n\nMuchas gracias por usar el programa. Hasta luego.\n\n\n\n" hline);
    exit(0);
}