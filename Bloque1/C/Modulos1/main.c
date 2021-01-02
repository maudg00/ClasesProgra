#include "funciones.h"
#include "vista.h"
void flujoPrograma();
int main()
{
    flujoPrograma();
}
void flujoPrograma()
{
    char opcion;
    do
    {
        system("cls");
        opcion=vistaMenu();
        switch(opcion)
        {
            case '1':
                funcionesHolaMundo();
            break;
            case '2':
                funcionesAdiosMundo();
            break;
            case '3':
                printf("Gracias por usar el programa.\n");
            break;
            default:
                printf("ERROR: opcion invalida.\n");
            break;
        }
        vistaEnter();
    } while (opcion!='3');
}
