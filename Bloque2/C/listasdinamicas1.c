#include "utilities.h"
struct StructAlumnos
{

    int calificacion;
    char Nombre[30];
    struct StructAlumnos* Siguiente;
};
typedef struct StructAlumnos Alumnos;
void inicializarLista(Alumnos **Inicio, Alumnos *PrimerElemento);
void llenarLista(Alumnos *Inicio);
void imprimirLista(Alumnos *Inicio);
void liberarLista(Alumnos *Inicio);
int main()
{
    Alumnos* Inicio=NULL;
    Alumnos JoseLuis;
    printf("Dime el nombre del alumno.\n");
    fgets(JoseLuis.Nombre, 30, stdin);
    utilitiesQuitarEnterString(JoseLuis.Nombre);
    printf("Dime la calificacion del primer alumno.\n");
    scanf("%d", &JoseLuis.calificacion);
    fflush(stdin);
    JoseLuis.Siguiente=NULL;
    fflush(stdin);
    inicializarLista(&Inicio, &JoseLuis);
    llenarLista(Inicio);
    imprimirLista(Inicio);
    liberarLista(Inicio);
}
void inicializarLista(Alumnos **Inicio, Alumnos *PrimerElemento)
{
    *Inicio=malloc(sizeof(Alumnos*));
    *Inicio=PrimerElemento;
}
void llenarLista(Alumnos *Inicio)
{
    Alumnos *temp=Inicio;
    int cali;
    while(temp->Siguiente!=NULL)
    {
        temp=temp->Siguiente;
    }
    temp->Siguiente=malloc(sizeof(Alumnos*));
    temp=temp->Siguiente;
    printf("Dime el nombre: ");
    fgets(temp->Nombre, 30, stdin);
    utilitiesQuitarEnterString(temp->Nombre);
    printf("Dime la calificacion: ");
    scanf("%d", &cali);
    temp->calificacion=cali;
    temp->Siguiente=NULL;
}
void imprimirLista(Alumnos *Inicio)
{
    Alumnos *temp=Inicio;
    while(temp!=NULL)
    {
        printf("Alumno:\n");
        printf("Nombre: %s\n", temp->Nombre);
        printf("Calificacion: %d\n", temp->calificacion);
        temp=temp->Siguiente;
    }
}
void liberarLista(Alumnos *Inicio)
{
    Alumnos *temp;
    while(Inicio!=NULL)
    {
        temp=Inicio;
        Inicio=temp->Siguiente;
        free(temp);
    }
}
