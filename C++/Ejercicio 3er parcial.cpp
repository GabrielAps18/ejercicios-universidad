/*
	Programa elaborado por Gabriel Pacheco, Alejandro Rodriguez, María Garcés y Alan Ruz
	Programa que simula el proceso de craqueo catalítico de la refinería Amuay - Punto Fijo, Venezuela
	Fecha: 02/02/2021
*/

#include<iostream> // Mostrar datos en pantalla
#include<fstream> // Leer y escribir en un archivo de texto
#include<windows.h> // Control de ejecución (tiempo de refrescamiento de pantalla)
using namespace std;

int main(){
	int trans_temp = 40;					// Transmisor de Temperatura
	int trans_presion_crudo = 49;			// Transmisor de presion (Bomba de Crudo)
	int trans_presion_cata = 39;			// Transmisor de presion (Bomba de Catalizador)
	int perturbacion;						// Perturbación + Temperatura 
	int perturbacion_min;					// Perturbación + Temperatura mínima
	int aux;								// Auxiliar
	string switch_tem = "ON";				// Switch de Temperatura
	string bomba_catalizador = "APAGADA";	// Estado de Bomba de Catalizador
	string bomba_crudo = "APAGADA";			// Estado de Bomba de Crudo
	
	int perturbacion_temp;					// Perturbación
	string switch_presion_dif;				// Switch de Presión
	string valvula_manual;					// Válvula Manual
	string pantalla="ON";					// Pantalla

	inicio:
	
	// Definimos los valores de estas variables
	perturbacion = 80 + perturbacion_temp;
	perturbacion_min = 40 + perturbacion_temp;
	
	// Recogemos la información del documento
	ifstream adicionales("c:\\torre.txt"); 
	
	adicionales>>perturbacion_temp>>switch_presion_dif>>valvula_manual;
	
	aux = perturbacion_temp - 21;
	contador:
 // imprimimos los valores en pantalla para el modo Remoto
 
 	if(pantalla=="ON")
 		{
		system("cls");
 		cout <<" - Transmisor de Temperatura= "<<trans_temp<<endl;
		cout <<" - Transmisor de Presion (Bomba de Catalizador)= "<<trans_presion_cata<<endl;
		cout <<" - Transmisor de Presion (Bomba de Crudo)= "<<trans_presion_crudo<<endl;
 		cout <<" - Switch de Temperatura= "<<switch_tem<<endl; 
 		cout <<" - Bomba de Catalizador= "<<bomba_catalizador<<endl;
 		cout <<" - Bomba de Crudo= "<<bomba_crudo<<endl;
 		cout <<" - Perturbacion de la temperatura de la torre= "<<perturbacion_temp<<endl;
 		cout <<" - Switch de Presion Diferencial= "<<switch_presion_dif<<endl;  
 		cout <<" - Valvula de Catalizador= "<<valvula_manual<<endl;  
 		pantalla ="OFF"; 
   		}	

//  Establecemos un tiempo de 1 de segundo para ver los cambios de la pantalla

    Sleep (1000);
	
// Switch de Temperatura
	// Tabla de la verdad fila 1
	if(trans_temp > 100){
			switch_tem = "OFF";
	}
	
	// Tabla de la verdad fila 5
	if(trans_temp <95){
			switch_tem = "ON";
	}
	
// Bomba de Crudo
	// Tabla de la verdad fila 2
	if(trans_presion_crudo < 50 and switch_tem == "ON" and switch_presion_dif == "ON" and bomba_crudo == "APAGADA"){
			bomba_crudo = "ENCENDIDA";
	}
	
	// Tabla de la verdad fila 3
	if(trans_presion_crudo < 50 and switch_tem == "ON" and switch_presion_dif == "OFF" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	
	// Tabla de la verdad fila 5
	if(trans_presion_crudo < 50 and switch_tem == "OFF" and switch_presion_dif == "ON" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	
	// Tabla de la verdad fila 7
	if(trans_presion_crudo < 50 and switch_tem == "OFF" and switch_presion_dif == "OFF" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	
	// Tabla de la verdad fila 9
	if(trans_presion_crudo > 90 and switch_tem == "ON" and switch_presion_dif == "ON" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	
	// Tabla de la verdad fila 11
	if(trans_presion_crudo > 90 and switch_tem == "ON" and switch_presion_dif == "OFF" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	
	// Tabla de la verdad fila 13
	if(trans_presion_crudo > 90 and switch_tem == "OFF" and switch_presion_dif == "ON" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	
	// Tabla de la verdad fila 15
	if(trans_presion_crudo > 90 and switch_tem == "OFF" and switch_presion_dif == "OFF" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	
	// Tabla de la verdad fila 19
	if(trans_presion_crudo <= 90 and switch_tem == "ON" and switch_presion_dif == "OFF" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	if(trans_presion_crudo >= 50 and switch_tem == "ON" and switch_presion_dif == "OFF" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	
	// Tabla de la verdad fila 21
	if(trans_presion_crudo <= 90 and switch_tem == "OFF" and switch_presion_dif == "ON" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	if(trans_presion_crudo >= 50 and switch_tem == "OFF" and switch_presion_dif == "ON" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	
	// Tabla de la verdad fila 23
	if(trans_presion_crudo <= 90 and switch_tem == "OFF" and switch_presion_dif == "OFF" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}
	if(trans_presion_crudo >= 50 and switch_tem == "OFF" and switch_presion_dif == "OFF" and bomba_crudo == "ENCENDIDA"){
			bomba_crudo = "APAGADA";
	}

// Bomba de Catalziador
	// Tabla de la verdad fila 2
	if(trans_presion_cata < 40 and switch_tem == "ON" and switch_presion_dif == "ON" and bomba_catalizador == "APAGADA"){
			bomba_catalizador = "ENCENDIDA";
	}
	
	// Tabla de la verdad fila 3
	if(trans_presion_cata < 40 and switch_tem == "ON" and switch_presion_dif == "OFF" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	
	// Tabla de la verdad fila 5
	if(trans_presion_cata < 40 and switch_tem == "OFF" and switch_presion_dif == "ON" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	
	// Tabla de la verdad fila 7
	if(trans_presion_cata < 40 and switch_tem == "OFF" and switch_presion_dif == "OFF" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	
	// Tabla de la verdad fila 9
	if(trans_presion_cata > 70 and switch_tem == "ON" and switch_presion_dif == "ON" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	
	// Tabla de la verdad fila 11
	if(trans_presion_cata > 70 and switch_tem == "ON" and switch_presion_dif == "OFF" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	
	// Tabla de la verdad fila 13
	if(trans_presion_cata > 70 and switch_tem == "OFF" and switch_presion_dif == "ON" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	
	// Tabla de la verdad fila 15
	if(trans_presion_cata > 70 and switch_tem == "OFF" and switch_presion_dif == "OFF" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	
	// Tabla de la verdad fila 19
	if(trans_presion_cata <= 70 and switch_tem == "ON" and switch_presion_dif == "OFF" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	if(trans_presion_cata >= 40 and switch_tem == "ON" and switch_presion_dif == "OFF" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	
	// Tabla de la verdad fila 21
	if(trans_presion_cata <= 70 and switch_tem == "OFF" and switch_presion_dif == "ON" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	if(trans_presion_cata >= 40 and switch_tem == "OFF" and switch_presion_dif == "ON" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	
	// Tabla de la verdad fila 23
	if(trans_presion_cata <= 70 and switch_tem == "OFF" and switch_presion_dif == "OFF" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	if(trans_presion_cata >= 40 and switch_tem == "OFF" and switch_presion_dif == "OFF" and bomba_catalizador == "ENCENDIDA"){
			bomba_catalizador = "APAGADA";
	}
	
// Transmisor de Presion (Bomba de Crudo)
	if(bomba_crudo == "ENCENDIDA"){
		if(trans_presion_crudo < 70){
			trans_presion_crudo = trans_presion_crudo + 1;
		}
		if(trans_presion_crudo > 70){
			trans_presion_crudo = trans_presion_crudo - 1;
		}
		pantalla ="ON";	
	}
	
	if(bomba_crudo == "APAGADA"){
		trans_presion_crudo = trans_presion_crudo - 1;
		pantalla ="ON";	
	}
	if(trans_presion_crudo < 0){
		trans_presion_crudo = 0;
	}
// Transmisor de Presion (Bomba de Catalziador)
	if(bomba_catalizador == "ENCENDIDA" and valvula_manual == "ABIERTA"){
		if(trans_presion_cata < 55){
			trans_presion_cata = trans_presion_cata + 1;	
		}
		if(trans_presion_cata > 55){
			trans_presion_cata = trans_presion_cata - 1;	
		}
		pantalla ="ON";	
	}
	
	if(bomba_catalizador == "ENCENDIDA" and valvula_manual == "CERRADA"){
		trans_presion_cata = trans_presion_cata + 2;
		pantalla ="ON";	
	}
	
	if(bomba_catalizador == "APAGADA" and valvula_manual == "ABIERTA"){
		trans_presion_cata = trans_presion_cata - 1;
		pantalla ="ON";	
	}
	if(trans_presion_cata < 0){
		trans_presion_cata = 0;
	}
	
// Temperatura 
	// Tabla de la verdad fila 1
	if(trans_temp > 100 and bomba_crudo == "ENCENDIDA" and bomba_catalizador == "ENCENDIDA"){
		trans_temp = trans_temp + 2;
	}
	
	// Tabla de la verdad fila 4
	if(trans_temp > 100 and bomba_crudo == "APAGADA" and bomba_catalizador == "APAGADA"){
		if(aux > 0){
			
		}else{
			trans_temp = trans_temp - 2;
		}
	}
	
	// Tabla de la verdad fila 5
	if(trans_temp < 95 and bomba_crudo == "ENCENDIDA" and bomba_catalizador == "ENCENDIDA"){
		if(trans_temp < 80){
			trans_temp = trans_temp + 1;
		}
		if(trans_temp > 80 and perturbacion_temp == 0){  
			trans_temp = trans_temp - 1;
		}
		if(trans_temp == perturbacion){
			trans_temp = trans_temp;
		}
	}
	// Tabla de la verdad fila 6
	if(trans_temp < 95 and bomba_crudo == "ENCENDIDA" and bomba_catalizador == "APAGADA"){
		if(trans_temp <= perturbacion_min){
			trans_temp = perturbacion_min;
		}if(trans_temp > perturbacion_min){
			trans_temp = trans_temp - 2;
		}
	}
	// Tabla de la verdad fila 7
	if(trans_temp < 95 and bomba_crudo == "APAGADA" and bomba_catalizador == "ENCENDIDA"){
		if(trans_temp <= 40){
			
		}if(trans_temp > perturbacion_min){
			trans_temp = trans_temp - 2;
		}
	}
	
	
	// Tabla de la verdad fila 8
	if(trans_temp < 95 and bomba_crudo == "APAGADA" and bomba_catalizador == "APAGADA"){
		if(trans_temp <= perturbacion_min){
			trans_temp = perturbacion_min; 
		}if(trans_temp > perturbacion_min){
			trans_temp = trans_temp - 2;
		}
	}
	
	// Tabla de la verdad fila 9
	if(trans_temp >= 95 and trans_temp <= 100 and bomba_crudo == "ENCENDIDA" and bomba_catalizador == "ENCENDIDA"){
		trans_temp = trans_temp + 2;
	}
	
	// Tabla de la verdad fila 12
	if(trans_temp >= 95 and trans_temp <= 100 and bomba_crudo == "APAGADA" and bomba_catalizador == "APAGADA"){
		trans_temp = trans_temp - 2;
	}

// Perturbacion 
	if(perturbacion_temp > 0){
		//if(perturbacion < perturbacion_temp){
		//	perturbacion = perturbacion + 1;
		//	trans_temp = trans_temp + perturbacion;
		//}
	//	if(trans_temp == perturbacion){
	//		
	//	}
		if(trans_temp == perturbacion_min and bomba_catalizador == "APAGADA"){
			goto inicio;
		}
		if(trans_temp == 101 and aux > 0){
			trans_temp = 101;
			aux = aux -1;
			goto contador;
		}
		if(trans_temp == perturbacion){
		}else{
			trans_temp = trans_temp +1;
		}
		
	}
	

	goto inicio;	
}