#include <iostream>
#include <stdio.h>
using namespace std;
//defino el nodo

struct Nodo{
    int info;
    Nodo *sgte;
};


void agregarPrimero(Nodo* &Lista,int valor);
int eliminarPrimero(Nodo* &Lista);
void mostrar(Nodo*Lista);
void liberar(Nodo* &Lista);
Nodo*buscar(Nodo* Lista, int valor); //me va a deolver el punterio o un null
void buscarYMostrar(Nodo*Lista, int valor);


int main(){
    //defino una lista
    Nodo *Lista=NULL;
    agregarPrimero(Lista,1);
    agregarPrimero(Lista,2);
    agregarPrimero(Lista,3);

    buscarYMostrar(Lista,8);
    mostrar(Lista);
    liberar(Lista);

    return 0;
}

void agregarPrimero(Nodo* &Lista,int valor){
//crear nodo
Nodo *nuevo=new Nodo();
//cargar el nodo
nuevo->info=valor;
nuevo->sgte=Lista;
// enlazar
Lista=nuevo;
}
int eliminarPrimero(Nodo* &Lista){
//retorno
int ret;
ret=Lista->info;
//eliminar nodo
Nodo *aux=Lista; //se queda mirando al nodo que tiene que eliminar
Lista=Lista->sgte;
delete(aux);
return ret;
}

void mostrar(Nodo*Lista){
    Nodo *aux=Lista;
    while (aux!=NULL)
    {
      cout<<"El valor es: "<<aux->info<<endl;
      aux=aux->sgte;
    }
}

void liberar(Nodo* &Lista){
    Nodo*aux;
    while (Lista!=NULL)
    {
        aux=Lista;
        Lista=Lista->sgte;
        delete(aux);
    }
    
}

Nodo* buscar(Nodo* Lista, int valor){ //me va a devolver el puntero al nodo
 Nodo*aux=Lista;
 while (aux!=NULL && aux->info!=valor) //me va a retornar aux null o su info
 {
    aux=aux->sgte;
 }
 return aux; //retorna un null o un nodo apuntando al valor
}

void buscarYMostrar(Nodo*Lista, int valor){
    Nodo*aux;
    aux=buscar(Lista,valor);
    if (aux==NULL)
    {
        cout<<"No se encontro el valor"<<endl;
    }
    else{
        cout<<"El valor encontrado es: "<<aux->info<<endl;
    }
    
}
