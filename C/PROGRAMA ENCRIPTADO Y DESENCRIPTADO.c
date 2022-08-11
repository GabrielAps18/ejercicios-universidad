/*
	Programa para encriptar y desencriptar mensajes por matrices
	Programa elaborado por Gabriel Pacheco 14/07/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Declaracion de funciones
int validar_letra(char VAL_LET[]);

int main(){
	//Declaramos variables
	char codigos[27] = { ' ' ,'A' , 'B' , 'C' , 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'W', 'X', 'Y', 'Z', '.'};
	char mensaje[27], msj_copia[27];
	int i, j, k, l, a, tam, num;
	int msj_num[9][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	do{
		system("cls");
		printf("Ingrese su mensaje a encriptar: ");
		fgets(mensaje, 27, stdin);
		strtok(mensaje, "\n");
		num = validar_letra(mensaje);
	}while(num == 0);
	
	//Creamos una copia del mensaje
	for(i = 0; i <= strlen(mensaje); i++) msj_copia[i] = mensaje[i];
	for(i = 0; i <= strlen(mensaje); i++) mensaje[i] = toupper(mensaje[i]);
	
	//Calculamos los vectores que necesitamos
	tam = strlen(mensaje) / 3;
	if((strlen(mensaje) % 3) != 0) tam = tam + 1;
	
	//Convertimos los caracteres a numeros e ingresamos a la matriz
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	a = 0;
	for(i = 0; i <= (tam - 1); i++){
		for(j = 0; j <= 2; j++){
			for(k = a; k <= (strlen(mensaje)); k++){
				for(l = 0; l <= 26; l++){
					if(mensaje[k] == codigos[l]){
						msj_num[i][j] = l;
						a++;
						break;
					}
				}
				/*if(a == strlen(mensaje)  ){
					msj_num[i][j] = 0;
				}*/
				break;	
			}
		}
	}
	a = 0;
	for(i = 0; i <= (tam - 1); i++){
		for(j = 0; j <= 2; j++){
			printf("%d ", msj_num[i][j]);
		}
		printf("\n");
	}
	
	//Realizamos multiplicacion de matrices
	for(i = 0; i <= (tam - 1); i++){
		for(j = 0; j <= 2; j++){
			printf("%d ", msj_num[i][j]);
		}
	}
	
	
	//printf("%s %d", mensaje, tam);
	//printf("\n%s", msj_copia);

}//FIN

//FUNCION PARA VALIDAR LETARS
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