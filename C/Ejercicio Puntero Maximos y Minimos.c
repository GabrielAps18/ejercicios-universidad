/*Ejercicio: Construya una funcion que reciba una matriz de reales y devuelva el maximo y
el minimo de sus elementos.*/
//Elaborado por Gabriel Pacheco

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void MIN_MAX (float *NUMEROS, float *p, float *q);

int main() {
	//Variables
	int i;
	float NUMS[7] = {4.10,6.10,2.23,1.24,3.76,4.23,5.42};
	float MAX, MIN;
	//Llamada de funcion
	MIN_MAX(NUMS, &MAX, &MIN);
	printf("El valor MAXIMO de la matriz es %.2f", MAX);
	printf("\nEl valor MINIMO de la matriz es %.2f", MIN);
}

//Funcion para obtener valores MAXIMOS y MINIMOS
void MIN_MAX (float *NUMEROS, float *p, float *q){
	int i, j;
	*p = 0;
	*q = 0;
	for(i = 0; i <= 10; i++){
		for(j = 0; j <= 5; j++){
			if(*p < NUMEROS[j]){
				*p = NUMEROS[j];
			}
		}
	}
	*q = *p;
	for(i = 0; i <= 10; i++){
		for(j = 0; j <= 5; j++){
			if(*q > NUMEROS[j]){
				*q = NUMEROS[j];
			}
		}
	}
}
