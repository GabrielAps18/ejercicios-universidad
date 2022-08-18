#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h> // Sirve para usar comandos del sistema operativo system(cls)
// Programa de múltiples opciones

int main () {
	int A, B, C, EDAD, AUX, OP;
	float PROM, K;
	char NOM[20], APE[20], SEX;
	
	//Menú de opciones
	do{
		system("cls");
		printf("¿Que actividad desea realizar? \n");
		printf("1-. Calcular Raiz \n");
		printf("2-. Intercambiar Valores \n");
		printf("3-. Notas de Alumno \n");
		printf("4-. Salir \n");
		scanf("%d", &OP);
	} while (OP < 1 || OP > 4);
	
	//Ejecución de opciones
	if(OP == 1){
		do{
			system("cls");
			printf("Ingrese el valor de a (debe ser mayor a 0) = ");
			scanf("%d", &A);
		} while ( A < 0);
		K = sqrt(A);
		printf("La raiz de %d es %.2f", A, K);
	}
	
	if(OP == 2){
		system("cls");
		printf("Ingrese el primer valor: ");
		scanf("%d", &A);
		printf("\nIngrese el segundo valor: ");
		scanf("%d", &B);
		printf("\nIngrese el tercer valor: ");
		scanf("%d", &C);
		
		AUX = A;
		A = B;
		B = C;
		C = AUX;
		
		printf("\nEl orden quedaria a = %d, b = %d y c = %d", A, B, C);
	}
	
	if(OP == 3){
		system("cls");
		printf("Ingrese el Nombre del estudiante: ");
		scanf("%s", NOM);
		printf("\nIngrese el Apellido del estudiante: ");
		scanf("%s", APE);
		printf("\nIngrese la Edad del estudiante: ");
		scanf("%d", &EDAD);
		
		printf("\nIngrese el sexo del estudiante 'F' o 'M': ");
		do{
			SEX = getchar();
		}while(SEX != 'F' && SEX != 'f' && SEX != 'M' && SEX != 'm');
		
		do{
			printf("\nIngrese el promedio del alumno (debe ser mayor a 0 y menor a 20): ");
			scanf("%f", &PROM);	
		}while(PROM < 0 || PROM > 20);
		
		if(PROM >= 9.5){
			printf("\nEl alumno %s %s (" , NOM, APE);
			putchar(SEX);
			printf(") ha APROBADO con un promedio de %.2f.", PROM);
		}else{
			printf("\nEl alumno %s %s (" , NOM, APE);
			putchar(SEX);
			printf(")ha REPROBADO con un promedio de %.2f.", PROM);
		}
	}
	
	if(OP == 4){
			system("cls");
			printf("Gracias por utilizar el programa");
	}
	getche();
}