
#include <iostream>
#include <stdio.h>
using namespace std;

struct multa{
    int dominio;
    int tipo;
    int importe;
};
//se llama corte de control porq me va a hacer un corte en el recorrido para asegurar la comparacion
int main(){

 int anterior;
 int sumMultas;

 FILE *Multas;
 Multas=fopen("multas.dat","rb");

 //leer
 multa raux;
 fread(&raux,sizeof(struct multa),1,Multas);

 while(!feof(Multas)){
 anterior=raux.dominio;
 sumMultas=0;

   while(!feof(Multas) && anterior==raux.dominio){ //este seria el control en el medio, no es final de archivo? si, el dominio es igual al anterior= si
    sumMultas+=raux.importe;
    fread(&raux,sizeof(struct multa),1,Multas);// acá ya lee el siguiente, independientemente si tiene el mismo dominio o no. si no lo tiene se rompe el while
    }
    //cuando sale tiene que mostrar la cantidad de multas acumuladas
    cout<<"Dominio: "<<raux.dominio<<" tiene un total de multas de: $"<<sumMultas;
    }

fclose(Multas);

    return 0;
}