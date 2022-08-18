#include <stdio.h>
#include <conio.h>
/*Programa realizado por Gabriel Pacheco - 03/04/2022 - Ejecicio para calcular el sueldo neto*/
int main() {
	//Definimos las variables
	char NOM[20];
	int EDAD;
	float MAM, MDM, SNM, SNQ, SNS;
	
	//Solicitamos los datos
	printf("Por favor ingrese el nombre: ");
	scanf("%s", NOM);
	printf("\n Por favor ingrese la edad: ");
	scanf("%d", &EDAD);
	printf("\n Ingrese el monto de la asignacion mensual: ");
	scanf("%f", &MAM);
	printf("\n Ingrese el monto de la deduccion mensual: ");
	scanf("%f", &MDM);
	
	//Realizamos las operaciones necesarias
	SNM = MAM - MDM;
	SNQ = SNM / 2;
	SNS = (SNM * 12) / 52;
	
	//Imprimimos los resultados
	printf("\nEl sueldo neto mensual de: %s es de %.2f \n", NOM, SNM);
	printf("El quincenal es: %.2f \n", SNQ);
	printf("El semanal es: %.2f \n", SNS);
	
	getche();
	
}