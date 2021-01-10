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
void Alumnos(Alumno **ListaAlumnos);
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
    int indice=0, num=0;
    double resultado=0;
    Alumno *Lista;
    switch (option)
    {
    case '1':
        clrscr();
        do
        {
            printf("A continuación se le pedirá un entero impar(entre 1 y 11) para construir\n"
            "un cuadro mágico.\n");
            utilitiesEnter();
            indice = utilitiesPedirEntero();
            if(!(indice>1&&indice<=11) || indice%2 == 0 || utilitiesValidarEntero(indice)==FALSE)
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
        clrscr();
        AlumnosDeclarar(&num, &Lista);
        AlumnosLlenar(num, &Lista);
        AlumnosArchivo(num, &Lista);
        utilitiesEnter();
        clrscr();
        return 0;
    break;
    case '3':
        clrscr();
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
        clrscr();
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