//Declaramos las librerias
#include <stdio.h>
#include <conio.h>
/*Programa elaborado por Gabriel Pacheco el 03/04/2022 para calcular el costo de una llamada telefonica*/
int main(){
	//Declaramos las variables
		char NOM[20];
		int NUM, MIN, MONT;
	//Ingresamos los datos
		printf("Ingrese el nombre del usuario: ");
		scanf("%s", NOM);
		printf("\nIngrese el numero telefonico: ");
		scanf("%d", &NUM);
		printf("\nIngrese la cantidad de minutos de la llamada: ");
		scanf("%d", &MIN);
	
	//Calculamos el costo sabiendo que el costo por minuto es de 8bs
		MONT = MIN * 8;
	
	//Imprimimos el resultado
		printf("\nLa llamada de %s desde el numero %d tuvo un costo de %d bs", NOM, NUM, MONT);
}