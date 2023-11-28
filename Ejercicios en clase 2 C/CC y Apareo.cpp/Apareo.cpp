
#include <iostream>
#include <stdio.h>
using namespace std;

struct Alum{
    int legajo;
    int dni;
    int Nota1;
    int Nota2;
};

int main(){

 FILE *A;
 FILE *B;
 FILE *C;

 A=fopen("ArchA.dat", "rb");
 B=fopen("ArchB.dat", "rb");
 C=fopen("ArchC.dat", "wb");

 Alum rauxA;
 Alum rauxB;

 fread(&rauxA, sizeof(struct Alum),1,A);
 fread(&rauxB,sizeof(struct Alum),1,B);

 while (!feof(A) && !feof(B)) //mientras los 2 tengan contenido, comparar.
{
  if(rauxA.legajo<rauxB.legajo){
   fwrite(&rauxA, sizeof(struct Alum),1,C);
   fread(&rauxA,sizeof(struct Alum),1,B);
  }
  else{
   fwrite(&rauxB,sizeof(struct Alum),1,C);
   fread(&rauxB,sizeof(struct Alum),1,B);
  }

 }//si sale alguno de aca es que se acabo.

fclose(A);
fclose(B);
fclose(C);

    return 0;
}