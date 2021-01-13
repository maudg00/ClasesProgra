#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


/******************************************************************************

Recibe una semilla y devuelve un número aleatorizado módulo a

@param long seed: número del cual se genera el número aleatorio.

@returns long int aleatorizado.

*******************************************************************************/
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

/******************************************************************************

Toma un valor entre 0 y 6

@param long seed: número del cual se genera el número aleatorio.

@returns long int aleatorizado.

*******************************************************************************/
char AssignValuePWD(unsigned short int value)
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
char* crearPasswordRepeated(long int seed, int length)
{
    char * Password; // PWD de 4 caracteres debido a naturaleza del juego.
    unsigned short int residue;

    Password = malloc((length+1)*sizeof(char)); 

    for(int i=0;i<length;i++)
    {
        seed = LCG(seed);
        residue = seed%7;
        *(Password+i) = AssignValuePWD(residue);
    }
    // Con el fin de poder comparar strings más fácilmente, el último es null.
    *(Password+length) = 0; 
    return Password;
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
    char * Choice = "RAYMBNC";
    unsigned short int residue, tmp, j=0;

    Password = malloc((length+1)*sizeof(char)); 

    for(int i=strlen(Choice)-1;i<length;i--)
    {
        seed = LCG(seed);
        residue = seed%(i+1);
        //Shuffle:
        tmp = *(Choice+residue);
        *(Choice+residue) = *(Choice+i);
        *(Choice+i) = tmp;
        //Assign values from shuffle
        *(Password+j) = *(Choice+i);
        j++;
    }
    // Con el fin de poder comparar strings más fácilmente, el último es null.
    *(Password+length) = 0; 
    return Password;
}

/* Revisa cuántos dígitos coinciden en posición con la contraseña.
* 
* @param char* Pwd: Contraseña contra la que se compara
* @param char* Attempt: contraseña intentada
*
* @returns Número de dígitos que coinciden en posición con la contraseña.
*
*/
int CheckPositionPWD(char * Pwd, char * Attempt)
{
    int count = 0;
    int length = strlen(Pwd);
    for(int i=0; i<length; i++)
    {
        if(*(Pwd+i)==toupper(*(Attempt+i)))
        {
            count++;
        }
    }
    return count;
}

/* Revisa cuántos colores coinciden con la contraseña sin importar posición
*
* NOTA JL: Tengo la impresión que es muy optimizable esta función, pero no lo 
* he intentado optimizar.
*
* @param char* Pwd: Contraseña contra la que se compara
* @param char* Attempt: Intento contra el que se compara
*
* @returns Número de colores que coinciden.
*
*/
int CheckColorsPWD(const char* Pwd, char* Attempt)
{
    const short length = strlen(Pwd);
    int count;
    for(int i=0;i<length;i++)
    {
        for(int j=0; j<length; j++)
        {
            if(toupper(*(Pwd+i))== *(Attempt+j))
            {
                *(Attempt+j) = 0;
                count++;
                break;
            }
        }
    }
    return count;
}

/******************************************************************************

Revisa un password introducido contra un patrón.

@param number int length - Longitud de la contraseña.
@param char* Pwd: Contraseña patrón.
@param char* Attempt: Contraseña intentada.

@returns int: 0 si es correcta, -1 si es incorrecta. 

*******************************************************************************/
int CheckPassword(char * Pwd, char * Attempt)
{
    int position=0, color=0;

    if(strcasecmp(Pwd,Attempt)==0)
    {
        printf("La contraseña es correcta!! Su valor era: %s\n",*Pwd);
        return 0;
    } 
    else
    {
        position = CheckPositionPWD(Pwd, Attempt);
        color = CheckColorsPWD(Pwd,Attempt);
        printf("Tiene %d colores correctos, con %d en la posición correcta.\n",
        color, position);
        return -1;
    }
}