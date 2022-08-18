#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define MAX 20
// PROGRAMA ELABORADO POR GABRIEL PACHECO EL 08/05/22 PARA INGRESAR VALORES NUMERICOS EN UNA MATRIZ 20x20
int validar_numero(char VAL_NUM[]);
int main(){
	int NUMS[MAX][MAX], i, j, k, NUM, p=1;
	char VAL_NUM[3];
	
	for (j = 0; j < MAX; ++j){
		for(k = 0; k < MAX; ++k){
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
				if(NUMS[j][k] < -1000 || NUMS[j][k] > 1000){
					printf("\nSOLO PUEDES INGRESAR NUMEROS > -1000 o < 1000");
				}
			} while(NUMS[j][k] < -1000 || NUMS[j][k] > 1000);
			printf(" \n %d", NUMS[j][k]);
		}
	}
	// Imprimimos matriz
	system("cls");
	printf("Los datos son: \n");
	for (j = 0; j < MAX; ++j){
		for(k = 0; k < MAX; ++k){
			printf("\t|%d", NUMS[j][k]);
			if(p == 10){
				printf("\n");
				p = 0;
			}
			++p;
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