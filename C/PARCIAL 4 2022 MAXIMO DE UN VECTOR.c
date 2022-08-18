/*
	Programa que calcule el maximo de un vector
	Elaborado por Gabriel Pacheco 12/07/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int validar_numero(char VAL_NUM[]);
void encontrar(int numeros[]);
int main(){
	int nums[10], op, salir, num, i, *p, aux, aux1;
	char VAL_NUM[3];
	
	do{
		do{
			system("cls");
			printf("\n\t\tMenu");
			printf("\n\t1-.Encontrar maximo de un vector");
			printf("\n\t2-.Salir");
			printf("\n\nIngrese su opcion: ");
			//fflush(stdin);
			//scanf("%s",VAL_NUM);
			fgets(VAL_NUM, 10, stdin);
			strtok(VAL_NUM, "\n");
			num = validar_numero(VAL_NUM);
		}while(num == 0);
		op = atoi(VAL_NUM);
		
		switch(op){
			case 1:
				for(i = 0; i <= 9; i++){
					again:
					do{
						system("cls");
						printf("Ingresa el numero %d: ", i+1);
						fgets(VAL_NUM, 10, stdin);
						strtok(VAL_NUM, "\n");
						num = validar_numero(VAL_NUM);
					}while(num == 0);
					
					nums[i] = atoi(VAL_NUM);
					
					if(nums[i] < 0 || nums[i] >= 1000){
						printf("\n\tERROR - Solo puede ingresar numeros de 0 a 999\n\n");
						system("pause");
						goto again;
					}
				}
					//Calculamos el maximo con puntero P
					p = nums;
					
					for(i=0; i<=9;i++){
						if(aux < *p){
							aux = *p;
							aux1 = i+1;
						}
						*p++;
					} 
					system("cls");
					printf("\n\tEl numero maximo es %d y se encuentra en la posicion %d del vector\n\n", aux, aux1);
					
					
					system("pause");
				break;
			case 2:
				salir = 2;
				printf("\n\tGRACIAS POR USAR EL PROGRAMA\n");
				system("pause");
				break;
			default:
				printf("\nERROR - Debe ingresar una opcion valida\n");
				system("pause");
		}
	}while(salir != 2);
}

//FUNCION PARA VALIDAR NUMEROS POSITIVOS ENTEROS
int validar_numero(char VAL_NUM[]){
	int i;
	for (i = 0; i < strlen(VAL_NUM); ++i){
		if(!(isdigit(VAL_NUM[i]))){
			if(isalpha(VAL_NUM[i])){
				printf("\nERROR - No puedes ingresar LETRAS\n\n");
				system("pause");
				return 0;
			}
			if(VAL_NUM[i] == '.'){
				printf("\nERROR - No puedes ingresar PUNTOS\n\n");
				system("pause");
				return 0;
			}
			if(VAL_NUM[0] == '-'){
				printf("\nERROR - No puedes ingresar NUMEROS NEGATIVOS\n\n");
				system("pause");
				return 0;
			}
			if(VAL_NUM[i] == 32){
				printf("\nERROR - No puedes ingresar ESPACIOS\n\n");
				system("pause");
				return 0;
			}
			printf("\nNo puedes ingresar SIMBOLOS\n\n");
			system("pause");
			return 0;
		}
	}
	return 1;
}

/*void encontrar(int numeros[]){
	int aux = 0, aux1;
	int i, j;
	for(i = 0; i<= 5; i++){
		for(j = 0; j <=10; j++){
			if(aux < numeros[j]){
				aux = numeros[j];
				aux1 = j + 1;
			}
		}
	}
	printf("\n\tEl numero maximo es %d y se encuentra en la posicion %d\n\n", aux, aux1);
}*/