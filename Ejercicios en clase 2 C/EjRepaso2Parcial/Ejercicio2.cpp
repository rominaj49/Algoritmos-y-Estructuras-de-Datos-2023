#include <iostream>
#include <stdio.h>
using namespace std;


// Ejercicio 3:
// Se tienen dos archivos de la materia prima necesaria para una cadena de comidas rápidas
// BurgerFastAgosto.dat y BurgerFastSeptiembre.dat ordenado por código de producto.
// - Código de Producto: 999999
// - Cantidad de unidades en depósito: 99999
// - Tipo de producto: ‘H’, ‘N’ ó ‘P’ (Hamburguesas, Nuggets o Pan)
// Se pide:
// a) Obtener un archivo BurgerFast.dat que consolide ambos archivos.
// b) Generar un archivo sólo para panes Pan.dat con la siguiente estructura:
// a. Código de Producto: 999999
// b. Cantidad de unidades en depósito: 99999

// Nota: Sólo puede leer 1 vez el archivo.

struct materiaPrima{
    int codProd;
    int catUnid;
    char tipoP;
};
struct materiaPan{
    int codProd;
    int cantUnid;
};

int main(){

FILE* rburguerago;
FILE* rburguersep;
FILE* rburguerall;

rburguerago=fopen("BurgerFastAgosto.dat", "rb");
rburguersep=fopen("BurgerFastSeptiembre.dat", "rb");
rburguerall=fopen("BurgerFast.dat", "wb");

materiaPrima rauxa;
materiaPrima rauxs;

fread(&rauxa,sizeof(struct materiaPrima),1,rburguerago);
fread(&rauxs,sizeof(struct materiaPrima),1,rburguersep);

//para punto b
FILE * rpan;
materiaPan rauxp;
rpan=fopen("panes.dat", "wb");


while (!feof(rburguerago) && !feof(rburguersep))
{
  if (rauxa.codProd<=rauxs.codProd) //ordeno de menor a mayor
  {
    //punto b que escribe el archivo solo con los panes ya que no puedo leer dos veces.
    if (rauxa.codProd=='P')
    {
      rauxp.codProd=rauxa.codProd;
      rauxp.cantUnid=rauxa.catUnid;
      fwrite(&rauxp,sizeof(struct materiaPan),1,rpan);
    }
    //termine punto b
    
    fwrite(&rauxa,sizeof(struct materiaPrima),1, rburguerall);
    fread(&rauxa,sizeof(struct materiaPrima),1,rburguerago);

  }
  else{
    if (rauxs.codProd=='P')
    {
      rauxp.codProd=rauxs.codProd;
      rauxp.cantUnid=rauxs.catUnid;
      fwrite(&rauxp,sizeof(struct materiaPan),1,rpan);
    }
    fwrite(&rauxs,sizeof(struct materiaPrima),1, rburguerall);
    fread(&rauxs,sizeof(struct materiaPrima),1,rburguersep);
  }
}

while (!feof(rburguerago))
{
   if (rauxa.codProd=='P')
    {
      rauxp.codProd=rauxa.codProd;
      rauxp.cantUnid=rauxa.catUnid;
      fwrite(&rauxp,sizeof(struct materiaPan),1,rpan);
    }
  fwrite(&rauxa,sizeof(struct materiaPrima),1,rburguerall);
  fread(&rauxa,sizeof(struct materiaPrima),1,rburguerago);
}

while (!feof(rburguersep))
{
    if (rauxs.codProd=='P')
    {
      rauxp.codProd=rauxs.codProd;
      rauxp.cantUnid=rauxs.catUnid;
      fwrite(&rauxp,sizeof(struct materiaPan),1,rpan);
    }
   fwrite(&rauxs,sizeof(struct materiaPrima),1, rburguerall);
   fread(&rauxs,sizeof(struct materiaPrima),1,rburguersep);
}

fclose(rpan);
fclose(rburguerago);
fclose(rburguersep);
fclose(rburguerall);

return 0;
}
