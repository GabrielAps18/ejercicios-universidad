// Programa elaborado por Gabriel Pacheco y Miguel Acevedo
// Universidad Santa Mar�a
// Programaci�n I
// Elaborado el 28-4-2021

//Programa visualizador de a�os bisiestos

#include <iostream>
using namespace std;

//Creamos las variables a utilizar en el proyecto

double ano; //A�o a introducir
int aux;
double aux1;
//Cocientes de divisiones
int coc; 
int coc2;
int coc3;

main(){
	
//Pedimos el ingreso de un a�o
	inicio:
	cout << "Ingresa un a�o entre 1581 y 2100"	<< endl;
	cin >> ano;
	
//Comprobamos que el a�o est� entre el rango permitido
	if(ano<=1581 or ano>=2101){
		system("cls");
		goto inicio;
	}
	
//Pasamos el valor del a�o a los auxiliares para comprobar que el numero no sea decimal
	aux=ano;
	aux1=ano;
	
	if(aux1-aux>0){
		system("cls");
		goto inicio;	
	}

//Comprobamos matematicamente que el a�o ingresado sea divisible entre 4
	coc= ano/4;
	coc2=ano/100;
	coc3=ano/400;
	
// Comprobar que el a�o es normal porque es divisible entre 4, 100 y pero no entre 400
	if(ano-(4*coc)==0 and ano-(100*coc2)==0 and ano-(400*coc3)!=0){
		cout << "El a�o " << ano << " es un a�o NORMAL porque es divisible entre 4 y 100, pero no entre 400" << endl;
		goto fin;
	}
	
// Comprobar si es un a�o bisiesto divisible entre 4
	if(ano-(4*coc)==0){
		cout << "El a�o " << ano << " es un a�o bisiesto" << endl;
		goto fin;
	}
	
// Comprobar que el a�o es normal porque no es divisible entre 4
	if(ano-(4*coc)!=0){
		cout << "El a�o " << ano << " es un a�o NORMAL porque no es divisible entre 4" << endl;
	}

	fin:
	system("pause");
}
