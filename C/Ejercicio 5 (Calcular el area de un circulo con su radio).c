//Declaramos las librerias
#include <stdio.h>
#include <conio.h>
#define PI 3.14159265359
/*Programa elaborado por Gabriel Pacheco el 03/04/2022 para calcular el area de un círculo con su radio*/
int main(){
	//Declaramos las variables
		float RADIO, AREA;
	//Ingresamos el dato
		printf("Ingrese el radio del circulo: ");
		scanf("%f", &RADIO);
	
	//Calculamos el area
		AREA = RADIO * 2 * PI;
	
	//Imprimimos el resultado
		printf("El area del circulo de radio %.2f es: %f", RADIO, AREA);
}
