// Ejercicio 3:
// Se tiene las ventas del año de un retail, dividido en 3 archivos, uno por trimestre (1erTrimestre.dat,
// 2doTrimestre.dat y 3erTrimestre.dat) ordenados por código de producto.
// - Código de producto: 999999
// - Descripción
// - Unidades vendidas: 99999
// Se pide:
// a) Obtener un único archivo con todas las ventas ordenado por código de producto 2018.dat

#include <iostream>
#include <stdio.h>
using namespace std;

struct Ventas{
    int codigo;
    char desc[40];
    int unid;
};


int maint(){

FILE * regprTr;
FILE * regdoTr;
FILE * regerTr;
FILE * reg2018;

regprTr=fopen("1erTrimestre.dat", "rb");
regdoTr=fopen("2doTrimestre.dat","rb");
regerTr=fopen("3erTrimestre.dat", "rb");
reg2018=fopen("2018.dat", "wb");

Ventas rauxP;
Ventas rauxS;
Ventas rauxT;

fread(&rauxP, sizeof(struct Ventas),1,regprTr);
fread(&rauxS, sizeof(struct Ventas),1,regdoTr);
fread(&rauxT, sizeof(struct Ventas),1,regerTr);

while (!feof(regprTr) && !feof(regdoTr) && !feof(regerTr)) // 3/6/2
{
    if (rauxP.codigo<=rauxS.codigo) // 1<2
    {
        if (rauxP.codigo<rauxT.codigo)// 1<3
        {
            fwrite(&rauxP,sizeof(struct Ventas),1,reg2018);
            fread(&rauxP, sizeof(struct Ventas),1,regprTr);
        }
        else{
            fwrite(&rauxT,sizeof(struct Ventas),1,reg2018);
            fread(&rauxT, sizeof(struct Ventas),1,regerTr);
        }
    }
    else if (rauxS.codigo<=rauxP.codigo){

       if (rauxS.codigo<rauxT.codigo)
       {
          fwrite(&rauxS,sizeof(struct Ventas),1,reg2018);
          fread(&rauxS, sizeof(struct Ventas),1,regdoTr);
       }
       else{
          fwrite(&rauxT,sizeof(struct Ventas),1,reg2018);
          fread(&rauxT, sizeof(struct Ventas),1,regerTr);
       }
       
    }

    
}


    return 0;
}