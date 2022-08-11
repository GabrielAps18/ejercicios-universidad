#include <iostream>
using namespace std;

int div = 1; //Divisores arrancando en número 1
double N; // Número inicial
double N1; // Número disminuidor
int aux;
double aux1;
int primo; // Contador de operaciones (Para probar que son primos)
int noPrimo = 0; // Contador de operaciones (Para probar que NO son primos)

main(){
	
	inicio:
	cout << "Ingresa un numero"	<< endl;
	cin >> N;
	N1 = N;
	
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
	
	cout << endl << endl << "Los numeros primos que se encuentran por debajo del " << N << " son: \n";
	
	// buscamos los numeros divisores	
ciclo:	
	if(N==1)
{
		goto fin;
}	
	aux=N/div;
	aux1=N/div;
	
	ciclo1:
	if(aux1-aux==0)
	{
		N=N/div;
		aux=N/div;
		aux1=N/div;
		div= div+1;
		noPrimo = noPrimo + 1;
		if(N == N1 or N==1)
		{
			primo++;
		}
		if(primo == 2)
		{
			cout << N1 << ", ";
			goto siguiente;
		}
		if (noPrimo >=2){
			goto siguiente;
		}  
		goto ciclo;
	}
	
	div= div+1;
	goto ciclo;
	
// Pasa a operar con otro número			
	siguiente:
	N = N1-1;
	N1 = N;
	primo = 0;
	div = 1;
	noPrimo = 0;
	goto ciclo;
	
// Fin de la operación
	fin:
	cout <<" "<< endl;
	system ("pause");
}
