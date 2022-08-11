// Tiffany Carrillo
// Proyecto de laboratorio
// Maquina tragamonedas

#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#define a 03 // Figura 1 del tragamonedas el corazon
#define b 04 // Figura 2 del tragamonedas el diamante
#define c 05 // Figura 3 del tragamonedas el trebol
#define d 30 
#define e 31 

char titulo(); // Funcion que muestra el titulo del programa
char ruedas(int x, int y, int z); // Funcion que muestra las ruedas del tragamonedas
int algoritmo(int *p, int j, int k); // Funcion que inicia cada jugada


int main(){
	
	int opc, n, loop, i;
	int dinero, apuesta;

	do{
	
		system("cls");
		titulo();
		ruedas(a,b,c);
			
		printf("\n\tIngrese un numero segun la opcion que desea: \n");
		printf("\n\t1)Jugar");
		printf("\n\t2)Ver como se juega");
		printf("\n\t3)Ver registro de juegos de ayer");
		printf("\n\t4)Salir\n\t");
		scanf("%d", &opc);
		
		switch(opc){
			
			case 1: 
			
				system("cls");
				
				titulo();
				ruedas(a,a,a);
				
				printf("\n\tIngrese el numero maximo de veces que quiere jugar: \n\t");
				scanf("%d", &n);
				
				printf("\n\tIngrese la cantidad de dinero que dispone: \n\t");
				scanf("%d", &dinero);
				
				i = 0;
				
				while(i < n && dinero != 0){
					algoritmo(&dinero, i, n);
					i++;
					getche();
			
				}
				
				printf("\n\n\tIngrese 1 para volver al menu, ingrese 2 para salir: ");
				scanf("%d", &loop);
				break;
			
			case 2:
				
				system("cls");
				
				printf("\n\tDe que trata el Juego? ");
				printf("\n\n\n\tEl juego consiste en que, al ser accionada la palanca, las ruedas comienzan a girar, \n\tpudiendose observar el desplazamiento de las figuras (corazon, diamante y trebol) a través de la ventana.");
				printf("\n\n\tSi al momento de detenerse las tres ruedas, quedan en la ventana tres figuras iguales,\n\tel jugador gana el triple de lo que aposto.");
				printf("\n\n\tSi solo dos figuras son iguales, el jugador gana el doble de lo que aposto\n\ty si las tres figuras son diferentes el jugador pierde.");
				
				printf("\n\n\tIngrese 1 para volver al menu, ingrese 2 para salir: ");
				scanf("%d", &loop);
				
				break;
			
			case 3:
				
				break;
				
			case 4:
				
				printf("\n\tSaliendo...");
				loop = 2;
				break;
		}
		
		if(loop != 1){
			
			while(loop < 1 || loop > 2){
				
				printf("\n\n\tOpcion invalida, ingrese 1 para volver al menu, ingrese 2 para salir: ");
				scanf("%d", &loop);
				
			}
			
			if(loop == 2){
				
				system("cls");
				
				titulo();
				ruedas(a,a,a);
				printf("\n\n\tSaliendo...");
				
			}
		}
		
	}while(loop == 1);
	
	return 0;
}

char titulo(){
	
	int fila, col;
	
	printf("\n\n");
	
	for(fila = 1; fila <= 5; fila++){
		
		
		printf("\t\t");
		
		for(col = 1; col <= 26; col++){
			
			if(fila == 1 || fila == 5){
				printf("*");
				
			}
			
			
			if((fila == 2 && col == 1) || (fila == 2 && col == 25) || (fila == 4 && col == 1) || (fila == 4 && col == 25)){
				printf("*");
				
			}
			
			if(fila == 3 && col == 1){
				printf("*  MAQUINA TRAGAMONEDAS  *");
				
			}
		
			else{
				
				if(fila != 1 && fila != 5){
					printf(" ");
				
				}
			}
			
			
		}
		printf("\n");
	}
	
}

char ruedas( int x, int y, int z){
	
	int fila, col;
	
	printf("\n");
	
	for(fila = 1; fila <= 3; fila++){
		
		printf("\t\t     ");
		
		for(col = 1; col <= 8; col++){
			
			if( fila == 1 || fila == 3){
				printf("-");
				
			}
			
			if(fila == 2 && (col == 1 || col == 3 || col == 5 || col == 7)){
				printf("|");
				
			}
			
			if(fila == 2 && col == 2){
				printf("%c ", x);
				
			}
			
			if(fila == 2 && col == 4){
				printf("%c ", y);
			}
			
			if(fila == 2 && col == 6){
				printf("%c ", z);
			}

			else {
				printf(" ");
			}
		}
		
		printf("\n");
	}
	
}

int algoritmo(int *p, int j, int k){
	
	system("cls");
					
	printf("\n\tJUGADA %d DE %d", j+1, k);
	
	int i, rueda[3], num1, num, apuesta;
	
	printf("\n\tDinero disponibe: %d, Ingrese el dinero a apostar en esta jugada: ", *p);
	scanf("%d", &apuesta);
	
	while(apuesta > *p){
		
		printf("\n\tCantidad invalida, usted no dispone de esa cifra");
		
		printf("\n\tDinero disponibe: %d, Ingrese el dinero a apostar en esta jugada: ", *p);
		scanf("%d", &apuesta);
		
	}

	*p = *p - apuesta;
	
	system("cls");
	
	printf("\n\tDinero disponible: %d, dinero apostado: %d", *p, apuesta);

	ruedas(a,a,a);
	
	printf("\n\tOprima cualquier boton para accionar la palanca y girar las ruedas");
	getch();
	
	//GIRO DE RUEDAS
	
	system("cls");
	srand(time(NULL));
	
		
	for(i = 0; i < 3; i++){
		
		num1 = rand() % 11;
		num = (rand() * num1) % 11;
		
		if(num > -1 && num < 3){
			rueda[i] = a;
		}
		
		if(num > 2 && num < 5){
			rueda[i] = b;
		}
		
		if(num > 4 && num < 7){
			rueda[i] = c;
		}
		
		if(num > 6 && num < 9){
			rueda[i] = d;
		}
		
		if(num > 8 && num < 11){
			rueda[i] = e;
		}
		
	}
	
	// Primera rueda
	
	ruedas(a,b,c);
	
	Sleep(300);
	
	system("cls");
	
	ruedas(e,a,b);
	
	Sleep(300);
	
	system("cls");
	
	ruedas(d,e,a);
	
	Sleep(300);
	
	system("cls");
	
	ruedas(rueda[0], d, e);
	
	Sleep(300);
	
	system("cls");
	
	// Segunda rueda
	
	ruedas(rueda[0], e, a);
	
	Sleep(300);
	
	system("cls");
	
	ruedas(rueda[0], a, b);
	
	Sleep(300);
	
	system("cls");
	
	ruedas(rueda[0], c, d);
	
	Sleep(300);
	
	system("cls");
	
	ruedas(rueda[0], rueda[0], a);
	
	Sleep(300);
	
	system("cls");
	
	// Tercera rueda
	
	ruedas(rueda[0], rueda[1], b);
	
	Sleep(300);
	
	system("cls");
	
	ruedas(rueda[0], rueda[1], c);
	
	Sleep(300);
	
	system("cls");
	
	ruedas(rueda[0], rueda[1], d);
	
	Sleep(300);
	
	system("cls");
	
	ruedas(rueda[0], rueda[1], e);
	
	Sleep(300);
	
	system("cls");
	
	
	// Resultado
	
	ruedas(rueda[0], rueda[1], rueda[2]);
	
	
	if(rueda[0] == rueda[1] && rueda[0] != rueda[2]){
		
		*p += apuesta * 2;
		printf("\n\tFelicidades, has ganado el doble de lo que apostaste! ahora tienes %d", *p);
		
	}
	
	if(rueda[0] == rueda[2] && rueda[0] != rueda[1]){
		
		*p += apuesta * 2;
		printf("\n\tFelicidades, has ganado el doble de lo que apostaste! ahora tienes %d", *p);
		
	}
	
	if(rueda[1] == rueda[2] && rueda[1] != rueda[0]){
		
		*p += apuesta * 2;
		printf("\n\tFelicidades, has ganado el doble de lo que apostaste! ahora tienes %d", *p);
	}
	
	if(rueda[0] == rueda[1] && rueda[0] == rueda[2]){
	
		*p += apuesta * 3;
		printf("\n\tFelicidades, has ganado el triple de lo que apostaste! ahora tienes %d", *p);
	}
	
	if(rueda[0] != rueda[1] && rueda[0] != rueda[2] && rueda[1] != rueda[2]){
		printf("\n\tLo siento, no has ganado nada!");
	}
	
	if(*p == 0){
		printf("\n\tTe has quedado sin dinero, no puedes jugar mas");
	}

}
