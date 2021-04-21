#define CAP 300
#define KEY_LENGTH 5


typedef struct hash_item{
    char key[KEY_LENGTH];
    int value;
}item;

typedef struct hash_table{
    item ** values;
    int size;
    int stored_values;
}table;

table create_table(int capacity)
{
    table Tabla;
    // Para que empiece sin basura se hace calloc,
    Tabla.values = calloc(capacity, sizeof(item*)); 
    Tabla.size = capacity;
    Tabla.stored_values = 0;

    // Apuntar cada pointer de la tabla a NULL
    for(int i=0; i<capacity; i++)
    {
        // NO HE PROBADO PEEERO según yo, dereferencia una vez al doble pointer
        // entonces al contenido de **values (que es *values) lo apunta a NULL,
        // dejando efectivamente vacía la tabla en ese lugar hmmmm.
        *(Tabla.values+i) = NULL;
    }
    return Tabla;
}

item * create_item(char llave[KEY_LENGTH], int valor)
{
    item * new_item = malloc(sizeof(new_item));
    new_item->value = valor;
    for(int i=0; i<KEY_LENGTH; i++) new_item->key[i] = llave[i]; 
    return new_item;
}

void delete_item(item * del_item)
{
    free(del_item);
}

void delete_table(table Tabla)
{
    for(int i = Tabla.size; i!=0; i--)
    {
        if(*(Tabla.values+i)!=NULL)
        {
            free(*(Tabla.values+i));
        }
    }
    free(Tabla.values)
}