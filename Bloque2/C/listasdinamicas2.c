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
void escribirArchivo(Alumnos *Inicio);
void leerArchivo(Alumnos **Inicio);
int main()
{
    Alumnos* Inicio;
    char opcion;
    Inicio=NULL;
    leerArchivo(&Inicio);
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
                escribirArchivo(Inicio);
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
void escribirArchivo(Alumnos *Inicio)
{
    char NombreArch[50];
    char ruta[100];
    FILE * Archivo;
    Alumnos *temp;
    if(Inicio==NULL)
    {
        printf("No se puede escribir achivo: Lista vacia.\n");
        return;
    }
    ruta[0]=0;
    printf("Dime el nombre del archivo, sin extension: ");
    fgets(NombreArch, 50, stdin);
    utilitiesQuitarEnterString(NombreArch);
    strcat(NombreArch,".csv");
    strcat(ruta, "./AlumnosArchivos/");
    strcat(ruta,NombreArch);
    if((strcmp(ruta, "./AlumnosArchivos/.csv"))==0)
    {
        return;
    }
    Archivo=fopen(ruta, "wt");
    temp=Inicio;
    fprintf(Archivo, "Nombre,FechaNacimiento,Semestre,Calificacion\n");
    while(temp!=NULL)
    {
        fprintf(Archivo, "%s, %s, %d, %d\n",temp->Nombre, temp->fechaN, temp->semestre, temp->calificacion);
        temp=temp->Siguiente;
    }
    fclose(Archivo);
}
void leerArchivo(Alumnos **Inicio)
{
    char NombreArch[50];
    char ruta[100];
    char basura[50];
    char lineaActual[100];
    FILE * Archivo;
    Alumnos *temp;
    ruta[0]=0;
    printf("Dime el nombre del archivo, sin extension: ");
    fgets(NombreArch, 50, stdin);
    utilitiesQuitarEnterString(NombreArch);
    strcat(NombreArch,".csv");
    strcat(ruta, "./AlumnosArchivos/");
    strcat(ruta,NombreArch);
    Archivo=fopen(ruta, "rt");
    if(Archivo==NULL)
    {
        printf("ERROR: no existe el archivo.\n");
        return;
    }
    
    //Leer primera linea que no nos sirve de nada.
    fgets(basura,50,Archivo);
    while((fgets(lineaActual, 100, Archivo))!=NULL)
    {
        Alumnos *temp;
        Alumnos *recorrer;
        utilitiesQuitarEnterString(lineaActual);
        temp=malloc(sizeof(Alumnos));
        sscanf(lineaActual, "%s %s %d, %d", temp->Nombre, temp->fechaN, &temp->semestre, &temp->calificacion);
        utilitiesQuitarEnterString(temp->Nombre);
        utilitiesQuitarEnterString(temp->fechaN);
        temp->Siguiente=NULL;
        if((*Inicio)==NULL)
        {
            *Inicio=temp;
        }
        else
        {
            recorrer=(*Inicio);
            while(recorrer->Siguiente!=NULL)
            {
                recorrer=recorrer->Siguiente;
            }
            recorrer->Siguiente=temp;
        }
    }
    fclose(Archivo);
}
void push(Alumnos **Inicio, Alumnos NuevoAlumno)
{
    if(*Inicio==NULL)
    {
        *Inicio=&NuevoAlumno;
        return;
    }
    Alumnos *recorre=*Inicio;
    while(recorre->Siguiente!=NULL)
        recorre=recorre->Siguiente;
    recorre->Siguiente=&NuevoAlumno;
}
