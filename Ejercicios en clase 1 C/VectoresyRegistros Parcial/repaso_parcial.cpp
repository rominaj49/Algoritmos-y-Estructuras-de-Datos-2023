#include <iostream>
#include <stdio.h>

using namespace std;

struct Proovedores {
    int cod_prod;
    char tipo_prod;
    int cpe;
};
struct ProovedoresA {
    int cod_prod;
    int cpe;
};

void inicializar(ProovedoresA vec[], ProovedoresA aux, int len);

void insertarOrdenado(ProovedoresA vec[], int &len, ProovedoresA prov);

void cargarArchivo(FILE *fProv, ProovedoresA vec[], int len);

int main() {
    FILE *fProvAll;
    FILE *fProvA;
    FILE *fProvG;

    Proovedores provAux;
    int lenA = 0;
    int lenG = 0;
    ProovedoresA vecProvA[100];
    ProovedoresA vecProvG[100];
    ProovedoresA provAAux;
    provAAux.cod_prod = 0;
    provAAux.cpe = 0;

    inicializar(vecProvA, provAAux, 100);
    inicializar(vecProvG, provAAux, 100);

    fProvAll = fopen("Prov_AllProd.DAT", "rb");

    fread(&provAux, sizeof(struct Proovedores), 1, fProvAll);

    while (!feof(fProvAll)) {
        provAAux.cod_prod = provAux.cod_prod;
        provAAux.cpe = provAux.cpe;

        if (provAux.tipo_prod == 'A') {
            insertarOrdenado(vecProvA, lenA, provAAux);
        }

        if (provAux.tipo_prod == 'G') {
            insertarOrdenado(vecProvG, lenG, provAAux);
        }

        fread(&provAux, sizeof(struct Proovedores), 1, fProvAll);
    }

    fProvA = fopen("PROV_A.DAT", "wb");
    cargarArchivo(fProvA, vecProvA, lenA);
    fclose(fProvA);
    fProvG = fopen("PROV_G.DAT", "wb");
    cargarArchivo(fProvG, vecProvG, lenG);
    fclose(fProvG);

    fclose(fProvAll);
    return 0;
}

void cargarArchivo(FILE *fProv, ProovedoresA vec[], int len) {

    for (int i = 0; i < len; i++) {
        fwrite(&vec[i], sizeof(struct ProovedoresA), 1, fProv);
    }
}
