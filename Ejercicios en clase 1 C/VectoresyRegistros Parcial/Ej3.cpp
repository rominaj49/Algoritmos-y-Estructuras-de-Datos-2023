#include <iostream>
using namespace std;
// 3) Dado un vector de Maratones que contiene el código de la maratón y la cantidad de
// inscriptos. Se sabe que hay 50 maratones, determinar:
// a- ¿Cuál fue la maratón que más inscriptos tuvo?
// b- ¿Cuál fue la maratón que menos inscriptos tuvo?
// c- Calcular el promedio de inscriptos en todas las maratones.
struct Maraton{
int codigo;
int inscriptos;
};

int main(){
Maraton maraton[50];
int len=50;
int may=0;
int men=0;
int ins= maraton[0].inscriptos; // maraton{ (12,32), (13,53), (14,35)}

for (int i = 1; i < len; i++)
{
  if (maraton[i].inscriptos>maraton[may].inscriptos)
  {
   may= i;
  }
  else if(maraton[i].inscriptos<maraton[men].inscriptos)
  {
   men= i;
  }
  ins+=maraton[i].inscriptos;
  
}




cout<<"---------------------------------"<<endl;
cout<<"La maraton que más inscriptos tuvo fue el de codigo: #"<<maraton[may].codigo<<endl;
cout<<"Con"<<maraton[may].inscriptos<<" inscriptos."<<endl;

cout<<"---------------------------------"<<endl;
cout<<"La maraton que menos inscriptos tuvo fue el de codigo: #"<<maraton[men].codigo<<endl;
cout<<"Con"<<maraton[men].inscriptos<<" inscriptos."<<endl;

cout<<"---------------------------------"<<endl;
cout<<"El promedio de ins fue de"<<ins/len<<endl;


cout<<"---------------------------------"<<endl;


return 0;
}
