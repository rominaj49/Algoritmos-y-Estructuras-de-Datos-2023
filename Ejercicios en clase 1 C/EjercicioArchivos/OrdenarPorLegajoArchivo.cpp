#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};

void inicializar (Alumno vec[], int cantP, Alumno ValorIni);
void mostrar (int vec [], int len1);
void insertar(Alumno vec[], int &len1,Alumno valor, int pos);
void insertarOrdenado(Alumno vec[], int &len1,Alumno valor);

int main(){
 Alumno vecAux[10];
 int len=0;

// inicializar(vec,10,0) no puede ser 0 porq no es un int, es un registro.
 Alumno regIni;
 regIni.legajo=0;
 regIni.dni= 0;
 regIni.nota1=0;
 regIni.nota2=0;
 inicializar(vecAux,10,regIni);

 //Empezamos a trabajar con archivos,

 FILE*Alum;
 Alum=fopen("K1151.dat","rb");
 //Ahora leemos o creamos
 Alumno raux; //donde se va a guardar la información leida. q es un registro auxiliar
 fread(&raux,sizeof(struct Alumno),1,Alum);

while(!feof(Alum)){
   insertarOrdenado(vecAux, len, raux); // x cada registro q inserto

 cout<<"-----------------"<<endl;
 cout<<"Legajo: "<<raux.legajo;
 cout<<" DNI: "<<raux.dni;
 cout<<" Nota1: "<<raux.nota1;
 cout<<" Nota2: "<<raux.nota2;

 fread(&raux,sizeof(struct Alumno),1,Alum); //hago la lectura para q no haga un bucle infinito
}
fclose(Alum);

Alum=fopen("K1152.dat","wb");
for ( int i = 0; i < len; i++)
{
   fwrite(&vecAux[i], sizeof(struct Alumno),1,Alum); //sobreescribo
    cout<<"-----------------"<<endl;
 cout<<"Legajo: "<<vecAux[i].legajo;
 cout<<" DNI: "<<vecAux[i].dni;
 cout<<" Nota1: "<<vecAux[i].nota1;
 cout<<" Nota2: "<<vecAux[i].nota2;

}
fclose(Alum);

return 0;
}


void inicializar (Alumno vec[], int cantP, Alumno ValorIni){
   for (int i=0; i<cantP; i++){
      vec[i].legajo=ValorIni.legajo;
      vec[i].dni=ValorIni.dni;
      vec[i].nota1=ValorIni.nota1;
      vec[i].nota2=ValorIni.nota2;
   }
}

void mostrar (int vec [], int len1){
   for (int i=0; i<len1; i++){
      cout<<vec[i]<<endl;
   }
}


void insertar(Alumno vec[], int &len1,Alumno valor, int pos){
   //generar el movimiento de los valores para generar el espacio de carga necesario
   for (int i=len1;i>pos;i--){
       vec[i].legajo=vec[i-1].legajo;
      vec[i].dni=vec[i-1].dni;
      vec[i].nota1=vec[i-1].nota1;
      vec[i].nota2=vec[i-1].nota2;
   }
   //cargo el valor
   vec[pos].legajo=valor.legajo;
      vec[pos].dni=valor.dni;
      vec[pos].nota1=valor.nota1;
      vec[pos].nota2=valor.nota2;
   len1++;
}

void insertarOrdenado(Alumno vec[], int &len1,Alumno valor){
   //1 d�nde lo voy a cargar, buscar la posici�n en la que lo tengo que insertar
   int i=0;
   while(i<len1 && vec[i].legajo<=valor.legajo){
      i++;
   }
   //2 CARGAR el valor en la posici�n que determin�
   if(i==len1){
      vec[len1].legajo=valor.legajo;
      vec[len1].dni=valor.dni;
      vec[len1].nota1=valor.nota1;
      vec[len1].nota2=valor.nota2;

      len1++;
   }else insertar(vec,len1,valor,i);
}
