#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Calcular serie Fibonacci con recursividad - Gabriel Pacheco - 25/05/22 - 2do Parcial
int validar_numero(char VAL_NUM[]);
long fibonacci(long FIB);
int main(){
	int i, REP, NUM, SALIR, OPC;
	long FIB;
	char VAL_NUM[4], OP;
	//Menu
	do{
		system("cls");
		printf("1-. Serie Fibonacci.");
		printf("\n2-. Salir");
		//Validamos la opcion que selecciona el usuario
		do{
			do{
				printf("\nSeleccione una opcion: ");
				fflush(stdin);
				scanf("%s",VAL_NUM);
				NUM = validar_numero(VAL_NUM);
			}while(NUM == 0);
			
			//Convertimos la validacion en un numero
			OPC = atoi(VAL_NUM);
			
			if(OPC <= 0 || OPC > 2){
				printf("\n\tOPCION INVALIDA!!!");
			}
		}while(OPC <=0 || OPC > 2);
	//Opciones
		switch(OPC){
		//Caso 1 = Serie Fibonacci
			case 1:
				//Solicitamos la cantidad de numeros que deseamos obtener
				system("cls");
				do{
					do{
						printf("\nCuantos numeros de la serie desea obtener?: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					//Convertimos la validacion en un numero
					REP = atoi(VAL_NUM);
					
					if(REP <= 0 || REP > 100){
							printf("\nEl maximo de numeros que puedes obtener es de 1 a 100");
						}
				}while(REP <=0 || REP > 100);
				
				//Imprimmos los resultados llamando a la funcion recursiva
				system("cls");
				printf("Serie Fibonnaci de %d numeros:\n", REP);
				for (i = 0; i < REP; ++i){
					printf("\t%d\n", fibonacci(1+i));
				}
				system("pause");
				break;
		//Caso 2 = Salida del sistema
			case 2:
				SALIR = 2;
				system("pause");
				break;
			default:
				printf("ERROR - Ingrese una opcion valida");
		}
	}while(SALIR != 2);
}
//FUNCION PARA VALIDAR NUMEROS POSITIVOS ENTEROS
int validar_numero(char VAL_NUM[]){
	int i;
	for (i = 0; i < strlen(VAL_NUM); ++i){
		if(!(isdigit(VAL_NUM[i]))){
				printf("\nDebes ingresar un numero ENTERO valido");
			return 0;
		}
	}
	return 1;
}
//FUNCION SERIE FIBUNACCI A PARTIR DE UN NUMERO - RECURSIVA
long fibonacci(long FIB){
	if (FIB <= 1){
		return 1;
	}else{
		return ((fibonacci(FIB - 1) + fibonacci(FIB - 2)));
	}		
}