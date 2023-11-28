#include <iostream>
using namespace std;

// Se tiene un archivo de la materia prima necesaria para una cadena de comidas rápidas BurgerFast.dat. (sin orden)
// -          Código de Producto: 999999
// -          Cantidad de unidades en depósito: 99999
// -          Tipo de producto: ‘H’, ‘N’ ó ‘P’ (Hamburguesas, Nuggets o Pan)
// -          Vencimiento: MMAAAA
// Se pide:
// a)       Generar un archivo sólo para panes Pan.dat con la siguiente estructura:
// - Código de Producto: 999999
// - Cantidad de unidades en depósito: 99999
// - Vencimiento: MMAAAA
// b)      Generar un archivo UsarAntes.dat con los productos que tengan más de 1000 unidades en stock ó se venzan el 122023 o antes,
//  con la estructura original
// Nota: Sólo puede leer 1 vez el archivo. ej similar al 4-


struct ComidaRapida{
int codProd;
int cantUni;
char tipoProd;
int venc;
};
struct Panes{
    int codProd;
    int cantUni;
    int venc;
};

int main(){
  
  FILE* regComid;
  regComid=fopen("BurgerFast.dat", "rb");
  ComidaRapida aux;
  fread(&aux, sizeof(struct ComidaRapida),1,regComid);

  FILE* regPanes;
  regPanes=fopen("Pan.dat","wb");
  Panes rcarga;

  FILE* regVenc;
  regVenc=fopen("UsarAntes.dat", "wb");
  ComidaRapida rcarga2;

  while (!feof(regComid))
  {
    if (aux.tipoProd=='P')
    {
    rcarga.codProd=aux.codProd;
    rcarga.cantUni=aux.cantUni;
    rcarga.venc=aux.venc;
        fwrite(&rcarga,sizeof(struct Panes),1,regPanes);// solo escribo sin vec porq no tienen orden
    }
    else if(aux.cantUni>100 or aux.venc<=122023){
        rcarga2.codProd=aux.codProd;
        rcarga2.cantUni=aux.cantUni;
        rcarga2.tipoProd=aux.tipoProd;
        rcarga2.venc=aux.venc;
        fwrite(&rcarga2,sizeof(struct ComidaRapida),1,regVenc);
    }
  fread(&aux, sizeof(struct ComidaRapida),1,regComid);
  }
  fclose(regComid);
  fclose(regPanes);
  fclose(regVenc);
  

    return 0;
}

