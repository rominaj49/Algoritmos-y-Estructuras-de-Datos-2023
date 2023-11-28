// 7) Se tiene un archivo de registros de tamaño fijo de productos a la venta en un depósito con
// nombre PROD_DEP.DAT. El formato del registro de este archivo es el siguiente:
// COD_PROD: Código del producto / Numérico
// PESO: Peso en kilogramos del producto / Numérico
// VTO: Fecha de vencimiento del producto / Numérico Formato ‘MMAAAA’
// Se pide realizar un programa que lea ese archivo y genere dos archivos nuevos. El primero
// (PESADOS.dat) que contenga todos los productos de más de 50 kg. Con el siguiente
// formato:
// COD_PROD: Código del producto / Numérico
// VTO: Fecha de vencimiento del producto / Numérico Formato ‘MMAAAA’
// El segundo (VENC2021.dat) que contenga los productos que se vencen en el año 2021 con el
// siguiente formato:
// COD_PROD: Código del producto / Numérico
// PESO: Peso en kilogramos del producto / Numérico
// VTO: Fecha de vencimiento del producto / Numérico Formato ‘MMAAAA’ NO CORREGIDO
// solo creacion de 2 archivos no ordenados.

#include <iostream>
using namespace std;

struct Deposito{
int codigo;
int peso;
int vencimiento;
};

struct Pesados{
    int codigo;
    int vencimiento;
};

struct Vencidos{
    int codigo;
    int peso;
    int vencimiento;
};

int main(){

Vencidos cargaVencidos;
Pesados cargaPesados;

//Ahora leemos el archivo.
FILE *Vnc;
Vnc=fopen("VENC2021.dat", "wb"); //creamos archivos ya que eso pide
FILE *Psd;
Psd=fopen("PESADOS.dat", "wb"); //creamos archivos ya que eso pide

FILE *dep;
dep=fopen("PROD_DEP.DAT", "rb");
Deposito raux;
fread(&raux,sizeof(struct Deposito),1,dep);

while(!feof(dep)){

   if(raux.peso>50){
    cargaPesados.codigo=raux.codigo;
    cargaPesados.vencimiento=raux.vencimiento;
    fwrite(&cargaPesados,sizeof(struct Pesados), 1, Psd);
   }

   if(raux.vencimiento==2021){
   cargaVencidos.codigo=raux.codigo;
   cargaVencidos.peso=raux.peso;
   cargaVencidos.vencimiento=raux.vencimiento;
    fwrite(&cargaVencidos,sizeof(struct Pesados), 1, Vnc);
   }
   
    fread(&raux,sizeof(struct Deposito),1,dep);
}
fclose(dep);
fclose(Vnc);
fclose(Psd);

return 0;
}



void inicializar (Pesados vec[], int cantP, Pesados ValorIni);
void inicializar (Vencidos vec[], int cantP, Vencidos ValorIni);
void insertarOrdenado(Vencidos vec[], int &len1,Vencidos valor, int pos);
void insertarOrdenado(Pesados vec[], int &len1,Pesados valor, int pos);

