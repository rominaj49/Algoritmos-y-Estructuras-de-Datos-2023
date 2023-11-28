#include <iostream>
using namespace std;

// Desarrolle los siguientes PROCEDIMIENTOS y defina los parámetros:
// a- Dadas 2 Colas de enteros (Cola A y Cola B) genere la UNION de ambas en Cola C.
// b- Dadas 2 Pilas de enteros (Pila A y Pila B) genere la UNION de ambas en Pila C.
// c- Dadas 2 Listas de enteros (Lista A y Lista B) genere la UNION de ambas en Lista C.
// d- Desarrolle una función que retorne una lista ordenada a partir la INTERSECCION de 2 Listas.
// e- Desarrolle una función que retorne una lista ordenada a partir la INTERSECCION de una Lista y
// una Pila.

struct Nodo{
    int info;
    Nodo *sgte;
};

//FUNCIONES PARA PILAS
void push(Nodo* &pila,int valor);
int pop(Nodo* &pila);
void apareoPilas(Nodo* &pila1, Nodo* &pila2, Nodo* &pila3);

int main(){

//inicializo las pilas
 Nodo*pila1=NULL;
 Nodo*pila2=NULL;

//pila que va a tener la union
 Nodo*pila3=NULL;

//carga de la primera pila
int carga;
cout<<"Ingrese un valor para la carga de la primera pila y 0 para terminar"<<endl;
cin>>carga;
while (carga!=0)
{
 cout<<"Ingrese un valor para la carga de la pila y 0 para terminar"<<endl;
 push(pila1,carga);
 cin>>carga;
}

//carga de la segunda pila
int carga1;
cout<<"Ingrese un valor para la carga de la pila de la segunda pila y 0 para terminar"<<endl;
cin>>carga1;
while (carga1!=0)
{
 cout<<"Ingrese un valor para la carga de la pila y 0 para terminar"<<endl;
 push(pila2,carga1);
 cin>>carga1;
}

//APAREO DE PILAS  EN UNA PILA NUEVA

apareoPilas(pila1,pila2,pila3);


//Muestro la carga de la cola apareada
while (pila3!=NULL)
{  
   int valor=pop(pila3);
   cout<<valor<<endl;
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

void apareoPilas(Nodo* &pila1, Nodo* &pila2, Nodo* &pila3){
while (pila1!=NULL)
{   int valor=pop(pila1);
    push(pila3,valor);
}

while (pila2!=NULL)
{   int valor=pop(pila2);
    push(pila3,valor);
}

}