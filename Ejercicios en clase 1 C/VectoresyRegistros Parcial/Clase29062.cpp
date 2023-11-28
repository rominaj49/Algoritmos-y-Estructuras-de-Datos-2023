#include <iostream>
using namespace std;
// EJERCICIO DE VECTORES
// Dado un vector de productos que contiene el código del producto, fecha de vencimiento del lote
// y la cantidad de unidades disponibles en depósito(Se sabe que máximo hay 200 productos en la empresa),
// determinar:
// a-¿Cuál es el producto que más unidades tiene en depósito?
// b-¿Cuáles son los productos que se vencen posterior al 01112022? (Mostrarlos por pantalla)
// c-Calcular el promedio de unidades en el depósito por producto.

struct vectorProd
{
   int codProd;
   int fechaVec;
   int cantDisp;
};

void inicializar(vectorProd vec[], int cantP, vectorProd ValorIni);
void insertar(vectorProd vec[], int &len1, vectorProd valor, int pos);
void insertarOrdenado(vectorProd vec[], int &len1, vectorProd valor);
int maximoVec(vectorProd vec[], int len);
double promUnidades(vectorProd vec[], int len);
void posProdVenc(vectorProd vec[], int len);

int main()
{
   vectorProd vec[200];
   int len; // lo dejo ya definido aunque sabemos que es 200
   // 1
   int posMax = maximoVec(vec, len);
   cout << "El mayor con productos disponibles es el codigo: #" << vec[posMax].codProd;
   // 2
   posProdVenc(vec, len); // muestra los productor vencidos.
   // 3
   cout << "El promedio de unidades por cada producto es del: %" << promUnidades(vec, len) << endl;
   return 0;
}

void inicializar(vectorProd vec[], int cantP, vectorProd ValorIni)
{
   for (int i = 0; i < cantP; i++)
   {
      vec[i].codProd = ValorIni.codProd;
      vec[i].fechaVec = ValorIni.fechaVec;
      vec[i].cantDisp = ValorIni.cantDisp;
   }
}

void insertar(vectorProd vec[], int &len1, vectorProd valor, int pos)
{
   // generar el movimiento de los valores para generar el espacio de carga necesario
   for (int i = len1; i > pos; i--)
   {
      vec[i].codProd = vec[i - 1].codProd;
      vec[i].fechaVec = vec[i - 1].fechaVec;
      vec[i].cantDisp = vec[i - 1].cantDisp;
   }
   // cargo el valor
   vec[pos].codProd = valor.codProd;
   vec[pos].fechaVec = valor.fechaVec;
   vec[pos].cantDisp = valor.cantDisp;
   len1++;
}

void insertarOrdenado(vectorProd vec[], int &len1, vectorProd valor)
{
   // 1 d�nde lo voy a cargar, buscar la posici�n en la que lo tengo que insertar
   int i = 0;
   while (i < len1 && vec[i].cantDisp <= valor.cantDisp)
   {
      i++;
   }
   // 2 CARGAR el valor en la posici�n que determin�
   if (i == len1)
   {
      vec[len1].codProd = valor.codProd;
      vec[len1].fechaVec = valor.fechaVec;
      vec[len1].cantDisp = valor.cantDisp;
      len1++;
   }
   else
      insertar(vec, len1, valor, i);
}

int maximoVec(vectorProd vec[], int len)
{
   int posMax = 0;
   for (int i = 1; i < len; i++)
   {
      if (vec[i].cantDisp > vec[posMax].cantDisp)
      {
         posMax = i;
      }
   }
   return posMax;
}

double promUnidades(vectorProd vec[], int len)
{
   int suma = 0;
   for (int i = 0; i < len; i++)
   {
      suma += vec[i].cantDisp;
   }
   return (double)suma / len;
}

void posProdVenc(vectorProd vec[], int len)
{
   for (int i = 0; i < len; i++)
   {
      if (vec[i].fechaVec < 01112022)
      {
         cout << "El producto" << vec[i].codProd << "ya venció" << endl;
      }
   }
}