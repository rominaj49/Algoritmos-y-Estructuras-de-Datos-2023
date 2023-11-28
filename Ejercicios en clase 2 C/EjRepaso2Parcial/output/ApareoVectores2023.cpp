//============================================================================
// Name        : ApareoVectores2023.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void insertar(int vec[], int &len1,int valor, int pos);
void insertarOrdenado(int vec[], int &len1,int valor);

int main() {
	int vecA[3];
	int lenA=0;
	int vecB[3];
   int lenB=0;
	int vecC[6];
	int lenC=0;
	//Agregado para poder probar el ejercicio.
	vecA[0]=1;
	lenA++;
	vecA[1]=2;
	lenA++;
	vecA[2]=4;
	lenA++;
	vecB[0]=3;
	lenB++;
	vecB[1]=5;
	lenB++;
	vecB[2]=7;
	lenB++;

   for (int i=0; i<lenA; i++){
      insertarOrdenado(vecC,lenC,vecA[i]);
   }

   for (int i=0; i<lenB; i++){
      insertarOrdenado(vecC,lenC,vecB[i]);
   }
   //solo lo agrego para mostrar como quedó el vector ressultante
   for(int i=0; i<lenC; i++){
      cout<<vecC[i]<<endl;
   }

	return 0;
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
   //1 d nde lo voy a cargar, buscar la posici n en la que lo tengo que insertar
   int i=0;
   while(i<len1 && vec[i]<=valor){
      i++;
   }
   //2 CARGAR el valor en la posici n que determin
   if(i==len1){
      vec[len1]=valor;
      len1++;
   }else insertar(vec,len1,valor,i);
}
