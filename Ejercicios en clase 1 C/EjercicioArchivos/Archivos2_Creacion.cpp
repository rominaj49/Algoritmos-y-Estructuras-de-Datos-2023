#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};

int main(){
 FILE * Alum;
 Alum = fopen ("K1151.dat","wb"); //Creando el archivo
 Alumno carga;

 cout<<"Ingrese un numero de legajo"<<endl;
 cin>>carga.legajo;

 while (carga.legajo!=0)
 {
    cout<<"Ingrese el DNI"<<endl;
    cin>>carga.dni;
    cout<<"Ingrese nota1"<<endl;
    cin>>carga.nota1;
    cout<<"Ingrese el nota2"<<endl;
    cin>>carga.nota2;
   fwrite (&carga,sizeof(struct Alumno),1,Alum);
   
    cout<<"Ingrese un numero de legajo"<<endl;
 cin>>carga.legajo;
 }
 fclose(Alum);

    return 0;
}