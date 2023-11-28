#include <iostream>
#include <stdio.h>
using namespace std;
//defino el nodo

struct Nodo{
    int info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo*&Lista, int valor);
Nodo* buscar(Nodo* Lista, int valor);
void agregar(Nodo* &cfte, Nodo* &cfin,int valor);
int suprimir(Nodo* &cfte, Nodo* &cfin);

int main(){
   Nodo*cfte1=NULL;
    Nodo*cfin1=NULL;

    Nodo*cfte2=NULL;
    Nodo*cfin2=NULL;

    Nodo*cfte3=NULL;
    Nodo*cfin3=NULL;

    Nodo*lista=NULL;

    int aux;
    Nodo* carga;

    agregar(cfte1,cfin1,1);
    agregar(cfte1,cfin1,2);
    agregar(cfte1,cfin1,3);
    agregar(cfte1,cfin1,4);

    agregar(cfte2,cfin2,1);
    agregar(cfte2,cfin2,5);
    agregar(cfte2,cfin2,7);
    agregar(cfte2,cfin2,4);

    while(cfte1!=NULL){

        aux = suprimir(cfte1,cfin1);
        insertarOrdenado(lista,aux);
    }

    while(cfte2!=NULL){
        aux = suprimir(cfte2,cfin2);
        carga = buscar(lista,aux);

        if(carga!=NULL){
            agregar(cfte3,cfin3,aux);
        }
    }

    while(cfte3!=NULL){
        aux = suprimir(cfte3,cfin3);
        cout<<"el valor de la cola es: "<<aux<<endl;
    }
        return 0;

    return 0;
}


void agregar(Nodo* &cfte, Nodo* &cfin,int valor){
    //crea nodo, pide memoria
    Nodo*nuevo = new Nodo(); //ya existe en memoria
     //cargarlo con el valor
     nuevo->info=valor; //este va a ser el ultimo valor siempre.
     nuevo->sgte=NULL; //por tanto siempre va a mirar a null el ult elemento.
     //encolarlo
     if (cfte==NULL)
     {
        cfte=nuevo;//los 2 tienen que mirar 
     }
     else{
        cfin->sgte=nuevo; 
     }
     cfin=nuevo; //tiene que mirar a nuevo

    
}

int suprimir(Nodo* &cfte, Nodo* &cfin){
    //Crear otra variable de retorno
    int rdo; //guarda la info
    //guardo el valor de retorno, pila esta mirando al valor que tengo q sacar
    rdo=cfte->info; //guarda el 1
    //libero memoria
    Nodo *aux=cfte; //creo una aux que va a estar mirando la misma estructura que mira cola frente o sea 2
    cfte=cfte->sgte; //pila va a mirar a 2
    // tengo q actualizar cola fin mira a otro nodo
    if (cfte==NULL)// el nodo es null?
    {
    cfin=NULL; 
    }  
    delete (aux);
    return rdo;
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


Nodo* buscar(Nodo* Lista, int valor){ //me va a devolver el puntero al nodo
 Nodo*aux=Lista;
 while (aux!=NULL && aux->info!=valor) //me va a retornar aux null o su info
 {
    aux=aux->sgte;
 }
 return aux; //retorna un null o un nodo apuntando al valor
}