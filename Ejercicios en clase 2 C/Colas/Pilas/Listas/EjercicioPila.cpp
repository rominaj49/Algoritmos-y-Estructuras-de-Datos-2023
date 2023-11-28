#include <iostream>
#include <stdio.h>
using namespace std;



//op de pila
void push(Nodo* &pila,int valor);
int pop(Nodo* &pila);

//op de lista
void insertarOrdenado(Nodo*&Lista, int valor);
void mostrar(Nodo*Lista);
void liberar(Nodo* &Lista);

//op de cola
int suprimir(Nodo* &cfte, Nodo* &cfin);




//union de una pila y cola en una lista
//tenemos que ir sacando elemento de la pila

//defino el nodo

struct Nodo{
    int info;
    Nodo *sgte;
};

int main(){

int carga;

// declaro la pila
Nodo *pila;

 //declaro la cola con sus 2 nodos.
    Nodo *cfte;
    Nodo *cfin;

// Inicializo la lista donde van a estar contenidas.

Nodo *lista=NULL;

while (pila!=NULL)
{
   carga=pop(pila);
   insertarOrdenado(lista,carga); //x cada uno de los elementos que tiene la pila.

}

while (cfte!=NULL)
{
    carga=suprimir(cfte,cfin);
    insertarOrdenado(lista,carga); //x cada uno de los elementos que tiene la cola.
}

mostrar(lista);
liberar(lista);


    return 0;
}
