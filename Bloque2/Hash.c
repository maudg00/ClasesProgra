#include "utilities.h"
#define CAPACIDAD 20

struct hash_item {
    int key;
    int * value;
};  

typedef struct hash_item hash;

hash * insert(int key, int value, hash * Table);
hash * handle_collisions(int key, hash * Table);
hash * search(int Hash, hash * Table);
hash * new_item();


int hashfunction(int key);

void buscar_en_tabla(hash * Table);

char menu();

int main()
{
    int key=-1,value;
    char option;
    hash Tabla[CAPACIDAD];
    do
    {
        option = menu();
        switch (option)
        {
        case '1': /* Insertar un valor a la tabla. */
            key = hashfunction(key);
            printf("Inserta el valor a llenar: ");
            scanf("%d",&value);
            fpurge(stdin);
            Tabla[key] = * insert(key,value,Tabla);
            break;
        case '2': /* Eliminar un valor de la tabla. */
            /* code */
            break;
        case '3': /* Buscar un valor de la tabla. */
            buscar_en_tabla(Tabla);
            
            break;
        case '4':  /* Salir */
            printf("Muchas gracias por usar el programa.\n");
            getchar();
            fpurge(stdin);
            return 0;
            break;
        default:
            printf("Introduzca una opción válida por favor.\n");
            break; 
        }

    }while (option!='4');
    return 0;
}
char menu()
{
        char option;
        printf("Dame tu opción: \n");
        scanf("%c",&option);
        fpurge(stdin);
        printf("1. Insertar valor \n");
        printf("2. Eliminar valor \n");
        printf("3. Buscar valor \n");
        printf("4. Salir \n");
        return option;
         
}

int hashfunction( int key ) { return key+1; }

hash * new_item()
{
    hash * item = malloc(sizeof(hash));
    return item;
}

/*
*
*
*/
hash * insert(int key, int value, hash * Table)
{
    if(key>= CAPACIDAD)
    {
        printf("Tabla llena.\n");
        return NULL;
    }
    if((Table+key)->value != NULL)
    { // Tengo que revisar si existe un valor. Si existe ya el valor, entonces key = key+1
        int newKey = hashfunction(key);
        hash * item = insert(newKey, value, Table);
    }
    hash * item = new_item();
    item->key = key;
    item->value = &value; 
    return item;
}

void buscar_en_tabla(hash * Table)
{
    int Hash;
    hash * item;
    printf("Inserte el key que va a buscar:\n");
    scanf("%d",&Hash);
    fpurge(stdin);

    item = search(Hash, Table);
    printf("Key: %d, Value: %d",item->key, *(item->value));
}

/*
Busca un valor en una tabla, retorna un pointer al valor en la tabla. 
*/
hash * search(int Hash, hash * Table)
{
    if((*(Table+Hash)).value == NULL)
    {
        printf("No existe el valor en la tabla con key %d.", Hash);
        return NULL;
    }
    else
    {
        return &(*(Table+Hash));
    }
}
