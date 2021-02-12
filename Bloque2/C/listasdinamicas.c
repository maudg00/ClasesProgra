#include "utilities.h"
struct StructAlumnos
{

    int calificacion;
    char Nombre[30];
    struct StructAlumnos* Siguiente;
};
typedef struct StructAlumnos Alumnos;
void inicializarLista(Alumnos **Inicio, Alumnos *PrimerElemento);
void liberarLista(Alumnos *Inicio);
int main()
{
    Alumnos* Inicio=NULL;
    Alumnos JoseLuis;
    printf("Dime la calificacion del primer alumno.\n");
    scanf("%d", &JoseLuis.calificacion);
    fflush(stdin);
    printf("Dime el nombre del alumno.\n");
    fgets(JoseLuis.Nombre, 30, stdin);
    utilitiesQuitarEnterString(JoseLuis.Nombre);
    JoseLuis.Siguiente=NULL;
    fflush(stdin);
    inicializarLista(&Inicio, &JoseLuis);
}
void inicializarLista(Alumnos **Inicio, Alumnos *PrimerElemento)
{
    *Inicio=malloc(sizeof(Alumnos*));
    *Inicio=PrimerElemento;
}