#include <stdio.h> 
#include <stdlib.h>
char Letras[27]={ 'A' , 'B' , 'C' , 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'W', 'X', 'Y', 'Z'};
void codificar(char Mensaje[27],int numero); 
void decodificar(char Mensaje[27],int numero); 
 
void codificar(char Mensaje[27],int numero){ 
	int i=0; 
	char c; 
	while(Mensaje[i]!= '\0' ){ 
		Mensaje[i]=Mensaje[i]+numero;
		i++; 
	} 
	printf("\nEl mensaje codificado es:\n%s\n",Mensaje); 
}
 
void decodificar(char Mensaje[27],int numero){ 
	int i=0; 
	while(Mensaje[i]!= '\0' ){ 
	Mensaje[i]=Mensaje[i]-numero; 
	i++; 
	} 
	printf("\nEl mensaje decodificado es:\n%s\n",Mensaje); 
} 
 
int main() { 
	int n; 
	char cadena[27]; 
	printf("introduce un mensaje: "); 
	fflush(stdin); 
	scanf("%s", cadena); 
	while(getchar()!= '\n' ); 
	printf("introduce un numero: "); 
	scanf("%d",&n); 
	while(getchar()!= '\n' ); 
	codificar(cadena, n); 
	decodificar(cadena, n); 
	return 0; 
}