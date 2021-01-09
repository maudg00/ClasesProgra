#include "utilities.h"
#include "cuadroMagico.h"
#include "Alumnos.h"
#include "calculos.h"
#define hline "--------------------------------------------------------------------------------\n"
#define clrscr() printf("\e[1;1H\e[2J")

char MenuExamen(void);
void DescripcionExamen();
int ControlExamen(char option);
void CuadroMagico(int num);
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
    printf(hline"\n\n"
"Este es el examen de Jose Luis Aguilar de la clase de programacion en C. \n"
"A continuación se le mostrará un menú.\n\n\n"hline);
    utilitiesEnter();
    clrscr();
}

void Alumnos(Alumno **ListaAlumnos)
{

}

int ControlExamen(char option)
{
    int indice=0, num=0;
    double resultado=0;
    switch (option)
    {
    case '1':
        do
        {
            printf("A continuación se le pedirá un entero impar(entre 1 y 11) para construir\n"
            "un cuadro mágico.");
            utilitiesEnter();
            indice = utilitiesPedirEntero();
            if(!(indice>1&&indice<=11) || indice%2 == 0 || utilitiesValidarEntero==FALSE)
            {
                printf("Por favor introduzca un valor válido\n");
                utilitiesEnter();
                clrscr();
            }
        } while (!(indice>1&&indice<=11) || indice%2 == 0);
        CuadroMagico(indice);
        utilitiesEnter();
        clrscr();
        return 0;
    break;
    case '2':
        return 0;
    break;
    case '3':
        printf("Introduzca el valor a buscar de la serie de Fibonacci: ");
        scanf("%d",&indice);
        fpurge(stdin);
        resultado = Fibonacci(indice);
        printf("El valor %d de Fibonacci es: %.0f\n",indice,resultado);
        utilitiesEnter();
        clrscr();
        return 0;
    break;
    case '4':
        printf("Introduzca el valor a obtener su factorial: ");
        scanf("%d",&indice);
        fpurge(stdin);
        resultado = Factorial(indice);
        printf("El factorial de %d es: %.0f\n",indice,resultado);
        utilitiesEnter();
        clrscr();
        return 0;
    break;
    case '5':
        Quit();
        return 0;
    break;
    default:
        printf("Introduzca una opción válida.\n");
        utilitiesEnter();
        clrscr();
        return 1;
    break;
    }
}

void Quit(void)
{
    printf("Muchas gracias por usar el programa. Hasta luego.\n");
    exit(0);
}