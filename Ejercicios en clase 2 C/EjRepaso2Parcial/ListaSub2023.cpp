//============================================================================
// Name        : ListaSub2023.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Tinfo2{
   int ID;
   int nota;
};
struct Nodo2{
   Tinfo2 info;
   Nodo2*sgte;
};

struct Tinfo{ //sublista principal
   int leg;
   Nodo2* notas; //va a tener una sub lista de notas que va a tener otro nodo asociado para el id de la mat y la nota
};

struct Nodo{ //Lista principal principal que contiene la lista de sublistas
   Tinfo info;
   Nodo* sgte;
};

int main() {
   //OBJETIVO: CALCULAR EL PROMEDIO POR CADA LEGAJO
   Nodo*lista; //list que ya viene cargada;
   int suma=0;
   int cant=0;
   Nodo*aux=lista;
   Nodo2*aux2; //necesito un aux para moverme en la lista de notas.

   while (aux!=NULL){ //recorro la lista principal 
     int suma=0;
     int cant=0;
      aux2=aux->info.notas; //para recorrer una lista si o si necesitamos un aux, aux2 es para lista de notas
      while (aux2!=NULL){
         cant++;
         suma=suma+aux2->info.nota;
         aux2=aux2->sgte;
      }//ya proceses la suma de todas las notas
      cout<<"el promedio de: "<<aux->info.leg<<"es : "<<suma/cant<<endl;
      aux=aux->sgte;
   }
	return 0;
}
