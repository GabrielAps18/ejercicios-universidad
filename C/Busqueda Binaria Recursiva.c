#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 7
//Busqueda Binaria Recursiva - Gabriel Pacheco - 26/05/22
int validar_numero(char VAL_NUM[]);
int busqueda(int BUS, int IZQ, int DER);
int main(){
	int i, j, NUMS[MAX], SALIR, NUM, AUX, MEDIO, BUS, RES;
	char OP, VAL_NUM[4];
	double IZQ , DER;
	do{
		system("cls");
		// Validamos el numero a ingresar al menu
  		do{
  			printf("Menu");
  			printf("\n\t1-. Llenar Matriz");
  			printf("\n\t2-. Busqueda Binaria");
  			printf("\n\t3-. Salir");
			do{
				printf("\nSelecciona una opcion : ");
				fflush(stdin);
				scanf("%s",VAL_NUM);
				NUM = validar_numero(VAL_NUM);
			}while(NUM == 0);
			
			OP = atoi(VAL_NUM);
			
			if(OP <= 0 || OP > 3){
					printf("\nDEBES INGRESAR UN NUMERO DE LAS OPCIONES DISPONIBLES\n\n");
				}
		} while(OP <=0 || OP > 3);
		
		//Menu
		switch (OP){
			case 1:
				//Cargamos la matriz + verificacion
				for(i = 0; i < MAX; ++i){
						do{
							do{
								printf("\nIngrese un numero > %d: ", i + 1);
								fflush(stdin);
								scanf("%s",VAL_NUM);
								NUM = validar_numero(VAL_NUM);
							}while(NUM == 0);
							
							NUMS[i] = atoi(VAL_NUM);
							
							if(NUMS[i] <= 0 || NUMS[i] > 1000){
									printf("\nSOLO PUEDES INGRESAR NUMEROS > 0 o < 1000");
								}
						} while(NUMS[i] <=0 || NUMS[i] > 1000);
				}
				//Ordenamos la matriz
				for (i = 0; i <= MAX -2; ++i){
					for (j = 0; j < MAX - 1; ++j){
						if(NUMS[j] > NUMS[j+1]){
							AUX = NUMS[j];
							NUMS[j] = NUMS[j+1];
							NUMS[j+1] = AUX;
						}
					}
				}
				system("pause");
				break;
			case 2:
				//Solicitamos numero a buscar
				do{
					system("cls");
					do{
						printf("\nQue numero desea buscar?: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					BUS = atoi(VAL_NUM);
					
					if(BUS <= 0 || BUS > 1000){
							printf("\nSOLO PUEDES INGRESAR NUMEROS > 0 o < 1000");
						}
				} while(BUS <=0 || BUS > 1000);
				
				//Busqueda Binaria
				IZQ = 0;
				DER = MAX;
				system("cls");
				for(i=0; i < MAX; ++i){
					MEDIO = floor((IZQ + DER) / 2);
					if(NUMS[MEDIO] == BUS){
						printf("[\t");
						for(i = 0; i < MAX; ++i){
							printf("%d\t", NUMS[i]);
						}
						printf("]\n");
						printf("El numero %d esta en la posicion %d del array.\n", BUS, MEDIO + 1);
						break;
					}
					if(BUS > NUMS[MEDIO]){
						IZQ = MEDIO;
					}
					if(BUS < NUMS[MEDIO]){
						DER = MEDIO;
					}
				}
				if(BUS != NUMS[MEDIO]){
					printf("No se encontro el numero %d.\n", BUS);
				}
				system("pause");
				break;
			case 3:
				SALIR = 3;
				break;
			default:
				printf("\nERROR - Ingrese una opcion valida\n");
				system("pause");
				break;
		}
	}while (SALIR != 3);
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
// FUNCION BUSQUEDA
int busqueda(int BUS, int IZQ, int DER){
	int i, NUMS[MAX];
	int MEDIO = floor((IZQ + DER) / 2);
	for(i=0; i < MAX; ++i){
		if(NUMS[MEDIO] == BUS){
			return 1;
			break;
		}
		if(BUS > NUMS[MEDIO]){
			IZQ = MEDIO;
		}
		if(BUS < NUMS[MEDIO]){
			DER = MEDIO;
		}
	}
	if(BUS != NUMS[MEDIO]){
		return 0;
	}
}