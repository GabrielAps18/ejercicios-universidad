/*Programa Elaborado por: Gabriel Pacheco
Angel Lopez
Alan Ruz 
Alejandro Rodriguez 
17 de junio de 2021
El juego del Ahorcado en C*/
#include<iostream>
#include <windows.h>
using namespace std;

//variables donde guardaremos el texto 
string palabra;
string adivina;
//con este auxiliar colocaremos los "piso", haciendo referencia al juego original
string aux = "_";
string resultado = "";
string espaciado = "";
int i, j, aux1, reset;
//contadores donde guardaremos el uso de las vidas y donde guardaremos el contador que validara las letras del ahorcado
int cont = 0, vidas = 8, voc;

main(){
	inicio:
	vidas = 8;
	cont = 0;
	voc = 0;
	//inicio del programa donde guardaremos la palabra a adivinararn
	cout << "Ingrese una palabra" << endl;
	cin >> palabra;
	
	aux1=palabra.size();
	
	//ciclo que validara que la palabra esta en el rango requerido de caracteres	
	if(aux1>=6 and aux1<=10){
	
		system("cls");
	}
	else{
		cout<<"la palabra que indico no es valida"<<endl<<endl<<endl;
		system("pause");
		system("cls");
		goto inicio;
	}
	//ciclo que usaremos para contar la cantidad de letras de la palabra y las cambiara por "pisos"
	j=palabra.size();
	for(i=0; i<j; i=i+1){
		resultado.replace(i,1, aux);
	}
	
	repite:
	
	//aqui daremos la oportunidad al usuario de adivinar por totalidad la palabra a adivinar
	cout << "Ingrese una letra o la palabra si está seguro de adivinar \n";
	cin >> adivina;
	
	if(adivina == "a" or adivina == "e" or adivina == "i" or adivina == "o" or adivina == "u"){
		voc = voc +1;
			if(voc >2){
				cout << "No puedes seguir colocando mas vocales" << endl;
				goto falso;
			}
	}
		
		if (adivina==palabra){
				cout << "HAZ ADIVINADO LA PALABRA" << endl<<endl<<endl;
			Beep (523,382);Beep (587,340);Beep (659,304);Beep (698,286);
			Beep (740,270);Beep (880,228);Beep (998,220); Beep (523,382);
		 	Sleep (1000);
		 	Beep (998,220);Beep (880,228);Beep (740,270);Beep (698,286);
		 	Beep (659,304);Beep (587,340);Beep (523,382);
			goto fin;
		
		}
		else{
			system("cls");
		}
		/*de lo contrario, iniciara el juego
		Este ciclo funcionara de la siguiente manera, se le pedira una letra al usuario, el programa 
		validara si la letra ocupa alguna posicion en la palabra, de no ser asi se le restara una vida y volvera a preguntar.
		En todo momento se le indicara al usuario la cantidad de vidas que posee*/
		for(i=0; i<=j; i=i+1){
			string aux (palabra,i,1);
			if(aux == adivina){
				system("cls");
				resultado.replace(i,1, aux);
				espaciado = resultado.substr(0,1) + " " + resultado.substr(1,1) + " " + resultado.substr(2,1) + " " + resultado.substr(3,1) + " " + resultado.substr(4,1) + " " + resultado.substr(5,1) + " " + resultado.substr(6,1) + " " + resultado.substr(7,1) + " " + resultado.substr(8,1) + " " + resultado.substr(9,1) + " ";
				cout << espaciado << "						Vidas Restantes: " << vidas << endl << endl; 
				cont = cont + 1;
			}
			
		}
		
		//de modo que, si el usuario se quedase sin vidas el juego le indicara que perdio y terminara su partida
		if(cont == 0){
			falso:
			vidas = vidas - 1;
			Beep (587,340);Beep (523,382);
			if(vidas == 0){
				system("cls");
				cout << "Oh no! Has perdido :(, la palabra correcta era: " + palabra << endl<<endl<<endl;
				goto fin;
			}
		}
	//por el contrario, si el usuario acierta todas las letras se le dara el anuncio de victoria
		cont = 0;
		if(palabra == resultado){
			cout << "HAS ADIVINADO LA PALABRA" << endl<<endl<<endl;
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
		//de terminar la partida indiferentemente de que el usuario pierda o gane se le dara la opcion de seguir jugando o de acabar su sesion
			cout <<"Si desea correr de nuevo el programa coloque 1 + Enter."<<endl;
			cout <<"Si desea salir del programa presione cualquier OTRO numero + Enter."<<endl<<endl;
					cin >>reset;
			cout<<endl;
		//ciclo que dara la opcion al usuario de seguir jugando o terminar su sesion
			if (reset==1)
     			{
					system ("cls");
					goto inicio;
				}
			else
				{
   					cout<<"Usted ha finalizado su sesion con el programa, que tenga buen dia."<<endl<<endl;
				}
	
system("pause");
}   
