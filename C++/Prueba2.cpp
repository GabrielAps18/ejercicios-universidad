//incluimos la biblioteca de instrucciones Input and Output Stream

#include <iostream> 

using namespace std;

int numero[7]={0,34,17,-4,50,0,-20};

int i,j,aux;

main()

{

	for (j=1;j<=5;j=j+1)  // ciclo de iteraciones

{

	for (i=1;i<=5;i=i+1) // Ciclo de comparaciones dentro de la iteración

	{

	if(numero[i]>numero[i+1])	

	{

		// Rutina de intercambio de números

		aux=numero[i];

		numero[i]=numero[i+1];

		numero[i+1]=aux;

	}

	}

}

	

// IMPRESIÓN DE VALORES EN PANTALLA



cout <<"Los numeros a ordenar dentro del arreglo son: 34, 17, -4, 50, 0, 20"<<endl<<endl;

cout <<"Los numeros a ordenados de mayor a menor son: "<<numero[1]<<" < "<<numero[2];

cout <<" < "<<numero[3]<<" < "<<numero[4]<<" < "<<numero[5]<<" < "<<numero[6]<<endl<<endl;

system("pause");

}
