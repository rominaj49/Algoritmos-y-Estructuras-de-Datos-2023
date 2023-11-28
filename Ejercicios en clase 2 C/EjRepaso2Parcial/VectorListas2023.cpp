//============================================================================
// Name        : VectorListas2023.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Ejercicio es sacar el promedio de cada alumno que esta en un vector lista

#include <iostream>
using namespace std;


void liberar(Nodo*&Lista);

struct Nodo{
	int info;
	Nodo*sgte;
};

int main() {

	//Vector de listas
	Nodo*vec[4]; //es decir tiene 4 listas
	int len;  //teniendo encuenta qu viene dado x el enunciad
 
   
  //tenemos que recorrer el vector, 
  //necesito sumarizar las notas en cada una de las listas
  Nodo*aux=NULL;

   for (int i = 0; i < len; i++)
   {
   int suma=0;
   int cant=0;
   aux=vec[i]; //aux representa el vector
   while (aux!=NULL)
	{
	 suma=suma+aux->info;
	 cant++;
	 aux=aux->sgte;
	}
	cout<<"El promedio es: "<<suma/cant<<endl;
   }
   
   //libero las listas

   for (int i = 0; i < len; i++)
   {
	liberar(vec[i]);
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
