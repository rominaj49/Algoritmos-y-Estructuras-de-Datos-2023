//============================================================================
// Name        : ApareoListas2023.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Nodo{
   int info;
   Nodo*sgte;
};

void insertarOrdenado(Nodo*&Lista,int valor);
void mostrar(Nodo*Lista);
void liberar(Nodo*&Lista);

int main() {
	Nodo*listaA; //Solo declaramos, ya que ya estan definidos.
	Nodo*listaB; //Solo declaramos, ya que ya estan definidos.
                //Los tenemos que aparear en lista C que debe estar vacia.
   
	Nodo*listaC=NULL;

	//esto no es parte del ejercicio, solo lo incluyo para probarlo
	insertarOrdenado(listaA,1);
	insertarOrdenado(listaA,3);
	insertarOrdenado(listaA,5);
	insertarOrdenado(listaB,2);
	insertarOrdenado(listaB,3);
	insertarOrdenado(listaB,7);

	listaC=listaA;   // De esta manera la lista C tiene todo los nodos de la lista A, solo nos faltaria la lista B
	Nodo*aux=listaB; //Para recordar con el aux lo que tiene la lista B

	while(aux!=NULL){ //Empiezo el apareo de listas
	   insertarOrdenado(listaC,aux->info); //lista donde lo inserta, el valor es aux.info
	   aux=aux->sgte; //una vez que lo inserto debe mover para adelante para que no quede loopeando
	} //Acá terminamos el apareo de 2 listas en una lista C

	mostrar(listaC);
   //Despues de mostrar siempre debo liberar las listas.
	liberar(listaA);
	liberar(listaB);
	liberar(listaC);
	return 0;
}

void mostrar(Nodo*Lista){
   Nodo*aux=Lista;
   while(aux!=NULL){
      cout<<"el valor es: "<<aux->info<<endl;
      aux=aux->sgte;
   }
}

void liberar(Nodo*&Lista){
   Nodo*aux;
   while(Lista!=NULL){
      aux=Lista;
      Lista=Lista->sgte;
      delete(aux);
   }
}


void insertarOrdenado(Nodo*&Lista,int valor){
   //crear el nodo
   Nodo*nuevo=new Nodo();
   //cargar el nodo
   nuevo->info=valor;
   nuevo->sgte=NULL; //porque no s� d�nde va
   //Enlazarlo
   Nodo*aux=Lista; //recorro sin modificar la lista!!!
   Nodo*ant=NULL; //este me va a permitir enlazar
   //BUSCAR!!!!!!!!!!!!!!!!!!!
   while(aux!=NULL&&aux->info<valor){
      ant=aux;
      aux=aux->sgte; //avanzabamos en la lista
   }
   if(ant==NULL){//No entr� al while 1)lista vac�a 2)debo insertar al principio
      Lista=nuevo;
   }else{//Entr� al while, 1) en alguna parte de la lista 2)agregar al final
      ant->sgte=nuevo;
   }
   nuevo->sgte=aux;
}
