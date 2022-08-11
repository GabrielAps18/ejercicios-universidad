#include<iostream>
using namespace std;
main(){
	
	string texto1 = "Andrea Daniela Farnetano";
	string texto2 (texto1, 7, 7);
	string texto3 (texto1, 0, 6);
	string texto4;
	int aux;
	
	texto4 = texto3 + " " + texto2 + " C.I = 27.858.322";
	aux = texto1.size();
	cout << aux << endl;
	cout << texto4 <<endl<<endl;
	
	// Insertar Datos
	string texto5 = "Sheila Ferrer";
	texto5.insert(6, " Daniela");
	cout << texto5 << endl;
	// Extraer Datos 
	/*texto5 = texto1.substr(0,6) + " " + texto1.substr(15);
	cout << texto5 << endl;*/
	//Reemplazar Datos
	texto4 = "D.";
	texto1.replace(7,7, texto4);
	cout << texto1 << endl;
}

