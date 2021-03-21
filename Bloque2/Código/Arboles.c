#include "utilities2.h"

struct StructArbol
{
    int numero;
    struct StructArbol * izquierda;
    struct StructArbol * derecha;
};
typedef struct StructArbol Arbol;

char menu();
Arbol * crearNodo();
void agregarNumero (Arbol **Root, Arbol *Node);
void imprimirNumero (Arbol *Root);
void vaciarArbol (Arbol *Root); 

int main()
{
    char opcion;
    Arbol * Root=NULL; 
    do
    {
        system("cls");
        opcion=menu();
        Arbol * Node;
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
            vaciarArbol(Root);
            break;
        }
        utilitiesEnter();
    } while (opcion!='3');
} 

char menu()
{
    char opcion;
    printf("Dame tu opcion:\n");
    printf("1. Agregar numero\n");
    printf("2. Imprimir numero\n");
    printf("3. Salir\n");
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
    if(Root->izquierda!=NULL)
    {
        imprimirNumero(Root->izquierda);
    }
    if(Root->derecha!=NULL)
    {
        imprimirNumero(Root->derecha);
    }
    printf("%d\n", Root->numero);
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