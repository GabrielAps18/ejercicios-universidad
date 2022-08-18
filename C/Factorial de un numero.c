#include <stdio.h>
#include <stdlib.h>
// Caclcular factorial de un numero con recursividad

int factorial(int n){
	if (n == 0){
		return 0;
	}else{
		return n * factorial(n -1);
	}
}

int main(){
	int n;
	n = 0;
	printf("El factorial de %d es: %d", n, factorial(n));
}