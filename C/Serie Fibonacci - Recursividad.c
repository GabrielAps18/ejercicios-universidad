#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Calcular serie fibunacci de dos numeros
int validar_numero(char VAL_NUM[]);
//long fibonacci(long FIB);
int main(){
	int i, REP, NUM, SALIR;
	long FIB, FIB1, FIB2;
	char VAL_NUM[4], OP;
	//Menu
	do{
		system("cls");
		printf("1-. Serie Fibonacci a partir de un numero.");
		printf("\n2-. Serie Fibonacci a partir de dos numeros.");
		printf("\n3-. Salir");
		printf("\nSeleccione una opcion: ");
		fflush(stdin);
		OP = getchar();
		switch(OP){
			case '1':
				//Solicitamos primer numero de la serie
				do{
					do{
						printf("\nIngresa el primer numero de la serie: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					FIB1 = atoi(VAL_NUM);
					if(FIB1 <= 0 || FIB1 > 1000){
							printf("\nSOLO PUEDES INGRESAR NUMEROS > 0 o < 1000");
						}
				} while(FIB1 <=0 || FIB1 > 1000);
				
				//Solicitamos cuantos numeros desea obtener
				do{
					do{
						printf("\nCuantos numeros de la serie desea obtener?: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					REP = atoi(VAL_NUM);
					
					if(REP <= 0 || REP > 100){
							printf("\nEl maximo de numeros que puedes obtener es 100");
						}
				} while(REP <=0 || REP > 100);
	
				for(i = 0; i < REP; ++i){
					FIB2 = FIB2 + FIB1;
					printf("\n%lli", FIB2);
					FIB1 = FIB2 - FIB1;
				}
				system("pause");
				break;
			case '2': // Fibonacci con dos numeros especificos
				//Solicitamos primer numero
				do{
					do{
						printf("\nIngresa el primer numero: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					FIB1 = atoi(VAL_NUM);
					if(FIB1 <= 0 || FIB1 > 1000){
							printf("\nSOLO PUEDES INGRESAR NUMEROS > 0 o < 1000");
						}
				} while(FIB1 <=0 || FIB1 > 1000);
				
				//Solicitamos segundo numero
				do{
					do{
						printf("\nIngresa el segundo numero: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					FIB2 = atoi(VAL_NUM);
					
					if(FIB2 <= 0 || FIB2 > 1000){
							printf("\nSOLO PUEDES INGRESAR NUMEROS > 0 o < 1000");
						}
				} while(FIB2 <=0 || FIB2 > 1000);
				
				//Solicitamos cuantos numeros desea obtener
				do{
					do{
						printf("\nCuantos numeros de la serie desea obtener?: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					REP = atoi(VAL_NUM);
					
					if(REP <= 0 || REP > 100){
							printf("\nEl maximo de numeros que puedes obtener es 100");
						}
				} while(REP <=0 || REP > 100);
				
				// Imprimimos la serie
				printf("%lli", FIB1);
				for(i = 0; i < REP; ++i){
					printf("\n%lli", FIB2);
					FIB2 = FIB2 + FIB1;
					FIB1 = FIB2 - FIB1;
				}
				system("pause");
				break;
			case '3':
				SALIR = 3;
				system("pause");
				break;
			default:
				printf("ERROR - Ingrese una opcion valida");
		}
	}while(SALIR != 3);
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
/*
//FUNCION SERIE FIBUNACCI A PARTIR DE UN NUMERO
long fibonacci(long FIB){
	if (FIB <= 1){
		return 1;
	}else{
		return (fibonacci(FIB - 1) + fibonacci(FIB - 2));
	}
		
}*/