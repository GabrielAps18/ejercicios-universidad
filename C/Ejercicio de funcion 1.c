#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//Ejercicio de multiplicacion de funciones
int suma (int x, int y); // Protoripo de funcion 

int main (){
	int a,b,OP;
	do{
		system("cls");
		printf("Ingrese el valor de A: ");
		scanf("%d", &a);
		printf("\n \nIngrese el valor de B: ");
		scanf("%d", &b);
		printf("\nLa multiplicacion de a y b es %d", suma(a,b));
		printf("\n\nDesea continuar? \n 	Pulse 2 para salir o pulse cualquier tecla para continuar: ");
		scanf("%d", &OP);
	}while(OP != 2);
}

int suma (int x, int y){
	return x*y;
}