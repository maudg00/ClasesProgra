#include <stdio.h>
// Funciones declaradas

int 
    CalcularPrimo(float *num), 
    Salida(), 
    Menu(float *num, int *flag),
    ValidarEnteroPositivo(float number);
void Descripcion(void);

// Main function
int main()
{
    int flag = 0;
    float numero=0;
    Descripcion();
    while(flag == 0)
    {
        Menu(&numero, &flag);
    }
    return 0;
}

// Funciones:
int CalcularPrimo(float *num)
{
    
    int flag = 0;
    while(flag==0)
    {
        printf("Introduzca el número que se quiere verificar si es primo:\n\n");
        scanf("%f",num);
        flag = ValidarEnteroPositivo(*num);
    }
    
    for(int i=2; i*i <= *num; i++)
    {
        if((int)*num%i==0)
        {
            printf("El número no es primo.\n\n");
            return 0;
        }
    }
    printf("El número es primo.\n\n");
    return 0;
}

int Salida()
{
    int flag;
    printf("Desea salir? 1 = sí, 0 = no\n");
    return scanf("%d",&flag);
}

int Menu(float *numero, int *flag)
{
    int opcion = 0;
    printf("Seleccione una opción introduciendo el número en la terminal:\n"
    "1 Calcular si un número es primo.\n2 Salir\n");
    scanf("%d",&opcion);

    if(opcion==1)
    {
        CalcularPrimo(numero);
    } 
    else if(opcion==2)
    {
        *flag = Salida();
    } else {
        printf("Introduzca una opción válida.\n");
    }
    return 0;
}

int ValidarEnteroPositivo(float num)
{
    if(num<=0)
    {
        printf("El número introducido es menor a 0. Intente de nuevo.\n\n");
        return 0;
    }
    else if(num - (int)num != 0)
    {
        printf("El número no es entero. Intente de nuevo.\n\n");
        return 0;
    }
    else if(num==1)
    {
        printf("El número 1 no se considera primo.\n\n");
        return 0;
    } 
    else
    {
        return 1;
    }
}

void Descripcion(void)
{
    printf(
            "Este programa verifica si un número es primo o no.\n"
            "Presione [Enter] para continuar.\n"
            );
    getchar();
}
