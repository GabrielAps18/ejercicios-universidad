#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define F 10
#define C 4
//Programa para sumar 2 matrices
int validar_numero(char VAL_NUM[]);
int main(){
	int MAT_A[F][C], MAT_B[F][C], MAT_C[F][C], i, j, k, NUM, Z = 0;
	char VAL_NUM[3];
	
	//Carga de matriz A
	for (j = 0; j < F; ++j){
		for(k = 0; k < C; ++k){
			do{
				// DO WHILE para verificar si es valido el numero
				do{
					printf("\nIngresa un numero para la posicion [%d][%d]: ", j,k);
					fflush(stdin);
					scanf("%s",VAL_NUM);
					NUM= validar_numero(VAL_NUM);
				}while(NUM == 0);
				
				//Insertamos el numero valido en la matriz
				MAT_A[j][k] = atoi(VAL_NUM);
				
				//Confirmamos si el numero está en el rango solicitado
				if(MAT_A[j][k] < -1000 || MAT_A[j][k] > 1000){
					printf("\nSOLO PUEDES INGRESAR NUMEROS > 0 y < 1000");
				}
			} while(MAT_A[j][k] < -1000 || MAT_A[j][k] > 1000);
		}
	}
	//Carga de matriz B
	for (j = 0; j < F; ++j){
		for(k = 0; k < C; ++k){
			do{
				// DO WHILE para verificar si es valido el numero
				do{
					printf("\nIngresa un numero para la posicion [%d][%d]: ", j,k);
					fflush(stdin);
					scanf("%s",VAL_NUM);
					NUM= validar_numero(VAL_NUM);
				}while(NUM == 0);
				
				//Insertamos el numero valido en la matriz
				MAT_B[j][k] = atoi(VAL_NUM);
				
				//Confirmamos si el numero está en el rango solicitado
				if(MAT_B[j][k] < -1000 || MAT_B[j][k] > 1000){
					printf("\nSOLO PUEDES INGRESAR NUMEROS > 0 y < 1000");
				}
			} while(MAT_B[j][k] < -1000 || MAT_B[j][k] > 1000);
		}
	}
	
	//Suma de matrices
	for (j = 0; j < F; ++j){
		for(k = 0; k < C; ++k){
			MAT_C[j][k] = MAT_A[j][k] + MAT_B[j][k];
		}
	}
	
	//Imprimir matriz A
	system("cls");
	printf("\n");
	for (j = 0; j < F; ++j){
		for(k = 0; k < C; ++k){
			if(Z == C){
				printf("\n");
				Z = 0;
			}
			printf("\t%d", MAT_A[j][k]);
			++Z;
		}
	}
	printf("\n\n\t\t + \n\n");
	
	//Imprimir matriz B
	for (j = 0; j < F; ++j){
		for(k = 0; k < C; ++k){
			if(Z == C){
				printf("\n");
				Z = 0;
			}
			printf("\t%d", MAT_B[j][k]);
			++Z;
		}
	}
	printf("\n\n\t\t = \n\n");
	//Imprimir matriz resultado
	for (j = 0; j < F; ++j){
		for(k = 0; k < C; ++k){
			if(Z == C){
				printf("\n");
				Z = 0;
			}
			printf("\t%d", MAT_C[j][k]);
			++Z;
		}
	}
}
//FUNCION PARA VALIDAR NUMEROS POSITIVOS Y NEGATIVOS ENTEROS
int validar_numero(char VAL_NUM[]){
	int i;
	for (i = 0; i < strlen(VAL_NUM); ++i){
		if(!(isdigit(VAL_NUM[i]))){
			if(VAL_NUM[0] == '-' && isdigit(VAL_NUM[i+1])){
				
			}else{
				printf("\nDebes ingresar un numero ENTERO valido");
			return 0;
			}
		}
	}
	return 1;
}