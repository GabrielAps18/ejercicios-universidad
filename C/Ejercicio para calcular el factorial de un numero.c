#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
//Programa para calcular el factorial de un número

int main(){
	int NUM, FAC, i, AG;
	do{
		system("cls");
		do{
			printf("Ingrese un numero para saber su factorial: ");
			scanf("%d", &NUM);
		} while(NUM < 0);
		if(NUM == 0){
			FAC = 1;
			goto final;
		}
		FAC = NUM;
		
		for(i = NUM; i >= 2; i--){
			FAC = FAC * (i-1);
		}
		final:
		printf("\nEL factorial de %d! es = %d", NUM, FAC);
		printf("\nDesea saber el factorial de otro numero? 1 = SI - 2 = NO: ");
		scanf("%d", &AG);
	} while (AG == 1);
}