#include <iostream>
using namespace std;

// Se tiene un archivo de registros de tamaño fijo de proveedores con nombre ISP_G.DAT. 
// El formato del registro de este archivo es el siguiente:
// ID_ISP: Número de Proveedor de Internet/ Numérico
// TIPO_PROD: Tipo de producto que vende / Un caracter 'A'; 'F' o 'G'. (ADSL– Fibra– 4G)
// CPI: Cantidad de Pedidos de instalación / Numérico
// CC: Cantidad de Clientes / Numérico
// Los registros en el archivo no tienen ningún orden específico y se sabe que no contiene más de 100.
// Se pide:
// Realizar un programa que lea ese archivo y genere un vector ordenado PROV_A que contenga los 
// Proveedores de la categoría ADSL y otro con los de Fibra, PROV_F.  
// Ambos tienen que estar ordenado por la cantidad de cantidad de clientes. 
// El formato del registro de estos vectores es el siguiente:
// ID_ISP: Número de Proveedor de Internet/ Numérico
// CPI: Cantidad de Pedidos de instalación / Numérico
// CC: Cantidad de Clientes / Numérico
//EL ARCHIVO YA EXISTE y CREACION DE ARCHIVOS NUEVOS A PARTIR DE OTRO

struct Proveedor{
    int ID;
    char tipo;
    int CPI;
    int CC;
};

struct ProvVec{
int ID;
int CPI;
int CC;
};

void inicializar (ProvVec vec[], int cantP, ProvVec ValorIni);
void insertar(ProvVec vec[], int &len1,ProvVec valor, int pos);
void insertarOrdenado(ProvVec vec[], int &len1,ProvVec valor);


int main(){
//no hace falta crear vectores porque no tienen un orden especifico y dice que son archivos.

ProvVec rcarga;
//para leer el archivo definimos un puntero
FILE *Prov; //este ya viene dado x el ejercicio
FILE *PROVA;
FILE *PROVF;
FILE *PROVG;
Prov = fopen("ISP_G.dat", "rb");
PROVA = fopen("PROV_A.dat", "wb"); //creamos el archivos en el world
PROVF = fopen("PROV_F.dat", "wb"); //creamos el archivos en el world
PROVG = fopen("PROV_G.dat", "wb"); //creamos el archivos en el world

//leemos pero creamos un archivo auxiliar
Proveedor raux;
fread(&raux, sizeof(struct Proveedor),1,Prov);

while (!feof(Prov))
{
   rcarga.ID=raux.ID;
    rcarga.CPI=raux.CPI;
    rcarga.CC=raux.CC;

   if (raux.tipo=='A')
   {
    fwrite(&rcarga, sizeof(struct ProvVec),1,PROVA); //lo guardo en el vector que corresponde
   }
   else if (raux.tipo=='F')
   {
    fwrite(&rcarga, sizeof(struct ProvVec),1,PROVF); //lo guardo en el vector que corresponde
   }
   else{ 
   fwrite(&rcarga, sizeof(struct ProvVec),1,PROVG); //lo guardo en el vector que corresponde
   }
fread(&raux, sizeof(struct Proveedor),1,Prov);
}
fclose(Prov);
fclose(PROVA);
fclose(PROVF);
fclose(PROVG);

    return 0;
}





void inicializar (ProvVec vec[], int cantP, ProvVec ValorIni){
   for (int i=0; i<cantP; i++){
      vec[i].ID=ValorIni.ID;
      vec[i].CPI=ValorIni.CPI;
      vec[i].CC=ValorIni.CC;
   }
}


void insertar(ProvVec vec[], int &len1,ProvVec valor, int pos){
   //generar el movimiento de los valores para generar el espacio de carga necesario
   for (int i=len1;i>pos;i--){
       vec[i].ID=vec[i-1].ID;
      vec[i].CPI=vec[i-1].CPI;
      vec[i].CC=vec[i-1].CC;
   }
   //cargo el valor
   vec[pos].ID=valor.ID;
      vec[pos].CPI=valor.CPI;
      vec[pos].CC=valor.CC;
   len1++;
}

void insertarOrdenado(ProvVec vec[], int &len1,ProvVec valor){
   //1 d�nde lo voy a cargar, buscar la posici�n en la que lo tengo que insertar
   int i=0;
   while(i<len1 && vec[i].CC<=valor.CC){
      i++;
   }
   //2 CARGAR el valor en la posici�n que determin�
   if(i==len1){
      vec[len1].ID=valor.ID;
      vec[len1].CPI=valor.CPI;
      vec[len1].CC=valor.CC;

      len1++;
   }else insertar(vec,len1,valor,i);