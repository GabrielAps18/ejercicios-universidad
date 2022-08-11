#include <iostream>

using namespace std;

double num,num1=0;

int sol=0;

int aux1=0;

double aux2=0;

int Pra_impr=0;

main()

{

Repite:

cout <<"Ingrese el valor de un numero ENTERO  (100 <= numero <= 1.000) = ";

cin >>num1;

	

	

if (num1<100 or num1>1000)

	{

		system ("cls");

		goto Repite;

	}

	

num=num1;

inicio:	

aux1= num/7;

aux2= num/7;

	

if (aux1 == aux2)

	

	{

	aux1= num/2;

	aux2= num/2;

	

	if (aux1/aux2!=1)

	        {

		sol=num;

		        if (Pra_impr==1)

		            {

			    cout <<" , "<<num;

		            }

			if (Pra_impr==0)

		            {

			    cout <<endl<<"Las numeros buscados en el rango de "<<num1<< " a 1.000 = "<<endl;

			    cout <<endl<<num;

			    Pra_impr=1;

		           }

        	}	

	}

	

num=num+1;

if (num<=1000)

	{

	goto inicio;

	}		

	

if (Pra_impr==0)

	{

	cout <<endl<<"No existe soluciones para el rango de "<<num1<< " a 1.000 "<<endl;

	}

}
