#include <iostream>
#include <stdio.h>
using namespace std;


//defino el nodo

struct prod{
    int ID;
    int stock;
};
struct Nodo{
    prod info;
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

//operacion de vectores
int buscar (prod vec[], int len, prod valor); //devolvia -1 o la pos

//interseccion de una lista y cola -> Lista Ordenada
//hay q usar una lista si o si
//actualizar un vector a partir de una lista 

int main(){

//ya esta cargado, solo defino
prod vec[20];
int len;

//defino lista con los pedidos del dia
Nodo*lista;
int pos;

//defino un puntero auxiliar ya q no puedo usar lista
Nodo*aux=lista;

while (aux!=NULL){ //busco en el vector 
   pos=buscar(vec,len,aux->info);

   if (pos!=1){ //tengo que agregar en el vector si es distinto de -1, lo encontro
   vec[pos].stock = vec[pos].stock + aux->info.stock;
   }
   aux=aux->sgte;
}
liberar(lista);

    return 0;
}



// int buscar (prod vec[], int len, prod valor){
//    int i=0;
//    while(i<len && vec[i] != valor){
//       i++;
//    }
//    if (i==len){
//       return -1;
//    }else return i;
// }