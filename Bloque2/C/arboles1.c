#include "utilities.h"

struct nodo
{
  int Num;
  struct nodo *Izq, *Der;
};

typedef struct nodo tNodo;
//Declarare el pointer de tipo nodo como su propio tipo de dato llamado ptrNodo
//Así, en vez de poner tNodo * Inicio, seria ptrNodo Inicio.
typedef tNodo* ptrNodo;

void Insertar(ptrNodo Raiz, ptrNodo Elemento);
void Imprimir(ptrNodo Raiz);
void VaciarArbol(ptrNodo Raiz);
ptrNodo Recorrer(ptrNodo Raiz, int Borrador);


int main()
{
  int Valor, Borrador;
  ptrNodo Raiz, temp, Raiz2;
  Raiz=NULL;
  printf("Teclea enteros, seguido por un caracter no numerico\n");
  while(scanf("%d", &Valor)==1)
    {
      fflush(stdin);
      temp=(ptrNodo)malloc(sizeof(ptrNodo));
      temp->Izq=NULL;
      temp->Der=NULL;
      temp->Num=Valor;
      if(Raiz==NULL)
      {
            Raiz=temp;
      }
      else
      {
            Insertar(Raiz, temp);
      }
      
    }
  printf("Numeros impresos en orden:\n");
  Imprimir(Raiz);
  VaciarArbol(Raiz);
  Raiz=NULL;
}

void Insertar(ptrNodo Raiz, ptrNodo Elemento)
{
  ptrNodo Recorre;
  Recorre=Raiz;
  if(Recorre!=NULL)
    {
        if(Elemento->Num>Recorre->Num)
        {
            if(Recorre->Der!=NULL)
            {
                Insertar(Recorre->Der, Elemento);
            }
            else
            {
                Recorre->Der=Elemento;
                return;
            }
        }
        if(Elemento->Num<=Recorre->Num)
        {
            if(Recorre->Izq!=NULL)
            {
                Insertar(Recorre->Izq, Elemento);
            }
            else
            {
                Recorre->Izq=Elemento;
                return;
            }
        }
    }
}

void Imprimir(ptrNodo Raiz)
{
  if(Raiz!=NULL)
    {
      Imprimir(Raiz->Izq);
      printf("%d\n", Raiz->Num);
      Imprimir(Raiz->Der);
    }
}

void VaciarArbol(ptrNodo Raiz)
{
  if(Raiz!=NULL)
    {
      VaciarArbol(Raiz->Izq);
      VaciarArbol(Raiz->Der);
      free(Raiz);
    }
}
/*
ptrNodo Recorrer(ptrNodo Raiz, int Borrador)
{
  if(Raiz!=NULL&&Raiz->Num!=Borrador)
    {
      
      Recorrer(Raiz->Izq, Borrador);     
      Recorrer(Raiz->Der, Borrador);
    }
  else
    {
      return Raiz;
    }
}
*/
