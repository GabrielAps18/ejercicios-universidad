#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define F 5
#define C 4
// PROGRAMA ELABORADO POR GABRIEL PACHECO EL 08/05/22 PARA INGRESAR VALORES NUMERICOS EN UNA MATRIZ 20x20
int validar_numero(char VAL_NUM[]);
int main(){
	int NUMS[F][C], i, j, k, NUM, MENOR=1001, MAYOR=0, COL_MAY, FIL_MENOR;
	char VAL_NUM[3];
	
	for (j = 0; j < F; ++j){
		for(k = 0; k < C; ++k){
			do{
				// DO WHILE para verificar si es valido el numero
				do{
					printf("\nIngresa un numero: ");
					fflush(stdin);
					scanf("%s",VAL_NUM);
					NUM= validar_numero(VAL_NUM);
				}while(NUM == 0);
				
				//Insertamos el numero valido en la matriz
				NUMS[j][k] = atoi(VAL_NUM);
				
				//Confirmamos si el numero está en el rango solicitado
				if(NUMS[j][k] < 0 || NUMS[j][k] > 1000){
					printf("\nSOLO PUEDES INGRESAR NUMEROS > 0 y < 1000");
				}
			} while(NUMS[j][k] < 0 || NUMS[j][k] > 1000);
			printf(" \n %d", NUMS[j][k]);
		}
	}
	//Buscamos el numero menor
	for (j = 0; j < F; ++j){
		for(k = 0; k < C; ++k){
			if(NUMS[j][k] < MENOR){
				MENOR = NUMS[j][k];
				FIL_MENOR = j+1;
			}
		}
	}
	
	//Buscamos el numero mayor
	for (j = 0; j < F; ++j){
		for(k = 0; k < C; ++k){
			if(NUMS[j][k] > MAYOR){
				MAYOR = NUMS[j][k];
				COL_MAY = k+1;
			}
		}
	}
	system("cls");
	printf("El numero menor es %d y se encuentra en la fila %d.", MENOR, FIL_MENOR);
	printf("\nEl numero mayor es %d y se encuentra en la columna %d.", MAYOR, COL_MAY);
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