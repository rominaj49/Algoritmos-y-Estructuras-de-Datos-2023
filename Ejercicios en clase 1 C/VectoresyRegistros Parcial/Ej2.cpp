// 2) Dado un vector (de registros) acerca las estadísticas de los jugadores que participaron en la
// Copa América 2021 y marcaron goles; que contiene el código del jugador, Inicial de
// Selección a la que pertenecen y la cantidad de goles convertidos. (Se sabe que hay
// cómo máximo 276 jugadores), se pide determinar:
// a- ¿Cuál es el Jugador que más goles convirtió? (Código del Jugador y cantidad de goles)
// b- ¿Cuál es el Jugador que menos goles convirtió? (Código del Jugador y cantidad de goles)
// c- Calcular el promedio de goles convertidos.
#include <iostream>
using namespace std;

struct Jugadores{
    int codigo;
    char inicial;
    int goles;
};


int main(){

//ya estarian definidos los vectores
Jugadores vec[276];
int len;
int may=0;
int men=0;
int cantGoles = vec[0].goles;

for (int i = 1; i < len; i++)
{
   if (vec[i].goles<vec[men].goles)
   {
      men=i;
   }
   else if(vec[i].goles>vec[may].goles){
      may=i;
   }
   cantGoles+=vec[i].goles;   
}




cout<<"---------------------------------"<<endl;
cout<<"El jugador que más goles hizo fue el de codigo: #"<<vec[may].codigo<<endl;
cout<<"Con"<<vec[may].goles<<" goles."<<endl;

cout<<"---------------------------------"<<endl;
cout<<"El jugador que menos goles hizo fue el de codigo: #"<<vec[men].codigo<<endl;
cout<<"Con"<<vec[men].goles<<" goles."<<endl;

cout<<"---------------------------------"<<endl;
cout<<"El promedio de goles fue de"<<cantGoles/len<<endl;


cout<<"---------------------------------"<<endl;


    return 0;
}



