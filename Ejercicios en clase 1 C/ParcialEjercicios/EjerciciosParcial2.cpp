#include <iostream>
using namespace std;
// Desarrolle un procedimiento muestre por pantalla el número escrito en letras, del
// número que recibe por parámetro. Se sabe que del programa principal, le enviarán un
// número múltiplo de 100 entre 100 y 500.

int main(){

int numero;
cout<<"Ingrese un numero multiplo de 100, entre 100 y 500"<<endl;
cin>>numero;

if (numero==100 or numero==200 or numero==300 or numero==400 or numero==500)
{
 switch (numero)
{
case 100:
   cout<<"Cien"<<endl;
   break;

case 200:
   cout<<"Doscientos"<<endl;
   break;

case 300:
   cout<<"Trescientos"<<endl;
   break;

case 400:
   cout<<"Cuantrocientos"<<endl;
   break;

case 500:
   cout<<"Quinientos"<<endl;
   break;
}
}
else{
   cout<<"Ha ingresado un numero no válido, favor de volver a ingresar"<<endl;
}


   return 0;
}
