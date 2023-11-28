
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

Nodo *pila=NULL;
int carga;
int rdo;

cout<<"Ingrese un valor y termine con 0"<<endl;
cin>>carga;
while (carga!=0) //cargo elementos a la pila
{
    push(pila,carga);
    cout<<"Ingrese un valor y termine con 0"<<endl;
    cin>>carga;
}

while (pila!=NULL) //saco elementos de la pila
{
   rdo=pop(pila); 
   cout<<"El elemento extraido es: "<<rdo<<endl;
}


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