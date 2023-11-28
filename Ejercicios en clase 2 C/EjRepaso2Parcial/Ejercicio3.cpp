#include <iostream>
#include <stdio.h>
using namespace std;

// Ejercicio 4:
// Se tiene un vector de Resumen de las reservas de Pre-viaje para el verano 2023 en la costa Argentina,
// que contiene el código de la ciudad costera, cantidad de reservas hechas en todos los alojamientos y
// visitantes:
// - Código de la ciudad
// - Cantidad de reservas
// - Cantidad de visitantes por reserva.

// Además, se cuenta con una lista ordenada que contiene las últimas cargas realizadas, cada nodo de la
// lista contiene (puede haber varios nodos por cada ciudad, ya que 1 nodo implica 1 reserva):
// - Código de la ciudad
// - Cantidad de visitantes.
// Se pide, actualizar el vector Pre-Viaje con la información que hay en la lista. Importante: Si en la lista hay
// una reserva para la ciudad "123", hay que actualizar el campo cantidad de visitantes e incrementar en 1
// la reserva.
// Se sabe que cómo Máximo hay 20 ciudades.

struct viaje23{
    int codCiudad;
    int cantRes;//++
    int cantVisxRes; //actualizar
};

struct cargasReservas{
    int codCiudad;
    int cantVis;
};

struct Nodo{
    cargasReservas info;
    Nodo*sgte;
};

//operaciones de la lista
void push(Nodo* &pila,int valor);
int pop(Nodo* &pila);
void insertarOrdenado(Nodo*&Lista, int valor);
void buscarYMostrar(Nodo*Lista, cargasReservas valor);
void mostrar(Nodo*Lista);
void liberar(Nodo* &Lista);
int buscar (viaje23 vec[], int len, int valor);


int maint(){
    viaje23 vecPreviaje[20];
    int len;
    Nodo*listviaje; // hay que actualizar el anterior vector con la informacion cargada en la lista

    Nodo*aux=listviaje; //para no modificar nada de esa lista, ya que las listas son libres y manipulables a dif de otas estru. ya q perdemos la referencia
    int pos;
    while (aux!=NULL)
    {
    pos=buscar(vecPreviaje,len,aux->info.codCiudad);
    if (pos!=-1)
    {
     vecPreviaje[pos].cantRes++;
     vecPreviaje[pos].cantVisxRes+=aux->info.cantVis;
    }        
        aux=aux->sgte;
    }
    
    return 0;
}