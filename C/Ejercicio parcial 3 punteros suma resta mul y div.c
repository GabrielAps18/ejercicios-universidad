/*Elaborar un programa en lenguaje C que realice las operaciones basicas suma, resta, producto y division por medio de llamadas
a funciones que formen parte de una matriz aplicando punteros*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Prototipos de funciones
int validar_numero_ent(char VAL_NUM[]);
int validar_numero(char VAL_NUM[]);
void MATRIZ(float *SUMA, float *RESTA, float *MULTI, float *DIV);
void OPERACIONES(float *NUMERO1, float *NUMERO2, float *RESULTADO, int OPERACION);

int main(){
	int NUM, SALIR, OP, OPERACION;
	float NUM1, NUM2, RES;
	char VAL_NUM[20];
	do{
		SALIR = 0;
		do{
			do{
				system("cls");
				printf("\n\t\tMenu: ");
				printf("\n\t1-. Suma");
				printf("\n\t2-. Resta");
				printf("\n\t3-. Multiplicacion");
				printf("\n\t4-. Division");
				printf("\n\t5-. Salir\n");
				printf("\n\tQue opcion desea realizar?: ");
				fflush(stdin);
				scanf("%s",VAL_NUM);
				NUM = validar_numero_ent(VAL_NUM);
			}while(NUM == 0);
				
			OP = atoi(VAL_NUM);
				
			if(OP <= 0 || OP > 5){
				printf("\nERROR - Escoge una opcion entre 1 y 5\n");
				system("pause");
			}
		} while(OP <=0 || OP > 5);
		
		switch(OP){
			case 1:
				OPERACION = 1;
				do{
					do{
						system("cls");
						printf("\nIngrese el PRIMER numero: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
						
					NUM1 = atof(VAL_NUM);
						
					if(NUM1 <= 0 || NUM1 > 1000){
						printf("\nERROR - SOLO PUEDES INGRESAR NUMEROS > 0 o < 1000\n");
						system("pause");
					}
				} while(NUM1 <=0 || NUM1 > 1000);
				do{
					do{
						system("cls");
						printf("\nIngrese el SEGUNDO numero: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
						
					NUM2 = atof(VAL_NUM);
						
					if(NUM2 <= 0 || NUM2 > 1000){
						printf("\nERROR - SOLO PUEDES INGRESAR NUMEROS > 0 o < 1000\n");
						system("pause");
					}
				} while(NUM2 <=0 || NUM2 > 1000);
				
				OPERACIONES(&NUM1, &NUM2, &RES, OPERACION);
				system("cls");
				printf("\n\n\tEl resultado de la SUMA entre %.2f + %.2f es de %.2f\n\n", NUM1, NUM2, RES);
				system("pause");
				break;
			case 2:
				OPERACION = 2;
				do{
					do{
						system("cls");
						printf("\nIngrese el PRIMER numero: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
						
					NUM1 = atof(VAL_NUM);
						
					if(NUM1 <= 0 || NUM1 > 1000){
						printf("\nERROR - SOLO PUEDES INGRESAR NUMEROS > 0 o < 1000\n");
						system("pause");
					}
				} while(NUM1 <=0 || NUM1 > 1000);
				do{
					do{
						system("cls");
						printf("\nIngrese el SEGUNDO numero: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
						
					NUM2 = atof(VAL_NUM);
						
					if(NUM2 <= 0 || NUM2 > 1000){
						printf("\nERROR - SOLO PUEDES INGRESAR NUMEROS > 0 o < 1000\n");
						system("pause");
					}
				} while(NUM2 <=0 || NUM2 > 1000);
				
				OPERACIONES(&NUM1, &NUM2, &RES, OPERACION);
				
				system("cls");
				printf("\n\n\tEl resultado de la RESTA entre %.2f - %.2f es de %.2f\n\n", NUM1, NUM2, RES);
				system("pause");
				break;
			case 3:
				OPERACION = 3;
				do{
					do{
						system("cls");
						printf("\nIngrese el PRIMER numero: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
						
					NUM1 = atof(VAL_NUM);
						
					if(NUM1 <= 0 || NUM1 > 1000){
						printf("\nERROR - SOLO PUEDES INGRESAR NUMEROS > 0 o < 1000\n");
						system("pause");
					}
				} while(NUM1 <=0 || NUM1 > 1000);
				do{
					do{
						system("cls");
						printf("\nIngrese el SEGUNDO numero: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
						
					NUM2 = atof(VAL_NUM);
						
					if(NUM2 <= 0 || NUM2 > 1000){
						printf("\nERROR - SOLO PUEDES INGRESAR NUMEROS > 0 o < 1000\n");
						system("pause");
					}
				} while(NUM2 <=0 || NUM2 > 1000);
				
				OPERACIONES(&NUM1, &NUM2, &RES, OPERACION);
				
				system("cls");
				printf("\n\n\tEl resultado de la MULTIPLICACION entre %.2f * %.2f es de %.2f\n\n", NUM1, NUM2, RES);
				system("pause");
				break;
			case 4:
				OPERACION = 4;
				do{
					do{
						system("cls");
						printf("\nIngrese el PRIMER numero: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
						
					NUM1 = atof(VAL_NUM);
						
					if(NUM1 <= 0 || NUM1 > 1000){
						printf("\nERROR - SOLO PUEDES INGRESAR NUMEROS > 0 o < 1000\n");
						system("pause");
					}
				} while(NUM1 <=0 || NUM1 > 1000);
				do{
					do{
						system("cls");
						printf("\nIngrese el SEGUNDO numero: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
						
					NUM2 = atof(VAL_NUM);
						
					if(NUM2 <= 0 || NUM2 > 1000){
						printf("\nERROR - SOLO PUEDES INGRESAR NUMEROS > 0 o < 1000\n");
						system("pause");
					}
				} while(NUM2 <=0 || NUM2 > 1000);
				
				OPERACIONES(&NUM1, &NUM2, &RES, OPERACION);
				
				system("cls");
				printf("\n\n\tEl resultado de la DIVISION entre %.2f / %.2f es de %.2f\n\n", NUM1, NUM2, RES);
				system("pause");
				break;
			case 5:
				SALIR = 5;
				break;
			default:
				printf("\nERROR - Esa opcion no existe\n");
				system("pause");
		}
	} while(SALIR != 5);
}

//Funciones
//FUNCION PARA VALIDAR NUMEROS POSITIVOS DECIMALES
int validar_numero(char VAL_NUM[]){
	int i, punto = 0;
	for (i = 0; i < strlen(VAL_NUM); ++i){
		if(!(isdigit(VAL_NUM[i]))){
			if(VAL_NUM[i] == '.'){
				if(punto > 1){
					printf("\nERROR - Solo puedes ingresar un numero valido\n");
					system("pause");
					return 0;	
				}else punto = punto + 1;
			}else{
				printf("\nERROR - No puedes ingresar LETRAS\n");
				system("pause");
				return 0;
			}
		}
	}
	return 1;
}
//FUNCION PARA VALIDAR NUMEROS POSITIVOS ENTEROS
int validar_numero_ent(char VAL_NUM[]){
	int i, punto = 0;
	for (i = 0; i < strlen(VAL_NUM); ++i){
		if(!(isdigit(VAL_NUM[i]))){
				printf("\nERROR - No puedes ingresar LETRAS ni SIMBOLOS\n");
				system("pause");
				return 0;
		}
	}
	return 1;
}
//FUNCION OPERACIONES
void OPERACIONES(float *NUMERO1, float *NUMERO2, float *RESULTADO, int OPERACION){
	int NUM;
	if(OPERACION == 1){
		*RESULTADO = *NUMERO1 + *NUMERO2;
	}
	if(OPERACION == 2){
		*RESULTADO = *NUMERO1 - *NUMERO2;
	}
	if(OPERACION == 3){
		*RESULTADO = *NUMERO1 * *NUMERO2;
	}
	if(OPERACION == 4){
		*RESULTADO = *NUMERO1 / *NUMERO2;
	}
}
//Funcion matrices
void MATRIZ(float *SUMA, float *RESTA, float *MULTI, float *DIV){
	int OPE[4] = {1,2,3,4};
	int S,R,M,D;
	*SUMA = OPE[1];
	*RESTA = OPE[2];
	*MULTI = OPE[3];
	*DIV = OPE[4];
}