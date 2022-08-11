#include<iostream>
double auxd=0,aux,resta=0,i;
int num=0; //Valor de Entrada al programa
int auxi=0,j;
int b[7]={0,0,0,0,0,0,0}, e[7]={0,0,0,0,0,0,0}; //Vectores de Salida del programa
using namespace std;
int main()
{


cout <<"Elaborado por Wilmer Duque - Catedra Programacion - USM"<<endl;
cout <<"Semestre 2019-II"<<endl;
inicio:


while (num<2 or num>2500)
	{
	cout <<"Ingrese numero (2-2500)="<<endl;
	cin >>num;
	aux=num; 
	}


for (i=2;i<=aux;i=i+1) //Determinamos si cumple con la condición requerida
	{
 	auxi=aux/i;
 	auxd=aux/i;
 	resta= auxd -auxi;


 	if (resta== 0) // Guardamos cada elemento donde corresponde
 		{
  		for (j=1;j<9;j=j+1)
  			{
      		if (b[j]==i) 
   				{
       			e[j]=e[j]+1;
       			auxi=0;
       			auxd=0;
   				}
   			if (b[j]==0) 
   				{
    			b[j]=i;
    			e[j]=1;
    			auxi=0;
    			auxd=0;
   				}
   			if (auxi==0)
   				{
   				j=100; 
   				}
  			}
  		aux=aux/i; 
 		i=1;        
  
 		}
 
	}

system("cls");

auxd=0;
while (auxd!=1 and auxd!=2)
	{
	cout <<"Ingrese (1) para terminar o (2) para ingresar otro numero "<<endl;
	cin >>auxd;
	}

if (auxd==2)
	{
 	num=0;
 	for (j=1;j<=6;j=j+1) 
    	{
		b[j]=0;
    	e[j]=0;
    	}
	}
 system("cls");
 goto inicio;
}