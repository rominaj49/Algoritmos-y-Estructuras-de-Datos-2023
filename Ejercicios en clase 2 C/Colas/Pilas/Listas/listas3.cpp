#include <iostream>
#include <stdio.h>
using namespace std;
//defino el nodo

struct Nodo{
    int info;
    Nodo *sgte;
};


void agregarPrimero(Nodo* &Lista,int valor);
void insertarOrdenado(Nodo*&Lista, int valor);
int eliminarPrimero(Nodo* &Lista);
void mostrar(Nodo*Lista);
void liberar(Nodo* &Lista);
Nodo*buscar(Nodo* Lista, int valor); //me va a deolver el punterio o un null
void buscarYMostrar(Nodo*Lista, int valor);


int main(){
     //defino una lista
    Nodo *lista=NULL;
    
    insertarOrdenado(lista,4);
    insertarOrdenado(lista,1);
    insertarOrdenado(lista,2);

    mostrar(lista);
    liberar(lista);

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

void insertarOrdenado(Nodo*&Lista, int valor){
    //crear el nodo
    Nodo *nuevo= new Nodo();
    //cargar el nodo
    nuevo->info=valor;
    nuevo->sgte=NULL; //porque no se donde va a ir para enlazarlo
    //enlazarlo
    Nodo*aux=Lista; //recorro sin modificar la lista!
    Nodo*ant=NULL; //este me va a permitir enlazar
    //empieso a BUSCAR
    while (aux!=NULL&&aux->info<valor)
    {
       ant=aux;
       aux=aux->sgte; //avanzabamos en la lista
    }
    //No entra al while 
    //1- La lista está vacia
    //2- Debo insertar al principio
    //3- Entre al while y sali porque encontre en alguna parte el lugar
    //4- Debo agregar al final

    if (ant==NULL) //esto significa si no entre al while, debo insetar al principio
    {
        Lista=nuevo;
        nuevo->sgte=aux;
    }
    else{ //entre al while, 1) en alguna parte de la lista 2)agregar al final
        ant->sgte=nuevo;
    }
        nuevo->sgte=aux;
}
