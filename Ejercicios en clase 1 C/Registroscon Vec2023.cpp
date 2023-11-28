//============================================================================
// Name        : Registroscon.cpp
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

int main() {

   Alumno vec[5];
   int len=0;
   Alumno RegIni; //creo un registro para inicializar mi vector es necesario ya que no contamos con int, sino con registro
   int sum=0;
   RegIni.Legajo=0;
   RegIni.Curso=0;
   RegIni.Nota=0;

   inicializar(vec,5,RegIni);

   for(int i=0;i<5;i++){
      cout<<"ingrese un legajo"<<endl;
      cin>>vec[i].Legajo;
      cout<<"Ingrese un n�mero de curso"<<endl;
      cin>>vec[i].Curso;
      cout<<"ingrese la nota"<<endl;
      cin>>vec[i].Nota;
      sum=sum+vec[i].Nota;
      len++;
   }

   cout<<"El promedio de las notas de los alumnos es: "<<sum/5<<endl;
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
