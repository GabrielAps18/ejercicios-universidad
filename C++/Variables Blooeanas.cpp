// Programa para buscar un numero aleatorio usarndo variables booleanas

#include <iostream> // Recepción de datos desde la consola y hacia ella
#include <time.h> // Libreria del tiempo, permite capturar el ciclo de procesamiento de la PC
#include <stdlib.h> // Convierte los ciclos de procesamiento en valores numericos

using namespace std;

main(){
	bool status;
	int random = 0; // nro aleatorio
	
	int numero, primer_digito, segundo_digito, tercer_digito, cuarto_digito;
	
	srand(time(NULL)); // Establece quien le da el pulso para cambiar en este caso el tiempo de procesamiento del programa
	
	random = 0;
	
	while(random < 10 || random > 30){
	
	random = 0+rand()%(9999); // Guarda en la variable random el tiempo de procesamiento en la escala de 0 a 9999

	primer_digito = random / 1000;
	
	segundo_digito = random / 100 - primer_digito*10;
	
	tercer_digito = random / 10 - primer_digito*100-segundo_digito*10;
	
	cuarto_digito = random - primer_digito*1000-segundo_digito*100-tercer_digito*10;
	
	random = cuarto_digito*10+tercer_digito;
}
	repite:
	cout <<"ingrese un numero entre (10-30) = ";
	cin >> numero;
	
	if (numero == random){
		status = true;
	}else{
		status = false;
	}
	
	if (status == true){
		system("cls");
		cout << "Usted ha ganado! el numero es = " << random;
		system ("pause");
	}else{
		goto repite;
	}
	
	system("pause");
}
