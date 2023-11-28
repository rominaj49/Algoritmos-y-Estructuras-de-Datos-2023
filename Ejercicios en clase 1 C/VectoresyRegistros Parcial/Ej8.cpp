// Se tiene un archivo de registros de tamaño fijo de los jugadores convocados a la Copa
// América 2021 con nombre Jugadores2021.DAT. El formato del registro de este archivo es el
// siguiente:
// COD_JUG: Código del Jugador / Número
// SELECCIÓN: ID de la Selección en la que juegan / Número
// EDAD: Edad / Numérico
// ALTURA: Estatura del jugador / Número decimal

// Se pide realizar un programa que lea ese archivo y genere dos archivos nuevos. El primero
// (SUB23.dat) que contenga todos los Jugadores de hasta 23 años. Con el siguiente formato:
// COD_JUG: Código del Jugador / Número
// SELECCIÓN: ID de la Selección en la que juegan / Número
// EDAD: Edad / Numérico
// ALTURA: Estatura del jugador / Número decimal
// El segundo (MAY180.dat) que contenga los Jugadores que miden más de 1,80m el siguiente
// formato:
// COD_JUG: Código del Jugador / Número
// SELECCIÓN: ID de la Selección en la que juegan / Número
// EDAD: Edad / Numérico CREACION DE 2 ARCHIVOS CON DIF STRUCT A PARTIR DE UN ARCHIVO PRINCIPAL

#include <iostream>
using namespace std;

struct CopAmerica{
int COD_JUG;
int SELECCION;
int EDAD;
double ALTURA;
};

struct SUB23{
    int COD_JUG;
int SELECCION;
double ALTURA;
};

struct MAY180{
int COD_JUG;
int SELECCION;
int EDAD;
};

int main(){

SUB23 rcargaEdad;
MAY180 rcargaAltura;

FILE * RegEdad;
FILE * RegAltura;
RegEdad=fopen("SUB23.DAT", "wb");
RegAltura=fopen("MAY180.DAT", "wb");


FILE * copaRegis;
copaRegis=fopen("Jugadores2021.DAT", "rb");
CopAmerica raux;

while (!feof(copaRegis))
{
  if (raux.EDAD<=23)
  {
    rcargaEdad.COD_JUG=raux.COD_JUG;
    rcargaEdad.ALTURA=raux.ALTURA;
    rcargaEdad.SELECCION=raux.SELECCION;
    fwrite(&rcargaEdad,sizeof(struct SUB23), 1, RegEdad);
  }

  else if(raux.ALTURA>=1.80){
    rcargaAltura.COD_JUG=raux.COD_JUG;
    rcargaAltura.EDAD=raux.EDAD;
    rcargaAltura.SELECCION=raux.SELECCION;
    fwrite(&rcargaAltura,sizeof(struct MAY180), 1, RegAltura);
  }
fread(&raux, sizeof(struct CopAmerica),1,copaRegis);
}
fclose(copaRegis);
fclose(RegEdad);
fclose(RegAltura);

    return 0;
}