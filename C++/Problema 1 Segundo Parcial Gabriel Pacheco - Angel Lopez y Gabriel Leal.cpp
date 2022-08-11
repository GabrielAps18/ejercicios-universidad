// Programa elaborado por Gabriel Pacheco - Angel Lopez - Gabriel Leal
// Universidad Santa María
// Programación I
// Elaborado el 26-05-2021

//Programa para multiplicar matrices 4x4

#include <iostream>
using namespace std;

//Creamos los arrays a utilizar:

//Matriz A (Se organiza por filas)
int fila[17] = {0};

//Matriz B (Se organiza por columnas)
int colum[17] = {0};

//Matriz Resultado
int resultado[17];

//Variables de apoyo
int i=1;
int j=1;
int k=1;
int aux;
int aux2;
int valor;

main(){
	//Ciclos para introducir los datos de las matrices:
	
	//Matriz A (Organizada por filas)
	//El ciclo "for" sirve para pedir los datos de una fila por columna, mientras el while ayuda a cambiar de fila
	cout <<  "Matriz A:" << endl;
	while(k<=4){
		for(i=1; i<=4; i=i+1){
			cout << "Ingrese el numero de la fila [" << k << "] columna [" << i << "] " << endl;
			cin >> fila[j]; 
			j=j+1;
		};
		k=k+1;
	};
	i=1;
	j=1;
	k=1;
	system("cls");
	
	//Matriz B (Organizada por columnas)
	//El ciclo "for" sirve para pedir los datos de una columna por fila, mientras el while ayuda a cambiar de columna
	cout <<  "Matriz B:" << endl;
	while(k<=4){
		for(i=1; i<=4; i=i+1){
			cout << "Ingrese el numero de la columna [" << k << "] fila [" << i << "] " << endl;
			cin >> colum[j]; 
			j=j+1;
		};
		k=k+1;
	};
	i=1;
	j=1;
	k=1;
	system("cls");
	
	//Primer "do while" multiplica la fila 1 de la matriz A por las 4 columnas de la matriz B
	do{
		for (i=1; i<=4; i=i+1){
			aux = fila[i]*colum[j];
			aux2 = aux2 + aux;
			j=j+1;
		}
		// Almacena la suma de las multiplicaciones (aux2) en la "Matriz Resultado"
		resultado[k] = aux2;
		k=k+1;
		aux2 = 0;
	}while(j<=16);
	j=1;
	
	//Segundo "do while" multiplica la fila 2 de la matriz A por las 4 columnas de la matriz B
	
	do{
		for (i=5; i<=8; i=i+1){
			aux = fila[i]*colum[j];
			aux2 = aux2 + aux;
			j=j+1;
		}
		resultado[k] = aux2;
		k=k+1;
		aux2 = 0;
	}while(j<=16);	
	j=1;
	
	//Tercer "do while" multiplica la fila 3 de la matriz A por las 4 columnas de la matriz B
	
	do{
		for (i=9; i<=12; i=i+1){
			aux = fila[i]*colum[j];
			aux2 = aux2 + aux;
			j=j+1;
		}
		resultado[k] = aux2;
		k=k+1;
		aux2 = 0;
	}while(j<=16);	
	j=1;
	
	//Cuarto "do while" multiplica la fila 4 de la matriz A por las 4 columnas de la matriz B
	
	do{
		for (i=13; i<=16; i=i+1){
			aux = fila[i]*colum[j];
			aux2 = aux2 + aux;
			j=j+1;
		}
		resultado[k] = aux2;
		k=k+1;
		aux2 = 0;
	}while(j<=16);	
	j=1;
	
	// Ciclo "for" para mostrar la Matriz Resultado en consola
	cout << "La Matriz Resultado de la multiplicación A x B es:" << endl << endl;
	for (i=1; i<=16; i=i+1){
		cout << "   " <<resultado[i] << "   |";
		// Este if sirve para cada vez que termine de mostrar una fila de la matriz da un salto de linea
		if(i==4 or i==8 or i==12 or i==16){ 
			cout << endl;
		}
	}

}
