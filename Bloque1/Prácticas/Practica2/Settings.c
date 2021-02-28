#include "Settings.h"




int SettingsHandle(char option)
{
    int difficulty;

    printf(
        "Introduzca el número de la dificultad con la que quiere jugar:\n"
        "\tDificultad: \n\t\t1. Fácil \n\t\t2. Normal \n\t\t3. Difícil\n\n");
    scanf("%d", difficulty);
    return difficulty+2;
}