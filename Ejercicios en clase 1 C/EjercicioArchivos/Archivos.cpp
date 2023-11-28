#include <iostream>
#include <stdio.h>
using namespace std;
// Archivo conjunto de valores que viven en un almacenamiento de memoria, ej disco duro.
//  Para trabajar con archivos: Alum va a ser nuestro puntero
//  1) Definir el puntero al archivo - FILE * Alum; //ME PERMITE IR REGISTRO TRAS REGISTRO EN MI ARCHIVO
//  2) Abrir el archivo - para leer o escribir Alum = fopen ("k1131.dat", "wb"); // "rb"-Lectura // "wb"-Escritura
// Rb+ - Primero para leer y luego para escribir // "Wb+" - Primero para escribir y luego para leer
//  3) Lectura del archivo (si lo estoy abriendo para leer)
//  4) Proceso/calculos o lo que me pidan
//  5) Cerrar el archivo fclose(Alum);

//contar la cantidad de promocionados ejemplo hacer

struct Alumno{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};

int main(){
int suma=0;
int cont=0;

 Alumno raux;

// 1) Definir el puntero
 FILE *Alum;
// 2) Abrir el archivo en modo lectura
 Alum = fopen("K1151.dat", "rb");
// 3) Leer mi archivo  ,(donde lo voy a guardar, el tamaño del registro, de a cuantos voy a leer, que voy a leer)
 fread(&raux,sizeof(struct Alumno),1,Alum);

while (!feof(Alum))
{
 suma=suma+raux.nota1;
 cont++;

 cout<<"-----------------"<<endl;
 cout<<"Legajo: "<<raux.legajo;
 cout<<" DNI: "<<raux.dni;
 cout<<" Nota1: "<<raux.nota1;
 cout<<" Nota2: "<<raux.nota2;

 fread(&raux,sizeof(struct Alumno),1,Alum);
}
 fclose(Alum);
 cout<<"El promedio del primer parcial es: "<<suma/cont<<endl;
return 0;
}