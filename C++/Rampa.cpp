/* 
	Programa para calcular la longitud minima de una rampa de manejos de desechos
	Programa diseñado por Alejandro Rodríguez 28.052.651 y Gabriel Pacheco 28.426.233
	El 20/10/2021

*/

#include <math.h>
#include <iostream>
using namespace std;

// Variables
double v; // Base de apoyo
double y; // Valor de base incognita
double x; // Altura de la construccion
double z; // Longitud de rampa
double a; // Angulo
double r; // Distancia de construccion a punto de apoyo de la rampa en el piso
double pi=3.14159265359;



main(){
	inicio:
	cout << "Ingrese el valor de la Base de apoyo de 1.5 a 2 (mts)" << endl;
	cin >> v;
	if(v<(1.5) or v>2){
		system("cls");
		goto inicio;
	}
	system("cls");
	// Según nuestros calculos Y nuestra base restante es igual a "2v"
	y=2*v;
	
	// Procedemos a obtener el valor de x que sería la altura de la pared donde se apoya la rampa
	x=(y*v)/(y-1);
	
	// Teniendo X y Y sacamos Z (longitud de la rampa)
	z = sqrt(pow(x,2) + pow(y,2));
	
	// Para encontrar el angulo "a" procedemos a sacar el arcoseno de x/y
	a = (asin(x/z)*180)/pi;
	
	// Sacamos la distancia de la rampa con respecto a la construccion donde se apoya en el suelo es
	r= 1+y;
	
	
	// Procedemos a imprimir las respuestas
	cout << "a) Longitud minima de la rampa (mts): " << z << endl << endl;
	cout << "b) Altura de la pared donde se apoya la rampa (mts): " << x << endl << endl;
	cout << "c) Distancia de la rampa con respecto a la construccion donde se apoya en el suelo (mts): " << r << endl << endl;
	cout << "d) Valor del angulo theta (grados): " << a << endl << endl;
	
	
}
