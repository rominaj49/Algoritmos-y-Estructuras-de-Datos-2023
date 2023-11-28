//============================================================================
// Name        : RegistrosVec22023.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

//Defino los tipos de datos
struct Alumno{
   int Legajo;
   int Curso;
   int Nota;
};

void inicializar (Alumno vec[], int cantP, Alumno ValorIni);
void mostrar (Alumno vec [], int len1);
int maximoVec (Alumno vec[], int len);

int main() {

   Alumno vec[5];
   int len=0;
   Alumno RegIni; //creo un registro para inicializar mi vector
   int aux;
   RegIni.Legajo=0;
   RegIni.Curso=0;
   RegIni.Nota=0;

   inicializar(vec,5,RegIni);

   for(int i=0;i<5;i++){
      cout<<"ingrese un legajo"<<endl;
      cin>>vec[i].Legajo;
      cout<<"Ingrese un número de curso"<<endl;
      cin>>vec[i].Curso;
      cout<<"ingrese la nota"<<endl;
      cin>>vec[i].Nota;
      len++;
   }

   aux=maximoVec(vec,len);
   cout<<"La nota máxima la tuvo el legajo: "<<vec[aux].Legajo<<"y fue: "<<vec[aux].Nota<<endl;
   mostrar(vec,len);
   return 0;
}

void inicializar (Alumno vec[], int cantP, Alumno ValorIni){
   for (int i=0; i<cantP; i++){
      vec[i].Legajo=ValorIni.Legajo;
      vec[i].Curso=ValorIni.Curso;
      vec[i].Nota=ValorIni.Nota;
   }
}

void mostrar (Alumno vec [], int len1){
   for (int i=0; i<len1; i++){
      cout<<vec[i].Legajo<<"."<<vec[i].Curso<<"."<<vec[i].Nota<<endl;
   }
}

int maximoVec (Alumno vec[], int len){
   int posMax=0;

   for (int i=1;i<len;i++){
      if (vec[i].Nota>vec[posMax].Nota){
         posMax=i;
      }
   }
   return posMax;
}

