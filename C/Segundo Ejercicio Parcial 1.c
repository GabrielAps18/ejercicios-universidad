#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
//Programa para intercambiar valores - Primer Parcial - Ejercicio 2 - Elaborado por Gabriel Pacheco 28426233
int main(){
	//Definimos las variables
	int OP;
	float NUM1, NUM2, AUX;
	do{
		OP = 0;
		
		//Solicitamos los datos (numeros positivos y negativos)
		system("cls");
		printf("Ingrese el primer numero para intercambiar: ");
		scanf("%f", &NUM1);
		printf("\nIngrese el segundo numero para intercambia: ");
		scanf("%f", &NUM2);
		
		//Intercambiamos valores
		AUX = NUM1;
		NUM1 = NUM2;
		NUM2 = AUX;
		
		//Imprimimos los resultados
		printf("\nAhora el primer numero es: %.2f", NUM1);
		printf("\nY el segundo numero es: %.2f", NUM2);
		
		//Opcion desea continuar?
		do{
			printf("\nDesea realizar otro intercambio? (1-. SI - 2-. NO): ");
			scanf("%d", &OP);
		}while(OP != 1 && OP !=2);
	}while(OP !=2);
		printf("\nVuelva pronto...");
}