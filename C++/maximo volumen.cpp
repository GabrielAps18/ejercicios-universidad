#include <iostream>
#include <math.h> 
//Programa para calcular el máximo volumen con cortes de madera que suman un area

double area, x, y, v;
main() {
	do{
		std::cout << "Ingrese el area (20 a 30 mts^2): "; std::cin >> area;
	} while (area < 20 || area > 30 );
	y = sqrt(area/6);
	x = (area - 2*pow(y,2)) / 4*y;
	v = x*pow(y,2);
	std::cout << std::endl << "El valor de Y seria:" <<y;
	std::cout << std::endl << "El valor de X seria:" <<x;
	std::cout << std::endl << "El volumen maximo seria:" <<v;
}