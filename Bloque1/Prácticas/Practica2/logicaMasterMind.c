#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


/* Recibe una semilla y devuelve un número aleatorizado módulo a*/
long int LCG(long int seed)
{
    long long m = pow(2,48);
    long int a = 0x5DEECE66D;
    int c = 11;

    for(int i=0; i<15; i++)
    {
        seed = (m*seed+c)%a;
    }

    return seed;
}

char AssignValuePWD(short int value)
{
    switch (value)
        {
        case 0:
            return 'R';
        break;
        case 1:
            return 'A';
        break;
        case 2:
            return 'Y';
        break;
        case 3:
            return 'M';
        break;
        case 4:
            return 'B';
        break;
        case 5:
            return 'N';
        break;
        case 6:
            return 'C';
        break;
        default:
            printf("ERROR: Algún cálculo salió mal. Lo siento :(\n");
            return 0;
        break;
        }
}

/******************************************************************************


Crea un password de 7 tipos de caracteres distintos usando un algoritmo de
generación lineal, dado un seed y una longitud de contraseña. 

@param long seed: idealmente basada en el tiempo en que se toma.
@param int length: Longitud de la contraseña.

@returns char * password: contraseña de 7 valores posibles {R,A,Y,M,B,N,C}. 
Pueden encontrarse repetidos. 

*******************************************************************************/
char* crearPassword(long int seed, int length)
{
    char * Password; // PWD de 4 caracteres debido a naturaleza del juego.
    short int residue;

    Password = malloc(length*sizeof(char)); 

    

    for(int i=0;i<length;i++)
    {
        seed = LCG(seed);
        residue = seed%7;
        *(Password+i) = AssignValuePWD(residue);
    }

    return Password;
}