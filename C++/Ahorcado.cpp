#include<iostream>
#include <windows.h>
using namespace std;

string palabra;
string adivina;
string aux = "_";
string resultado = "";
int i, j, voc;
int cont = 0, vidas = 8;

main(){
	cout << "Ingrese una palabra" << endl;
	cin >> palabra;
	j=palabra.size();
	for(i=0; i<j; i=i+1){
		resultado.replace(i,1, aux);
	}
	system("cls");
	repite:
	cout << "Ingrese una letra o la palabra si está seguro de adivinar \n";
	cin >> adivina;
	if(adivina == "a" or adivina == "e" or adivina == "i" or adivina == "o" or adivina == "u"){
		voc = voc +1;
	}
	if(voc >2){
		vidas = vidas - 1;
		Beep (587,340);Beep (523,382);
		system("cls");
		cout << "No puedes seguir colocando mas vocales" << endl;
		cout << resultado << "						Vidas Restantes: " << vidas << endl << endl; 
		goto repite;
	}
		for(i=0; i<=j; i=i+1){
			string aux (palabra,i,1);
			if(aux == adivina){
				system("cls");
				resultado.replace(i,1, aux);
				cout << resultado << "						Vidas Restantes: " << vidas << endl << endl; 
				cont = cont + 1;
			}
		}
		if(cont == 0){
			vidas = vidas - 1;
			Beep (587,340);Beep (523,382);
			if(vidas == 0){
				system("cls");
				cout << "Oh no! Haz perdido :(, la palabra correcta era: " + palabra << endl;
				goto fin;
			}
		}
		cont = 0;
		if(palabra == resultado){
			cout << "HAZ ADIVINADO LA PALABRA" << endl;
			Beep (523,382);Beep (587,340);Beep (659,304);Beep (698,286);
			Beep (740,270);Beep (880,228);Beep (998,220); Beep (523,382);
		 	Sleep (1000);
		 	Beep (998,220);Beep (880,228);Beep (740,270);Beep (698,286);
		 	Beep (659,304);Beep (587,340);Beep (523,382);
			goto fin;
			
		}
		system("cls");
		cout << resultado << "						Vidas Restantes: " << vidas << endl << endl; 
		Beep (880,228);Beep (998,220);
		goto repite;
		fin:
	
system("pause");
}                     

