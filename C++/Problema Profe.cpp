// Programa elaborado Carlos Ferrer

// Universidad Santa Mar�a
// Programaci�n I
// elaborado 25-4-2021

#include <iostream>
#include <math.h>

using namespace std;

main() 

{

double area=0; //area del trapecio
double x; // representa la longitud de la cabilla
double Q; // angulo Q donde el area se hace maxima
double pi=3.14159265358979;
double aux1=0,aux2=0;


x=10000; //valor inicial de la cabilla (si lo varias el �ngulo debe ser el mismo)
Q=0.1; //Valor inicial de �ngulo


// calculamos las �reas variando el �ngulo ente 0.1 y 90
// registramos en aux2 el �ngulo donde el �rea se hace m�xima
while (Q<=90)
{
	
area = pow(x,2)*(sin(Q*pi/180)+sin(Q*pi/180)*cos(Q*pi/180))/9;

if (area>aux1)
{
	aux1=area;
	aux2=Q;
}

Q=Q+0.1;
	
}

// presentamos el valor del �ngulo

cout <<endl<<endl<<"El angulo donde el area se hace maxima es = "<<aux2<<" grados"<<endl<<endl;
system("pause");
}
