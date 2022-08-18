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
int validar_numero(char VAL_NUM[]);
int main(){
	//Declaramos variables
	char codigos[27] = { ' ' ,'A' , 'B' , 'C' , 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char mensaje[27], msj_copia[27], VAL_NUM[10];
	int i, j, k, l, a, tam, num, sum, aa, op, num1, salir, car;
	int msj_num[9][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int m_cod[3][3] = {{1, -1, 0}, {0, 1, 0}, {2, 0, 1}};
	int m_dec[3][3] = {{1, 1, 0}, {0, 1, 0}, {-2, -2, 1}};
	
	
	do{
		do{
			for(i = 0; i <= 8; i++){
				for(j = 0; j <= 2; j++){
					msj_num[i][j] = 0;
				}
			}
			system("cls");
			printf("\n\t\tMenu");
			printf("\n\t1-.Encriptar mensaje");
			printf("\n\t2-.Desencriptar mensaje");
			printf("\n\t3-.Salir");
			printf("\n\nIngrese su opcion: ");
			fgets(VAL_NUM, 10, stdin);
			strtok(VAL_NUM, "\n");
			num = validar_numero(VAL_NUM);
		}while(num == 0);
		op = atoi(VAL_NUM);
	
		switch(op){
			case 1:
				do{
					system("cls");
					printf("\n\tIngrese su mensaje a encriptar: ");
					fgets(mensaje, 27, stdin);
					strtok(mensaje, "\n");
					num = validar_letra(mensaje);
				}while(num == 0);
				
				//Creamos una copia del mensaje
				for(i = 0; i <= strlen(mensaje); i++) msj_copia[i] = tolower(mensaje[i]);
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
							break;	
						}
					}
				}
				
				system("cls");
				printf("\n\tEl codigo del mensaje (sin encriptar) es: ");
				//Imprimimos codigo de mensaje
				for(i = 0; i <= (tam - 1); i++){
					for(j = 0; j <= 2; j++){
						printf("%d ", msj_num[i][j]);
					}
				}
				printf("\n\n");
				
				//Multiplicamos por la matriz para encriptar
				a = 0;
				do{
					aa = (msj_num[a][0] * m_cod[0][1]) + (msj_num[a][1] * m_cod[1][1]) + (msj_num[a][2] * m_cod[2][1]);
					msj_num[a][0] = (msj_num[a][0] * m_cod[0][0]) + (msj_num[a][1] * m_cod[1][0]) + (msj_num[a][2] * m_cod[2][0]);
					msj_num[a][1] = aa;
					msj_num[a][2] = (msj_num[a][0] * m_cod[0][2]) + (msj_num[a][1] * m_cod[1][2]) + (msj_num[a][2] * m_cod[2][2]);
					
					a++;
				} while(a != tam);
				
				printf("\n\tEl mensaje encriptado es: ");
				//Imprimimos mensaje encriptado
				for(i = 0; i <= (tam - 1); i++){
					for(j = 0; j <= 2; j++){
						printf("%d ", msj_num[i][j]);
					}
				}
				printf("\n\n");
				system("pause");
				
				break;
			case 2:
				tam = 0;
				car = 0;
				do{
					do{
						system("cls");
						printf("\n\nCuantos caracteres desea desencriptar (3 a 27): ");
						fgets(VAL_NUM, 10, stdin);
						strtok(VAL_NUM, "\n");
						num = validar_numero(VAL_NUM);
					}while(num == 0);
					car = atoi(VAL_NUM);
					
					if(car < 3 || car > 27){
						printf("\n\tERROR - Debe ingresar un numero valido (3 a 27)\n\n");
						system("pause");
						
					}
				}while(car < 3 || car > 27);
				
				//Calculamos los vectores que necesitamos
				tam = car / 3;
				if((car % 3) != 0) tam = tam + 1;
				
				k = 0;
				for(i = 0; i <= (tam - 1); i++){
					for(j = 0; j <= 2; j++){
						do{
							system("cls");
							k++;
							printf("\n\nIngrese el caracter encriptado numero %d: ", k);
							fgets(VAL_NUM, 10, stdin);
							strtok(VAL_NUM, "\n");
							num = validar_numero(VAL_NUM);
						}while(num == 0);
						msj_num[i][j] = atoi(VAL_NUM);
					}
				}
				//
				a = 0;
				do{
					aa = (msj_num[a][0] * m_dec[0][1]) + (msj_num[a][1] * m_dec[1][1]) + (msj_num[a][2] * m_dec[2][1]);
					msj_num[a][0] = (msj_num[a][0] * m_dec[0][0]) + (msj_num[a][1] * m_dec[1][0]) + (msj_num[a][2] * m_dec[2][0]);
					msj_num[a][1] = aa;
					msj_num[a][2] = (msj_num[a][0] * m_dec[0][2]) + (msj_num[a][1] * m_dec[1][2]) + (msj_num[a][2] * m_dec[2][2]);
					
					a++;
				} while(a != tam);
				
				//Convertimos los numeros a caracteres e ingresamos a la matriz
				i = 0;
				j = 0;
				a = 0;
				for(i = 0; i <= (tam - 1); i++){
					for(j = 0; j <= 2; j++){
						mensaje[a] = codigos[msj_num[i][j]];
						a++;	
					}
				}
				for(i = 0; i <= strlen(mensaje); i++) mensaje[i] = tolower(mensaje[i]);
				mensaje[0] = toupper(mensaje[0]);
				
				
				printf("\n\tEl mensaje desencriptado es: %s", mensaje);
				
				//
				printf("\n\n");
				system("pause");
				break;
			case 3:
				salir = 4;
				printf("\n\tGRACIAS POR USAR EL PROGRAMA\n");
				system("pause");
				break;
			default:
				printf("\nERROR - Debe ingresar una opcion valida\n");
				system("pause");
		}
				
	}while(salir != 4);
				system("cls");
	
	do{
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
				break;	
			}
		}
	}

	//Multiplicamos por la matriz para encriptar
	a = 0;
	do{
		aa = (msj_num[a][0] * m_cod[0][1]) + (msj_num[a][1] * m_cod[1][1]) + (msj_num[a][2] * m_cod[2][1]);
		msj_num[a][0] = (msj_num[a][0] * m_cod[0][0]) + (msj_num[a][1] * m_cod[1][0]) + (msj_num[a][2] * m_cod[2][0]);
		msj_num[a][1] = aa;
		msj_num[a][2] = (msj_num[a][0] * m_cod[0][2]) + (msj_num[a][1] * m_cod[1][2]) + (msj_num[a][2] * m_cod[2][2]);
		
		a++;
	} while(a != tam);
	a = 0;
	
	printf("\n");
	printf("\n");
	for(i = 0; i <= (tam - 1); i++){
		for(j = 0; j <= 2; j++){
			printf("%d ", msj_num[i][j]);
		}
		printf("\n");
	}

	do{
		aa = (msj_num[a][0] * m_dec[0][1]) + (msj_num[a][1] * m_dec[1][1]) + (msj_num[a][2] * m_dec[2][1]);
		msj_num[a][0] = (msj_num[a][0] * m_dec[0][0]) + (msj_num[a][1] * m_dec[1][0]) + (msj_num[a][2] * m_dec[2][0]);
		msj_num[a][1] = aa;
		msj_num[a][2] = (msj_num[a][0] * m_dec[0][2]) + (msj_num[a][1] * m_dec[1][2]) + (msj_num[a][2] * m_dec[2][2]);
		
		a++;
	} while(a != tam);
	
	printf("\n");
	printf("\n");
	for(i = 0; i <= (tam - 1); i++){
		for(j = 0; j <= 2; j++){
			printf("%d ", msj_num[i][j]);
		}
		printf("\n");
	}
	
	//Convertimos los numeros a caracteres e ingresamos a la matriz
	i = 0;
	j = 0;
	a = 0;
	for(i = 0; i <= (tam - 1); i++){
		for(j = 0; j <= 2; j++){
			mensaje[a] = codigos[msj_num[i][j]];
			a++;	
		}
	}
	for(i = 0; i <= strlen(mensaje); i++) mensaje[i] = tolower(mensaje[i]);
	mensaje[0] = toupper(mensaje[0]);
	
	
	
	printf("\n\n%s", mensaje);
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
			if(VAL_NUM[i] == 32){
				printf("\nERROR - No puedes ingresar ESPACIOS\n\n");
				system("pause");
				return 0;
			}
			if(VAL_NUM[0] == '-' && isdigit(VAL_NUM[i+1])){
				
			}else{
				printf("\nNo puedes ingresar SIMBOLOS\n\n");
				system("pause");
				return 0;
			}
			
		}
	}
	return 1;
}