/* Programa para calcular el resultado de multiplicar dos matrices de 4 x 4

elaborado por el profesor Carlos Ferrer como parte del 2do parcial de Prog 1

USM Fecha= 27 de mayo de 2021*/

#include<iostream>

#include<locale.h>

using namespace std;

// Matriz A (un arreglo por fila)

int MAF1[5]={0,1,0,3,2};

int MAF2[5]={0,-1,1,4,0};

int MAF3[5]={0,2,3,1,4};

int MAF4[5]={0,1,-2,4,-1};

// Matriz B (un arreglo por fila)

int MBF1[5]={0,2,1,-2,1};

int MBF2[5]={0,-1,1,1,4};

int MBF3[5]={0,1,0,1,5};

int MBF4[5]={0,0,-2,0,-1};

// Matriz AxB (un arreglo por fila)

int MAXBF1[5]={0};

int MAXBF2[5]={0};

int MAXBF3[5]={0};

int MAXBF4[5]={0};

int i,j; // Índices

main()

{

//Ingresamos los datos de la matriz A

cout <<"Ingrese datos de la matriz A"<<endl<<endl;

for (i=1;i<=4;i=i+1)

    {

    cout <<"fila[1] Columna["<<i<<"]= ";

    cin >>MAF1[i];

    cout <<"fila[2] Columna["<<i<<"]= ";

    cin >>MAF2[i];

    cout <<"fila[3] Columna["<<i<<"]= ";

    cin >>MAF3[i];

    cout <<"fila[4] Columna["<<i<<"]= ";

    cin >>MAF4[i];

    }

//Ingresamos los datos de la matriz B

cout <<endl<<endl<<"Ingrese datos de la matriz B"<<endl<<endl;

for (i=1;i<=4;i=i+1)

    {

    cout <<"fila[1] Columna["<<i<<"]= ";

    cin >>MBF1[i];

    cout <<"fila[2] Columna["<<i<<"]= ";

    cin >>MBF2[i];

    cout <<"fila[3] Columna["<<i<<"]= ";

    cin >>MBF3[i];

    cout <<"fila[4] Columna["<<i<<"]= ";

    cin >>MBF4[i];

    }



// Calculamos AxB



for(i=1;i<=4;i=i+1)

    {

    MAXBF1[i]=MAF1[1]*MBF1[i]+MAF1[2]*MBF2[i]+MAF1[3]*MBF3[i]+MAF1[4]*MBF4[i];

    MAXBF2[i]=MAF2[1]*MBF1[i]+MAF2[2]*MBF2[i]+MAF2[3]*MBF3[i]+MAF2[4]*MBF4[i];

    MAXBF3[i]=MAF3[1]*MBF1[i]+MAF3[2]*MBF2[i]+MAF3[3]*MBF3[i]+MAF3[4]*MBF4[i];

    MAXBF4[i]=MAF4[1]*MBF1[i]+MAF4[2]*MBF2[i]+MAF4[3]*MBF3[i]+MAF4[4]*MBF4[i];

    }



// Presentamos la respuesta 



system("cls");



cout <<"  A= | "<<MAF1[1]<<"  "<<MAF1[2]<<"  "<<MAF1[3]<<"  "<<MAF1[4]<<" | "<<endl;

cout <<"     | "<<MAF2[1]<<"  "<<MAF2[2]<<"  "<<MAF2[3]<<"  "<<MAF2[4]<<" | "<<endl;

cout <<"     | "<<MAF3[1]<<"  "<<MAF3[2]<<"  "<<MAF3[3]<<"  "<<MAF3[4]<<" | "<<endl;

cout <<"     | "<<MAF4[1]<<"  "<<MAF4[2]<<"  "<<MAF4[3]<<"  "<<MAF4[4]<<" | "<<endl<<endl<<endl;



cout <<"  B= | "<<MBF1[1]<<"  "<<MBF1[2]<<"  "<<MBF1[3]<<"  "<<MBF1[4]<<" | "<<endl;

cout <<"     | "<<MBF2[1]<<"  "<<MBF2[2]<<"  "<<MBF2[3]<<"  "<<MBF2[4]<<" | "<<endl;

cout <<"     | "<<MBF3[1]<<"  "<<MBF3[2]<<"  "<<MBF3[3]<<"  "<<MBF3[4]<<" | "<<endl;

cout <<"     | "<<MBF4[1]<<"  "<<MBF4[2]<<"  "<<MBF4[3]<<"  "<<MBF4[4]<<" | "<<endl<<endl<<endl;



cout <<"AxB= | "<<MAXBF1[1]<<"  "<<MAXBF1[2]<<"  "<<MAXBF1[3]<<"  "<<MAXBF1[4]<<" | "<<endl;

cout <<"     | "<<MAXBF2[1]<<"  "<<MAXBF2[2]<<"  "<<MAXBF2[3]<<"  "<<MAXBF2[4]<<" | "<<endl;

cout <<"     | "<<MAXBF3[1]<<"  "<<MAXBF3[2]<<"  "<<MAXBF3[3]<<"  "<<MAXBF3[4]<<" | "<<endl;

cout <<"     | "<<MAXBF4[1]<<"  "<<MAXBF4[2]<<"  "<<MAXBF4[3]<<"  "<<MAXBF4[4]<<" | "<<endl<<endl;

system("pause");

}
