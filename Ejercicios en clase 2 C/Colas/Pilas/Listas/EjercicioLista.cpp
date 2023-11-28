#include <iostream>
#include <stdio.h>
using namespace std;
//defino el nodo



struct Alum{
    int legajo;
    int nota;
};

struct Nodo{
    Alum info;
    Nodo *sgte;
};


void mostrar(Nodo*Lista);
void liberar(Nodo* &Lista);
void insertarOrdenado(Nodo*&Lista, Alum valor);

//archivo es un almacenamiento secundaria no una memoria principal.


//Como reescribir en un archivo por legajo ordenado a partir de una lista;

int main(){

//defino una lista
Nodo *Lista=NULL;
//declarar el puntero
FILE*k1151;
 //el modo de apertura del archivo
k1151= fopen("k1151.dat", "rb");
Alum raux;

fread(&raux, sizeof (struct Alum), 1 , k1151);

while(!feof(k1151)){//aca estamos leyendo

 insertarOrdenado(Lista, raux);
 fread(&raux, sizeof (struct Alum), 1 , k1151);
}
fclose(k1151);


//de la lista ya ordenada lo reescribimos al archivo
k1151= fopen("k1151.dat", "wb"); //abrimos el archivo nuevamente

//declaramos un puntero auxiliar para no perder la referencia
Nodo*aux=Lista;
while (aux!=NULL)
{
    fwrite(&aux->info,sizeof(struct Alum),1,k1151);
    aux=aux->sgte;
}
//cerrar archivo 
fclose(k1151);
//liberar lista
liberar(Lista);
return 0;
}


