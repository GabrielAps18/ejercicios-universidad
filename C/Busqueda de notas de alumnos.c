#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 3
//
int validar_numero(char VAL_NUM[]);
int main(){
	int OP, i, j, punto, NUM, BUS;
	float NOTAS[20], SUMA = 0, MEDIA = 0;
	char VAL_NUM[3], NOM_ALUMS[MAX][50], ALUM[MAX];
	
	//Solicitamos los nombres de los alumnos
	for(i = 0; i < MAX; ++i){
		printf("\nIngrese el nombre del alumno %d: ", i+1);
		fflush(stdin);
		gets(NOM_ALUMS[i]);
		
		//Ordenamos las letras de los nombres y apellidos
		for(j = 0; j < strlen(NOM_ALUMS[i]); j++){
   			NOM_ALUMS[i][j] = tolower(NOM_ALUMS[i][j]);
   			if(j == 0){
   				NOM_ALUMS[i][j] = toupper(NOM_ALUMS[i][j]);
			}
			if(j > 0 && NOM_ALUMS[i][j-1] == ' '){
				NOM_ALUMS[i][j] = toupper(NOM_ALUMS[i][j]);
			}
		}
		
		//Solicitamos la nota del estudiante
  		do{
			do{
				printf("\nIngrese la nota del alumno : ");
				fflush(stdin);
				scanf("%s",VAL_NUM);
				NUM = validar_numero(VAL_NUM);
			}while(NUM == 0);
			
			NOTAS[i] = atoi(VAL_NUM);
			
			if(NOTAS[i] <= 0 || NOTAS[i] > 20){
					printf("\nSOLO PUEDES INGRESAR NUMEROS > 0 o < 20");
				}
		} while(NOTAS[i] <=0 || NOTAS[i] > 20);	
	}
	for (i = 0; i < MAX; ++i){
		printf("\nAlumno %d: %s", i+1, NOM_ALUMS[i]);
		printf("\nNota: %.2f", NOTAS[i]);
	}
	
	
	
	system("cls");
	printf("\nBienvenido al Menu!");
	printf("\n1-.Buscar un alumno");
	printf("\n2-.Modificar nota de un alumno");
	printf("\n3-.Realizar media de todas las notas");
	printf("\n4-.Realizar media de las notas menores a 5");
	printf("\n5-.Mostrar alumno con mejor nota");
	printf("\n6-.Mostrar alumno con peor nota");
	printf("\n7-.Salir");
	printf("\n\nElija la opcion que desea utilizar: ");
	fflush(stdin);
	scanf("%d", &OP);
	  
	switch (OP){
		case 1:
			system("cls");
			printf("\nQue alumno desea buscar?: ");
		    fflush(stdin);
		    gets(ALUM);
		    
		    //Ordenamos el nombre del alumno
		    for(j = 0; j < strlen(ALUM); j++){
	   			ALUM[j] = tolower(ALUM[j]);
	   			if(j == 0){
	   				ALUM[j] = toupper(ALUM[j]);
				}
				if(j > 0 && ALUM[j-1] == ' '){
					ALUM[j] = toupper(ALUM[j]);
				}
			}
			
			//Buscamos el alumno
			system("cls");
			for(i = 0; i < MAX; i++){
			    BUS = strcmp(ALUM, NOM_ALUMS[i]);
			    if(BUS == 0){
			    printf("\n\tAlumno: %s", NOM_ALUMS[i]);
				printf("\n\tNota: %.2f \n", NOTAS[i]);
				system("pause");
			    break;
			    } 
		    }
		    if(BUS != 0){
		    	printf("\nNo se encontro el alumno: ", ALUM);
		    } 
			break;
		case 2:
			system("cls");
			printf("\nQue alumno desea buscar?: ");
		    fflush(stdin);
		    gets(ALUM);
		    
		    //Ordenamos el nombre del alumno
		    for(j = 0; j < strlen(ALUM); j++){
	   			ALUM[j] = tolower(ALUM[j]);
	   			if(j == 0){
	   				ALUM[j] = toupper(ALUM[j]);
				}
				if(j > 0 && ALUM[j-1] == ' '){
					ALUM[j] = toupper(ALUM[j]);
				}
			}
			
			//Buscamos el alumno
			system("cls");
			for(i = 0; i < MAX; i++){
			    BUS = strcmp(ALUM, NOM_ALUMS[i]);
			    if(BUS == 0){
			    printf("\n\tAlumno: %s", NOM_ALUMS[i]);
				printf("\n\tNota Actual: %.2f \n", NOTAS[i]);
				//Solicitamos y validamos nueva nota
				do{
					do{
						printf("Ingrese la nueva nota: ");
						fflush(stdin);
						scanf("%s",VAL_NUM);
						NUM = validar_numero(VAL_NUM);
					}while(NUM == 0);
					
					NOTAS[i] = atoi(VAL_NUM);
					
					if(NOTAS[i] <= 0 || NOTAS[i] > 20){
							printf("\nSOLO PUEDES INGRESAR NUMEROS > 0 o < 20");
						}
				} while(NOTAS[i] <=0 || NOTAS[i] > 20);
				
				//Imprimimos valores nuevos
				printf("\nLos datos actualizados son:");
				printf("\n\tAlumno: %s", NOM_ALUMS[i]);
				printf("\n\tNota Actual: %.2f \n", NOTAS[i]);
				system("pause");
			    break;
			    } 
		    }
		    if(BUS != 0){
		    	printf("\nNo se encontro el alumno: ", ALUM);
		    }
			break;
		case 3:
			system("cls");
			for(i = 0; i < MAX; ++i){
				SUMA = SUMA + NOTAS[i];
			}
			MEDIA = SUMA / MAX;
			printf("\n\tLa media de todas las notas es: %.2f", MEDIA);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			printf("\nERROR - Ingrese una opcion valida\n");
			system("pause");
			break;			
	}
	
	
	
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
				printf("\nDebes ingresar un numero ENTERO valido");
				return 0;
			}
		}
	}
	return 1;
}