/*#include<iostream>
#include<fstream>
using namespace std;
main(){
	ifstream fin("C:/Users/Gabo/Documents/C/Datos/data.txt");
	int mat1[4][4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int mat2[4][4] = {0,0,0,0,0,1,2,2,0,1,3,3,0,1,4,4};
	int i,j;
	
	for (i=1; i<=3; i=i+1){
		
		for (j=1; j<=3; j=j+1){
			fin >> mat1[i][j];
		}
	}
}*/
#include<fstream>  //Biblioteca para manejo de archivos

using namespace std;

 

main()

{

         ifstream fin("C:/Users/Gabo/Documents/C/Datos/data.txt");

         //Definimos el archivo de entrada

         ofstream fout("C:/Users/Gabo/Documents/C/Datos/datafinal.txt");

         //Definimos el archivo de salida (este lo creara el programa)

        

         int mat1[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

         //Definimos la matriz de entrada que usara los datos del archivo data.txt

         int mat2[4][4]={0,0,0,0,0,1,2,2,0,1,3,3,0,1,4,4};

         //Definimos la matriz por la cual multiplicaremos a la matriz 1

         int mat3[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

         // Definimos la matriz de Salida

          int i,j;

          //Índices de fila y columna    



          //Leemos los datos de del archivo data.txt y lo vaciamos en mat1

          for (i=1;i<=3;i=i+1)

                   {

                   for (j=1;j<=3;j=j+1) 

                                      {

                                      fin >>mat1[i][j];                  

                                      }                  

                    }

        

        

         /*Ejecutamos la multiplicación de las matrices mat1 x mat2 y

         colocamos el resultado en mat3*/

          

          for (i=1;i<=3;i=i+1)

                   {

                   for (j=1;j<=3;j=j+1) 

                                      {

                                      mat3[i][j]=mat1[i][1]*mat2[1][j]+mat1[i][2]*mat2[2][j]+mat1[i][3]*mat2[3][j];                  

                                      }                 

                    }       

 /* Escribimos los resultados de la matriz mat3 en un archivo de nombre

datafinal.txt que estará en la misma ruta que data.txt. Este archivo

es creado por el programa*/

 for (i=1;i<=3;i=i+1)

                   {

                   for (j=1;j<=3;j=j+1) 

                                      {

                                      fout <<mat3[i][j]<<" ";

                                       }                  

                    }        

                    system("pause");

 }