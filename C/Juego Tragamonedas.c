#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//
void validar_op();
int validar_numero(char VAL_NUM[]);
int formas(int RANDOM);
int NUM, OP;
char VAL_NUM[4];

int main (){
	int i, j, BUS, SALIR, RANDOM, VECES;
	float DINERO, DIN_JUGADO, DIF_DINERO, DIN_MAQUINA;
	char  ICON1, ICON2, ICON3, ICON4;
	
	
	do{
		DINERO = 0;
		DIN_MAQUINA = 0;
		system("cls");
		
		//Numero de jugadores o partidas jugadas
		FILE * JUGADORES = fopen("D:/jugadores.txt", "rb");
		
		int NUM_JUG;
		while(feof(JUGADORES) == 0){
			fscanf(JUGADORES, "%d", &NUM_JUG);
			NUM_JUG += 1;
		}
		fclose(JUGADORES);
		// Validamos el numero a ingresar al menu
  		do{
  			printf("%d\n", NUM_JUG);
  			printf("Menu");
  			printf("\n\t1-. Jugar");
  			printf("\n\t2-. Registro de jugadas");
  			printf("\n\t3-. Salir");
			
			validar_op();
			
		} while(OP <=0 || OP > 3);
		
		// Menu
		switch (OP){
			//Seleccionar asientos
			case 1:
				DIF_DINERO = 0;
				DIN_JUGADO = 0;
				system("cls");
				//Ingresar dinero
				recarga:
				do{
					system("cls");
					do{
						printf("\nIngrese su dinero para jugar (1000$ MAX): ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					DINERO = DINERO + atoi(VAL_NUM);
					
					if(DINERO <= 4 || DINERO > 1000){
							printf("\nDEBES INGRESAR UN MONTO ENTRE 5$ Y 1000$\n\n");
							system("pause");
						}
				} while(DINERO <=4 || DINERO > 1000);
				
				//Ingresar veces que desea jugar
				recarga_veces:
				do{
					system("cls");
					do{
						printf("\nCuantas veces desea jugar? ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					VECES = atoi(VAL_NUM);
					
					if(VECES <= 0 || VECES > 10){
							printf("\nPUEDES JUGAR ENTRE 1 a 10 VECES\n\n");
							system("pause");
						}
				} while(VECES <=0 || VECES > 10);
				

				// Random symbols
				do{
					continuar:
					system("cls");
					do{
			  			printf("Cada jugada tiene un costo del 50 porciento de su Dinero restante - Costo minimo por jugada: 2.5$\n\n");
						printf("\t\tDinero Restante: %.2f$					Jugadas Restantes: %d", DINERO, VECES);
						printf("\n\n\t\t\t   'Pulse 1 para accionar la palanca o 2 para retirarse'");
						validar_op();
						
					} while(OP <=0 || OP > 2);
					
					switch (OP){
						case 1:
							system ("cls");
							if(DINERO / 2 < 2.5){
								do{
									printf("\n\t Dinero insuficiente!!!\n\n\t");
									printf("Pulse 1 para recargar o 2 para retirarse\n");
									validar_op();
									if(OP <= 0 || OP >2){
										printf("\n\nERROR - INGRESE UNA OPCION VALIDA!!!\n\n");
										system("cls");
									}
								} while (OP <= 0 || OP >2);
								if (OP == 1){
									goto recarga;
								}
								if(OP == 2){
									goto salir;
								}
							}
							if(VECES == 0){
								do{
									printf("\n\t No tiene jugadas restantes!!!\n\n\t");
									printf("Pulse 1 para recargar sus jugadas o 2 para retirarse\n");
									validar_op();
									if(OP <= 0 || OP >2){
										printf("\n\nERROR - INGRESE UNA OPCION VALIDA!!!\n\n");
										system("cls");
									}
								} while (OP <= 0 || OP >2);
								if (OP == 1){
									goto recarga_veces;
								}
								if(OP == 2){
									goto salir;
								}
							}
								DINERO = DINERO / 2;
								DIN_MAQUINA = DIN_MAQUINA + DINERO;
								DIN_JUGADO = DINERO + DIN_JUGADO;
								DIF_DINERO = DIF_DINERO - DINERO;
								VECES = VECES - 1;
								for (i = 0; i <= 6; i++){
									Sleep(400);
									ICON1 = formas(RANDOM = rand() % 8);
									ICON2 = formas(RANDOM = rand() % 8);
									ICON3 = formas(RANDOM = rand() % 8);
									ICON4 = formas(RANDOM = rand() % 8);						

									system("cls");
									printf("\n \t>>>>>> %c %c %c %c <<<<<<\n", ICON1, ICON2, ICON3, ICON4);
								}
								if(ICON1 == ICON2 && ICON2 == ICON3 && ICON3 == ICON4){
									if(DIN_MAQUINA < (DINERO * 3)){
										
										ICON1 = 3;
										ICON2 = 4;
										ICON3 = 5;
										ICON4 = 6;
										system("cls");
										printf("\n \t>>>>>> %c %c %c %c <<<<<<\n", ICON1, ICON2, ICON3, ICON4);
										printf("\nOH VAYA... HAZ PERDIDO\n\n");
										system("pause");
										goto continuar;
									}else{
										printf("\nFELICIDADES! TODAS LAS FIGURAS SON IGUALES! HAZ GANADO UN x3 DE TU APUESTA\n\n");
										DIF_DINERO = DIF_DINERO + (DINERO * 3);
										DIN_MAQUINA = DIN_MAQUINA - (DINERO *3);
										DINERO = DINERO + (DINERO * 3);
										system("pause");
										goto continuar;
										
									}
								}
								if(ICON2 == ICON3 && ICON2 == ICON4){
									if(DIN_MAQUINA < (DINERO * 2)){
										ICON1 = 4;
										ICON2 = 3;
										ICON3 = 5;
										ICON4 = 6;
										system("cls");
										printf("\n \t>>>>>> %c %c %c %c <<<<<<\n", ICON1, ICON2, ICON3, ICON4);
										printf("\nOH VAYA... HAZ PERDIDO\n\n");
										system("pause");
										goto continuar;
									}else{
										printf("\nFELICIDADES! TRES FIGURAS SON IGUALES! HAZ GANADO UN x2 DE TU APUESTA\n\n");
										DIF_DINERO = DIF_DINERO + (DINERO * 2);
										DIN_MAQUINA = DIN_MAQUINA - (DINERO *2);
										DINERO = DINERO + (DINERO * 2);
										system("pause");
										goto continuar;
									}
								}
								if(ICON1 == ICON3 && ICON1 == ICON4){
									if(DIN_MAQUINA < (DINERO * 2)){
										ICON1 = 3;
										ICON2 = 4;
										ICON3 = 6;
										ICON4 = 5;
										system("cls");
										printf("\n \t>>>>>> %c %c %c %c <<<<<<\n", ICON1, ICON2, ICON3, ICON4);
										printf("\nOH VAYA... HAZ PERDIDO\n\n");
										system("pause");
										goto continuar;
									}else{
										printf("\nFELICIDADES! TRES FIGURAS SON IGUALES! HAZ GANADO UN x2 DE TU APUESTA\n\n");
										DIF_DINERO = DIF_DINERO + (DINERO * 2);
										DIN_MAQUINA = DIN_MAQUINA - (DINERO *2);
										DINERO = DINERO + (DINERO * 2);
										system("pause");
										goto continuar;
									}
								}
								if(ICON1 == ICON2 && ICON1 == ICON4){
									if(DIN_MAQUINA < (DINERO * 2)){
										ICON1 = 4;
										ICON2 = 3;
										ICON3 = 6;
										ICON4 = 5;
										system("cls");
										printf("\n \t>>>>>> %c %c %c %c <<<<<<\n", ICON1, ICON2, ICON3, ICON4);
										printf("\nOH VAYA... HAZ PERDIDO\n\n");
										system("pause");
										goto continuar;
									}else{
										printf("\nFELICIDADES! TRES FIGURAS SON IGUALES! HAZ GANADO UN x2 DE TU APUESTA\n\n");
										DIF_DINERO = DIF_DINERO + (DINERO * 2);
										DIN_MAQUINA = DIN_MAQUINA - (DINERO *2);
										DINERO = DINERO + (DINERO * 2);
										system("pause");
										goto continuar;
									}
								}
								if(ICON1 == ICON2 && ICON1 == ICON3){
									if(DIN_MAQUINA < (DINERO * 2)){
										ICON1 = 6;
										ICON2 = 5;
										ICON3 = 4;
										ICON4 = 3;
										system("cls");
										printf("\n \t>>>>>> %c %c %c %c <<<<<<\n", ICON1, ICON2, ICON3, ICON4);
										printf("\nOH VAYA... HAZ PERDIDO\n\n");
										system("pause");
										goto continuar;
									}else{
										printf("\nFELICIDADES! TRES FIGURAS SON IGUALES! HAZ GANADO UN x2 DE TU APUESTA\n\n");
										DIF_DINERO = DIF_DINERO + (DINERO * 2);
										DIN_MAQUINA = DIN_MAQUINA - (DINERO *2);
										DINERO = DINERO + (DINERO * 2);
										system("pause");
										goto continuar;
									}
								}
								printf("\nOH VAYA... HAZ PERDIDO\n\n");
								
							system("pause");
							goto continuar;
							system("pause");
							break;
						case 2:
							salir: ;
							//Acutalizar jugador	
							FILE * JUGADORES = fopen("D:/jugadores.txt", "w");
							fprintf(JUGADORES, "%d", NUM_JUG);
							fflush(JUGADORES);
							fclose(JUGADORES);
								
							SALIR = 4;
							system("cls");
							printf("\n\t\t Gracias por jugar\n\n");
							printf("\t Usted se esta retirando con %.2f$\n\n\t", DINERO);
							system("pause");
							break;
						default:
							printf("ERROR - LA OPCION QUE INGRESO NO EXISTE!");
							break;
					}
					
				} while (SALIR != 4);
				break;
			case 3:
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
	int i;
	for (i = 0; i < strlen(VAL_NUM); ++i){
		if(!(isdigit(VAL_NUM[i]))){
				printf("\nDebes ingresar un numero ENTERO valido");
			return 0;
		}
	}
	return 1;
}
//Funcion Random + Clasificar numeros
int formas(int RANDOM){
	if(RANDOM == 0 || RANDOM == 1){
		return 3;			
	}
	if(RANDOM == 2 || RANDOM == 3){
		return 4;			
	}
	if(RANDOM == 4 || RANDOM == 5){
		return 5;			
	}
	if(RANDOM == 6 || RANDOM == 7){
		return 6;			
	}
}
//Funcion para validar OP de Menus
void validar_op(){
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
}
