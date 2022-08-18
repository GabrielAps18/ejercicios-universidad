#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ANCHO 55
#define FILAS 2
void linea();
void lados();
// Programa que imprime un mensaje rodeado por un borde
int main(){
	//Texto
	char texto[130];
	char lin1[30], lin2[30], lin3[30], lin4[30];
	int i;
	printf("Introduce un texto de 130 parametros (en caso de ser mayor se cortara el sobrante): \n");
	fgets(texto, 130, stdin);
	if ((strlen(texto) > 0) && (texto[strlen(texto) - 1] == '\n'))
    {
        texto[strlen(texto) - 1] = '\0';
    }
    system("cls");
    // Cuadro
	printf("\n\n\n\n");
	linea();
	lados();
	if(strlen(texto) > 0){
		for(i=0; i<=30; ++i) lin1[i] = texto[i];
		printf(" *\t\t%s\t\t *", lin1);
		if(strlen(texto) > 30){
			int j = 0;
			for(i=31; i<=60; ++i){
				lin2[j] = texto[i];
				++j;
			}
			printf("\n *\t\t%s\t\t *", lin2);
			if(strlen(texto) > 60){
				int j = 0;
				for(i=61; i<=90; ++i){
					lin3[j] = texto[i];
					++j;
			}
				printf("\n *\t\t%s\t\t *", lin3);
				if(strlen(texto) > 90){
					int j = 0;
					for(i=91; i<=120; ++i){
						lin4[j] = texto[i];
						++j;
					}
					printf("\n *\t\t%s\t\t\n", lin4);
				}
			}
		}
	}
	lados();
	linea();
	printf("\n\n\n\n");
}
void linea(){
	int x;
	printf(" ");
	for (x=0; x<=ANCHO; ++x) putchar('*');
	putchar('\n');
}
void lados(){
	int y;
	for (y=1; y<=FILAS; ++y) printf(" *\t\t\t\t\t\t\t *\n");
}
//Este es el texto de prueba que necesito utilizar para poder realizar mi programa, en el cual me piden imprimir un texto con borde