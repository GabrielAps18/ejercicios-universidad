#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define MAX 20
//PROGRAMA ELABORADO POR GABRIEL PACHECO 08/05/22 PARA INGRESAR NUMS POR TECLADO Y SEPARARLOS EN NEG Y POS CON MATRICES
int validar_numero(char VAL_NUM[]);
int main (){
	int NUMS[MAX], POS[MAX], NEG[MAX], j, NUM, N = 0, P = 0;
	char VAL_NUM[3];
	
	//FOR para cargar la matriz principal
	for (j = 0; j < MAX; ++j){
		do{
			// DO WHILE para verificar si es valido el numero
			do{
				printf("\nIngresa un numero de -10 a 10: ");
				fflush(stdin);
				scanf("%s",VAL_NUM);
				NUM= validar_numero(VAL_NUM);
			}while(NUM == 0);
			
			//Insertamos el numero valido en la matriz
			NUMS[j] = atoi(VAL_NUM);
			
			//Confirmamos si el numero está en el rango solicitado
			if(NUMS[j] < -10 || NUMS[j] > 10){
				printf("\nDEBES INGRESAR UN NUMERO ENTRE -10 y 10");
			}
		} while(NUMS[j] < -10 || NUMS[j] > 10);
		printf(" \n %d", NUMS[j]);
	}
	
	//Asignamos valores para la matriz positiva > 0 y Negativa <= 0
	for(j = 0; j < MAX; j++){
		if(NUMS[j] > 0){
			POS[P] = NUMS[j];
			++P;
		}
		if(NUMS[j] <= 0){
			NEG[N] = NUMS[j];
			++N;
		}
	}
	
	//Imprimimos los resultados
	system("cls");
	printf("Los valores ingresados son:");
	for(j = 0; j < MAX; ++j){
		printf("\t%d", NUMS[j]);
	}
	printf("\n\nLos valores positivos son:");
	for(j = 0; j < P; ++j){
		printf("\t%d", POS[j]);
	}
	printf("\n\nLos valores negativos o iguales a 0 son:");
	for(j = 0; j < N; ++j){
		printf("\t%d", NEG[j]);
	}
}
//FUNCION PARA VALIDAR NUMEROS POSITIVOS Y NEGATIVOS ENTEROS
int validar_numero(char VAL_NUM[]){
	int i;
	for (i = 0; i < strlen(VAL_NUM); ++i){
		if(!(isdigit(VAL_NUM[i]))){
			if(VAL_NUM[0] == '-' && isdigit(VAL_NUM[i+1])){
				
			}else{
				printf("\nDebes ingresar un numero valido");
			return 0;
			}
		}
	}
	return 1;
}