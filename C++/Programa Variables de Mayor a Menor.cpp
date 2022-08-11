#include<iostream>
#include<locale.h>
using namespace std;

double num1=-300,num2=600,num3=3.141592,num4=2.7172,num5=-1414,num6=2500,aux;
int i;



main()
{
setlocale(LC_ALL,"spanish");
	i=1;
	//iterar:
	//if(i<=5){
	//while(i<=5){
	/*while(num6<-1000 or num6>1000){
		cout << "Ingrese num6 = ";
		cin >> num6;
	}*/
	for(i=1;i<=5;i=i+1)
	{
		if(num1 < num2){
			aux = num1;
			num1 = num2;
			num2 = aux;
		}
		if(num2 < num3){
			aux = num2;
			num2 = num3;
			num3 = aux;
		}
		if(num3 < num4){
			aux = num3;
			num3 = num4;
			num4 = aux;
		}
		if(num4 < num5){
			aux = num4;
			num4 = num5;
			num5 = aux;
		}
		if(num5 < num6){
			aux = num5;
			num5 = num6;
			num6 = aux;
		}
	//i=i+1;
	//goto iterar;
	}
	cout << "El orden de mayor a menor de los números es: " << endl;
	cout << num1 << " > " << num2 << " > " << num3 << " > " << num4 << " > " << num5 << " > " << num6 << endl;
	
	
	
	
}
