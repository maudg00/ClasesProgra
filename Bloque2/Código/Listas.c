#include "utilities2.h"
struct StructAlumnos
{

    int calificacion;
    char Nombre[30];
    int Semestre;
    char fechanacimiento[20];
    struct StructAlumnos* Siguiente;
};
typedef struct StructAlumnos Alumnos;
char menu();
void daralta(Alumnos **inicio);
void darbaja(Alumnos **inicio);
void modificar(Alumnos **inicio);
void imprimir(Alumnos *inicio);
void escribirArchivo(Alumnos *inicio);
void leerArchivo(Alumnos **inicio);
void liberar(Alumnos **inicio);
int main()
{
    char opcion;
    Alumnos*inicio=NULL;
    leerArchivo(&inicio);
    do
    {
        system("cls");
        opcion=menu();
        switch(opcion)
        {
            case '1':
            daralta(&inicio);
            break;
            case '2':
            darbaja(&inicio);
            break;
            case '3':
            modificar(&inicio);
            break;
            case '4':
            imprimir(inicio);
            break;
            case '5':
            escribirArchivo(inicio);
            liberar(&inicio);
            break;
            default:
            printf("Esa opcion no es correcta, intenta de nuevo.");
            break;
        }
        utilitiesEnter();
    } while (opcion!='5');
    
}
char menu()
{
    char opcion;
    printf("Opcion 1: dar alumno de alta\n");
    printf("Opcion 2: dar alumno de baja\n");
    printf("Opcion 3: modificar alumno\n");
    printf("Opcion 4: imprimir lista de alumnos\n");
    printf("Opcion 5: salir\n");
    scanf("%c", &opcion);
    fflush(stdin);
    return opcion;
}
void daralta(Alumnos **inicio)
{
    Alumnos*AlumnoNuevo;
    AlumnoNuevo=malloc(sizeof(Alumnos));
    AlumnoNuevo->Siguiente=NULL;
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
    }
    else
    {
        Alumnos*Recorre=*inicio;
        while(Recorre->Siguiente!=NULL)
        {
            Recorre=Recorre->Siguiente;
        }
        Recorre->Siguiente=AlumnoNuevo;
    }
}
void darbaja(Alumnos **inicio)
{
    if(*inicio==NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }
    char nombre[30];
    Alumnos*temp=*inicio;
    Alumnos*temp2=*inicio;
    printf("A quien quieres dar de baja?\n");
    fgets(nombre,30,stdin);
    utilitiesQuitarEnterString(nombre);
    while((strcmp(nombre,temp->Nombre))!=0)
    {
        temp2=temp;
        temp=temp->Siguiente;
        if(temp==NULL)
        {
            printf("No existe el alumno\n");
            return;
        }
    }
    if(temp==*inicio)
    {
        (*inicio)=(*inicio)->Siguiente;
        free(temp);
        return;
    }
    temp2->Siguiente=temp->Siguiente;
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
void leerArchivo(Alumnos **inicio)
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
            Recorre=(*inicio);
            while(Recorre->Siguiente!=NULL)
            {
                Recorre=Recorre->Siguiente;
            }
            Recorre->Siguiente=temp;
        }
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