#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 5
//Busqueda Binaria
int validar_numero(char VAL_NUM[]);
int main(){
	int i, j, NUMS[MAX], SALIR, NUM, AUX, MEDIO, BUS;
	double IZQ , DER;
	char OP, VAL_NUM[3], NOMS[20][20]={'G','a','b','r', 'i', 'e', 'l'};
	do{
		system("cls");
		printf("1-. Busqueda Binaria de un numero.");
		printf("\n2-. Busqueda Binaria de una letra.");
		printf("\n3-. Salir");
		printf("\nSeleccione una opcion: ");
		fflush(stdin);
		OP = getchar();
		switch (OP){
			case '1':
				//Cargamos la matriz + verificacion
				for(i = 0; i < MAX; ++i){
					do{
						do{
							printf("\nIngrese un numero > 0: ");
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
						printf("El numero %d esta en la posicion %d del vector.\n", BUS, MEDIO + 1);
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
			case '2':
				break;
			case '3':
				SALIR =3;
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