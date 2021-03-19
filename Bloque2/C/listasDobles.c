#include "utilities.h"
struct StructAlumnos
{

    int calificacion;
    char Nombre[30];
    int Semestre;
    char fechanacimiento[20];
    struct StructAlumnos* Siguiente;
    struct StructAlumnos* Anterior;
};
typedef struct StructAlumnos Alumnos;
char menu();
void daraltaInicio(Alumnos **inicio, Alumnos **fin);
void daraltaFin(Alumnos **inicio, Alumnos **fin);
void darbaja(Alumnos **inicio, Alumnos **fin);
void modificar(Alumnos **inicio);
void popQueue(Alumnos **inicio, Alumnos **fin);
void popStack(Alumnos **inicio, Alumnos **fin);
void imprimir(Alumnos *inicio);
void imprimirReves(Alumnos *fin);
void escribirArchivo(Alumnos *inicio);
void leerArchivo(Alumnos **inicio, Alumnos **fin);
void liberar(Alumnos **inicio);
int main()
{
    char opcion;
    Alumnos*inicio=NULL;
    Alumnos*fin=NULL;
    leerArchivo(&inicio, &fin);
    do
    {
        system("cls");
        opcion=menu();
        switch(opcion)
        {
            case '1':
            daraltaFin(&inicio, &fin);
            break;
            case '2':
            daraltaInicio(&inicio, &fin);
            break;
            case '3':
            darbaja(&inicio, &fin);
            break;
            case '4':
            modificar(&inicio);
            break;
            case '5':
            popQueue(&inicio, &fin);
            break;
            case '6':
            popStack(&inicio, &fin);
            break;
            case '7':
            imprimir(inicio);
            break;
            case '8':
            imprimirReves(fin);
            break;
            case '9':
            escribirArchivo(inicio);
            liberar(&inicio);
            fin=NULL;
            break;
            default:
            printf("Esa opcion no es correcta, intenta de nuevo.");
            break;
        }
        utilitiesEnter();
    } while (opcion!='9');
    
}
char menu()
{
    char opcion;
    printf("Opcion 1: dar alumno de alta al final de la lista\n");
    printf("Opcion 2: dar alumno de alta al inicio de la lista\n");
    printf("Opcion 3: dar de baja\n");
    printf("Opcion 4: modificar\n");
    printf("Opcion 5: Borrar primer elemento de la lista\n");
    printf("Opcion 6: Borrar ultimo elemento de la lista\n");
    printf("Opcion 7: imprimir lista de alumnos en orden\n");
    printf("Opcion 8: imprimir lista de alumnos al reves\n");
    printf("Opcion 9: salir\n");
    scanf("%c", &opcion);
    fflush(stdin);
    return opcion;
}
void daraltaInicio(Alumnos **inicio, Alumnos **fin)
{
    Alumnos*AlumnoNuevo;
    AlumnoNuevo=malloc(sizeof(Alumnos));
    AlumnoNuevo->Siguiente=NULL;
    AlumnoNuevo->Anterior=NULL;
    printf("Escribe el nombre del alumno:\n");
    fgets(AlumnoNuevo->Nombre,30,stdin);
    utilitiesQuitarEnterString(AlumnoNuevo->Nombre);
    printf("Escribe la fecha de nacimiento del alumno:\n");
    fgets(AlumnoNuevo->fechanacimiento,20,stdin);
    utilitiesQuitarEnterString(AlumnoNuevo->fechanacimiento);
    printf("Escribe el semestre del alumno:\n");
    scanf("%d", &AlumnoNuevo->Semestre);
    fflush(stdin);
    printf("Escribe la calificacion del alumno:\n");
    scanf("%d", &AlumnoNuevo->calificacion);
    fflush(stdin);
    if(*inicio==NULL)
    {
        *inicio=AlumnoNuevo;
        *fin=AlumnoNuevo;
    }
    else
    {
       (*inicio)->Anterior=AlumnoNuevo;
       AlumnoNuevo->Siguiente=*inicio;
       *inicio=AlumnoNuevo;
    }
}
void daraltaFin(Alumnos **inicio, Alumnos **fin)
{
    Alumnos*AlumnoNuevo;
    AlumnoNuevo=malloc(sizeof(Alumnos));
    AlumnoNuevo->Siguiente=NULL;
    AlumnoNuevo->Anterior=NULL;
    printf("Escribe el nombre del alumno:\n");
    fgets(AlumnoNuevo->Nombre,30,stdin);
    utilitiesQuitarEnterString(AlumnoNuevo->Nombre);
    printf("Escribe la fecha de nacimiento del alumno:\n");
    fgets(AlumnoNuevo->fechanacimiento,20,stdin);
    utilitiesQuitarEnterString(AlumnoNuevo->fechanacimiento);
    printf("Escribe el semestre del alumno:\n");
    scanf("%d", &AlumnoNuevo->Semestre);
    fflush(stdin);
    printf("Escribe la calificacion del alumno:\n");
    scanf("%d", &AlumnoNuevo->calificacion);
    fflush(stdin);
    if(*inicio==NULL)
    {
       
        *inicio=AlumnoNuevo;
        *fin=AlumnoNuevo;
    }
    else
    {
       (*fin)->Siguiente=AlumnoNuevo;
       AlumnoNuevo->Anterior=*fin;
       *fin=AlumnoNuevo;
    }
}
void darbaja(Alumnos **inicio, Alumnos **fin)
{
    if(*inicio==NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }
    char nombre[30];
    Alumnos*temp=*inicio;
    printf("A quien quieres dar de baja?\n");
    fgets(nombre,30,stdin);
    utilitiesQuitarEnterString(nombre);
    while((strcmp(nombre,temp->Nombre))!=0)
    {
        temp=temp->Siguiente;
        if(temp==NULL)
        {
            printf("No existe el alumno\n");
            return;
        }
    }
    if((*inicio)==(*fin))
    {
        *inicio=NULL;
        *fin=NULL;
        free(temp);
        return;
    }
    if(temp==*inicio)
    {
        (*inicio)=(*inicio)->Siguiente;
        (*inicio)->Anterior=NULL;
        free(temp);
        return;
    }
    if (temp==*fin)
    {
        (*fin)=(*fin)->Anterior;
        (*fin)->Siguiente=NULL;
        free(temp);
        return;
    }
    temp->Anterior->Siguiente=temp->Siguiente;
    temp->Siguiente->Anterior=temp->Anterior;
    free(temp);
}
void modificar(Alumnos **inicio)
{
    if(*inicio==NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }
    char nombre[30];
    Alumnos*temp=*inicio;
    printf("A quien quieres modificar?\n");
    fgets(nombre,30,stdin);
    utilitiesQuitarEnterString(nombre);
    while((strcmp(nombre,temp->Nombre))!=0)
    {
        temp=temp->Siguiente;
        if(temp==NULL)
        {
            printf("No existe el alumno\n");
            return;
        }
    }
    printf("Dame el semestre nuevo: \n");
    scanf("%d", &temp->Semestre);
    fflush(stdin);
    printf("Dame la calificacion nueva: \n");
    scanf("%d", &temp->calificacion);
    fflush(stdin);
}
void popQueue(Alumnos **inicio, Alumnos **fin)
{
    if(inicio==NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }
    Alumnos *temp=*inicio;
    (*inicio)=temp->Siguiente;
    if(*inicio==NULL)
    {
        *fin=NULL;
    }
    printf("Voy a borrar %s\n", temp->Nombre);
    free(temp);
}
void popStack(Alumnos **inicio, Alumnos **fin)
{
    if(inicio==NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }
    Alumnos *temp=*fin;
    (*fin)=(*fin)->Anterior;
    if(*fin==NULL)
    {
        *inicio=NULL;
    }
    else
        temp->Anterior->Siguiente=NULL;
    printf("Voy a borrar a %s\n", temp->Nombre);
    free(temp);
}
void imprimir(Alumnos *inicio)
{
    if(inicio==NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }
    Alumnos*temp=inicio;
    while(temp!=NULL)
    {
        printf("Nombre: %s\n", temp->Nombre);
        printf("Fecha de nacimiento: %s\n", temp->fechanacimiento);
        printf("Semestre: %d\n", temp->Semestre);
        printf("Calificacion: %d\n", temp->calificacion);
        temp=temp->Siguiente;
    }
}
void imprimirReves(Alumnos *fin)
{
    if(fin==NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }
    Alumnos*temp=fin;
    while (temp!=NULL)
    {
        printf("Nombre: %s\n", temp->Nombre);
        printf("Fecha de nacimiento: %s\n", temp->fechanacimiento);
        printf("Semestre: %d\n", temp->Semestre);
        printf("Calificacion: %d\n", temp->calificacion);
        temp=temp->Anterior;
    }
}
void escribirArchivo(Alumnos *inicio)
{
    if(inicio==NULL) return;
    FILE*archivo;
    char nombreArchivo[50];
    printf("Dame el nombre del archivo sin extension:\n");
    fgets(nombreArchivo, 50, stdin);
    utilitiesQuitarEnterString(nombreArchivo);
    strcat(nombreArchivo, ".csv");
    archivo=fopen(nombreArchivo, "wt");
    fprintf(archivo, "Nombre, Fecha de nacimiento, Semestre, Calificacion\n");
    Alumnos*temp=inicio;
    while(temp!=NULL)
    {
        fprintf(archivo,"%s, %s, %d, %d\n", temp->Nombre, temp->fechanacimiento, temp->Semestre, temp->calificacion);
        temp=temp->Siguiente;
    }
    fclose(archivo);
}
void leerArchivo(Alumnos **inicio, Alumnos **fin)
{
    FILE*archivo;
    char nombreArchivo[50];
    printf("Dame el nombre del archivo sin extension:\n");
    fgets(nombreArchivo, 50, stdin);
    utilitiesQuitarEnterString(nombreArchivo);
    strcat(nombreArchivo, ".csv");
    archivo=fopen(nombreArchivo, "rt");
    if(archivo==NULL)
    {
        return;
    }
    char basura[100];
    char lineaActual[100];
    fgets(basura, 100, archivo);
    while((fgets(lineaActual, 100, archivo))!=NULL)
    {
        utilitiesQuitarEnterString(lineaActual);
        Alumnos*temp;
        Alumnos*Recorre;
        temp=malloc(sizeof(Alumnos));
        temp->Anterior=NULL;
        sscanf(lineaActual, "%s %s %d, %d", temp->Nombre, temp->fechanacimiento, &temp->Semestre, &temp->calificacion);
        utilitiesQuitarEnterString(temp->Nombre);
        utilitiesQuitarEnterString(temp->fechanacimiento);
        temp->Siguiente=NULL;
        if((*inicio)==NULL) 
        {
            *inicio=temp;
        }
        else
        {
            (*fin)->Siguiente=temp;
            temp->Anterior=*fin;
        }
        *fin=temp;
    }
    fclose(archivo);
}
void liberar(Alumnos **inicio)
{
    if(*inicio==NULL) return;
    while(*inicio!=NULL)
    {
        Alumnos*temp=*inicio;
        *inicio=(*inicio)->Siguiente;
        free(temp);
    }
}