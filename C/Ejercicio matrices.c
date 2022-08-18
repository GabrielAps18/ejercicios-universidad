#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define MAX 100
//Arrays Unidimensionales y bidimensionales
int validar_numero(char VAL_NUM[]);
int main(){
	int ART[MAX][3], N_VEN, SUMA, i, j, k, V_VEN[MAX], NUM, MENOR, V_MENOR, REP = 0, V_REPS[5];
	char NOM[MAX][20], VAL_NUM[3];
	do{
		// DO WHILE para verificar si es valido el numero
		do{
			printf("\nCuantos vendedores desea registrar?: ");
			fflush(stdin);
			scanf("%s",VAL_NUM);
			NUM= validar_numero(VAL_NUM);
		}while(NUM == 0);
		
		//Insertamos el numero valido en la matriz
		N_VEN = atoi(VAL_NUM);
		
		//Confirmamos si el numero está en el rango solicitado
		if(N_VEN < 1 || N_VEN > 100){
			printf("\nDEBES INGRESAR UN NUMERO ENTRE 1 y 100");
		}
	} while(N_VEN < 1 || N_VEN > 100);
		
	// Carga de nombres
	for(i = 0; i < N_VEN; ++i){
		system("cls");
		printf("Ingrese el nombre del vendedor %d: ",i+1);
		scanf("%s", NOM[i]);
		SUMA = 0;
		for (j = 0; j < 3; ++j){
			
			do{
				// DO WHILE para verificar si es valido el numero
				do{
					printf("\nIngrese el numero de articulos vendidos: ");
					fflush(stdin);
					scanf("%s",VAL_NUM);
					NUM= validar_numero(VAL_NUM);
				}while(NUM == 0);
				
				//Insertamos el numero valido en la matriz
				ART[i][j] = atoi(VAL_NUM);
				
				//Confirmamos si el numero está en el rango solicitado
				if(ART[i][j] < 1 || ART[i][j] > 1000){
					printf("\nDEBES INGRESAR UN NUMERO ENTRE 1 y 1000");
				}
			} while(ART[i][j] < 1 || ART[i][j] > 1000);
			SUMA += ART[i][j];
		}
		V_VEN[i] = SUMA;
	}
	MENOR = V_VEN[0] + 1;
	for(i = 0; i < N_VEN; i++){
		if(V_VEN[i] == MENOR){
			V_REPS[REP] = i;
			++REP;
		}
		if(V_VEN[i] < MENOR){
			MENOR = V_VEN[i];
			V_MENOR = i;
			if(REP == 0){
				V_REPS[REP] = i;
				++REP;
			}else{
				for(j = 0; j < 5; j++){
					V_REPS[j] = 0;	
				}
				REP = 0;
			}
		}
	}
	
	//Imprimimos resultados
	system("cls");
	for(i = 0; i < N_VEN; ++i){
		printf("\n%s vendio: %d articulos.", NOM[i], V_VEN[i]);
	}
	if(REP > 0){
		printf("\nLos vendedores que menos vendieron con un total de %d: articulos son:", MENOR);
		for(i=0; i < REP; ++i){
			printf("\n%s", NOM[V_REPS[i]]);
		}
	}else{
		printf("\n\nEl vendedor que menos vendio fue %s con: %d articulos.", NOM[V_MENOR], MENOR);
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