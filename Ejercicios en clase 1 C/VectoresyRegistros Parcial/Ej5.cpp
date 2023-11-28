// 5) Se tiene un archivo de registros de tamaño fijo de proveedores con nombre ISP_G.DAT. El
// formato del registro de este archivo es el siguiente:

// ID_ISP: Número de Proveedor de Internet/ Numérico
// TIPO_PROD: Tipo de producto que vende / Un caracter 'A'; 'F' o 'G'. (ADSL– Fibra– 4G)
// CPI: Cantidad de Pedidos de instalación / Numérico
// CC: Cantidad de Clientes / Numérico
// Los registros en el archivo no tienen ningún orden específico y se sabe que no contiene más
// de 100.
// Se pide:
// - Ordenar el Archivo ISP_G.dat
// - Informar por pantalla la cantidad total de clientes, sin importar el proveedor.

//REESCRIBIR ARCHIVO DE FORMA ORDENADA.

void insertarOrdenado(Proveedor vec[], int &len1,Proveedor valor);
   void inicializar (Proveedor vec[], int cantP, Proveedor ValorIni);


struct Proveedor{
int ID_ISP;
char TIPO_PROD;
int CPI;
int CC;
};

#include <iostream>
using namespace std;

int main(){
int sumt=0;
int len=0;

Proveedor vecOrdenado[100];
Proveedor regIni;
regIni.TIPO_PROD='\0';
regIni.ID_ISP=0;
regIni.CPI=0;
regIni.CC=0;
inicializar(vecOrdenado,100,regIni);

FILE * Prov; //creo el puntero
Prov= fopen("ISP_G.DAT.dat", "rb" ); //abro el archivo con mi puntero

Proveedor raux; //leemos pero creamos un archivo auxiliar
fread(&raux,sizeof (struct Proveedor),1,Prov);

while (!feof(Prov))
{
sumt += raux.CC;
insertarOrdenado(vecOrdenado,len,raux);
fread(&raux,sizeof (struct Proveedor),1,Prov);
}
fclose(Prov);


Prov= fopen("ISP_G.DAT.dat", "wb" ); //abro el archivo con mi puntero
for (int i = 0; i < len; i++)
{
fwrite(&vecOrdenado[i],sizeof(struct Proveedor),1,Prov);
}
fclose(Prov);

    return 0;
}




void insertar(Proveedor vec[], int &len1, Proveedor valor, int pos)
{
   // generar el movimiento de los valores para generar el espacio de carga necesario
   for (int i = len1; i > pos; i--)
   {
      vec[i].CC = vec[i - 1].CC;
      vec[i].CPI = vec[i - 1].CPI;
      vec[i].ID_ISP = vec[i - 1].ID_ISP;
      vec[i].TIPO_PROD = vec[i - 1].TIPO_PROD;
      
   }
   // cargo el valor
   vec[pos].CC = valor.CC;
   vec[pos].CPI = valor.CPI;
   vec[pos].ID_ISP = valor.ID_ISP;
   vec[pos].TIPO_PROD = vec[pos - 1].TIPO_PROD;
   len1++;
}

void insertarOrdenado(Proveedor vec[], int &len1,Proveedor valor){
   //1 d�nde lo voy a cargar, buscar la posici�n en la que lo tengo que insertar
   int i=0;
   while(i<len1 && vec[i].CC<=valor.CC){
      i++;
   }
   //2 CARGAR el valor en la posici�n que determin�
   if(i==len1){
      vec[len1].CC=valor.CC;
      len1++;
   }else insertar(vec,len1,valor,i);}

   void inicializar (Proveedor vec[], int cantP, Proveedor ValorIni){
   for (int i=0; i<cantP; i++){
      vec[i].ID_ISP=ValorIni.ID_ISP;
      vec[i].CPI=ValorIni.CPI;
      vec[i].CC=ValorIni.CC;
      vec[i].TIPO_PROD=ValorIni.TIPO_PROD;

   }
}