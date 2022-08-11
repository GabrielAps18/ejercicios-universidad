#include<iostream>
#include<locale.h>
using namespace std;
struct telefonos{
	string marca;
	string modelo;
	int ano;
	double costo;
}telefono[200];

int i,k;
int j = 1;
main(){
	setlocale(LC_ALL, "spanish");
	cout << "Ingrese cuantos telefonos quiere registrar: ";
	cin >> k;
	system("cls");
	for(i=1;i<=k;i=i+1){
		cout << "Ingrese La Marca del teléfono" << endl;
		cin >> telefono[i].marca;
		cout << "Ingrese el modelo del teléfono" << endl;
		cin >> telefono[i].modelo;
		cout << "Ingrese el año del teléfono" << endl;
		cin >> telefono[i].ano;
		cout << "Ingrese el costo del teléfono" << endl;
		cin >> telefono[i].costo;
		system("cls");
	}
	
	do{
		cout << "Carácteristicas teléfono " << j << ":" << endl;
		cout << telefono[j].marca << endl;
		cout << telefono[j].modelo << endl;
		cout << telefono[j].ano << endl;
		cout << telefono[j].costo << "$"<< endl; 
		j=j+1;
	}while(j<=k);
}