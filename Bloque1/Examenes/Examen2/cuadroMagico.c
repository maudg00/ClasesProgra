#include "cuadroMagico.h"

/*
* Inicializa una matriz cuadrada dinámicamente, inicicializada a cero.
*
* @param int num: Tamaño de la matriz cuadrada.
* @returns int** Matriz inicializada en ceros. 
*
*/
int ** cuadroMagicoDeclarar(int num)
{   // Matriz dinámica; usa calloc para que devuelva inicializados a cero.

    int ** Matriz = malloc(num*sizeof(int*));

    for(int i=0; i<num;i++)
    {
        *(Matriz+i) = calloc(num,sizeof(int));
    }
    return Matriz;
}

void cuadroMagicoLiberar(int ** Matriz, int num)
{
    for(int i=0; i<num;i++)
    {
        free(*(Matriz+i)); 
    }
    free(Matriz);
}

void cuadroMagicoMostrar(int **matriz, int num)
{
    printf("Este es el cuadro magico: \n");
    for(int i=0; i<num; i++)
    {
        printf("\t");
        for(int j=0; j<num; j++)
        {
            printf("%03d ",*(*(matriz+j)+i));
        }
        printf("\n");
    }
}

/* Calcula el cuadro mágico con el método siamés. 
*
* @param int num: tamaño del cuadro mágico. Requiere que sea un número impar
*
*/
void CuadroMagico(int num)
{
    if(num%2!=1 || num<1 || num>11)
    { 
        printf("ERROR: Valor no válido"); 
        return;
    }

    int **cuadroMagico=cuadroMagicoDeclarar(num);
    int i=num-1, offset = (num+1)/2, fill = 0;
    do
    {
        fill++;
        if(*(*(cuadroMagico+(i+offset)%num)+(i)%num)!=0)
        {
            offset++;
            i-=2; // Esto se hace debido al orden de las pruebas;
                  // regresa dos hacia arriba e izquierda, y uno hacia la derecha. 
                  // i mueve en ambos, columna y fila.
        }
        *(*(cuadroMagico+(i+offset)%num)+(i)%num)=fill;
        ++i;
    }while(fill<num*num);

    cuadroMagicoMostrar(cuadroMagico, num);
    cuadroMagicoLiberar(cuadroMagico, num);
}

/* Método para llamar la función cuadro mágico a la terminal con instrucciones. */
void callCuadroMagico()
{
    int num;
    clrscr();
    do
    {
        printf("A continuación se le pedirá un entero impar(entre 1 y 11) para construir\n"
        "un cuadro mágico.\n");
        utilitiesEnter();
        num = utilitiesPedirEntero();
        if(!(num>1&&num<=11) || num%2 == 0 || utilitiesValidarEntero(num)==FALSE)
        {
            printf("Por favor introduzca un valor válido\n");
            utilitiesEnter();
            clrscr();
        }
    } while (!(num>1&&num<=11) || num%2 == 0);
    CuadroMagico(num);
    utilitiesEnter();
    clrscr();
}