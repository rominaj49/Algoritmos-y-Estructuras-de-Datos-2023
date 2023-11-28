//
// Created by agutierrez on 04/07/23.
//

#include "peliculas_infantiles.h"

#include <iostream>
#include <stdio.h>

using namespace std;

struct Peliculas {
    int cod_pelicula;
    int cant_cines_presentado;
    int cant_entradas_vendidas;
};

void listarMasVendidas(Peliculas vec[], int len, int cantPel);

void insertar(Peliculas vec[], int &len1, Peliculas valor, int pos);

void insertarOrdenado(Peliculas vec[], int &len1, Peliculas valor);

int main() {
    int len = 50;
    Peliculas vecPeliculas[len];
    Peliculas pelAux;
    FILE *fPelis = fopen("PellInf.dat", "rb");
    fread(&pelAux, sizeof(struct Peliculas), 1, fPelis);
    while (!feof(fPelis)) {
        insertarOrdenado(vecPeliculas, len, pelAux);
        fread(&pelAux, sizeof(struct Peliculas), 1, fPelis);
    }
    int cantPeliculas = 10;

    listarMasVendidas(vecPeliculas, len, cantPeliculas);

    fclose(fPelis);

    return 0;
}


void listarMasVendidas(Peliculas vec[], int len, int cantPel) {
    cout << " ****** Peliculas mas vendidas ****** " << endl;
    for (int i = 0; i < cantPel; i++) {
        cout << " --- Pelicula N° " << i << " --- " << endl;
        cout << "Codigo de la Pelicula:  " << vec[i].cod_pelicula << endl;
        cout << "Cantidad de cines en las que fue presentada:  " << vec[i].cant_cines_presentado << endl;
        cout << "Cantidad de entradas vendidas:  " << vec[i].cant_entradas_vendidas << endl;
        cout << endl;
    }
}

void insertar(Peliculas vec[], int &len1, Peliculas valor, int pos) {
    //generar el movimiento de los valores para generar el espacio de carga necesario
    for (int i = len1; i > pos; i--) {
        vec[i].cod_pelicula = vec[i - 1].cod_pelicula;
        vec[i].cant_cines_presentado = vec[i - 1].cant_cines_presentado;
        vec[i].cant_entradas_vendidas = vec[i - 1].cant_entradas_vendidas;
    }
    //cargo el valor
    vec[pos].cod_pelicula = valor.cod_pelicula;
    vec[pos].cant_cines_presentado = valor.cant_cines_presentado;
    vec[pos].cant_entradas_vendidas = valor.cant_entradas_vendidas;
    len1++;
}

void insertarOrdenado(Peliculas vec[], int &len1, Peliculas valor) {
    //1 d�nde lo voy a cargar, buscar la posici�n en la que lo tengo que insertar
    int i = 0;
    while (i < len1 && vec[i].cant_entradas_vendidas <= valor.cant_entradas_vendidas) {
        i++;
    }
    //2 CARGAR el valor en la posici�n que determin�
    if (i == len1) {
        vec[len1].cod_pelicula = valor.cod_pelicula;
        vec[len1].cant_cines_presentado = valor.cant_cines_presentado;
        vec[len1].cant_entradas_vendidas = valor.cant_entradas_vendidas;
        len1++;
    } else insertar(vec, len1, valor, i);
}