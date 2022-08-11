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
	double A[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	//Índices de fila y columna    
	int i,j;
	
	//Leemos los datos de del archivo mat1.txt y lo vaciamos en mat1

    for (i=1;i<=4;i=i+1){
        for (j=1;j<=4;j=j+1){
            matriz1 >>A[i][j];                  
       }                  
   }
   
// Hacemos lo mismo para la segunda matriz
	
	// Archivo de entrada de la segunda matriz
	ifstream matriz2("C:/matrices/mat2.txt");
	
	// Matriz que usará los datos de mat2.txt
	double B[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	// Matriz auxiliar (se usará más adelante)
	double aux[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
	double aux2[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	//Leemos los datos de del archivo mat1.txt y lo vaciamos en mat1
    for (i=1;i<=4;i=i+1){
        for (j=1;j<=4;j=j+1){
            matriz2 >>B[i][j];            
       }                  
	}
	/*
	// Pasamos valores de mat2 a aux
	for (i=0;i<=3;i=i+1){
        for (j=0;j<=3;j=j+1){
            aux[i][j] = mat2[i][j];            
       }                  
   }*/

// Calculamos el determinante
// Calculamos matriz adjunta
	int o,p = 1 ;
	int m = 1;

		for(j=2; j<=4; j=j+1){
			for(i=1; i<=4; i= i+1){
				if(i==m){	
					
				}else{
					aux[j-1][i-1] = B[j][i];
				}
			}
		}
					
		
		aux2[1][1] = ( (aux[1][1]*aux[2][2]*aux[3][3]) + (aux[2][1]*aux[3][2]*aux[1][3]) + (aux[3][1]*aux[1][2]*aux[2][3]) ) - ( (aux[1][3]*aux[2][2]*aux[3][1]) + (aux[2][3]*aux[3][2]*aux[1][1]) + (aux[3][3]*aux[1][2]*aux[2][1]) );
		m=m+1;
		
		 
		
		                                                                                                                                                                                                                                                                                                                                                                                                                                                               

}