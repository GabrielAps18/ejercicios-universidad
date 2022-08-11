// Programa elaborado por Gabriel Pacheco
// Descomponer numeros primos

//Declaramos bibliotecas (No requiere punto y coma cuando declaramos libreria)


#include <iostream>
using namespace std;

int div = 2; //Divisores arrancando en número 2
int pot; // Potencia
double N; // Número a descomponer
int aux;
double aux1;

main()
{
	inicio:
	cout << "Ingresa el numero a descomponer (entero >= 2) = "	<< endl;
	cin >> N;
	
	if(N<=2)
	{
		system("cls");
		goto inicio;
	}
	aux=N;
	aux1=N;
	
	if(aux1-aux>0)
	{
		system("cls");
		goto inicio;
	}
	
	cout << endl << endl << N << " = ";
	
	// buscamos los numeros divisores	
ciclo:	
	if(N==1)
{
		goto fin;
}
	pot=0;
	
	aux=N/div;
	aux1=N/div;
	
	ciclo1:
	if(aux1-aux==0)
	{
		
	N=N/div;
	pot=pot+1;
	aux=N/div;
	aux1=N/div;
	goto ciclo1;
	
	}
	
	if (pot>1)
	{
		cout << div << "^" << pot;
	}
		if (pot==1)
	{
		cout << div;
	}
		if (N!=1 and pot>=1)
	{
		cout << " x ";
	}
	
	div= div+1;
	goto ciclo;
	
	
	
	
	
	
	
	fin:
	cout <<" "<< endl;
	system ("pause");
}
