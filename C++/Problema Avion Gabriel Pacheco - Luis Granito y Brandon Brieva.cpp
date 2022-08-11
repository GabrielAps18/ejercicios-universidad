/*
	Programa elaborado por Gabriel Pacheco, Luis Granito y Brandon Brieva
	LOTE #2 (Velocidad Aleatoria)
	Fecha: 01/12/2021
	Programa para calcular tiempo en el que se debe soltar un paquete para que llegue a su destino
*/

#include <iostream>		// Recepción de datos desde la consola y hacia ella
#include <math.h> 		// Biblioteca matemática
#include <stdlib.h>		// Crear numero random
#include <time.h> 		// Ayuda a que el numero random vaya cambiando con respecto al tiempo
#include <windows.h>	// Biblioteca para incorporar posibilidades de modificar el tiempo ejecución y manejar sonidos
#include <iomanip>		// Es usado para la precision de los decimales

using namespace std;

// Variables
double g = 9.8; // Gravedad
double h; // Altura de vuelo
double d; // Distacia horizontal entre avion y zona de descarga
double v; // Velocidad del avion
double decimal; // Decimal
double t; // Tiempo de vuelo
double a; // Alcance del paquete
double dr; // Distancia restante
double tr; // Tiempo restante de lanzamiento
int i,j,k; // Variables para contadores

// Calculamos aleatoriamente la velocidad del avion
		float velocidadRandom() {
			srand(time(NULL));
			return 100 + rand() % (400 + 1 - 100);
		}

main(){
	repite:
	// Ingresamos altura y distancia horizontal
	cout << "Ingrese la altura en (mts): "; cin >>  h;
	cout << endl << "Ingrese la distancia horizontal en (mts): "; cin >>  d;
	
	// Calcular velocidad random
		while (v < 100 or v > 400){ // Establecemos un límite
			srand(time(NULL)); 
			v=100+rand()% (301);    
			
			srand(time(NULL));
			decimal=0+rand()%(100);
			
			decimal=decimal/100;
			v=v+decimal;
		}
	
	// Calculamos tiempo de vuelo
	t = sqrt((2*h)/g);
	
	// Calculamos alcance del paquete
	a = v*t;
	
	// Calculamos distancia restante
	dr = d-a;
	
	// Calculamos el tiempo restante para soltar el paquete
	tr = (dr)/v;
	
	// En caso de que el avión ya haya pasado la zona de lanzamiento
	if (tr <= 0){
		system("cls");
		cout << endl << "	OH, NO! Se ha pasado de la zona de lanzamiento" << endl;
		cout << "	De la vuelta, e intenlo de nuevo" << endl << endl;
		cout << "	Debiste lanzar hace " << tr <<" segundos." << endl;
		cout << "	Y hace " << dr << " metros." << endl;
		cout << "	Con la velocidad " << v << " m/s" << endl;
		cout << "	Altura: " << h << " metros" << endl << endl;
		goto final;
	}
	
	// Imprimimos el tiempo
	while(tr>=0){
		cout << endl <<endl << "           Datos del lanzamiento " << endl << endl;
		cout << endl << "  Tiempo de lanzamiento: " << tr <<" segundos" ;
		cout << endl << "  Distancia restante: " << dr << " metros" ;
		cout << endl << "  Altura: " << h << " metros" ;
		cout << endl << "  Velocidad del avion: " << setprecision(5) << v << " mts/s" ;
		Sleep(1000); 	// Establece el intervalo del sonido en 1000 ms;
		system("cls");
		tr=tr-1; 		// Se resta los segundos
		dr = dr - v; 	// Restamos los metros
	// Sonido que se activará en los ultimos 2 segundos
		if (tr <= 2){
			cout << endl <<"	=== LANZA EL PAQUETE ===";
			Beep (659,304);
			system("cls");
		}
	}
	
		cout << endl << "	Lanzamiento exitoso, hemos ayudado a nuestros amigos Zulianos!!!" << endl;
		return 0;
		final:
		cout << "	Si no pudiste soltar el paquete, da la vuelta! Y vuelve a intentarlo"<<endl<<endl;	
	goto repite;
	
}