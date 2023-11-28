#include <iostream>
#include <stdio.h>
using namespace std;


// Ejercicio 5:
// Se tiene un vector de Resumen de las carpas alquiladas en Mar del Plata para verano 2023, que contiene
// el código del balneario, cantidad de días de la temporada reservados y cantidad de confirmaciones:
// - Código del balneario
// - Cantidad de días reservados
// - Cantidad de confirmaciones/reservas
// Además, se cuenta con una lista ordenada que contiene los últimos pedidos realizados, cada nodo de la
// lista contiene:
// - Código del balneario
// - Cantidad de días reservados
// Se pide, actualizar el vector Carpas con la información que hay en la lista. Importante: Si en la lista hay
// una reserva para el balneario "123", hay que actualizar el campo cantidad de días reservados e
// incrementar en 1 la reserva.
// Se sabe que cómo Máximo hay 23 balnearios.


struct carpa{
    int codBal;
    int cantDiasRes; //actualizar
    int cantConf;// incrementar 1
};
struct cargaBaln{
    int codBal;
    int cantDiasRes;
};

struct Nodo{
    cargaBaln info;
    Nodo*sgte;
};

//operaciones de la lista
void push(Nodo* &pila,int valor);
int pop(Nodo* &pila);
void insertarOrdenado(Nodo*&Lista, int valor);
void buscarYMostrar(Nodo*Lista, carpa valor);
void mostrar(Nodo*Lista);
void liberar(Nodo* &Lista);
int buscar (carpa vec[], int len, int valor);

int main(){
    carpa vecCarpa[20]; 
    int len;
    Nodo* cargaLista;

   Nodo*aux=cargaLista;

    while (aux!=NULL)
    {
        int pos=buscar(vecCarpa,len,aux->info.codBal);
        if (pos!=-1)
        {
            vecCarpa[pos].cantDiasRes+=aux->info.cantDiasRes;
            vecCarpa[pos].cantConf++;
        }
        
        aux=aux->sgte;
    }
 liberar(cargaLista);

    return 0;
}