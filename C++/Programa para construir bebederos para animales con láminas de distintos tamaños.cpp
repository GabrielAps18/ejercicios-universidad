/*Programa elaborado por Alan Ruz, María Garcés y Gabriel Pacheco
Fecha: 27/10/2021
Programación 2
Programa para construir bebederos para animales con láminas de distintos tamaños
y con una área máxima

*/
#include <math.h>
#include <iostream>
using namespace std;

//Variables
double anch; // Anchura de la lámina
int larg = 3; // Largo de la lámina
double pi = 3.14159265359; // Valor de pi
double a_tope; // Area del tope de madera
double v_beb; // Volumen del bebedero
double litros; // Litros del bebedero

main() {
	inicio:
	cout << "Ingrese el ancho de la lamina" << endl;
	cin >> anch;
	if(anch<(1.5) or anch>2.5){
		system("cls");
		goto inicio;
	}
	// Dividimos el ancho entre 5
	anch = anch/5;
	system("cls");

	// Calculamos el area total del tope de madera
	a_tope = (pow(anch, 2)*sin(60*pi/180)) + (pow(anch,2)*sin(60*pi/180)*cos(60*pi/180)) + pow(anch, 2) + (2*pow(anch, 2)*cos(60*pi/180));
	
	// Calculamos el volumen máximo del bebedero
	v_beb = (a_tope) * 3;
	
	// Calculamos la capacidad del bebedero en litros 
	litros = v_beb*1000;
	
	// Imprimimos resultados:
	cout << endl << "El area total del tope de madera es = " <<  a_tope << " mts^2" << endl << endl;
	cout << "El volumen maximo del bebedero es = " <<  v_beb << " mts^3" << endl << endl;
	cout << "La capacidad máxima en litros del bebedero es = " << litros << " lts" << endl << endl;
}