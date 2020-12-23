<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5ccbecb (Práctica 1 ya es funcional, falta hacer la documentación.)
// pract1.c
//
// Desarrollado por José Luis Aguilar el 23/12/2020
//
// Este programa permite una pequeña interfaz para poder obtener las sumas 
// consecutivas de un número o hacer un cambio de base, donde la base se 
// encuentre entre 2 y 16.  

// Bibliotecas a incluir
#include <stdio.h>
#include <math.h>
#define clrscr() printf("\e[1;1H\e[2J")
<<<<<<< HEAD
#define hline "-------------------------------------------------------------------------------"
=======
#define hline "--------------------------------------------------------------------------------"
>>>>>>> 5ccbecb (Práctica 1 ya es funcional, falta hacer la documentación.)
#define true 1
#define false 0

// Funciones a declarar

void Author(void), Description(void);
int Menu(float *num, float *base), Quit(void);

/*
* SumasConsecutivas recibe la dirección de memoria de un número entero, y cal
* cula las distintas formas en que puede escribirse el número como una serie de
* sumas consecutivas, y después las imprime.
*
* @params
*   int * num: se recupera el entero para imprimir las sumas.
*
* @returns
*/
void SumasConsecutivas(float *X);
void OddSum(int x, int n), EvenSum(int x, int n);   
/*
* CambioDeBase recibe un entero, la base a la que se cambia y la dirección en
* la que se escribe el entero con base cambiada. Después, imprime el número en 
* la base cambiada.
*
* @params
    int * num: se recupera el entero para imprimir las sumas.
*
* returns:
*/
void CambioDeBase(int num, int base);
int ValidarEnteroPositivo(float num); 
<<<<<<< HEAD
=======
// Bibliotecas a incluir
#include <stdio.h>
#include <stdlib.h>

// Funciones a declarar
void 
    Author(void), 
    Description(void),
    OddSum(int *x, int n),
    EvenSum(int *x, int n);
>>>>>>> 81f12f2 (Práctica 0 hecha, documentación también, primeros adelantos de la práctica 1.)
=======
>>>>>>> 5ccbecb (Práctica 1 ya es funcional, falta hacer la documentación.)

// Main
int main()
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5ccbecb (Práctica 1 ya es funcional, falta hacer la documentación.)
    clrscr();
    int  option = 0, resultado=0;
    float number = 0, base = 0;

    Author();
    Description();
    while (option == 0)
    {
        option = Menu(&number,&base);
    }
    return 0;
}

// Funciones auxiliares
void Author(void)
{
    printf(hline"\n\n\n\n");
    printf("Este programa fue desarrollado por José Luis Aguilar el 23/12/2020.\n"
           "Presione [Enter] para continuar.\n");
    printf("\n\n\n"hline"\n");
    getchar();
    fpurge(stdin);
    clrscr();
}

void Description(void)
{
    printf(hline"\n\n\n\n");
    printf("A continuación se mostrará un menú. Presione [Enter] para continuar.\n");
    printf("\n\n\n\n"hline"\n");
    getchar();
    fpurge(stdin);
    clrscr();
}

void SumasConsecutivas(float *X)
{
    int n = 1;
/* El criterio usado en el while loop sale de la suma de términos consecutivos
de Gauss. Debido a que se toman de dos en dos términos, la sumatoria con 
fórmula n*(n+1)/2 se convierte en (2n+1)*(2n+2)/2 == (2n+1)*(n+1) */
    while ((2*n+1)*(n+1)<= *X) 
    {
        OddSum((int)*X, 2*n+1);
        EvenSum((int)*X, 2*(n+1));
        n++;
    }
<<<<<<< HEAD

=======
    printf("Presione [Enter] para continuar\n");
    fpurge(stdin);
    getchar();
    clrscr();
>>>>>>> 5ccbecb (Práctica 1 ya es funcional, falta hacer la documentación.)
}

void CambioDeBase(int num, int base)
{
    // Validaciones
    if(base > 16)
    {
        printf("La base no es un número o es mayor a 16.\n"
               "Se le regresará al menú ahora.\n");
        printf("Presione [Enter] para continuar.\n");
        fpurge(stdin);
        getchar();
        clrscr();
        return;
    }
    else if(base<2)
    {
        printf("La base no es un número o es menor a 2.\n"
               "Se le regresará al menú ahora.\n");
        printf("Presione [Enter] para continuar.\n");
        fpurge(stdin);
        getchar();
        clrscr();
        return;
    }
    // Declaraciones
    int residuo=0, counter=0;
    int digits = log(num)/log(base); // Propiedad: Log_a(x) = log(x)/log(a) 

    printf("El número en base %d es: ", base);

    while(num>0)
    {
        if(residuo>num)
        {
            residuo-= pow(base,digits); // Se hace porque tiene un overshoot.
            counter--; // también contiene el overshoot
            digits--;
            num-=residuo;
<<<<<<< HEAD
            if(counter==10){ printf("A"); }
            else if(counter==11){ printf("B"); }
            else if(counter==12){ printf("C"); }
            else if(counter==13){ printf("D"); }
            else if(counter==14){ printf("E"); }
            else if(counter==15){ printf("F"); }
            else{ printf("%d",counter); }
=======
            printf("%x",counter);
>>>>>>> 5ccbecb (Práctica 1 ya es funcional, falta hacer la documentación.)
            residuo=0;
            counter=0;
        } 
        else 
        {
            residuo+= pow(base,digits);
            counter++;
        }
    }
    for(int i = 0; i<= digits; i++) // Cuenta ocasiones que el número sea 
    {                               // múltiplo de la base.
        printf("0");
    }
    printf("\n");
    printf("Presione [Enter] para continuar.\n");
    fpurge(stdin);
    getchar();
    clrscr();
}

/* Las siguientes funciones toman como argumento el número a separar en sumas, 
y el número de términos en los que se separarán las sumas. Se calcula usando un
array para acomodar en el número de sumas, y se hace un offset, para que no 
tenga que sumarse con respecto al valor medio. OddSum y EvenSum son usadas
en la función principal.*/

void OddSum(int x, int n)
{
    if(x % (n) == 0) // Validación para que sea correcta la suma.
        { 
            int offset = (n-1)/2;
            int ValorInicial = x/n-offset; // Primer valor en las sumas
            int sumas = ValorInicial;
            /* El primer término está fuera del loop, con el propósito de que 
            al imprimir los valores de la suma, no salga un signo de más. */

            printf("%d sumas consecutivas: \n%d ", n, sumas);
    
            for(int i = 1; i < n; i++)
            {
                sumas = ValorInicial+i;
                printf("+ %d ", sumas);
            }
            printf("\n");
        } 
}

void EvenSum(int x, int n)
{
    if(x%n==n/2)
    { if(x>=n*(n+1)/2)
        {
            int offset = n/2-1;
            int ValorInicial = x/n-offset; 
            /* Primer término fuera del loop, con el propósito de que al 
            imprimir los valores de la suma, no salga un signo de más. */
            int sumas = ValorInicial;
            printf("%d sumas consecutivas: \n%d ", n, sumas);
<<<<<<< HEAD
            for(int i = 1; i < n; i++)
            {
                sumas = ValorInicial+i;
                printf("+ %d ", sumas);
            }
            printf("\n");
        }
    }
}

int Menu(float *num, float *base)
{
    int option = 0, flag=false;

    printf(hline "\n");
    printf
    (
        "\t\t\t\t    Menú\n\t\t\t\t   ------\n"
        "Escoge una opción escribiendo el número "
        "de la acción que desees tomar:\n\n"
        "\t1. Cambio de base a un número\n"
        "\t2. Calcular sumas consecutivas de un número\n"
        "\t3. Salir\n"
    );
    printf("\n" hline "\n");
    scanf("%d",&option);
    clrscr();
    if(option==1)
    {
        while(true)
        {
            printf("Introduzca el número entero positivo a convertir: ");
            scanf("%f",num);
            flag = ValidarEnteroPositivo(*num);
            if(flag==false)
            { 
                printf("Ahora regresará al menú.\n"
                "Presione [Enter] para continuar.\n");
                fpurge(stdin);
                getchar();
                clrscr();
                break;
            }
            printf("Introduzca la primera base (entre 2 y 16) a la que desea convertir: ");
            scanf("%f",base);
            flag = ValidarEnteroPositivo(*base);
            if(flag==false)
            { 
                printf("Ahora regresará al menú.\n"
                "Presione [Enter] para continuar.\n");
                fpurge(stdin);
                getchar();
                clrscr();
                break; 
            }
            CambioDeBase((int)*num,(int)*base);
            printf("Introduzca la segunda base (entre 2 y 16) a la que desea convertir: ");
            scanf("%f",base);
            flag = ValidarEnteroPositivo(*base);
            if(flag==false)
            { 
                printf("Ahora regresará al menú.\n"
                "Presione [Enter] para continuar.\n");
                fpurge(stdin);
                getchar();
                clrscr();
                break; 
            }
            CambioDeBase((int)*num,(int)*base);
            printf("Introduzca la tercera base (entre 2 y 16) a la que desea convertir: ");
            scanf("%f",base);
            flag = ValidarEnteroPositivo(*base);
            if(flag==false)
            { 
                printf("Ahora regresará al menú.\n"
                "Presione [Enter] para continuar.\n");
                fpurge(stdin);
                getchar();
                clrscr();
                break; 
            }
            CambioDeBase((int)*num,(int)*base);
            printf("Presione [Enter] para continuar.\n");
            fpurge(stdin);
            getchar();
            clrscr();
            break;
        }
        clrscr();
    }
    else if(option==2)
    {
        while(true)
        {
            printf("Introduzca el número entero positivo a mostrar sus sumas: ");
            scanf("%f",num);
            flag = ValidarEnteroPositivo(*num);
            if(flag==false)
            { 
                printf("Ahora regresará al menú.\n"
                "Presione [Enter] para continuar.\n");
                fpurge(stdin);
                getchar();
                clrscr();
                break; 
            }
            SumasConsecutivas(num);
            printf("Presione [Enter] para continuar\n");
            fpurge(stdin);
            getchar();
            clrscr();
            break;
        }
    }
    else if(option==3)
    {
        return Quit();
    }
    else
    {
        printf("La opción introducida no es válida. Intente de nuevo.\n");
        fpurge(stdin);
        getchar();
        clrscr();
        return 0;
    }
    return 0;
}

int Quit(void)
{
    int flag = 0;
    printf(hline"\n\n\n\t\t\t\t  Desea salir?\n\n"
    "\t\t\t\t1 = sí, 0 = no.\n\n\n\n"hline"\n");
    scanf("%d",&flag);
    clrscr();
    if(flag!=0)
    {
        if(flag!=1)
        {
            printf(hline"\n\n\n\nLa opción introducida no fue válida. Se regresará al menú.\n"
            "Presione [Enter] para continuar.\n\n\n\n"hline"\n");
            fpurge(stdin);
            getchar();
            clrscr();
            return 0;
        }
    }
    return flag;
}

int ValidarEnteroPositivo(float num)
{
    if(num<=0)
    {
        printf("El número introducido es menor a 0. Intente de nuevo.\n");
        fpurge(stdin);
        return false;
    }
    else if(num - (int)num != 0)
    {
        printf("El número introducido no es entero. Intente de nuevo.\n");
        fpurge(stdin);
        return false;
    }
    else
    {
        return true;
    }
=======
    int number = 0; 
    Author(void);
    Description(void);
    Menu(&option);

    exit(1)
}

void Author(void)
{
    printf("Este programa fue desarrollado por José Luis Aguilar.\n"
           "Presione [Enter] para continuar.");
    getchar();
}
void Description(void)
{
    printf("A continuación se le mostrará un menú o se le pide el número whatever");
}

void SumasConsecutivas(int *X)
{
    int n = 1;
    
    while (n*(n+1)/2<=X) 
    {
        if(X%2==1)
        {
            OddSum(&X, 2*n+1)
        }

        if(X%(2*(n+1))==n+1)
        {
            EvenSum(&X, 2*(n+1));
        }

        n++
    }
}
/* La siguiente función toma como argumento el número a separar en sumas, y el 
número de términos en los que se separarán las sumas.*/
void OddSum(int *x, int n)
{
    if(*x % (n) == 0) // Validación para que sea correcta la suma.
        {
            int sumas[n]; // Se hace un array para facilitar la impresión
            int offset = (n-1)/2;
            int ValorInicial = *x/n-offset; // Primer valor en las sumas

    /* Primer término fuera del loop, con el propósito de que al imprimir los
    valores de la suma, no salga un signo de más. */
            sumas[0] = ValorInicial;
            printf("%d sumas consecutivas: \n%d ", n, sumas[0]);
    
            for(int i = 1; i < n; i++)
            {
                sumas[i] = ValorInicial+i;
                printf("+ %d", sumas[i]);
                i++;
            }
            printf("\n");
        }
    
}

void EvenSum(int *x, int n)
{
    int sumas[n]; // Se hace un array para facilitar la impresión
    int offset = (n-1)/2;
    int ValorInicial = *x/n-offset; // Primer valor en las sumas
    /* Primer término fuera del loop, con el propósito de que al imprimir los
    valores de la suma, no salga un signo de más. */
    sumas[0] = ValorInicial;
    printf("%d sumas consecutivas: \n%d ", sumas[0]);
    for(int i = 1; i < n; i++)
    {
        sumas[i] = ValorInicial+i;
        printf("+ %d", sumas[i]);
        i++;
    }
    
>>>>>>> 81f12f2 (Práctica 0 hecha, documentación también, primeros adelantos de la práctica 1.)
=======
            for(int i = 1; i < n; i++)
            {
                sumas = ValorInicial+i;
                printf("+ %d ", sumas);
            }
            printf("\n");
        }
}

int Menu(float *num, float *base)
{
    int option = 0, flag=false;

    printf(hline "\n");
    printf
    (
        "\t\t\t\t    Menú\n\t\t\t\t   ------\n"
        "Escoge una opción escribiendo el número:"
        "de la acción que desees tomar:\n\n"
        "\t1. Cambio de base a un número\n"
        "\t2. Calcular sumas consecutivas de un número\n"
        "\t3. Salir\n"
    );
    printf("\n" hline "\n");
    scanf("%d",&option);
    clrscr();
    if(option==1)
    {
        while(true)
        {
        printf("Introduzca el número entero positivo a convertir: ");
        scanf("%f",num);
        flag = ValidarEnteroPositivo(*num);
        if(flag==false)
        { 
            printf("Ahora regresará al menú.\n"
            "Presione [Enter] para continuar.\n");
            fpurge(stdin);
            getchar();
            clrscr();
            break;
        }
        printf("Introduzca la base (entre 2 y 16) a la que desea convertir: ");
        scanf("%f",base);
        flag = ValidarEnteroPositivo(*base);
        if(flag==false)
        { 
            printf("Ahora regresará al menú.\n"
            "Presione [Enter] para continuar.\n");
            fpurge(stdin);
            getchar();
            clrscr();
            break; 
        }
        CambioDeBase((int)*num,(int)*base);
        fpurge(stdin);
        break;
        }
        clrscr();
    }
    else if(option==2)
    {
        while(true)
        {
            printf("Introduzca el número entero positivo a mostrar sus sumas: ");
            scanf("%f",num);
            flag = ValidarEnteroPositivo(*num);
            if(flag==false)
            { 
                printf("Ahora regresará al menú.\n"
                "Presione [Enter] para continuar.\n");
                fpurge(stdin);
                getchar();
                clrscr();
                break; 
            }
            SumasConsecutivas(num);
            fpurge(stdin);
            break;
        }
    }
    else if(option==3)
    {
        return Quit();
    }
    else
    {
        printf("La opción introducida no es válida. Intente de nuevo.\n");
        fpurge(stdin);
        getchar();
        clrscr();
        return 0;
    }
    return 0;
}

int Quit(void)
{
    int flag = 0;
    printf(hline"\n\n\n\t\t\t\t  Desea salir?\n\n"
    "\t\t\t\t1 = sí, 0 = no.\n\n\n\n"hline"\n");
    scanf("%d",&flag);
    clrscr();
    if(flag!=0)
    {
        if(flag!=1)
        {
            printf(hline"\n\n\n\nLa opción introducida no fue válida. Se regresará al menú.\n"
            "Presione [Enter] para continuar.\n\n\n\n"hline"\n");
            fpurge(stdin);
            getchar();
            clrscr();
            return 0;
        }
    }
    return flag;
}

int ValidarEnteroPositivo(float num)
{
    if(num<=0)
    {
        printf("El número introducido es menor a 0. Intente de nuevo.\n");
        fpurge(stdin);
        return false;
    }
    else if(num - (int)num != 0)
    {
        printf("El número introducido no es entero. Intente de nuevo.\n");
        fpurge(stdin);
        return false;
    }
    else
    {
        return true;
    }
>>>>>>> 5ccbecb (Práctica 1 ya es funcional, falta hacer la documentación.)
}