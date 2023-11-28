#include <iostream>
#include <stdio.h>
using namespace std;

struct Nodo{
    int info;
    Nodo* sgte;
};

void insertarOrdenado(Nodo*&Lista,int valor);
void mostrar(Nodo*Lista);
void liberar(Nodo*&Lista);
void agregarPrimero(Nodo* &Lista,int valor);
int eliminarPrimero(Nodo* &Lista);
void mostrar(Nodo*Lista);
void liberar(Nodo* &Lista);
Nodo*buscar(Nodo* Lista, int valor); //me va a deolver el punterio o un null
void buscarYMostrar(Nodo*Lista, int valor);
void cargaLista(Nodo*&A);
Nodo*interseccionListas(Nodo* &listaA, Nodo* &listaB);

int main(){

 Nodo*A=NULL;
 Nodo*B=NULL;


cargaLista(A);
cargaLista(B);
Nodo*C=interseccionListas(A,B);
mostrar(C);
    return 0;
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


void cargaLista(Nodo*&A){

    int carga;
    cout<<"ingrese valores a cargar en la lista, finalice con 0"<<endl;
    cin>>carga;
 while (carga!=0)
 {
   insertarOrdenado(A,carga);
   cout<<"ingrese valores a cargar en la lista, finalice con 0"<<endl;
   cin>>carga;
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




Nodo*interseccionListas(Nodo* &listaA, Nodo* &listaB){

Nodo*C=NULL;
Nodo*aux=listaA;
Nodo*valorE=NULL;

while (aux!=NULL)
{
   valorE=buscar(listaB,aux->info);
   
   if (valorE!=NULL)
   {
    insertarOrdenado(C,aux->info);
   }
   aux=aux->sgte;
}

return C;
}