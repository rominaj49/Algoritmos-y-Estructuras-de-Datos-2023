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

//FUNCIONES PARA COLAS
void agregar(Nodo* &cfte, Nodo* &cfin,int valor);
int suprimir(Nodo* &cfte, Nodo* &cfin);
void unionColas(Nodo*&cfte1, Nodo*&cfin1, Nodo*&cfte2, Nodo*&cfin2, Nodo*&cfte3, Nodo*&cfin3);

int main(){

Nodo *cfte1= NULL;
Nodo *cfin1= NULL;

//carga de la primera cola
int carga;

cout<<"Ingrese un valor para la carga de la primera cola y 0 para terminar"<<endl;
cin>>carga;
while (carga!=0)
{
 cout<<"Ingrese un valor para la carga de la cola y 0 para terminar"<<endl;
 agregar(cfte1,cfin1,carga);
 cin>>carga;
}

Nodo*cfte2= NULL;
Nodo*cfin2= NULL;

int carga1;

cout<<"Ingrese un valor para la carga de la cola de la segunda cola y 0 para terminar"<<endl;
cin>>carga1;
while (carga1!=0)
{
 cout<<"Ingrese un valor para la carga de la cola y 0 para terminar"<<endl;
 agregar(cfte2,cfin2,carga1);
 cin>>carga1;
}

//APAREO DE COLAS  EN UNA COLA NUEVA
Nodo*cfte3=NULL;
Nodo*cfin3=NULL;

unionColas(cfte1,cfin1,cfte2,cfin2,cfte3,cfin3);


//Muestro la carga de la cola apareada
while (cfte3!=NULL)
{
   int val=suprimir(cfte3,cfin3);
   cout<<val<<endl;
}

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

void unionColas(Nodo*&cfte1, Nodo*&cfin1, Nodo*&cfte2, Nodo*&cfin2, Nodo*&cfte3, Nodo*&cfin3){
while (cfin1!=NULL)
{
    int valor=suprimir(cfte1,cfin1);
    agregar(cfte3,cfin3,valor);
}

while (cfin2!=NULL)
{
    int valor=suprimir(cfte2,cfin2);
    agregar(cfte3,cfin3,valor);
}
}