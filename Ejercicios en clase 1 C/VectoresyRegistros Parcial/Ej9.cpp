// 9) Se tiene un archivo de registros de tamaño fijo de los jugadores convocados a la Copa
// América 2021 con nombre Jugadores2021.DAT. El formato del registro de este archivo es el
// siguiente:
// COD_JUG: Código del Jugador / Número
// SELECCIÓN: ID de la Selección en la que juegan / Número
// EDAD: Edad / Numérico
// ALTURA: Estatura del jugador / Número decimal
// Se pide realizar un programa que lea ese archivo y genere dos vectores nuevos. El primero
// (SUB23. que contenga todos los Jugadores de hasta 23 años. Con el siguiente formato:
// COD_JUG: Código del Jugador / Número
// SELECCIÓN: ID de la Selección en la que juegan / Número
// EDAD: Edad / Numérico
// ALTURA: Estatura del jugador / Número decimal
// El segundo (MAY180) que contenga los Jugadores que miden más de 1,80m el siguiente
// formato:
// COD_JUG: Código del Jugador / Número
// SELECCIÓN: ID de la Selección en la que juegan / Número
// EDAD: Edad / Numérico
// Se sabe que máximo hay 100 registros en el archivo. CREACION DE 2 ARRAYS DIF A PARTIR DE UN ARCHIVO
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

void inicializar (SUB23 vec[], int cantP, SUB23 ValorIni);
void inicializar (MAY180 vec[], int cantP, MAY180 ValorIni);
void insertar(SUB23 vec[], int &len1, SUB23 valor, int pos);
void insertar(MAY180 vec[], int &len1, MAY180 valor, int pos);
void insertarOrdenado(SUB23 vec[], int &len1,SUB23 valor);
void insertarOrdenado(MAY180 vec[], int &len1,MAY180 valor);

int main(){

SUB23 vecEdad[100];
int len=0;
MAY180 vecAlt[100];
int len1=0;

SUB23 scarga;
SUB23 regIni;
regIni.ALTURA=0;
regIni.COD_JUG=0;
regIni.SELECCION=0;
inicializar(vecEdad,len,regIni);

MAY180 mcarga;
MAY180 regIni1;
regIni1.EDAD=0;
regIni1.COD_JUG=0;
regIni1.SELECCION=0;
inicializar(vecAlt,len1,regIni1);

FILE * CopaRegistro;
CopaRegistro=fopen("Jugadores2021.DAT", "rb");

CopAmerica raux;
fread(&raux, sizeof(struct CopAmerica),1,CopaRegistro);

while (!feof(CopaRegistro))
{
    if (raux.ALTURA>1.80)
    {
       mcarga.COD_JUG=raux.COD_JUG;
       mcarga.EDAD=raux.EDAD;
       mcarga.SELECCION=raux.EDAD;
       insertarOrdenado(vecAlt,len1,mcarga);
    }
    else if(raux.EDAD<=23){
       scarga.COD_JUG=raux.COD_JUG;
       scarga.ALTURA=raux.ALTURA;
       scarga.SELECCION=raux.EDAD;
       insertarOrdenado(vecEdad,len,scarga);
    }
    
}

    return 0;
}

