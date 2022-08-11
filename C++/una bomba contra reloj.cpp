/*Programacion 2    24/11/21

este programa simula una bomba con las siguentes caracteristicas:

*una cuenta regresiva
*clave de tres letras
*en caso de fallar la clave se restan 20 seg

*/

#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

main()
{
	int x=100;       //contador de tiempo
	int intentos=0;    //contador de intentos
	string clave="000";       //clave de tres letras

	
	while (x>=0 and x<=100)            //tiempo mayor o igual a 0 y menor o igual que 100
	{	
	
		cout<<"   \""<<x<<"\""<<endl;                      //imprime en pantalla el tiempo
		cout<<"Ingresar clave: "<<clave<<endl;              //imprime los caracteres de clave introducidos por el usuario
		x=x-1;                  //resta de 1 en 1 el tiempo                       
		Sleep(1000);            //hace que el tiempo se a en segundos  1000 milisegundos =1 segundo                        
		Beep(250,250);          //genera un pitido al paso de cada segundo
		system("cls");          //limpia la pantalla
			                               
	
		if(kbhit()!=0 and intentos==0)             //detecta si el usuario presiono una tecla y cuantos intentos lleva                      
		{
			clave[0]=getch();                       //guarda el el caracter en la posicion 0 de la clave
			intentos=1;                               
		}
		
		if(kbhit()!=0 and intentos==1)
		{
			clave[1]=getch();                      //guarda el segundo caracter
			intentos=2;
		}
		
		if(kbhit()!=0 and intentos==2)
		{
			clave[2]=getch();                     //guarda el tercer caracter
			intentos=3;
		}
		
		if(intentos==3)
		{
			if(clave=="Sol" or clave=="sol" or clave=="SOL")         //clave             
			{
				cout<<"Introdujo la clave correcta"<<endl;
				cout<<"Bomba desactivada";
				Beep(900,200);                                 
				Beep(900,200);
				Beep(900,200);
				exit(0);                         //termina el programa                 
			}
		
			else
			{
				cout<<"tiempo actual: "<<x<<" -20 seg"<<endl;
				cout<<"recalculando: "<<x<<endl;
				x=x-20;
				cout<<"nuevo tiempo: "<<x<<endl;
				Sleep(1000);
				intentos=0;
			}	
		}
			
	}
	
	system("cls");
	cout<<"BOOM!!!!!!"<<endl<<endl;
	Beep(250,250);
	Beep(150,250);
	
	
	
	system("pause");
}
