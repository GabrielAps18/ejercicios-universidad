#include <iostream> // recepción de datos desde la consola y hacia ella

#include <time.h> //Biblioteca del tiempo permite capturar el ciclo de procesamiento de la PC

#include <stdlib.h> // convierte los ciclos de procesamiento en valores numéricos

#include <windows.h> // incorpora posibilidades de modificar el tiempo ejecucion y manejar sonidos





using namespace std;

            

main()

{

	bool status; //variable tipo booleana que indica que el jugador gano

	int random = 0; //nro aleatorio

	char s1, s2, s3, s4;

	int numero, primer_digito,segundo_digito,tercer_digito,cuarto_digito;

	int i;

	srand(time(NULL)); // establece quien le da el pulso para cambiar en este caso el 

	                //tiempo de procesamiento del programa

	

	

	int tiempo = 200;
while(tiempo>0){
	random=0+rand()%(9); //Guarda en la variable ramdom el tiempo de procesamiento en la escala de 0 a 9999


	                       // el % hace el enlace entre el pulso y el rango

	                       

	

	/*Para lograr un numero aleatorio dificil de predecir vamos a descomponer el numero previo

	  en 4 dígitos (unidad de mil, centena, decena y unidad) 

	  el numero a construir tendrá como decena la unidad previa multiplicada por 10 y como 

	  unidad el digito de la centena determinado anteriormente*/
/*
	for (i=3; i<7; i=i+1){
		borrar = i;
		cout << borrar;
	}*/

	primer_digito=random;

	

	segundo_digito=random+2;
	if( segundo_digito >= 10){
		segundo_digito = segundo_digito-10;
	}

	                       

	 tercer_digito=random+5;                      
	if( tercer_digito >= 10){
		tercer_digito = tercer_digito-10;
	}
	                       

	 cuarto_digito=random+7;
	if( cuarto_digito >= 10){
		cuarto_digito = cuarto_digito-10;
	}
          

	if (primer_digito >= 0 and primer_digito <2){primer_digito = 3;}
	if (primer_digito >= 3 and primer_digito <4){primer_digito = 4;}
	if (primer_digito >= 5 and primer_digito <6){primer_digito = 5;}
	if (primer_digito >= 7 and primer_digito <9){primer_digito = 6;}
	
	if (segundo_digito >= 0 and segundo_digito <2){segundo_digito = 3;}
	if (segundo_digito >= 3 and segundo_digito <4){segundo_digito = 4;}
	if (segundo_digito >= 5 and segundo_digito <6){segundo_digito = 5;}
	if (segundo_digito >= 7 and segundo_digito <9){segundo_digito = 6;}
	
	if (tercer_digito >= 0 and tercer_digito <2){tercer_digito = 3;}
	if (tercer_digito >= 3 and tercer_digito <4){tercer_digito = 4;}
	if (tercer_digito >= 5 and tercer_digito <6){tercer_digito = 5;}
	if (tercer_digito >= 7 and tercer_digito <9){tercer_digito = 6;}
	
	if (cuarto_digito >= 0 and cuarto_digito <2){cuarto_digito = 3;}
	if (cuarto_digito >= 3 and cuarto_digito <4){cuarto_digito = 4;}
	if (cuarto_digito >= 5 and cuarto_digito <6){cuarto_digito = 5;}
	if (cuarto_digito >= 7 and cuarto_digito <9){cuarto_digito = 6;}

	s1 = primer_digito;
	s2 = segundo_digito;
	s3 = tercer_digito;
	s4 = cuarto_digito;
	
	cout << tiempo << "    " << s1 << " - "<< s2 << " - "<< s3 << " - "<< s4;
	Beep (659, 304);
	Sleep(tiempo);
	system("cls");
	tiempo = tiempo - 6;
	
}
if (intentos <2){
	cout << tiempo << "    " << s1 << " - "<< s2 << " - "<< s3 << " - "<< s4;
	system("pause");                       
}else{
	cout << tiempo << "    " << s1 << " - "<< s1 << " - "<< s1 << " - "<< s1 << endl;
	cout << "VAYA A CAJA A CAMBIAR LOS COINS!!!!!"<< endl;
	//Beep(523, 382); Beep(587,340);Beep(659,304);Beep(698,286);
	system("pause"); 
}

}
