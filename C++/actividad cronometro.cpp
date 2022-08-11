/* Programa elaborado por Gabriel Pacheco

Programa para elaborar un cronometro con sonido

Fecha 11 de junio de 2021*/

#include <iostream> // recepción de datos desde la consola y hacia ella

#include <time.h> 

#include <stdlib.h> // convierte los ciclos de procesamiento en valores numéricos

#include <windows.h> // incorporar posibilidades de modificar el tiempo ejecución y manejar sonidos

using namespace std;

// Variables
int minu; // Variable de minuto
int sec; // Variable de segundos
int x = 1000; // Intervalo de segundos
bool respuesta;
char punto = 4;

main(){
	inicio:
	cout << "Ingrese los minutos que desea que dure el cronometro de (1 a 5) minutos = ";
	cin >> minu;
	if (minu <1 or minu >5){ // Solicitamos el numero de 1 a 5
		system("cls"); 
		goto inicio;
	}

	srand(time(NULL)); // Establece quien le da el pulso para cambiar
	
	while(sec<1 or sec>59){ // Calculamos el numero aleatorio
		sec=0+rand()%(99); 
	}
	system("cls");
	cout << "El tiempo del cronometro sera de: ";
	cout << minu << "m:" << sec<< "s"<< endl; 
	system("pause");
	
	//Ciclo del cronometro
	repite:
	while(sec>=0){
		if(sec < 10){
			cout << minu << "m:0" << sec<< "s"; 
		}else{
			cout << minu << "m:" << sec<< "s"; 
		}
		if (!respuesta){ // Cada dos segundos se mostrará un pequeño punto
			respuesta = 1;
		}else{
			respuesta = 0;
			cout << punto;
		}
		Sleep(x); // Establece el intervalo del sonido en 1000 ms;
		Beep (659,304); // Sonido que se activará cada segundo
		system("cls");
		sec=sec-1; // Se resta los segundos
	}
	if(minu != 0 and sec !=0){
		sec = 59;
		minu = minu-1;
		goto repite;
	}
	// Alarma
	cout <<"SE HA ACABADO EL TIEMPO!!"<<endl<<endl;
	Beep (523,382);Beep (587,340);Beep (659,304);Beep (698,286);
	Beep (740,270);Beep (880,228);Beep (998,220); Beep (523,382);
	
	// Validacion para volver a iniciar el cronometro
	cout << "Desea volver a iniciar otro conteo? Si su respuesta es 'si' escriba '1', si es 'no' escriba '0' " << endl;
	cin >> respuesta;
	if (respuesta){
		system("cls");
		goto inicio;
	}
}
