/*Este programa calcula el menor costo posible de tender un cable de comunicacion
en el lago de maracaibo, basado en dos cables (terrestre y maritimo) de costos distintos
Elaborado por Gabriel Pacheco el 13 de Oct de 2021*/

#include <iostream>
#include <math.h>
using namespace std;
double BD,CT=3000, CM = 5000, W=0,X;
double a,b,c;

main(){
	
	cin >> CT;
	cin >> CM;
	
	W=pow(CT,2)/pow(CM,2);
	
	a=1-W;
	b=40*(W-1);
	c=400-596*W;
	
	X= (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
	BD=sqrt(596-40*X+pow(X,2));
	
	cout << endl << "La distacia opcima X (mts) = " << X;
	
}