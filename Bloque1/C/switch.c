#include <stdio.h>
#include <stdlib.h>
void Menu(int *opcion);
void opcion1();
void opcion2();
void opcion3();
int main()
{
    int opcion;
    do
    {
        Menu(&opcion);
        switch(opcion)
        {
            case 1:
                opcion1();
                printf("Esa fue la opcion 1 :).\n");
            break;
            case 2: //if(opcion==2){                            
                opcion2();
                printf("Esa fue la opcion 2 :).\n");
            break; //}
            case 3:
                opcion3();
                printf("Esa fue la opcion 3 :).\n");
            break;
            case 4:
                printf("Muchas gracias por usar este programa :).\n");
            break;
            default:
                printf("Esa opcion no existe.\n");
            break;
        }
    }
    while (opcion!=4);
    
}
void Menu(int *opcion)
{
    char enter;
    printf("Menu\n");
    printf("\tOpcion 1: imprime 'Hola mundo'.\n");
    printf("\tOpcion 2: imprime 'Adios mundo'.\n");
    printf("\tOpcion 3: imprime 'En serio ahora si adios'.\n");
    printf("\tOpcion 4: salir.\n");
    printf("Dame tu opcion: ");
    scanf("%d", opcion);
    fflush(stdin);
    printf("Presiona <enter> para continuar...\n");
    scanf("%c", &enter);
    fflush(stdin);
}
void opcion1()
{
    printf("Hola mundo.\n");
}
void opcion2()
{
    printf("Adios mundo.\n");
}
void opcion3()
{
    printf("En serio ahora si adios.\n");
}