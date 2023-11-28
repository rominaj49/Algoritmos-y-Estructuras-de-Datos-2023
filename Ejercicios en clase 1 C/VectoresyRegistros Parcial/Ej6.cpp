// 6) Se tiene un archivo de películas infantiles en cartelera en los cines de Buenos Aires para las
// vacaciones de invierno PelInf.DAT (Sin Orden)
// - Código de Película: 999999
// - Cantidad de Cines en las que se presentó: 99999
// - Cantidad de entradas vendidas: 999999999
// Se pide:
// a) Ordenar el Archivo por Entradas Vendidas
// b) Listar las 10 películas que más entradas vendidas tuvieron (al listar incluir toda la
// información referente a la película)
// Nota: Sólo debe leer 1 vez el archivo. Se sabe que no hay más de 50 películas.

#include <iostream>
using namespace std;

void inicializar (Peliculas vec[], int cantP, Peliculas ValorIni);
void insertarOrdenado(Peliculas vec[], int &len1,Peliculas valor);
void insertar(Peliculas vec[], int &len1, Peliculas valor, int pos);

struct Peliculas{
    int codPel;
    int cantCines;
    int cantEntrads;
};

int main(){
Peliculas pOrdenado[10];
int len=0;
Peliculas regIni;
regIni.cantCines=0;
regIni.cantEntrads=0;
regIni.codPel=0;
inicializar(pOrdenado,len,regIni);


//ya existe el registro principal, lo leo.
FILE * PeliculasReg;
PeliculasReg=fopen("PelInf.DAT","rb");

Peliculas raux;
fread(&raux,sizeof(struct Peliculas),1,PeliculasReg);

while (!feof(PeliculasReg))
{
insertarOrdenado(pOrdenado,len,raux);

fread(&raux,sizeof(struct Peliculas),1,PeliculasReg);
}

fclose(PeliculasReg);

PeliculasReg=fopen("PelInf.DAT","wb");//reescribo el archivo con el vector aux ordenado.
for (int i = 0; i < len; i++)
{
    fwrite(&pOrdenado[i],sizeof(struct Peliculas),1, PeliculasReg);

    if (i<10)
    {
        cout<<"--------------------NRO:"<<i+1<<"------------------------"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"Codigo de Pelicula #"<<pOrdenado[i].codPel<<endl;
        cout<<"Cantidad de Cines que presento"<<pOrdenado[i].cantCines<<endl;
        cout<<"Codigo de Ventas #"<<pOrdenado[i].cantEntrads<<endl;
        i--;
    }
    
}
fclose(PeliculasReg);
return 0;
}




void insertar(Peliculas vec[], int &len1, Peliculas valor, int pos)
{
   // generar el movimiento de los valores para generar el espacio de carga necesario
   for (int i = len1; i > pos; i--)
   {
      vec[i].cantCines = vec[i - 1].cantCines;
      vec[i].cantEntrads = vec[i - 1].cantEntrads;
      vec[i].codPel = vec[i - 1].codPel;
   }
   // cargo el valor
   vec[pos].cantCines = valor.cantCines;
   vec[pos].cantEntrads = valor.cantEntrads;
   vec[pos].codPel = valor.codPel;
   len1++;
}

void insertarOrdenado(Peliculas vec[], int &len1,Peliculas valor){
   //1 d�nde lo voy a cargar, buscar la posici�n en la que lo tengo que insertar
   int i=0;
   while(i<len1 && vec[i].cantEntrads<=valor.cantEntrads){
      i++;
   }
   //2 CARGAR el valor en la posici�n que determin�
   if(i==len1){
      vec[len1].cantEntrads=valor.cantEntrads;
      len1++;
   }
   else insertar(vec,len1,valor,i);}

   void inicializar (Peliculas vec[], int cantP, Peliculas ValorIni){
   for (int i=0; i<cantP; i++){
      vec[i].cantCines=ValorIni.cantCines;
      vec[i].cantEntrads=ValorIni.cantEntrads;
      vec[i].codPel=ValorIni.codPel;

   }
}