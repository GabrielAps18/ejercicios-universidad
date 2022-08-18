#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h> // Sirve para usar comandos del sistema operativo system(cls)
//Programa de inscripción de alumnos a una universidad

int main () {
	int NUM_EXP, EDAD, UD, VUD, OP = 1;
	float ADM_PROM, ING_PROM, EDU_PROM, ADM_E, ADM_E_PROM, INS_ADM, INS_ING, INS_EDU, T_INS;
	char NOM[20], SEX, FAC;
	
	do{
		system("cls");
		printf("Bienvenido al sistema de inscripcion de la USM");
		printf("\nIngrese el numero de expediente del alumno: ");
		scanf("%d", &NUM_EXP);
		printf("\nIngrese el nombre del alumno: ");
		scanf("%s", NOM);
		printf("\nIngrese la edad del alumno: ");
		scanf("%d", &EDAD);
		printf("\nIngrese el sexo del estudiante 'F' o 'M': ");
		do{
			SEX = getchar();
		}while(SEX != 'F' && SEX != 'f' && SEX != 'M' && SEX != 'm');
		printf("\nIngrese el numero de unidades de credito a inscribir (Minimo 5 - Maximo 20): ");
		do{
			scanf("%d", &UD);
		}while(UD < 5 || UD > 20);
		printf("\nIngrese la facultad a estudiar (a = Administracion, i = Ingenieria, e = Educacion): ");
		do{
			FAC = getchar();
		}while(FAC !='a' && FAC !='A' && FAC !='i' && FAC !='I' && FAC !='e' && FAC !='E');
		
		if(FAC == 'a' || FAC == 'A'){
			INS_ADM = INS_ADM + 1;
			VUD = UD * 5;
			ADM_E = ADM_E + EDAD;
		}
		
		if(FAC == 'i' || FAC == 'I'){
			INS_ING = INS_ING + 1;
			VUD = (UD * 5) + 50;
		}
		
		if(FAC == 'e' || FAC == 'E'){
			INS_EDU = INS_EDU + 1;
			VUD = UD * 5;
		}
		
		printf("\nEl alumno %s con expediente #%d debe pagar por %d unidades de credito un total de %d bs.", NOM, NUM_EXP, UD, VUD);
		
		printf("\nDesea inscribir a otro alumno? 1-. Si 2-. No: ");
		scanf("%d", &OP);
		
	} while(OP == 1);
	
	T_INS = INS_ADM + INS_ING + INS_EDU;
	ADM_PROM = (100 * INS_ADM) / T_INS;
	ING_PROM = (100 * INS_ING) / T_INS;
	EDU_PROM = (100 * INS_EDU) / T_INS;
	ADM_E_PROM =  ADM_E / INS_ADM;
	system("cls");
	printf("Resumen de inscripciones: ");
	printf("\nTotal de alumnos inscritos: %.0f", T_INS);
	printf("\nPorcentaje de alumnos inscritos por facultad: \nAministracion = %.2f \nIngenieria = %.2f \nEducacion = %.2f ", ADM_PROM, ING_PROM, EDU_PROM);
	printf("\nEl promedio de edad en la facultad de Administracion es: %.2f", ADM_E_PROM);
	
	
	
}
