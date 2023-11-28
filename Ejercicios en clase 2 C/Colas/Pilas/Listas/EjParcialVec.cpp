#include <iostream>
#include <stdio.h>
using namespace std;



//defino el nodo

struct Nodo{
    hab info;
    Nodo *sgte;
};

struct hotel{
  int codHab;
  int reservas;
  int dias;
};

struct hab{
  int codHab;
  int dias;
};

//operaciones de la lista
void insertarOrdenado(Nodo*&Lista, int valor);
void buscarYMostrar(Nodo*Lista, hotel valor);
void mostrar(Nodo*Lista);
void liberar(Nodo* &Lista);


//Actualizar la cantidad de res,cant dias, hab, del vector Hotel
//con la cantidad de habitacion y cantidad de dias de la lista

int buscar (hotel vec[], int len, int valor);

int main(){
   hotel vec[20];
   int len;
   Nodo *lista;

  //defino la lista aux
  Nodo*aux= lista;

  int pos;
  while (aux!=NULL)
  {
    pos=buscar(vec,len,aux->info.codHab);

    if (pos!=1)
    {
      vec[pos].reservas++;
      vec[pos].dias=vec[pos].dias + aux->info.dias;
    }
    aux=aux->sgte;
  }
  liberar(lista);

    return 0;
}

int buscar (hotel vec[], int len, int valor){
   int i=0;
   while(i<len && vec[i].codHab != valor){
      i++;
   }
   if (i==len){
      return -1;
   }else return i;
}