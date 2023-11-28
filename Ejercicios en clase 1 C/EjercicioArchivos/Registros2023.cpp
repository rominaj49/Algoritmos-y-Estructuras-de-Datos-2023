//============================================================================
// Name        : Registros2023.cpp
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

int main() {
	// 3 variables del tipo de dato Alumno
   Alumno x;
   Alumno y;
   Alumno z;
   // 3 variables x, y & z del tipo de dato Alumno
   int sum=0;

   cout<<"ingrese un legajo"<<endl;
   cin>>x.Legajo;
   cout<<"Ingrese un número de curso"<<endl;
   cin>>x.Curso;
   cout<<"ingrese la nota"<<endl;
   cin>>x.Nota;

   cout<<"ingrese un legajo"<<endl;
   cin>>y.Legajo;
   cout<<"Ingrese un número de curso"<<endl;
   cin>>y.Curso;
   cout<<"ingrese la nota"<<endl;
   cin>>y.Nota;

   cout<<"ingrese un legajo"<<endl;
   cin>>z.Legajo;
   cout<<"Ingrese un número de curso"<<endl;
   cin>>z.Curso;
   cout<<"ingrese la nota"<<endl;
   cin>>z.Nota;

   sum=x.Nota+y.Nota+z.Nota;
   cout<<"El promedio de las notas de los alumnos es: "<<sum/3<<endl;

	return 0;
}
