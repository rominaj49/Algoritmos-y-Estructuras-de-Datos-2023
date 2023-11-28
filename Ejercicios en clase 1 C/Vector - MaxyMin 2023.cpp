//============================================================================
// Name        : Vector.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdio.h>
using namespace std;

void inicializar (int vec[], int cantP, int ValorIni);
void mostrar (int vec [], int len1);
void insertar(int vec[], int &len1,int valor, int pos);
void insertarOrdenado(int vec[], int &len1,int valor);
int maximoVector(int vec[], int len);
int minimoVector(int vec[], int len);

int main() {
   //1 Declarar el vector
   int numeros [10];
   int len =0;
   int n;
   int cont=0;
   int max;
   int min;
   //2 Inicializar el vector
   inicializar(numeros,10,0);

   //3 Cargar el vector - insertar ordenado
   cout<<"ingrese un valor o 0 para terminar"<<endl;
   cin>>n;

   while(n!=0&&cont<10){
      insertarOrdenado(numeros,len,n);
      cont++; //cuento para no pasarme de la capacidad del vector
      cout<<"ingrese un valor o 0 para terminar"<<endl;
      cin>>n;
   }

   //4 mostrar el Max y el Min
   max= maximoVector(numeros,len);
   cout<<"el valor maximo es: "<<numeros[max]<<"  que se encuentra en la pos: "<<max<<endl;
   min= minimoVector(numeros,len);
   cout<<"el valor m�nimo es: "<<numeros[min]<<"  que se encuentra en la pos: "<<min<<endl;

   //5 Mostrar el vector
   mostrar(numeros,len);

   return 0;
}

void inicializar (int vec[], int cantP, int ValorIni){
   for (int i=0; i<cantP; i++){
      vec[i]=ValorIni;
   }
}

void mostrar (int vec [], int len1){
   for (int i=0; i<len1; i++){
      cout<<vec[i]<<endl;
   }
}


void insertar(int vec[], int &len1,int valor, int pos){
   //generar el movimiento de los valores para generar el espacio de carga necesario
   for (int i=len1;i>pos;i--){
      vec[i]=vec[i-1];
   }
   //cargo el valor
   vec[pos]=valor;
   len1++;
}

void insertarOrdenado(int vec[], int &len1,int valor){
   //1 d�nde lo voy a cargar, buscar la posici�n en la que lo tengo que insertar
   int i=0;
   while(i<len1 && vec[i]<=valor){
      i++;
   }
   //2 CARGAR el valor en la posici�n que determin�
   if(i==len1){
      vec[len1]=valor;
      len1++;
   }else insertar(vec,len1,valor,i);
}

int maximoVector(int vec[], int len){
   int posmax;
   posmax=0; //que tomo la primera posici�n como el m�ximo
   for(int i=1;i<len;i++){
      if(vec[posmax]<vec[i]){
         posmax=i;
      }
   }
   return posmax;
}
int minimoVector(int vec[], int len){
   int posmin;
   posmin=0;
   for(int i=1;i<len; i++){
      if(vec[posmin]>vec[i]){
         posmin=i;
      }
   }
   return posmin;
}

