/*Programa Elaborado por: 
Gabriel Pacheco
Angel Lopez 
Alejandro Rodriguez 
30 de junio de 2021
Tabla de posiciones de Grupo de fútbol
Parcial 3*/

#include<iostream>
#include<locale.h>
using namespace std;

string equipos[5];
string win[34];
string aux4;

int puntos[5][9];

int aux3[5][9];
int i,k,aux,aux2,m;

main(){
	setlocale(LC_ALL, "spanish");
	for (i=1; i<=4; i=i+1){
		cout << "Ingrese el equipo número: "<< i << endl;
		cin >> equipos[i];
		//cout << endl;
	}
	system("cls");

	// JORNADA 1

	cout << "Jornada 1" << endl;
	k=2;
	for(i=1; i<=3; i=i+2){
		cout << "Partido: " << equipos[i] << " VS "<< equipos[k] << endl;
		cout << "Ingrese el resultado: " << endl << equipos[i] << " ";
		// Partido Jugado
		puntos[i][1] = puntos[i][1] + 1;
		puntos[k][1] = puntos[k][1] + 1;
		// Goles Favor Equipo1
		cin >> aux; 
		puntos[i][5] = puntos[i][5] + aux;
		// Goles Contra Equipo2
		puntos[k][6] = puntos[k][6] + aux; 
		cout << equipos[k] << " ";
		// Goles Favor Equipo2
		cin >> aux2; 
		puntos[k][5] = puntos[k][5] + aux2;
		// Goles Contra Equipo1
		puntos[i][6] = puntos[i][6] + aux2; 
		cout << endl;
		if(aux > aux2){
			puntos[i][8] = puntos[i][8] + 3; // Puntos por Victoria
			puntos[i][2] = puntos[i][2] + 1; // Partido Ganado
			puntos[k][4] = puntos[k][4] + 1; // Partido Perdido
			m=(i*10)+k;
			win[m] = equipos[i].substr(0) + "1" + equipos[k].substr(0);
			
		}else if(aux < aux2){
			puntos[k][8] = puntos[k][8] + 3; // Puntos por Victoria
			puntos[k][2] = puntos[k][2] + 1; // Partido Ganado
			puntos[i][4] = puntos[i][4] + 1; // Partido Perdido
		}else{
			puntos[i][8] = puntos[i][8] + 1; // Punto por Empate
			puntos[k][8] = puntos[k][8] + 1; // Punto por Empate
			puntos[i][3] = puntos[i][3] + 1; // Partido Empatado
			puntos[k][3] = puntos[k][3] + 1; // Partido Empatado
		}
		k=k+2;		
	}
//	system("cls");

	// JORNADA 2

	cout << "Jornada 2" << endl;
	k=3;
	for(i=1; i<=2; i=i+1){
		cout << "Partido: " << equipos[i] << " VS "<< equipos[k] << endl;
		cout << "Ingrese el resultado: " << endl << equipos[i] << " ";
		// Partido Jugado
		puntos[i][1] = puntos[i][1] + 1;
		puntos[k][1] = puntos[k][1] + 1;
		// Goles Favor Equipo1
		cin >> aux; 
		puntos[i][5] = puntos[i][5] + aux;
		// Goles Contra Equipo2
		puntos[k][6] = puntos[k][6] + aux; 
		cout << equipos[k] << " ";
		// Goles Favor Equipo2
		cin >> aux2; 
		puntos[k][5] = puntos[k][5] + aux2;
		// Goles Contra Equipo1
		puntos[i][6] = puntos[i][6] + aux2; 
		cout << endl;
		if(aux > aux2){
			puntos[i][8] = puntos[i][8] + 3; // Puntos por Victoria
			puntos[i][2] = puntos[i][2] + 1; // Partido Ganado
			puntos[k][4] = puntos[k][4] + 1; // Partido Perdido
			
		}else if(aux < aux2){
			puntos[k][8] = puntos[k][8] + 3; // Puntos por Victoria
			puntos[k][2] = puntos[k][2] + 1; // Partido Ganado
			puntos[i][4] = puntos[i][4] + 1; // Partido Perdido
		}else{
			puntos[i][8] = puntos[i][8] + 1; // Punto por Empate
			puntos[k][8] = puntos[k][8] + 1; // Punto por Empate
			puntos[i][3] = puntos[i][3] + 1; // Partido Empatado
			puntos[k][3] = puntos[k][3] + 1; // Partido Empatado
		}
		k=k+1;		
	}
	// JORNADA 3

	cout << "Jornada 3" << endl;
	k=4;
	for(i=1; i<=2; i=i+1){
		cout << "Partido: " << equipos[i] << " VS "<< equipos[k] << endl;
		cout << "Ingrese el resultado: " << endl << equipos[i] << " ";
		// Partido Jugado
		puntos[i][1] = puntos[i][1] + 1;
		puntos[k][1] = puntos[k][1] + 1;
		// Goles Favor Equipo1
		cin >> aux; 
		puntos[i][5] = puntos[i][5] + aux;
		// Goles Contra Equipo2
		puntos[k][6] = puntos[k][6] + aux; 
		cout << equipos[k] << " ";
		// Goles Favor Equipo2
		cin >> aux2; 
		puntos[k][5] = puntos[k][5] + aux2;
		// Goles Contra Equipo1
		puntos[i][6] = puntos[i][6] + aux2; 
		cout << endl;
		if(aux > aux2){
			puntos[i][8] = puntos[i][8] + 3; // Puntos por Victoria
			puntos[i][2] = puntos[i][2] + 1; // Partido Ganado
			puntos[k][4] = puntos[k][4] + 1; // Partido Perdido
			
		}else if(aux < aux2){
			puntos[k][8] = puntos[k][8] + 3; // Puntos por Victoria
			puntos[k][2] = puntos[k][2] + 1; // Partido Ganado
			puntos[i][4] = puntos[i][4] + 1; // Partido Perdido
		}else{
			puntos[i][8] = puntos[i][8] + 1; // Punto por Empate
			puntos[k][8] = puntos[k][8] + 1; // Punto por Empate
			puntos[i][3] = puntos[i][3] + 1; // Partido Empatado
			puntos[k][3] = puntos[k][3] + 1; // Partido Empatado
		}
		k=k-1;		
	}
	// Calcular DIF
	for(i=1; i<=4; i=i+1){
		puntos[i][7] = puntos[i][5] - puntos[i][6];
	}
	
	// Ordenar por Puntos
	for(k=1;k<=3;k=k+1){
		// Si 1 < 2
		if(puntos[1][8] < puntos[2][8]){
			aux4 = equipos[1];
			equipos[1] = equipos[2];
			equipos[2] = aux4;
			for(i=1;i<=8;i=i+1){
				aux3[1][i] = puntos[1][i];
			}
			for(i=1;i<=8;i=i+1){
				puntos[1][i] = puntos[2][i];
			}
			for(i=1;i<=8;i=i+1){
				puntos[2][i] = aux3[1][i];
			}
		}
		// Si 2 < 3
		if(puntos[2][8] < puntos[3][8]){
			aux4 = equipos[2];
			equipos[2] = equipos[3];
			equipos[3] = aux4;
			for(i=1;i<=8;i=i+1){
				aux3[2][i] = puntos[2][i];
			}
			for(i=1;i<=8;i=i+1){
				puntos[2][i] = puntos[3][i];
			}
			for(i=1;i<=8;i=i+1){
				puntos[3][i] = aux3[2][i];
			}
		}
		// Si 3 < 4
		if(puntos[3][8] < puntos[4][8]){
			aux4 = equipos[3];
			equipos[3] = equipos[4];
			equipos[4] = aux4;
			for(i=1;i<=8;i=i+1){
				aux3[3][i] = puntos[3][i];
			}
			for(i=1;i<=8;i=i+1){
				puntos[3][i] = puntos[4][i];
			}
			for(i=1;i<=8;i=i+1){
				puntos[4][i] = aux3[3][i];
			}
		}
		
	}
	// Imprimir Tabla
	//cout << "País	" << "Juegos	" << "Ganados	" << "Empatados " << "Perdidos	" << "GF	" << "GC	" <<  "DIF	" << "PTS" << endl;
	for (i=1; i<=4; i=i+1){
		cout << equipos[i] << "	" << 
		puntos[i][1] << "	" <<
		puntos[i][2] << "	" <<
		puntos[i][3] << "	" <<
		puntos[i][4] << "	" << 
		puntos[i][5] << "	" << 
		puntos[i][6] << "	" <<
		puntos[i][7] << "	" << 
		puntos[i][8] << endl;
	}
	system("pause");
}
