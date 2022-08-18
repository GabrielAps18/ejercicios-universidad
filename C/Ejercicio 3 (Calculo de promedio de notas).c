//Declaramos las librerias
#include <stdio.h>
#include <conio.h>
/*Programa elaborado por Gabriel Pacheco el 03/04/2022 para Promediar las notas de un estudiante*/
int main(){
	//Declaramos las variables
		char NOM[20];
		int EDAD;
		float NOT1, NOT2, NOT3, PROM;
	
	//Solicitamos los datos	del estudiante
		printf("Ingrese el nombre del estudiante: ");
		scanf("%s", NOM);
		printf("\nIngrese la edad del estudiante: ");
		scanf("%d", &EDAD);
		printf("\nIngrese la primer nota: ");
		scanf("%f", &NOT1);
		printf("\nIngrese la segunda nota: ");
		scanf("%f", &NOT2);
		printf("\nIngrese la tercer nota: ");
		scanf("%f", &NOT3);
	
	//Sacamos el promedio de notas
		PROM = (NOT1 + NOT2 + NOT3) / 3;
	
	//Imprimimos el resultados
		printf("\nEl promedio del estudiante %s es: %.2f", NOM, PROM);
	
}