/*
	Programa que convierta las iniciales de las palabras a MAYUSCULAS
	Elaborado por Gabriel Pacheco 12/07/2022	
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Declaracion de funciones
int validar_letra(char VAL_LET[]);
int validar_numero(char VAL_NUM[]);
void m(char mensaje[]);

int main(){
	int i, num, op, salir, a=0;
	char mensaje2[50], mensaje1[1] = {'a'}, VAL_NUM[10], *p;
	do{
		do{
			system("cls");
			printf("\n\t\tMenu");
			printf("\n\t1-.Conversion de mensaje");
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
				do{
					system("cls");
					printf("Ingrese su mensaje: ");
					fgets(mensaje2, 50, stdin);
					strtok(mensaje2, "\n");
					num = validar_letra(mensaje2);
				}while(num == 0);
				for(i=0;i<=strlen(mensaje2);i++){
					mensaje2[i] = tolower(mensaje2[i]);
				}
				m(mensaje2);
				p = mensaje1;
				for(i=0; i <= a; i++){
					if(i=0){
						*p = toupper(*p);
					}
					if(*p+i == 32){
						*p+i;
						*p= toupper(*p);
					}else{
						p++;
					}					
				}
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

//FUNCION PARA VALIDAR LETRAS
int validar_letra(char VAL_LET[]){
	int i;
	for (i = 0; i < strlen(VAL_LET); ++i){
		if(!(isalpha(VAL_LET[i]))){
			if(isdigit(VAL_LET[i])){
				printf("\nERROR - No puedes usar NUMEROS\n\n");
				system("pause");
				return 0;
			}
			
			if(VAL_LET[i] == 32){
				
			}else{
				printf("\nERROR - No puedes usar SIMBOLOS\n\n");
				system("pause");
				return 0;
			}
		}
	}
	return 1;
}
//
void m(char mensaje[]){
	int i;
	for(i = 0; i <= strlen(mensaje); i++){
		mensaje[0] = toupper(mensaje[0]);
		if(mensaje[i] == 32){
			mensaje[i+1] = toupper(mensaje[i+1]);
		}
	}
	system("cls");
	printf("\n\t%s\n\n", mensaje);
	system("pause");

}