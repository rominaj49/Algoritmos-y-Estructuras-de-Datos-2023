// Ejercicio 4:
// Se tiene un archivo de las ventas realizadas por un local de comidas rápidas en todo el año pasado.
// BurgerFast.dat (ordenado por código de combo).
// - Código de combo: 999999
// - Mes de venta
// - Cantidad de unidades vendidas para ese mes: 99999
// Se pide:
// a) Obtener el total de unidades vendidas de cada combo para cada año.
#include <iostream>
#include <stdio.h>
using namespace std;

struct Ventas{
int codigo;
int mes;
int unidades;
};


int main(){

FILE* regBurger;
regBurger=fopen("BurgerFast.dat", "rb");

Ventas raux;
fread(&raux, sizeof(struct Ventas),1, regBurger);

while (!feof(regBurger))
{

 int sumCombo=0;
 int comboAct=raux.codigo;

  while(!feof(regBurger) && comboAct==raux.codigo){
    sumCombo+=raux.unidades;
    fread(&raux, sizeof(struct Ventas),1,regBurger);
  }
  cout<<"El total de unidades vendidas en el año fue de: "<<sumCombo<<endl;


}


    return 0;
}