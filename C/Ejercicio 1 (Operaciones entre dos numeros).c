//Declaramos las librerias
#include <stdio.h>
#include <conio.h>
/*Programa elaborado por Gabriel Pacheco el 03/04/2022 para realizar la Suma, Resta, Multiplicación y División de dos numeros enteros ingresados por teclado*/
int main(){
	//Declaramos variables
		int NUM1, NUM2, SUM, RES, MUL;
		float DIV;
	
	//Pedimos los numeros
		printf("Ingrese el primer numero: ");
		scanf("%d", &NUM1);
		printf("\nIngrese el segundo numero: ");
		scanf("%d", &NUM2);
	
	//Hacemos las operaciones
		SUM = NUM1 + NUM2;
		RES = NUM1 - NUM2;
		MUL = NUM1 * NUM2;
		DIV = (float)NUM1 / (float)NUM2;
	
	//Imprimimos los resultados
		printf("\n La suma entre %d + %d es: %d", NUM1, NUM2, SUM);
		printf("\n La resta entre %d - %d es: %d", NUM1, NUM2, RES);
		printf("\n La multiplicacion entre %d * %d es: %d", NUM1, NUM2, MUL);
		printf("\n La division entre %d / %d es: %.2f", NUM1, NUM2, DIV);
	
}