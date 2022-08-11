/*Construya una funcion que recibe dos numeros enteros correspondientes a
minutos y segundos y devuelve tres enteros representando horas, minutos y
segundos que corresponden. Por ejemplo, si se dan 123 minutos y 80 segundos,
la salida de la funcion seria 2 horas, 4 minutos y 20 segundos. */
//Elaborado por Gabriel Pacheco

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void tiempo(int *HORAS, int *MINUTOS, int *SEGUNDOS);

int main() {
	int horas, min, seg;
	
	printf("Ingrese los minutos: ");
	scanf("%d", &min);
	printf("\nIngrese los segundos: ");
	scanf("%d", &seg);
	
	seg = seg + (min * 60);
	
	tiempo(&horas, &min, &seg);
	
	system("cls");
	printf("%d h - %d m - %d s", horas, min, seg);
}
void tiempo(int *HORAS, int *MINUTOS, int *SEGUNDOS){
	int AUX_SEC;
	*HORAS = *SEGUNDOS / 3600;
	AUX_SEC = *SEGUNDOS % 3600;
	*MINUTOS = AUX_SEC / 60;
	*SEGUNDOS = AUX_SEC % 60;
	
}
