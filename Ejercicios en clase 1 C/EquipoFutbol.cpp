#include <iostream>
using namespace std;

//cuando dice "dado un vector" no hay que inicianizarlo pero si definirlo
//Defino los tipos de datos
struct Equipo{
   int codEq;
   int rdo;
};
int puntaje (char x);

int main(){

 Equipo vec[90];
 int len; //vale 90
 int sum=0;//sumar el puntaje x equipo
 int aux, aux2;

 aux = vec[0].codEq;
 for (int i = 0; i < len; i++)
 {
    if(vec[i].codEq==aux){
        aux2=puntaje(vec[i].rdo);
        sum=sum+aux2;
    }
    else{
        cout<<"El equipo: "<<"sumó los siguientes puntos: "<<sum;
        aux=vec[i].codEq;
        sum=puntaje(vec[i].rdo);
    }
 }
    return 0;
}
int puntaje (char x){
    if (x=='P'){
        return 0;
    }
    else if( x=='E'){
        return 1;
    }
    else return 3;
}