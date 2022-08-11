/*programa se utiliza para determinar el radio y la altura de un
tanque de maximo volumen con forma cilindrica

Gabriel Pacheco
Fecha 08/10/21
*/

#include <iostream> /*inpu and output de cadena de caracteres*/
#include<math.h> /*para tener potenciacion (POW)*/
using namespace std;

double volumen = 0, radio = 0, altura = 0, litros = 0, bolsa = 0;
// Variables a calcular (volumen, radio, altura y litros son del tanque)
// La variable bolsa corresponde a la cantidad de material por bolsa de pellets

double pi = 3.14159265359;

main() {
	cout << "favor ingresa la capacidad de la bolsa (mts2)= ";
	cin >> bolsa;
	
	radio=sqrt(bolsa/(6*pi));
	altura=(bolsa-18)/(6*sqrt(pi));
	volumen=pi*pow(radio,2)*altura;
	litros = volumen*1000;
	
	cout << endl << endl << "El radio para obtener el máximo volumen es: " << radio;
	cout << endl << "La altura para obtener maximo volumen es= " << altura;
	cout << endl << "El volumen del tanque es= " << volumen;
	cout << endl << "Y su capacidad es de: " << litros << " litros";
	
	cout << endl;
	system("pause");
	
	
	
	
}