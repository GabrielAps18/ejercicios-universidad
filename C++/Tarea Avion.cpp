/*
	Programa elaborado por Alan Ruz, María Garcés, Gabriel Pacheco y Alejandro Rodríguez
	Fecha: 12/11/2021
	Programa para calcular el tiempo al que debe ubicarse un avión para soltar una bomba y dar en el blanco según los datos ingresados
*/
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

double va; // Velocidad del avion
double vb; // Velocidad del barco
double d; // Distancia del avion al barco
double h; // Altura
double t; // Tiempo de caida de bomba
double dt; // Distancia tiro
double tf; // Tiempo faltante


main() {
	// Pedimos los datos al usuario
	cout << "Ingrese la velocidad del avion (km/h)" << endl; cin >> va;
	cout << endl<< "Ingrese la velocidad del barco (km/h)" << endl; cin >> vb;
	cout << endl<< "Ingrese la distancia del avion al barco (km)" << endl; cin >> d;
	cout << endl<< "Ingrese la altura a la que vuela el avion (m)" << endl; cin >> h;
	
	// Hacemos las conversiones de km/h a m/s y km a m
		va = va/3.6;
		vb = vb/3.6;
		d = d*1000;
		
	// Calculamos el tiempo de caida de la bomba
		t=sqrt(h/4.9);
	
	// Calculamos la distancia a la que debe disparar el avión
		dt=va*((d-(va-vb)*t)/(va-vb));
		
	// Calculamos el tiempo que le falta al avión para posicionarse en la ditancia para disparar
		tf = dt / va;
	
	cout << endl << "El tiempo faltante para disparar es:";
	cout << fixed << setprecision(3) << tf << endl;
}
