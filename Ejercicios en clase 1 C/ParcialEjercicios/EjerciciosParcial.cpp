#include <iostream>
using namespace std;

// 3) Dado un vector acerca del stock de un depósito, que contiene el código del producto y
// la cantidad de unidades disponibles para la venta (Se sabe que máximo hay 150
// productos en proceso de fabricación), determinar:
// a- ¿Cuál es el producto que más unidades tiene?
// b- ¿Cuál es el producto que menos unidades tiene?
// c- Indicar la cantidad total de productos almacenados según el vector.

struct Deposito{
    int Codigo;
    int ProdDisponibles;
};

void inicializar (Deposito vec[], int cantP, Deposito ValorIni);
int maximoVec (Deposito vec[], int len);
int minimoVec (Deposito vec[], int len);
void mostrar (Deposito vec [], int len);

int main(){

Deposito lista[150];
int len=0;
int max=0;
int min=0;
//inicializando el registro.
Deposito IniRegi;
IniRegi.Codigo=0;
IniRegi.ProdDisponibles=0;

inicializar(lista,4,IniRegi);



for (int i = 0; i < 4; i++)
{
cout<<"Ingrese el codigo del producto"<<endl; 
cin>>lista[i].Codigo;
cout<<"Ingrese la cantidad de productos disponibles"<<endl; 
cin>>lista[i].ProdDisponibles;
len++;
}

max= maximoVec(lista,len);
cout<<"El producto disponbile con más cantidad es el : "<<endl;
cout<< lista[max].Codigo<<endl;

min= minimoVec(lista,len);
cout<<"El producto disponbile con menos cantidad es el : "<<endl;
cout<< lista[min].Codigo<<endl;

mostrar(lista, len);
 return 0;
}


void inicializar (Deposito vec[], int cantP, Deposito ValorIni){
   for (int i=0; i<cantP; i++){
      vec[i].Codigo=ValorIni.Codigo;
      vec[i].ProdDisponibles=ValorIni.ProdDisponibles;
   }
}


int maximoVec (Deposito vec[], int len){
   int posMax=0;

   for (int i=1;i<len;i++){
      if (vec[i].ProdDisponibles>vec[posMax].ProdDisponibles){
         posMax=i;
      }
   }
   return posMax;
}
int minimoVec (Deposito vec[], int len){
   int posMin=0;

   for (int i=1;i<len;i++){
      if (vec[posMin].ProdDisponibles>vec[i].ProdDisponibles){
         posMin=i;
      }
   }
   return posMin;
}

void mostrar (Deposito vec [], int len){
   for (int i=0; i<len; i++){
      cout<<vec[i].Codigo<<"-"<<vec[i].ProdDisponibles<<endl;
   }
}

