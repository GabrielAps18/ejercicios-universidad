/*
	Programa elaborado por Alan Ruz, María Garcés, Gabriel Pacheco
	Fecha: 19/11/2021
	Programa para dividir dos matrices 4x4 por el método del determinante
*/
#include<fstream>  //Biblioteca para manejo de archivos

using namespace std;

double det; // Determinante
main(){
	
	// Archivo de entrada de la primera matriz
	ifstream matriz1("C:/matrices/mat1.txt");
	
	// Matriz que usará los datos de mat1.txt
	double mat1[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	//Índices de fila y columna    
	int i,j;
	
	//Leemos los datos de del archivo mat1.txt y lo vaciamos en mat1

    for (i=0;i<=3;i=i+1){
        for (j=0;j<=3;j=j+1){
            matriz1 >>mat1[i][j];                  
       }                  
   }
   
// Hacemos lo mismo para la segunda matriz
	
	// Archivo de entrada de la segunda matriz
	ifstream matriz2("C:/matrices/mat2.txt");
	
	// Matriz que usará los datos de mat2.txt
	double mat2[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	// Matriz auxiliar (se usará más adelante)
	double aux[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	//Leemos los datos de del archivo mat1.txt y lo vaciamos en mat1
    for (i=0;i<=3;i=i+1){
        for (j=0;j<=3;j=j+1){
            matriz2 >>mat2[i][j];            
       }                  
	}
	
	// Pasamos valores de mat2 a aux
	for (i=0;i<=3;i=i+1){
        for (j=0;j<=3;j=j+1){
            aux[i][j] = mat2[i][j];            
       }                  
   }

// Calculamos el determinante
	int k, l; // Contadores

	det=aux[0][0];
	
	for(k=0;k<=2;k++){
		l=k+1;
		for(i=l;i<=3;i++){
			for(j=l;j<=3;j++){
				aux[i][j] = ( aux[k][k]*aux[i][j]-(aux[k][j]*aux[i][k]) )/aux[k][k]; 
			}
		}
		det=det*aux[k+1][k+1];
	}
// Calculamos la matriz adjunta

}
