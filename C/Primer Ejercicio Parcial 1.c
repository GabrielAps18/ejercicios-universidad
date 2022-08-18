#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define CLAVE 2311	//Definimos la clave como constante
//Programa de cajero - Primer Parcial - Ejercicio 1 - Elaborado por Gabriel Pacheco 28426233
int main() {
	//Definimos las variables
	int INT_CLAVE, OP;
	float SALDO = 520, RET, DEP;
	
	do{
		// Despues de cada iteracion las variables tendran valor de 0
		OP = INT_CLAVE = RET = DEP = 0;
		system("cls");
		
		//Solicitamos la contraseña
		do{
			system("cls");
			if(INT_CLAVE > 0 || INT_CLAVE < 0){
				printf("Clave incorrecta!\n");
			}
		printf("Ingrese su clave de 4 digitos para acceder al sistema: ");
		scanf("%d", &INT_CLAVE);
		} while(INT_CLAVE != CLAVE);
		
		//Menu de opciones
		while(OP != 1 && OP != 2 && OP != 3 && OP != 4){
			system("cls");
			printf("  Que operacion desea realizar? \n	1-.Consulta de saldo \n	2-.Retiro \n	3-.Deposito \n	4-.Salir \n");
			scanf("%d", &OP);
		}
		//Opcion 1
		if(OP == 1){
			system("cls");
			printf("Su saldo es: %.2f", SALDO);
			printf("\n");
			system("pause");
		}
		//Opción 2
		if(OP == 2){
			// Do while para exigir que el monto sea mayor a 0
			do{
				system("cls");
				if(RET < 0){
					printf("Ingrese un numero mayor a 0! \n");
				}
				printf("Ingrese el monto a retirar: ");
				scanf("%f", &RET);
			} while(RET <= 0);
			
			//Realizamos la operacion correspondiente
			if(RET > SALDO){
				printf("\nFondos insuficientes para realizar esta transaccion...\n");
				printf("\n");
				system("pause");
			}else{
				SALDO -= RET;
				printf("\nImprimiento billetes...");
				printf("\nSu saldo restante es de: %.2f", SALDO);
				printf("\n");
				system("pause");
			}
		}
		//Opcion 3
		if(OP == 3){
			//Solicitamos el monto a depositar (Que sea mayor a 0)
			do{	
				system("cls");
				if(DEP < 0){
					printf("Ingrese un numero mayor a 0! \n");
				}
				printf("Ingrese el monto a depositar: ");
				scanf("%f", &DEP);
			} while(DEP <= 0);
			//Realizamos la operacion
			SALDO += DEP;
			printf("\nIngrese los billetes...");
			printf("\nSu saldo actual es de: %.2f", SALDO);
			printf("\n");
			system("pause");
		}
	// Salida
	}while(OP != 4);
	printf("\nGracias! Vuelva pronto...");
}