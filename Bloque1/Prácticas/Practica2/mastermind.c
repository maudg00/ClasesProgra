/* mastermind.c

Este programa es un juego de Master Mind. El jugador tiene 16 vidas para poder
adivinar una contraseña de 4 valores distintos ("colores") de 7 posibles. 
Conforme juegue, el programa le indica el número de "colores" acertados y los 
que se encuentren en su posición correcta. Para aprender a jugar, vendrá una 
descripción breve del juego y los controles, desde cómo ingresar la contraseña,
hasta algunas otras opciones, como mostrar su historial de todas las jugadas,
hacer trampa, o rendirse. 

@author José Luis Aguilar Charfén <aguilarch.joseluis@gmail.com>
@author Tania Cesin Abou Atme <MailDeTaniaXd>

13 de enero de 2021.

#include "logicaMasterMind.h"

#include "files.h"
*/
#include "utilities.h"
#include "logicaMasterMind.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main()
{
    char option;
    char * Password;
    int LP = 4; // ! ES LA LONGITUD DEL PASSWORD; por si gustamos cambiarla.
    int lives = LP*(LP+1)/2; // Vidas disponibles para jugar; luego configuro --JL
    struct timespec spec;
    
    while(TRUE)
    {   
        scanf("%c",&option);
        fpurge(stdin);
        switch (option)
            {
            case '1':
                crearPassword(clock_gettime(CLOCK_REALTIME,&spec),LP);
                while(lives>0)
                {
                    fgets(Password,LP+2,stdin);
                    validatePassword();
                    *(Password+LP) = 0; // Siempre se asegura que sea máximo la longitud
                                        // del password.
                    switch (strlen(Password))
                    {
                    case 1:
                        SettingsHandle(Password);
                    break;
                    case 4:
                        
                    break;
                    default:
                    printf("Introduzca una opción válida.\n");
                    break;
                    }
                }
                /* Jugar */
            break;
            case '2':
                /* Leaderboard */
            break;
            case '3':
                /* Opciones (Dificultad) */
            break;
            case '4':
                /* Salir */
            break;
            
            default:
                printf("Introduzca una opción válida por favor.\n");
                utilitiesEnter();
            break;
            }
    }
    return 0;
}
