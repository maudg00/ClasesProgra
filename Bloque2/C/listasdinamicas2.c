#include "utilities.h"
struct StructAlumnos
{

    int calificacion;
    int semestre;
    char Nombre[30];
    char fechaN[20];
    struct StructAlumnos* Siguiente;
};
typedef struct StructAlumnos Alumnos;
char Menu();
void darAlta(Alumnos **Inicio);
void darBaja(Alumnos **Inicio);
void modificar(Alumnos *Inicio);
void imprimir(Alumnos *Inicio);
void liberar(Alumnos **Inicio);
int main()
{
    Alumnos* Inicio;
    char opcion;
    Inicio=NULL;
    do
    {
        system("cls");
        opcion=Menu();
        switch(opcion)
        {
            case '1':
                darAlta(&Inicio);
            break;
            case '2':
                darBaja(&Inicio);
            break;
            case '3':
                modificar(Inicio);
            break;
            case '4':
                imprimir(Inicio);
            break;
            case '5':
                liberar(&Inicio);
                printf("Gracias por usar el programa.\n");
            break;
            default:
                printf("ERROR: Opcion invalida.\n");
            break;
        }
        fflush(stdin);
        utilitiesEnter();
    } while (opcion!='5');
    
}
char Menu()
{
    char opcion;
    printf("Menu: \n\n");
    printf("\t1.- Dar alta.\n");
    printf("\t2.- Dar baja.\n");
    printf("\t3.- Modificar.\n");
    printf("\t4.- Imprimir.\n");
    printf("\t5.- Salir.\n");
    scanf("%c", &opcion);
    fflush(stdin);
    return opcion;
}
void darAlta(Alumnos **Inicio)
{
    Alumnos *temp, *recorrer;
    int bandera, dia, mes, ano;
    temp=malloc(sizeof(Alumnos));
    temp->Siguiente=NULL;
    printf("Dame el nombre: ");
    fgets(temp->Nombre, 30, stdin);
    utilitiesQuitarEnterString(temp->Nombre);
    fflush(stdin);
    do
    {
        bandera=0;
        printf("Dame la fecha de nacimiento: ");
        fgets(temp->fechaN, 30, stdin);
        fflush(stdin);
        utilitiesQuitarEnterString(temp->fechaN);
        if((sscanf(temp->fechaN, "%d/%d/%d", &dia, &mes, &ano))!=3)
        {
            bandera=1;
        }
        else
        {
            if(!(dia>=1 && dia<=31))
            {
                bandera=1;
            }
            if(!(mes>=1 && mes<=12))
            {
                bandera=1;
            }
            if(!(ano>=1000 && ano<=3000))
            {
                bandera=1;
            }
        }
        if(bandera==1)
        {
            printf("ERROR: Formato invalido.\n");
        }
    } while (bandera==1);
    printf("Dime el semestre: ");
    scanf("%d", &temp->semestre);
    fflush(stdin);
    printf("Dime la calificacion: ");
    scanf("%d", &temp->calificacion);
    fflush(stdin);
    if(*Inicio==NULL)
    {
        *Inicio=temp;
    }
    else
    {
        recorrer=*Inicio;
        while(recorrer->Siguiente!=NULL)
        {
            recorrer=recorrer->Siguiente;
        }
        recorrer->Siguiente=temp;
    }
}
void darBaja(Alumnos **Inicio)
{
    char Nombre[30];
    Alumnos* temp=*Inicio;
    Alumnos* tempAnt=*Inicio;
    if(*Inicio==NULL)
    {
        printf("ERROR: Lista vacia.\n");
        return;
    }
    printf("Dime a quien quieres dar de baja: ");
    fgets(Nombre, 30, stdin);
    utilitiesQuitarEnterString(Nombre);
    while((strcmp(temp->Nombre, Nombre)!=0))
    {
        tempAnt=temp;
        temp=temp->Siguiente;
        if(temp==NULL)
        {
            printf("No existe el alumno.\n");
            return;
        }
    }
    //Si se borro el primero hay que
    //  a) Si era el único elemento, hacer a inicio NULL.
    //  b) Si habia más, cambiar a donde apunta inicio.
    if(temp==*Inicio && tempAnt==*Inicio)
    {
        //Si solo existe el primero
        if(temp->Siguiente==NULL)
        {
            printf("SOLO HABIA UNO.\n");
            free(temp);
            *Inicio=NULL;
            return;
        }
        *Inicio=temp->Siguiente;
        free(temp);
    }
    
    tempAnt->Siguiente=temp->Siguiente;
    free(temp);
    
}
void modificar(Alumnos *Inicio)
{
    char Nombre[30];
    Alumnos* temp=Inicio;
    if(Inicio==NULL)
    {
        printf("ERROR: Lista vacia.\n");
        return;
    }
    printf("Dime a quien quieres dar de baja: ");
    fgets(Nombre, 30, stdin);
    utilitiesQuitarEnterString(Nombre);
    while((strcmp(temp->Nombre, Nombre)!=0))
    {
        temp=temp->Siguiente;
        if(temp==NULL)
        {
            printf("No existe el alumno.\n");
            return;
        }
    }
    printf("Dime el semestre: ");
    scanf("%d", &temp->semestre);
    fflush(stdin);
    printf("Dime la calificacion: ");
    scanf("%d", &temp->calificacion);
    fflush(stdin);

}
void imprimir(Alumnos *Inicio)
{
    Alumnos *temp;
    if(Inicio==NULL)
    {
        printf("ERROR: Lista vacia.\n");
        return;
    }
    temp=Inicio;
    while(temp!=NULL)
    {
        printf("Alumno:\n\n");
        printf("\tNombre: %s\n", temp->Nombre);
        printf("\tFecha de Nacimiento: %s\n", temp->fechaN);
        printf("\tSemestre: %d\n", temp->semestre);
        printf("\tCalificacion: %d\n", temp->calificacion);
        temp=temp->Siguiente;
    }
}
void liberar(Alumnos **Inicio)
{
    Alumnos *temp;
    while(*Inicio!=NULL)
    {
        temp=*Inicio;
        *Inicio=temp->Siguiente;
        free(temp);
    }
    
}