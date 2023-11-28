
#include <iostream>
#include <stdio.h>
using namespace std;


//defino el nodo

struct Nodo{
    int info;
    Nodo *sgte;
};

void push(Nodo* &pila,int valor);
int pop(Nodo* &pila);

int main(){

//inicializo la pila
 int rdo;
 Nodo*pila=NULL;

//cargo la pila
 push(pila,1);
 push(pila,2);
 push(pila,3);
 push(pila,4);
 push(pila,5);
 push(pila,6);

//muestro los elementos eliminandolos.
 rdo=pop(pila);
 cout<<"El valor extraido es: "<<rdo<<endl;
  rdo=pop(pila);
 cout<<"El valor extraido es: "<<rdo<<endl;
  rdo=pop(pila);
 cout<<"El valor extraido es: "<<rdo<<endl;
  rdo=pop(pila);
 cout<<"El valor extraido es: "<<rdo<<endl;
 rdo=pop(pila);
 cout<<"El valor extraido es: "<<rdo<<endl;
  rdo=pop(pila);
 cout<<"El valor extraido es: "<<rdo<<endl;

    return 0;
}

void push(Nodo* &pila, int valor){
    //crea nodo, pide memoria
    Nodo*nuevo=new Nodo(); //le asigne la memoria, pedi memoria
    //cargar el nodo con el valor
    nuevo->info=valor;
    nuevo->sgte=pila; //a donde tiene que mirar, va a mirar a null
    //conectar mira al que acabamos de agregar
    pila=nuevo;
}
int pop(Nodo *&pila){
    //Crear otra variable de retorno
    int rdo; //guarda la info
    //guardo el valor de retorno, pila esta mirando al valor que tengo q sacar
    rdo=pila->info;
    //libero memoria
    Nodo *aux=pila; //creo una aux que va a estar mirando la misma estructura que mira pila osea el 3
    pila=aux->sgte; //pila va a mirar a 2
    delete (aux);
    return rdo;
}