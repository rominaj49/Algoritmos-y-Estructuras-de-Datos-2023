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

//De un censo realizado en una población se conocen los siguientes datos:

// - Día de nacimiento (2 dig.)
// - Mes (2 dig.)
// - Año (4 dig.)
// - Sexo ('M'=masc. 'F'=fem.)

// Con estos datos de cada habitante se forma un lote finalizado con un día cero. Desarrollar el
// programa que determine e imprima:
// 1) Cuántos nacimientos hubo en el mes de octubre de todos los años.
// 2) Cuántos nacimientos hubo antes del 9 de julio de 1990.
// 3) Cuántos nacimientos de mujeres hubo en la primavera del 1982.
// 4) Sexo de la persona más vieja (solo existe una).

struct Censo{
    int diaNac;
    int mesNac;
    int Anio;
    char sexo;
};

int main(){

int totalNacOctubre=0;
int nacJulio=0;
int nacMuj=0;

Censo raux;

FILE *cenAnios;
cenAnios = fopen("CensosTT.dat", "rb");
fread(&raux, sizeof(struct Censo),1, cenAnios);

while (!feof(cenAnios))
{

    if (raux.mesNac==10)
    {
       totalNacOctubre++;
    }

    if (raux.Anio<1990)
    { 
       nacJulio++;
       if (raux.Anio==1982 && raux.sexo == 'F' && raux.mesNac>=9 && raux.mesNac<=12)
       {
        nacMuj++;
       }
       if (raux.Anio==1990)
       {
        if (raux.mesNac<=7){
         if (raux.diaNac<9){
          nacJulio++;
         }
        }  
       }
    }

    fread(&raux, sizeof(struct Censo),1, cenAnios);

}
fclose(cenAnios);


return 0;
}