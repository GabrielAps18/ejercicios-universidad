#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10 // Aqui definimos el tamano del vector
//Vector de tamano 10 con numeros reales - Gabriel Pacheco - 25/05/22 - 2do parcial

int validar_numero(char VAL_NUM[]);
int main(){
	float NUMS[MAX], PROM, SUMA, MAYORES[MAX], MENORES[MAX], IGUALES[MAX];
	int MAYOR = 0, MENOR = 0, IGUAL = 0, i, j, NUM;
	char VAL_NUM[6];
	//Solicitamos los valores del vector
	for(i = 0; i < MAX; ++i){
		do{
			do{
				printf("\nIngrese el valor %d: ", i+1);
				fflush(stdin);
				scanf("%s",VAL_NUM);
				NUM = validar_numero(VAL_NUM);
			}while(NUM == 0);
			
			//Convertimos la validacion en un numero
			NUMS[i] = atof(VAL_NUM);
			
			if(NUMS[i] <= 0 || NUMS[i] > 100){
				printf("\n\tEL NUMERO DEBE ESTAR EN EL RANGO DE 0+ y 100");
			}
		}while(NUMS[i] <= 0 || NUMS[i] > 100);
	}
	// Caclculamos el promedio
	for(i = 0; i < MAX; ++i){
		SUMA = SUMA + NUMS[i];
	}
	PROM = SUMA / MAX;
	
	//Calculamos cuantos son MAYORES, MENORES O IGUALES AL PROMEDIO y los guardamos en sus vectores correspondientes
	for(i = 0; i < MAX; ++i){
		if(NUMS[i] < PROM){
			MENORES[MENOR] = NUMS[i];
			MENOR = MENOR + 1;
		}
		if(NUMS[i] > PROM){
			MAYORES[MAYOR] = NUMS[i];
			MAYOR = MAYOR + 1;
		}
		if(NUMS[i] == PROM){
			IGUALES[IGUAL] = NUMS[i];
			IGUAL = IGUAL + 1;
		}
	}
	
	//Imprimimos los resultados
	system("cls");
	printf("\nEl promedio de todos los numeros es: %.2f", PROM);
	
	printf("\n\n\tHay %d elementos MAYORES al Promedio:", MAYOR);
	for(i = 0; i < MAYOR; ++i) printf("\t%.2f", MAYORES[i]);
	
	printf("\n\tHay %d elementos MENORES al Promedio:", MENOR);
	for(i = 0; i < MENOR; ++i) printf("\t%.2f", MENORES[i]);
	
	printf("\n\tHay %d elementos IGUALES al Promedio:", IGUAL);
	for(i = 0; i < IGUAL; ++i) printf("\t%.2f", IGUALES[i]);
	
	printf("\n\nLista de numeros ingresados:");
	for(i = 0; i < MAX; ++i){
		printf("\n\t%.2f", NUMS[i]);
	}
}
//FUNCION PARA VALIDAR NUMEROS REALES POSITIVOS
int validar_numero(char VAL_NUM[]){
	int i, punto = 0;
	for (i = 0; i < strlen(VAL_NUM); ++i){
		if(!(isdigit(VAL_NUM[i]))){
			if(VAL_NUM[i] == '.'){
				if(punto > 1){
					printf("\nDebes ingresar un numero REAL POSITIVO valido");
					return 0;	
				}else punto = punto + 1;
			}else{
				printf("\nDebes ingresar un numero REAL POSITIVO valido");
				return 0;
			}
		}
	}
	return 1;
}