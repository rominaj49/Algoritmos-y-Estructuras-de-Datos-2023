//============================================================================
// Name        : VectorLista2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Materia{
   int ID;
   int nota;
};
struct Nodo{
   Materia info;
   Nodo*sgte;
};

struct Alum{
   int leg;
   Nodo* notas; //lista con notas puntero a todas las notas (ID MATERIA, INT NOTA)
};

int main() {
   Alum vec[4]; // TD Nombre [cant pos]
   int len;
   Nodo*aux=NULL;


   for(int i=0;i<len;i++){
   int suma=0;
   int cant=0;
   aux=vec[i].notas; 
      while (aux!=NULL){
         suma=suma+aux->info.nota; //necesito sumar las notas. info ya tiene 2 campos
         cant++;
         aux=aux->sgte;
      }
   cout<<"el promedio de: "<<vec[i].leg<<"es: "<<suma/cant<<endl;
   }

   for(int i=0;i<len;i++){
      liberar(vec[i].notas);
   }
   return 0;
}

void liberar(Nodo*&Lista){
   Nodo*aux;
   while(Lista!=NULL){
      aux=Lista;
      Lista=Lista->sgte;
      delete(aux);
   }
}
