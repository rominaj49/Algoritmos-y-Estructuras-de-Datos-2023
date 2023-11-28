// Ejercicio 2:
// Se tiene un archivo de los productos almacenados en el ala este del depósito Este.dat (ordenado por
// código de producto) y otro archivo de igual tipo con los productos del ala oeste Oeste.dat. (ordenado
// por código de producto).
// - Código de producto: 999999
// - Descripción
// - Stock: 99999
// Se pide:
// a) Obtener un único archivo con todos los productos y su stock ordenado por código de producto

#include <iostream>
#include <stdio.h>
using namespace std;

struct deposito{
    int codProd;
    char desc[50];
    int stock;
};

int main(){

FILE * E;
FILE * O;
FILE * EO;

E=fopen("ESTE.dat", "rb");
O=fopen("OESTE.dat", "rb");
EO=fopen("EOrdenado.dat", "wb");

deposito rauxE;
deposito rauxO;

fread(&rauxE,sizeof(struct deposito),1,E);
fread(&rauxO,sizeof(struct deposito),1,O);

while (!feof(E) && !feof(O))
{

   if (rauxE.codProd<rauxO.codProd)
   {
    fwrite(&rauxE,sizeof(struct deposito),1,EO);
    fread(&rauxE,sizeof(struct deposito),1,O);
   }
   else{
    fwrite(&rauxO,sizeof(struct deposito),1,EO);
    fread(&rauxO,sizeof(struct deposito),1,O);

   }
   
}

while (!feof(E)){
   fwrite(&rauxE,sizeof(struct deposito),1,EO);
    fread(&rauxE,sizeof(struct deposito),1,O);
}

while(!feof(O)){
    fwrite(&rauxO,sizeof(struct deposito),1,EO);
    fread(&rauxO,sizeof(struct deposito),1,O);
}

return 0;
}