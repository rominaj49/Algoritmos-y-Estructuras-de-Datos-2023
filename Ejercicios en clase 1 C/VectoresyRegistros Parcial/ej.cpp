#include <iostream>
using namespace std;


void MostrarFecha(int fecha){
int anio;
anio= (fecha%10000);
cout<<"El anio es: "<<anio<<endl;
}

// bool Validar(int num){
//     bool ret=true;

//     if (num%2==0)
//     {
//               cout<<"es par"<<endl;

//       return ret;
//     }
    
//     else{
//         ret=false;
//               cout<<"es impar"<<endl;

//         return ret;
//     }
// }

// int velocidadMxima(int vec[], int len){
// int max=0;

// for (int i = 1; i <=len; i++)
// {
//    if (vec[i]>vec[max])
//    {
//     max=i;
//    }
   
// }
// return max;
// }
// int velocidadMxima(int vec[], int len){
// int min=0;

// for (int i = 1; i <=len; i++)
// {
//    if (vec[i]<vec[min])
//    {
//     min=i;
//    }
   
// }
// return min;
// }

// double promedioVeloc(int vec[], int len){
//     int sum=0;
//     for (int i = 0; i < len; i++)
//     {
//         sum+= vec[i];
//     }
//     return sum/len;
    
// }
int main() {
    
//    int vEnteros[200]; // viene cargado, solo lo defino
//    int len;
//   int iMax= velocidadMaxima(vEnteros, len);
//   int iMin= velocidadMinima(vEnteros,len);
//   double prom= promedioVeloc(vEnteros,len);

//   cout<<"La velodidad maxima fue de: "<<vEnteros[iMax]<<endl;
//   cout<<"La velodidad minima fue de: "<<vEnteros[iMax]<<endl;
//   cout<<"La promedio fue de: "<<prom<<"%"<<endl;
  
  MostrarFecha(12122023);

    return 0;
}