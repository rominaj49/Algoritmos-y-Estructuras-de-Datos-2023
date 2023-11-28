#include <iostream>
#include <stdio.h>
using namespace std;
//defino el nodo

struct Nodo{
    int info;
    Nodo *sgte;
};
void agregar(Nodo* &cfte, Nodo* &cfin,int valor);
int suprimir(Nodo* &cfte, Nodo* &cfin);

int main(){

    int rdo;
    //inicializo la cola con sus 2 nodos.
    Nodo *cfte= NULL;
    Nodo *cfin= NULL;

    //cargo la cola
    agregar(cfte,cfin,1);
    agregar(cfte,cfin,2);
    agregar(cfte,cfin,3);

    // muestro suprimienodo la cola
    rdo=suprimir(cfte,cfin);
    cout<<"El valor extraido es: "<<rdo<<endl;
    rdo=suprimir(cfte,cfin);
    cout<<"El valor extraido es: "<<rdo<<endl;
    rdo=suprimir(cfte,cfin);
    cout<<"El valor extraido es: "<<rdo<<endl;
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