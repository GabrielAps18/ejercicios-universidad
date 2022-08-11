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
string aux5;
string aux6;
string aux7;

int puntos[5][9];

int aux3[5][9];
int i,k,aux,aux2,m;

main(){
	setlocale(LC_ALL, "spanish");
	cout << "Recomendación: Escribe los nombres de los equipos de forma abreviada, ejemplo..." << endl;
	cout << "FRA, GER, POR, HUN" << endl << endl;
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
			win[m] = equipos[i].substr(0) + equipos[k].substr(0);
			
		}else if(aux < aux2){
			puntos[k][8] = puntos[k][8] + 3; // Puntos por Victoria
			puntos[k][2] = puntos[k][2] + 1; // Partido Ganado
			puntos[i][4] = puntos[i][4] + 1; // Partido Perdido
			m=(i*10)+k;
			win[m] = equipos[k].substr(0) + equipos[i].substr(0);
		}else{
			puntos[i][8] = puntos[i][8] + 1; // Punto por Empate
			puntos[k][8] = puntos[k][8] + 1; // Punto por Empate
			puntos[i][3] = puntos[i][3] + 1; // Partido Empatado
			puntos[k][3] = puntos[k][3] + 1; // Partido Empatado
			m=(i*10)+k;
			win[m] = equipos[i].substr(0) + "0" + equipos[k].substr(0);
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
			m=(i*10)+k;
			win[m] = equipos[i].substr(0) + equipos[k].substr(0);
			
		}else if(aux < aux2){
			puntos[k][8] = puntos[k][8] + 3; // Puntos por Victoria
			puntos[k][2] = puntos[k][2] + 1; // Partido Ganado
			puntos[i][4] = puntos[i][4] + 1; // Partido Perdido
			m=(i*10)+k;
			win[m] = equipos[k].substr(0) + equipos[i].substr(0);
		}else{
			puntos[i][8] = puntos[i][8] + 1; // Punto por Empate
			puntos[k][8] = puntos[k][8] + 1; // Punto por Empate
			puntos[i][3] = puntos[i][3] + 1; // Partido Empatado
			puntos[k][3] = puntos[k][3] + 1; // Partido Empatado
			m=(i*10)+k;
			win[m] = equipos[i].substr(0) + "0" + equipos[k].substr(0);
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
			m=(i*10)+k;
			win[m] = equipos[i].substr(0) + equipos[k].substr(0);
			
		}else if(aux < aux2){
			puntos[k][8] = puntos[k][8] + 3; // Puntos por Victoria
			puntos[k][2] = puntos[k][2] + 1; // Partido Ganado
			puntos[i][4] = puntos[i][4] + 1; // Partido Perdido
			m=(i*10)+k;
			win[m] = equipos[k].substr(0) + equipos[i].substr(0);
		}else{
			puntos[i][8] = puntos[i][8] + 1; // Punto por Empate
			puntos[k][8] = puntos[k][8] + 1; // Punto por Empate
			puntos[i][3] = puntos[i][3] + 1; // Partido Empatado
			puntos[k][3] = puntos[k][3] + 1; // Partido Empatado
			m=(i*10)+k;
			win[m] = equipos[i].substr(0) + "0" + equipos[k].substr(0);
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
	
	// Comparar empate total
	if(puntos[1][8] == puntos[2][8] and puntos[2][8] == puntos[3][8] and puntos[3][8] == puntos[4][8]){
		if(puntos[1][7] == puntos[2][7] and puntos[2][7] == puntos[3][7] and puntos[3][7] == puntos[4][7]){
			if(puntos[1][5] == puntos[2][5] and puntos[2][5] == puntos[3][5] and puntos[3][5] == puntos[4][5]){
				goto fin;
			}
		}
	}
	
	// Comparar empates triple
	if(puntos[1][8] == puntos[2][8] and puntos[2][8] == puntos[3][8] and puntos[1][8] == puntos[3][8]){
		for(k=1;k<=3;k=k+1){
			if(puntos[1][7] > puntos[2][7]){
			}else if(puntos[1][7] < puntos[2][7]){
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
			}else if(puntos[2][7] < puntos[3][7]){
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
		}
		if(puntos[1][7] == puntos[2][7] and puntos[2][7] == puntos[3][7] and puntos[1][7] == puntos[3][7]){
			k=1;
			for(k=1;k<=3;k=k+1){
				if(puntos[1][5] > puntos[2][5]){
				}else if(puntos[1][5] < puntos[2][5]){
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
				}else if(puntos[2][5] < puntos[3][5]){
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
			}
		}
		
		goto fin;
	}
	
	if(puntos[2][8] == puntos[3][8] and puntos[3][8] == puntos[4][8] and puntos[2][8] == puntos[4][8]){
		for(k=1;k<=3;k=k+1){
			if(puntos[2][7] > puntos[3][7]){
			}else if(puntos[2][7] < puntos[3][7]){
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
			}else if(puntos[3][7] < puntos[4][7]){
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
		if(puntos[2][7] == puntos[3][7] and puntos[3][7] == puntos[4][7] and puntos[2][7] == puntos[4][7]){
			k=1;
			for(k=1;k<=3;k=k+1){
				if(puntos[2][5] > puntos[3][5]){
				}else if(puntos[2][5] < puntos[3][5]){
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
				}else if(puntos[3][5] < puntos[4][5]){
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
		}
		goto fin;
	}
	
	// Comparar empates dobles
	if(puntos[1][8] == puntos[2][8]){
		aux4 = equipos[1].substr(0) + equipos[2].substr(0);
		aux5 = equipos[2].substr(0) + equipos[1].substr(0);
		aux6 = equipos[1].substr(0) + "0" + equipos[2].substr(0);
		aux7 = equipos[2].substr(0) + "0" + equipos[1].substr(0);
		for(i=1; i<=34; i=i+1){
			if(aux4 == win[i]){
				break;
			}else if(aux5 == win[i]){
				aux4 = equipos[1];
				equipos[1] = equipos[2];
				equipos[2] = aux4;
				for(k=1;k<=8;k=k+1){
					aux3[1][k] = puntos[1][k];
				}
				for(k=1;k<=8;k=k+1){
					puntos[1][i] = puntos[2][k];
				}
				for(k=1;k<=8;k=k+1){
					puntos[2][k] = aux3[1][k];
				}
				break;
			}else if(aux6 == win[i] or aux7 == win[i]){
				if(puntos[1][7] > puntos[2][7]){
					break;
				}else if(puntos[1][7] < puntos[2][7]){
					aux4 = equipos[1];
					equipos[1] = equipos[2];
					equipos[2] = aux4;
					for(k=1;k<=8;k=k+1){
						aux3[1][k] = puntos[1][k];
					}
					for(k=1;k<=8;k=k+1){
						puntos[1][i] = puntos[2][k];
					}
					for(k=1;k<=8;k=k+1){
						puntos[2][k] = aux3[1][k];
					}
					break;
				}else if(puntos[1][7] == puntos[2][7]){
					if(puntos[1][5] > puntos[2][5]){
						break;
						}else if(puntos[1][5] < puntos[2][5]){
							aux4 = equipos[1];
						equipos[1] = equipos[2];
						equipos[2] = aux4;
						for(k=1;k<=8;k=k+1){
							aux3[1][k] = puntos[1][k];
						}
						for(k=1;k<=8;k=k+1){
							puntos[1][i] = puntos[2][k];
						}
						for(k=1;k<=8;k=k+1){
							puntos[2][k] = aux3[1][k];
						}
						break;
					}
				}
			}
		}
	}
	if(puntos[2][8] == puntos[3][8]){
		aux4 = equipos[2].substr(0) + equipos[3].substr(0);
		aux5 = equipos[3].substr(0) + equipos[2].substr(0);
		aux6 = equipos[2].substr(0) + "0" + equipos[3].substr(0);
		aux7 = equipos[3].substr(0) + "0" + equipos[2].substr(0);
		for(i=1; i<=34; i=i+1){
			if(aux4 == win[i]){
				break;
			}else if(aux5 == win[i]){
				aux4 = equipos[2];
				equipos[2] = equipos[3];
				equipos[3] = aux4;
				for(k=1;k<=8;k=k+1){
					aux3[2][k] = puntos[2][k];
				}
				for(k=1;k<=8;k=k+1){
					puntos[2][k] = puntos[3][k];
				}
				for(k=1;k<=8;k=k+1){
					puntos[3][k] = aux3[2][k];
				}
				break;
			}else if(aux6 == win[i] or aux7 == win[i]){
				if(puntos[2][7] > puntos[3][7]){
					break;
				}else if(puntos[2][7] < puntos[3][7]){
					aux4 = equipos[2];
					equipos[2] = equipos[3];
					equipos[3] = aux4;
					for(k=1;k<=8;k=k+1){
						aux3[2][k] = puntos[2][k];
					}
					for(k=1;k<=8;k=k+1){
						puntos[2][k] = puntos[3][k];
					}
					for(k=1;k<=8;k=k+1){
						puntos[3][k] = aux3[2][k];
					}
					break;
					}else if(puntos[2][7] == puntos[3][7]){
						if(puntos[2][5] > puntos[3][5]){
							break;
						}else if(puntos[2][5] < puntos[3][5]){
							aux4 = equipos[2];
							equipos[2] = equipos[3];
							equipos[3] = aux4;
							for(k=1;k<=8;k=k+1){
								aux3[2][k] = puntos[2][k];
							}
							for(k=1;k<=8;k=k+1){
								puntos[2][k] = puntos[3][k];
							}
							for(k=1;k<=8;k=k+1){
								puntos[3][k] = aux3[2][k];
							}
							break;
						}
					}
				}

		}
	}
	if(puntos[3][8] == puntos[4][8]){
		aux4 = equipos[3].substr(0) + equipos[4].substr(0);
		aux5 = equipos[4].substr(0) + equipos[3].substr(0);
		aux6 = equipos[3].substr(0) + "0" + equipos[4].substr(0);
		aux7 = equipos[4].substr(0) + "0" + equipos[3].substr(0);
		for(i=1; i<=34; i=i+1){
			if(aux4 == win[i]){
				break;
			}else if(aux5 == win[i]){
				aux4 = equipos[3];
				equipos[3] = equipos[4];
				equipos[4] = aux4;
				for(k=1;k<=8;k=k+1){
					aux3[3][k] = puntos[3][k];
				}
				for(k=1;k<=8;k=k+1){
					puntos[3][k] = puntos[4][k];
				}
				for(k=1;k<=8;k=k+1){
					puntos[4][k] = aux3[3][k];
				}
				break;
			}else if(aux6 == win[i] or aux7 == win[i]){
				if(puntos[3][7] > puntos[4][7]){
					break;
				}else if(puntos[3][7] < puntos[4][7]){
					aux4 = equipos[3];
					equipos[3] = equipos[4];
					equipos[4] = aux4;
					for(k=1;k<=8;k=k+1){
						aux3[3][k] = puntos[3][k];
					}
					for(k=1;k<=8;k=k+1){
						puntos[3][k] = puntos[4][k];
					}
					for(k=1;k<=8;k=k+1){
						puntos[4][k] = aux3[3][k];
					}
					break;
					}else if(puntos[3][7] == puntos[4][7]){
						if(puntos[3][5] > puntos[4][5]){
							break;
						}else if(puntos[3][5] < puntos[4][5]){
							aux4 = equipos[3];
							equipos[3] = equipos[4];
							equipos[4] = aux4;
							for(k=1;k<=8;k=k+1){
								aux3[3][k] = puntos[3][k];
							}
							for(k=1;k<=8;k=k+1){
								puntos[3][k] = puntos[4][k];
							}
							for(k=1;k<=8;k=k+1){
								puntos[4][k] = aux3[3][k];
							}
							break;
						}
				}
			}
		}
	}
	fin:
	// Imprimir Tabla
	cout << "País	" << "Juegos " << "Ganados " << "Empatados " << "Perdidos " << "GF	" << "GC	" <<  "DIF	" << "PTS" << endl << endl;
	for (i=1; i<=4; i=i+1){
		cout << equipos[i] << "	" << 
		puntos[i][1] << "	" <<
		puntos[i][2] << "	" <<
		puntos[i][3] << "	" <<
		puntos[i][4] << "	" << 
		puntos[i][5] << "	" << 
		puntos[i][6] << "	" <<
		puntos[i][7] << "	" << 
		puntos[i][8] << endl << endl;
	}
	system("pause");
}
