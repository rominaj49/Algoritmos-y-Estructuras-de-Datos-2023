#include <iostream>
using namespace std;
// EJERCICIO DE VECTORES
// 1) Dado un vector acerca de la producción de una fábrica, que contiene el código del producto
// fabricado y la cantidad de unidades disponibles para la venta (Se sabe que máximo hay 150
// productos en proceso de fabricación), determinar:
// a- ¿Cuál es el producto que más unidades tiene fabricados?
// b- ¿Cuál es el producto que menos unidades tiene?
// c- Indicar la cantidad total de productos fabricados según el vector.

struct Produccion{
    int codigo;
    int cantDispon;
};

int maximoVec(Produccion vec[], int len);
int minimoVector(Produccion vec[], int len);

int main()
{
    Produccion vec[150];
    int len;
//1
int posMax=maximoVec(vec,len);
cout<<"El producto que tiene más fabricados el de codigo: #"<<vec[posMax].codigo<<endl;
//2
int posMin= minimoVector(vec, len);
cout<<"El producto que tiene menos fabricados el de codigo: #"<<vec[posMin].codigo<<endl;
//3
cout<<"La cantidad de productos fabricados son: "<<len<<endl;

   return 0;
}


int maximoVec(Produccion vec[], int len)
{
   int posMax = 0;
   for (int i = 1; i < len; i++)
   {
      if (vec[i].cantDispon > vec[posMax].cantDispon)
      {
         posMax = i;
      }
   }
   return posMax;
}

int minimoVector(Produccion vec[], int len){
   int posmin;
   posmin=0;
   for(int i=1;i<len; i++){
      if(vec[posmin].cantDispon>vec[i].cantDispon){
         posmin=i;
      }
   }
   return posmin;
}