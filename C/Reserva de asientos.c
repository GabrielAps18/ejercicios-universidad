#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define F 25
#define C 4
//Reserva de asientos - Gabriel Pacheco - 26/05/22 - 2do Parcial
int validar_numero(char VAL_NUM[]);
int main(){
	int i, j, k, ASIENTOS[F][C], OP, OCUP = 0, NUM, SALIR = 0, COL, FIL, N_ASI, COL_SEC[4], FIL_SEC[4], AUX[4], SELEC = 0, CON;
	char VAL_NUM[2];
	
	//Asignamos valores default a asientos
	for(i = 0; i < F; ++i){
		for(j = 0; j < C; ++j){
			if(OCUP == i){
				ASIENTOS[i][j] = 0;
				OCUP = 0;
			}else{
				ASIENTOS[i][j] = 1;
				OCUP = OCUP + 1;
			}
		}
	}
	
	do{
		system("cls");
		// Validamos el numero a ingresar al menu
  		do{
  			printf("Menu");
  			printf("\n\t1-. Seleccionar un asiento");
  			printf("\n\t2-. Cancelar reservacion de un asiento");
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
		
		// Menu
		switch (OP){
			//Seleccionar asientos
			case 1:
				system("cls");

				
				//Numero de asientos
				do{
					SELEC = 0;
					do{
						printf("\nSelecciona cuantos asientos deseas reservar (MAX 5): ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					N_ASI = atoi(VAL_NUM);
					
					if(N_ASI <= 0 || N_ASI > 5){
							printf("\nLo sentimos, solo puedes comprar de 1 a 5.\n");
						}
				} while(N_ASI <=0 || N_ASI > 5);
				
				
				
				do{
					printf("Asientos Disponibles: \n\n");
					for(k = 0; k <= 3; ++k){
						printf("\tC%d", k+1);
					}
					printf("\n");
					for(i = 0; i < F; ++i){
						printf("F%d", i+1);
						for(j = 0; j < C; ++j){
							printf("\t %d", ASIENTOS[i][j]);
						}
						printf("\n");
					}
					
					printf("\nQue asiento desea seleccionar?");
					
					//Escoger Fila
					do{
						do{
							printf("\nIngrese la FILA que desea escoger (solo numero): ");
							fflush(stdin);
							scanf("%s",VAL_NUM);
							NUM = validar_numero(VAL_NUM);
						}while(NUM == 0);
						
						FIL = atoi(VAL_NUM);
						
						if(FIL <= 0 || FIL > F){
								printf("\nSolo puedes escoger entre las columnas 1 y 25\n");
							}
					} while(FIL <=0 || FIL > F);
					
					
					//Escoger Columna
					do{
						do{
							printf("\nIngrese la COLUMNA que desea escoger (solo numero): ");
							fflush(stdin);
							scanf("%s",VAL_NUM);
							NUM = validar_numero(VAL_NUM);
						}while(NUM == 0);
						
						COL = atoi(VAL_NUM);
						
						if(COL <= 0 || COL > C){
								printf("\nSolo puedes escoger entre las columnas 1 y 4\n");
							}
					} while(COL <=0 || COL > C);
					
					
					if(ASIENTOS[FIL-1][COL-1] == 0){
						printf("\nLo sentimos, ese asiento no esta disponible, intenta con otro.");
						system("pause");
					} else {
						AUX[SELEC] = 1;
						COL_SEC[SELEC] = COL - 1;
						FIL_SEC[SELEC] = FIL - 1;
						ASIENTOS[FIL - 1][COL - 1] = 0;
						SELEC = SELEC + 1;
					}
					
				} while (SELEC != N_ASI);
				
				system("cls");
				printf("\n\tEscogiste los siguientes asientos: \n");
				for(i = 0; i < N_ASI; ++i){
					printf("\tF%d C%d", FIL_SEC[i] + 1, COL_SEC[i] + 1);					
				}
				printf("\n");
				
				printf("\n\tCONFIRMACION DE RESERVACION: \n ");
				printf("\n\t1-. CONFIRMAR");
				printf("\n\t2-. CANCELAR");
				// Validamos el numero a ingresar al menu
		  		do{
					do{
						printf("\nSelecciona una opcion : ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					OP = atoi(VAL_NUM);
					
					if(OP <= 0 || OP > 2){
							printf("\nDEBES INGRESAR UN NUMERO DE LAS OPCIONES DISPONIBLES\n\n");
						}
				} while(OP <=0 || OP > 2);
				switch(OP){
					case 1:
						printf("\nRESERVACION REALIZADA EXITOSAMENTE\n");
						break;
					case 2:
						printf("\nSE HAN CANCELADO LA RESERVACION Y LOS ASIENTOS QUEDAN DISPONIBLES NUEVAMENTE\n");
						for(i = 0; i < N_ASI; ++i){
							ASIENTOS[FIL_SEC[i]][COL_SEC[i]] = 1;
						}
						break;
				}
				
				system("pause");
				break;
			case 2:
				do{
					system("cls");
					
					printf("Lista de asientos: \n\n");
						for(k = 0; k <= 3; ++k){
							printf("\tC%d", k+1);
						}
						printf("\n");
						for(i = 0; i < F; ++i){
							printf("F%d", i+1);
							for(j = 0; j < C; ++j){
								printf("\t %d", ASIENTOS[i][j]);
							}
							printf("\n");
						}
					
					//Escoger Fila
						do{
							do{
								printf("\nIngrese la FILA del asiento (solo numero): ");
								fflush(stdin);
								scanf("%s",VAL_NUM);
								NUM = validar_numero(VAL_NUM);
							}while(NUM == 0);
							
							FIL = atoi(VAL_NUM);
							
							if(FIL <= 0 || FIL > F){
									printf("\nSolo puedes escoger entre las columnas 1 y 25\n");
								}
						} while(FIL <=0 || FIL > F);
					
					//Escoger Columna
						do{
							do{
								printf("\nIngrese la COLUMNA que desea escoger (solo numero): ");
								fflush(stdin);
								scanf("%s",VAL_NUM);
								NUM = validar_numero(VAL_NUM);
							}while(NUM == 0);
							
							COL = atoi(VAL_NUM);
							
							if(COL <= 0 || COL > C){
									printf("\nSolo puedes escoger entre las columnas 1 y 4\n");
								}
						} while(COL <=0 || COL > C);
					
					if(ASIENTOS[FIL-1][COL-1] == 1){
							printf("\nERROR - ESE ASIENTO NO TIENE RESERVACION\n");
							system("pause");
						} else {
							ASIENTOS[FIL-1][COL-1] = 1;
							printf("\n ASIENTO F%d C%d CANCELADO...\n", FIL, COL);
					}
					
					do{
			  			printf("\n1-.Cancelar otra reservacion");
			  			printf("\n2-.Salir");
						do{
							printf("\nSelecciona una opcion : ");
							fflush(stdin);
							scanf("%s",VAL_NUM);
							NUM = validar_numero(VAL_NUM);
						}while(NUM == 0);
						
						CON = atoi(VAL_NUM);
						
						if(CON <= 0 || CON > 2){
								printf("\nDEBES INGRESAR UN NUMERO DE LAS OPCIONES DISPONIBLES\n\n");
							}
					} while(CON <=0 || CON > 2);	
						
						
				} while (CON != 2);
				break;
			case 3:
				printf("\n");
				system("pause");
				SALIR = 3;
				break;
			default:
				printf("ERROR - LA OPCION QUE INGRESO NO EXISTE!");
				break;
		}
	} while(SALIR != 3);
	
}
//FUNCION PARA VALIDAR NUMEROS POSITIVOS ENTEROS
int validar_numero(char VAL_NUM[]){
	int i, punto = 0;
	for (i = 0; i < strlen(VAL_NUM); ++i){
		if(!(isdigit(VAL_NUM[i]))){
			if(VAL_NUM[i] == '.'){
				if(punto > 1){
					printf("\nDebes ingresar un numero ENTERO valido");
					return 0;	
				}else punto = punto + 1;
			}else{
				printf("\nNO PUEDES INGRESAR LETRAS");
				return 0;
			}
		}
	}
	return 1;
}