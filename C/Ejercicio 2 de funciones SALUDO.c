#include <stdio.h>
#include <stdlib.h>
// Saludo de presentacion con funcion
void saludo ();

int main (){
	saludo();
}

void saludo(){
	char NOM[10];
	printf("Cual es su nombre?: ");
	scanf("%s", NOM);
	system("cls");
	printf("Bienvenido %s.", NOM);
}
