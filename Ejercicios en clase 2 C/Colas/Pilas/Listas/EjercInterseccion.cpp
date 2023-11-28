#include <iostream>
#include <stdio.h>
using namespace std;


//defino el nodo

struct Nodo{
    int info;
    Nodo *sgte;
};


//operaciones de la lista
void push(Nodo* &pila,int valor);
int pop(Nodo* &pila);
void insertarOrdenado(Nodo*&Lista, int valor);
Nodo*buscar(Nodo* Lista, int valor); //me va a deolver el punterio o un null
void buscarYMostrar(Nodo*Lista, int valor);
void mostrar(Nodo*Lista);
void liberar(Nodo* &Lista);

//operaciones de la cola
void agregar(Nodo* &cfte, Nodo* &cfin,int valor);
int suprimir(Nodo* &cfte, Nodo* &cfin);

//interseccion de una lista y cola -> Lista Ordenada
//hay q usar una lista si o si

int main(){

 //declaro la lista ya existente
    Nodo *Lista1;
 // creo una nueva lista donde van a estar todos los numeros
    Nodo *Lista2= NULL;

 //declaro la cola con sus 2 nodos. el ej me indica que ya existe
    Nodo *cfte;
    Nodo *cfin;

  int carga;

while (cfte!=NULL) //si es distinto de null entonces inserto
{
  carga=suprimir (cfte,cfin);
  //busco en la lista un numero y me devuelve el puntero o un null
  Nodo*aux;
  aux=buscar(Lista1,carga);
  
  if (aux!=NULL) // osea que lo encontro
  {
    insertarOrdenado(Lista2,carga); //lo inserto en la nueva lista
  }
  //si no lo encontro no hago nada
}

mostrar(Lista2);
liberar(Lista1);
liberar(Lista2); //libero las 2 listas porque quedaron nodos al aire

    return 0;
}
