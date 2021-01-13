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
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


int main()
{
    char option;
    scanf("%c",&option);
    fpurge(stdin);

    switch (option)
    {
    case '1':
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
    return 0;
}
