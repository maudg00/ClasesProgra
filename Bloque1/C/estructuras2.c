#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Definicion_Pacientes
{
    char Nombre[20];
    int edad;
    float peso;
    float altura;
    char condicionClinica[100];
};
typedef struct Definicion_Pacientes Paciente;
char Menu();
void pedirPacientes(int *tamano, Paciente **listaPacientes);
void imprimirPacientes(int tamano, Paciente listaPacientes[10]);
int main()
{
    char opcion;
    int tamano;
    Paciente *listaPacientes;
    do
    {
        opcion=Menu();
        switch(opcion)
        {
            case '1':
                pedirPacientes(&tamano, &listaPacientes);
            break;
            case '2':
                imprimirPacientes(tamano, listaPacientes);
            break;
            case '3':
                printf("Gracias por usar el programa.\n");
            break;
            default:
                printf("ERROR: opcion invalida.\n");
            break;
        }
    } while (opcion!='3');
    
}
char Menu()
{
    char op;
    printf("MENU:\n");
    printf("\t1.- Ingresar lista pacientes.\n");
    printf("\t2.- Ver lista pacientes.\n");
    printf("\t3.- Salir\n");
    scanf("%c", &op);
    fflush(stdin);
    return op;
}
void pedirPacientes(int *tamano, Paciente **listaPacientes)
{
    int i;
    char Nombre[20], condicionClinica[100];
    int edad;
    float altura, peso;
    printf("Cuantos pacientes vas a ingresar? ");
    scanf("%d", tamano);
    fflush(stdin);
    *listaPacientes=malloc(*tamano*sizeof(Paciente));
    for(i=0; i<*tamano; i++)
    {
        printf("Paciente %d: \n", (i+1));
        printf("\tNombre: ");
        fgets(Nombre, 18, stdin);
        Nombre[strlen(Nombre)-1]=0;
        strcpy((*listaPacientes)[i].Nombre, Nombre);
        printf("\tEdad: ");
        scanf("%d", &edad);
        fflush(stdin);
        (*listaPacientes)[i].edad=edad;
        printf("\tPeso: ");
        scanf("%f", &peso);
        (*listaPacientes)[i].peso=peso;
        fflush(stdin);
        printf("\tAltura: ");
        scanf("%f", &altura);
        fflush(stdin);
        (*listaPacientes)[i].altura=altura;
        printf("\tCondicion Clinica: ");
        fgets(condicionClinica, 98, stdin);
        condicionClinica[strlen(condicionClinica)-1]=0;
        strcpy((*listaPacientes)[i].condicionClinica, condicionClinica);
    }
}
void imprimirPacientes(int tamano, Paciente listaPacientes[10])
{
    int i;
    for(i=0; i<tamano; i++)
    {
        printf("Paciente %d: \n", (i+1));
        printf("\tNombre: %s.\n", listaPacientes[i].Nombre);
        printf("\tEdad: %d.\n", listaPacientes[i].edad);
        printf("\tPeso: %f.\n", listaPacientes[i].peso);
        printf("\tAltura: %f.\n", listaPacientes[i].altura);
        printf("\tCondicion Clinica: %s\n", listaPacientes[i].condicionClinica);
    }
}
