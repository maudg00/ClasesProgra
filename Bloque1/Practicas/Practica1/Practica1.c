//librerias
#include <stdio.h>
#include <math.h>

void Desplegar();
int Menu();
void PedirNum(float *num, int *numE);
void Series(int numE);
void Bases(int numE);
//main
int main()
{
    int numE=0, opcion; float num=0;
    Desplegar();
    do
    {
        opcion=Menu();
       if (opcion==1)
        {
            PedirNum(&num, &numE);
            Series(numE);
        }
        if (opcion==2)
        {
            PedirNum(&num, &numE);
            Bases(numE);
        }
    }      
    while (opcion!=3);

    printf("Adios");
     
}
//mensaje inicio
void Desplegar()
{
    printf("Tania Cesin \n");
    printf("30 de diciembre 2020 \n");
    char enter;
    scanf("%c", &enter);
    fflush(stdin);
}
//menu
int Menu()
{
    int flag=0;
    while (flag<1 || flag>3)
    {
        printf("Elige una opcion:\n 1 - encontrar todas las series de 3 o mas numeros consecutivos que sumados den como resultado el numero deseado. \n 2 - convertir un numero en 3 bases desadas. \n 3 - salir del programa. \n");
        scanf("%d", &flag);
        if (flag<1 || flag>3)
        {
            printf("Opcion no valida. \n");
        }
    }
    return flag;
}
//Pedir numero para series o bases 
void PedirNum(float *num, int *numE)
{
    int flag=0;
    while (flag==0)
    {
        printf("Dame un mumero: ");
        scanf("%f", num);
        if (*num>0)
        {
            *numE=(int)*num;
            if (*num-*numE==0)
            {
                flag=1;
            }
        }
        else
        {
            flag=0;
        }
        if (flag==0)
        {
            printf("Tu numero no es correcto. \n");
        }
    }
}
//Series consecutivas
void Series(int numE)
{
    int i, j, res, flag=0;
    for (i = 3; i < numE; i++)
    {
        if (i%2==0 && numE%i==i/2 && numE/i>=i/2)
        {
            printf("Una serie de %d numeros que te da %d es: \n", i, numE);
            for(j=(i/2)-1; j>=1; j=j-1)
            {
                res=numE/i-j;
                printf("%d \n",res);
            }
            for(j=0; j<=i/2; j++)
            {
                res=numE/i+j;
                printf("%d \n",res);
            }
            flag=1;
        }
        if (i%2!=0 && numE%i==0 && numE/i>i/2)
        {
           printf("Una serie de %d numeros que te da %d es: \n", i, numE);
           for(j=i/2; j>=1; j=j-1)
           {
               res=numE/i-j;
               printf("%d \n",res);
           } 
           for(j=0; j<=i/2; j++)
           {
               res=numE/i+j;
               printf("%d \n",res);
           }
           flag=1;
        }
    }
    if(flag==0)
        {
            printf("No hay una serie de numeros consecutivos que sumados den %d. \n", numE);
        }
}
//Cambio de base
void Bases(int numE)
{
    int base1, base2, base3, i, res1, res2, res3, cont, bandera=0;
    fflush(stdin);
    do
    {
        printf("Dame las 3 bases a las que quieras cambiar entre binario y hexadecimal, separadas por ',' ej. (2,5,12): \n");
        scanf("%d,%d,%d", &base1, &base2, &base3);
        if (base1<2 || base1>16 || base2<2 || base2>16 || base3<2 || base3>16)
        {
            printf("Alguna de tus bases es incorrecta.\n");
        }
    } while (base1<2 || base1>16 || base2<2 || base2>16 || base3<2 || base3>16);
    //Primera base
    printf("%d en Base %d es: \n", numE, base1);
    res1=numE;
    for (i=100; i>=0; i=i-1)
    {
        cont=0;
        while(pow(base1,i)<=res1)
        {
            res1=res1-pow(base1,i);
            cont++;
            bandera=1;
        }
        if (bandera!=0)
        {
            if(cont==10)
            {
                printf("A");
            }
            else if(cont==11)
            {
                printf("B");
            }
            else if(cont==12)
            {
                printf("C");
            }
            else if(cont==13)
            {
                printf("D");
            }
            else if(cont==14)
            {
                printf("E");
            }
            else if(cont==15)
            {
                printf("F");
            }
            else
            {
                printf("%d", cont);
            }
        }
    }
    printf(".\n");
    //Segunda base
    printf("%d en Base %d es: \n", numE, base2);
    bandera=0;
    res2=numE;
    for (i=100; i>=0; i=i-1)
    {
        cont=0;
        while(pow(base2,i)<=res2)
        {
            res2=res2-pow(base2,i);
            cont++;
            bandera=1;
        }
        if(bandera!=0)
        {
            if(cont==10)
            {
                printf("A");
            }
            else if(cont==11)
            {
                printf("B");
            }
            else if(cont==12)
            {
                printf("C");
            }
            else if(cont==13)
            {
                printf("D");
            }
            else if(cont==14)
            {
                printf("E");
            }
            else if(cont==15)
            {
                printf("F");
            }
            else
            {
                printf("%d", cont);
            }
        }
    }
    printf(".\n");
    //Tercera base
    printf("%d en Base %d es: \n", numE, base3);
    bandera=0;
    res3=numE;
    for (i=10; i>=0; i=i-1)
    {
        cont=0;
        while(pow(base3,i)<=res3)
        {
            res3=res3-pow(base3,i);
            cont++;
            bandera=1;
        }
        if(bandera!=0)
        {
            if(cont==10)
            {
                printf("A");
            }
            else if(cont==11)
            {
                printf("B");
            }
            else if(cont==12)
            {
                printf("C");
            }
            else if(cont==13)
            {
                printf("D");
            }
            else if(cont==14)
            {
                printf("E");
            }
            else if(cont==15)
            {
                printf("F");
            }
            else
            {
                printf("%d", cont);
            }
        }
    }
    printf(".\n");
}