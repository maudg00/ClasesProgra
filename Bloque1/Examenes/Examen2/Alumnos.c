#include "Alumnos.h"


void AlumnosDeclarar(int *tamano, Alumno **ListaAlumnos)
{
    printf("Introduzca el numero de alumnos a poner en la lista:\n");
    scanf("%d",tamano);
    fpurge(stdin);

    *ListaAlumnos = malloc(*tamano * sizeof(Alumno));
}

char NumerALetra(float calificacion)
{
    char Letra;
    if(calificacion>=9) { return 'A'; }
    else if(calificacion<9 && calificacion>=8) { return 'B'; }
    else if(calificacion<8 && calificacion>=7) { return 'C'; }
    else if(calificacion<7 && calificacion>=6) { return 'D'; }
    else { return 'F'; }
}

int validarCalif(float num)
{
    if(num<0 || num>10)
    {
        printf
        (
            "El valor otorgado de calificación no es válido."
           "Intente de nuevo.\n"
        );
        return FALSE;
    }
    else{ return TRUE; }
}

int validarGrade(int grado)
{
    if(grado<1||grado>3)
    {
        printf("El grado introducido no es válido. Intente de nuevo.\n");
        return FALSE;
    }
    else { return TRUE; }
}

void AlumnosLlenar(int tamano, Alumno **Alumnos)
{
    char Nombre[50]; int flag;
    for(int i=0; i<tamano; i++)
    {
        printf("Alumno %d:\n",i+1);
        printf("\tEscriba el nombre del alumno: ");
        fgets(Nombre,48,stdin);
        Nombre[strlen(Nombre)-1]=0;
        strcpy((*Alumnos+i)->Nombre,Nombre);
        // Llena grado.
        do
        {
            printf("\tEscriba el grado del alumno (1o, 2o, o 3o): ");
            scanf("%do",&(*Alumnos+i)->grado);
            fpurge(stdin);
        
        }while(validarGrade((*Alumnos+i)->grado)==FALSE);
        // Llena calificación numérica
        do
        {
            printf("\tEscriba la calificacion numerica del alumno: ");
            flag = scanf("%f",&(*Alumnos+i)->califNumer);
            fpurge(stdin);
        } 
        while(validarCalif((*Alumnos+i)->califNumer)==FALSE ||  flag==0);
        // Llenar letra: No necesita pedirse desde terminal.
        (*Alumnos+i)->Letra = NumerALetra((*Alumnos+i)->califNumer);
    }
}

void AlumnosArchivo(int tamano, Alumno **Alumnos)
{
    FILE * students=fopen("alumnos.txt","wt");

    fprintf(students,"Lista de estudiantes:\n\n");

    for(int i=0; i<tamano; i++)
    {
        fprintf
        (
            students,
            "Alumno %d: %s\n\t"
            "Grado: %do\n\t"
            "Calificacion Numerica: %.2f\n\t"
            "Calificacion en letra: %c\n\n",
            i+1,
            (*Alumnos+i)->Nombre,
            (*Alumnos+i)->grado,
            (*Alumnos+i)->califNumer,
            (*Alumnos+i)->Letra
            );
    }
    fclose(students);
    printf("\nArchivo \"alumnos.txt\" generado.\n");
}

/* Método para hacer lista de alumnos en terminal. */
void callAlumnos(void)
{
    int num=0;
    Alumno *Lista;
    clrscr();
    AlumnosDeclarar(&num, &Lista);
    AlumnosLlenar(num, &Lista);
    AlumnosArchivo(num, &Lista);
    utilitiesEnter();
    free(Lista);
    clrscr();
}