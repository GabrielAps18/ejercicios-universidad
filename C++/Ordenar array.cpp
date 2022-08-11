/*Ordeanr arrays*/

#include<iostream>
using namespace std;

int numeros[7] = {0, 67, -99, -100, 1, 78, -14};
int aux;
int i,j;

main(){
int j=1;
while(j<=5){	
	for(i=1; i<=5; i=i+1){
		if(numeros[i+1]<numeros[i]){
			aux = numeros[i];
			numeros[i]=numeros[i+1];
			numeros[i+1]= aux;
		}
	}
j=j+1;
} 
	
}
