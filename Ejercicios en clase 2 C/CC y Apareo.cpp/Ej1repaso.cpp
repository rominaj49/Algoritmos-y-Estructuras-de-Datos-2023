#include <iostream>
#include <stdio.h>
using namespace std;

// Ejercicio 1:
// Se tiene un archivo de las notas de los alumnos de primer año de todos los finales rendidos, Primer.dat
// ordenado por número de legajo.
// - Legajo: 999999
// - Materia
// - Nota: 1..10
// Se pide:
// a) Obtener el promedio de cada alumno según los finales rendidos

// como esta ordenado x numero de legajo podemos usar el corte de control (es siempre que este ordenado)
struct Alum{
int legajo;
int materia;
double nota;
};

int main(){

int sum;
int ant;
int i;
FILE * regPrimer;
regPrimer=fopen("Primer.dat", "rb");
Alum raux;
fread(&raux,sizeof(struct Alum),1,regPrimer);

while (!feof(regPrimer))
{
    i=0;
    sum=0;
    ant=raux.legajo;

    while(!feof(regPrimer) && ant==raux.legajo){
        sum+=raux.nota;
        i++;
        fread(&raux,sizeof(struct Alum),1,regPrimer);
    }
    cout<<"El promedio del legajo: "<<raux.legajo<<", es del: "<<sum/i<<"%"<<endl;
}


    return 0;
}