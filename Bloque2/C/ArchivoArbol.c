#include "utilities.h"

struct StructArbol
{
    int numero;
    struct StructArbol * izquierda;
    struct StructArbol * derecha;
};

typedef struct StructArbol Arbol;
FILE* pedirNom ();
void guardarAch(FILE* Archivo, Arbol *Root);
char menu();
Arbol * crearNodo();
void agregarNumero (Arbol **Root, Arbol *Node);
void imprimirNumero (Arbol *Root);
void vaciarArbol (Arbol *Root); 
int obtenerFilas(char *string);
void leerArchivo(int *Arreglo, int filas, char *nombreArch, Arbol **Root);

int main()
{
    char opcion;
    Arbol * Root=NULL; 
    FILE* Archivo;

    do
    {
        system("cls");
        opcion=menu();
        Arbol * Node;
        int *Arreglo=NULL;
        int filas;
        char string[50];
        switch(opcion)
        {
            case '1':
            Node = crearNodo();
            agregarNumero(&Root, Node);
            break;
            case '2':
            imprimirNumero(Root);
            break;
            case '3':
            filas=obtenerFilas(string);
            utilitiesDeclararArregloEntero(&Arreglo, filas);
            leerArchivo(Arreglo, filas, string, &Root);
            break;
            case '4':
            Archivo=pedirNom();
            guardarAch(Archivo, Root);
            fclose(Archivo);
            vaciarArbol(Root);
            break;
        }
        utilitiesEnter();
    } while (opcion!='4');
} 

char menu()
{
    char opcion;
    printf("Dame tu opcion:\n");
    printf("1. Agregar numero\n");
    printf("2. Imprimir numero\n");
    printf("3. Leer archivo\n");
    printf("4. Salir\n"); 
    scanf("%c", &opcion);
    fflush(stdin);
    return opcion;
}
Arbol * crearNodo()
{
    Arbol * Node;
    Node = malloc(sizeof(Arbol));
    printf("Introduzca un numero: ");
    scanf("%d", &Node->numero);
    fflush(stdin);
    Node->izquierda=NULL;
    Node->derecha=NULL;
    return Node;
}
/**
 * @brief agregarNumero añade un nodo al árbol binario.
 * 
 * @param Root - double pointer a la raíz del árbol
 * @param Node  – nodo a agregar del árbol.
 */

void agregarNumero(Arbol ** Root, Arbol * Node)
{
    if(*Root==NULL)
    {
        *Root=Node;
        return;
    }
    if((*Root)->numero <= Node->numero)
    {
        agregarNumero(&((*Root)->izquierda),Node);
    }
    else
    {
        agregarNumero(&((*Root)->derecha),Node);
    }
}
/**
 * @brief Imprime el arbol binario de menor a mayor. 
 * 
 * @param Root Pointer a la raiz del arbol
 */
void imprimirNumero(Arbol * Root)
{
    if(Root==NULL)
    {
        return;
    }
    imprimirNumero(Root->izquierda);
    printf("%d.\n",Root->numero);
    imprimirNumero(Root->derecha);
}
FILE* pedirNom ()
{
    FILE* Archivo;
    char nomArch[30];
    int i;
    printf("Dime el nombre del archivo: ");
    fgets(nomArch, 28, stdin);
    utilitiesQuitarEnterString(nomArch);
    Archivo=fopen(nomArch, "wt");
    return Archivo;
}
void guardarAch(FILE* Archivo, Arbol *Root)
{
    if(Root==NULL)
    {
        return;
    }
    guardarAch(Archivo, Root->izquierda);
    fprintf(Archivo, "%d.\n",Root->numero);
    guardarAch(Archivo, Root->derecha);
}
void vaciarArbol(Arbol * Root)
{
  if(Root!=NULL)
    {
      vaciarArbol(Root->izquierda);
      vaciarArbol(Root->derecha);
      free(Root);
    }
}
int obtenerFilas(char *string)
{
    FILE *Archivo;
    int numeroFilas=0;
    int numero;
    printf("Dime el nombre de tu archivo: ");
    fgets(string, 50, stdin);
    utilitiesQuitarEnterString(string);
    Archivo=fopen(string, "rt");
    while(Archivo==NULL)
    {
        printf("ERROR: no existe un archivo con ese nombre.\n");
        printf("Dime el nombre de tu archivo: ");
        fgets(string, 50, stdin);
        utilitiesQuitarEnterString(string);
        Archivo=fopen(string, "rt");
    }
    while((fscanf(Archivo, "%d.\n",  &numero))==1)
    {
        numeroFilas++;
    }
    fclose(Archivo);
    return numeroFilas;
}
void leerArchivo(int *Arreglo, int filas, char *nombreArch, Arbol **Root)
{
    FILE *Archivo;
    int i;
    Archivo=fopen(nombreArch, "rt");
    for(i=0; (fscanf(Archivo, "%d.\n", Arreglo+i))==1; i++)
    {
        Arbol* Node = malloc(sizeof(Arbol));
        Node->numero=Arreglo[i];
        Node->derecha=NULL;
        Node->izquierda=NULL;
        agregarNumero(Root, Node);
    }
    fclose(Archivo);
}
