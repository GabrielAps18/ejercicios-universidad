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

//variable string donde guardaremos el nombre de los equipos
string equipos[5];
//variable donde asignaremos la victoria, derrota o empate de los enfrentamientos directos para los criterios de desempate por puntos
string win[34];
//varibles auxiliares para guardar valores de resultados
string aux4;
string aux5;
string aux6;
string aux7;
//variable donde guardaremos los valores de la tabla
int puntos[5][9];

int aux3[5][9];
//contadores  y varibles auxiliares 
int i,k,aux,aux2,m;

main(){
	//set para poder usar caracteres en EspañOL
	setlocale(LC_ALL, "spanish");
	cout << "Recomendación: Escribe los nombres de los equipos de forma abreviada, ejemplo..." << endl;
	cout << "FRA, GER, POR, HUN" << endl << endl;
	//Ciclo para introducir los equipos del grupo
	for (i=1; i<=4; i=i+1){
		cout << "Ingrese el equipo número: "<< i << endl;
		cin >> equipos[i];
		//cout << endl;
	}
	system("cls");

	// JORNADA 1
	//ciclo de partidos de la jornada 1, guardaremos todos los datos en la tabla para ir haciendo el recuento de datos
	cout << "Jornada 1" << endl;
	k=2;
	//el for indica la cantidad de partidos que habra por esta jornada
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
		//cadenas de if que validaran lo siguiente:
		//si el equipo  gano, se le asignara sus puntos correspondientes a cada uno y guardara los datos de los goles 
		//se le asignara una variable especial para diferenciar si su enfrentamiento directo fue victoria (segun corresponda), para asi tener preferencia en los criterios de desempate
		if(aux > aux2){
			puntos[i][8] = puntos[i][8] + 3; // Puntos por Victoria
			puntos[i][2] = puntos[i][2] + 1; // Partido Ganado
			puntos[k][4] = puntos[k][4] + 1; // Partido Perdido
			m=(i*10)+k;
			win[m] = equipos[i].substr(0) + equipos[k].substr(0);
		//si el equipo  perdio, se le asignaran sus puntos correspondientes a cada uno y guardara los datos de los goles 
		//se le asignara una variable especial para diferenciar si su enfrentamiento directo fue victoria (segun corresponda), para asi tener preferencia en los criterios de desempate
		}else if(aux < aux2){
			puntos[k][8] = puntos[k][8] + 3; // Puntos por Victoria
			puntos[k][2] = puntos[k][2] + 1; // Partido Ganado
			puntos[i][4] = puntos[i][4] + 1; // Partido Perdido
			m=(i*10)+k;
			win[m] = equipos[k].substr(0) + equipos[i].substr(0);
		//si el equipo  empato, se le asignara sus puntos correspondientes a cada uno y guardara los datos de los goles
		//se le asignara una variable especial para diferenciar si su enfrentamiento directo fue un empato, asi no tendra ninguno preferencia en este criterio de desempate
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
	//ciclo de partidos de la jornada 2, guardaremos todos los datos en la tabla para ir haciendo el recuento de datos
	cout << "Jornada 2" << endl;
	k=3;
	//el for indica la cantidad de partidos que habra por esta jornada
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
		//cadenas de if que validaran lo siguiente:
		//si el equipo  gano, se le asignara sus puntos correspondientes a cada uno y guardara los datos de los goles 
		//se le asignara una variable especial para diferenciar si su enfrentamiento directo fue victoria (segun corresponda), para asi tener preferencia en los criterios de desempate
		if(aux > aux2){
			puntos[i][8] = puntos[i][8] + 3; // Puntos por Victoria
			puntos[i][2] = puntos[i][2] + 1; // Partido Ganado
			puntos[k][4] = puntos[k][4] + 1; // Partido Perdido
			m=(i*10)+k;
			win[m] = equipos[i].substr(0) + equipos[k].substr(0);
		//si el equipo  perdio, se le asignaran sus puntos correspondientes a cada uno y guardara los datos de los goles 
		//se le asignara una variable especial para diferenciar si su enfrentamiento directo fue victoria (segun corresponda), para asi tener preferencia en los criterios de desempate
		}else if(aux < aux2){
			puntos[k][8] = puntos[k][8] + 3; // Puntos por Victoria
			puntos[k][2] = puntos[k][2] + 1; // Partido Ganado
			puntos[i][4] = puntos[i][4] + 1; // Partido Perdido
			m=(i*10)+k;
			win[m] = equipos[k].substr(0) + equipos[i].substr(0);
		//si el equipo  empato, se le asignara sus puntos correspondientes a cada uno y guardara los datos de los goles
		//se le asignara una variable especial para diferenciar si su enfrentamiento directo fue un empato, asi no tendra ninguno preferencia en este criterio de desempate
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
	//ciclo de partidos de la jornada 3, guardaremos todos los datos en la tabla para ir haciendo el recuento de datos
	cout << "Jornada 3" << endl;
	k=4;
	//el for indica la cantidad de partidos que habra por esta jornada
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
		//cadenas de if que validaran lo siguiente:
		//si el equipo  gano, se le asignara sus puntos correspondientes a cada uno y guardara los datos de los goles 
		//se le asignara una variable especial para diferenciar si su enfrentamiento directo fue victoria (segun corresponda), para asi tener preferencia en los criterios de desempate
		if(aux > aux2){
			puntos[i][8] = puntos[i][8] + 3; // Puntos por Victoria
			puntos[i][2] = puntos[i][2] + 1; // Partido Ganado
			puntos[k][4] = puntos[k][4] + 1; // Partido Perdido
			m=(i*10)+k;
			win[m] = equipos[i].substr(0) + equipos[k].substr(0);
		//si el equipo  perdio, se le asignaran sus puntos correspondientes a cada uno y guardara los datos de los goles 
		//se le asignara una variable especial para diferenciar si su enfrentamiento directo fue victoria (segun corresponda), para asi tener preferencia en los criterios de desempate	
		}else if(aux < aux2){
			puntos[k][8] = puntos[k][8] + 3; // Puntos por Victoria
			puntos[k][2] = puntos[k][2] + 1; // Partido Ganado
			puntos[i][4] = puntos[i][4] + 1; // Partido Perdido
			m=(i*10)+k;
			win[m] = equipos[k].substr(0) + equipos[i].substr(0);
		//si el equipo  empato, se le asignara sus puntos correspondientes a cada uno y guardara los datos de los goles
		//se le asignara una variable especial para diferenciar si su enfrentamiento directo fue un empato, asi no tendra ninguno preferencia en este criterio de desempate
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
	// Ciclo para calcular la diferencia de goles de cada equipo
	for(i=1; i<=4; i=i+1){
		puntos[i][7] = puntos[i][5] - puntos[i][6];
	}
	
	// Ciclo que ordenara por puntos (Criterio 1)
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
	
	// Ciclo (criterio 7) Empate total entre los equipos
	if(puntos[1][8] == puntos[2][8] and puntos[2][8] == puntos[3][8] and puntos[3][8] == puntos[4][8]){
		if(puntos[1][7] == puntos[2][7] and puntos[2][7] == puntos[3][7] and puntos[3][7] == puntos[4][7]){
			if(puntos[1][5] == puntos[2][5] and puntos[2][5] == puntos[3][5] and puntos[3][5] == puntos[4][5]){
				goto fin;
			}
		}
	}
	
	// Comparar empates triple
	if(puntos[1][8] == puntos[2][8] and puntos[2][8] == puntos[3][8] and puntos[1][8] == puntos[3][8]){
		//ciclo que valida si empatan los 3 primeros equipos
			//criterio 5: empate triple y se ordena por el que tenga mayor Diferencia de goles
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
			//ciclo que valida si empatan los 3 ultimos equipos
				//criterio 5: empate triple y se ordena por el que tenga mayor Diferencia de goles
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
	//ciclo que valida empates triples
	if(puntos[2][8] == puntos[3][8] and puntos[3][8] == puntos[4][8] and puntos[2][8] == puntos[4][8]){
		//ciclo que valida si empataron los primeros 3 equipos
		 //criterio 6: empate triple con igual diferencia de goles se ordenara por mayor Goles a Favor
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
		//ciclo que valida si empataron los ultimos 3 equipos
		 	//criterio 6: empate triple con igual diferencia de goles se ordenara por mayor Goles a Favor
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
		//Este ciclo valida los enfrenamientos directos de los equipos, le dara la ventaja al que haya ganado su partido en cuanto al posicionamiento del grupo
	//Empate 1er equipo vs 2do equipo
	if(puntos[1][8] == puntos[2][8]){
		//Cada aux almacena un "token" que indica si un equipo ganó el enfrentamiento o empató, el token consiste en Nombre equipo ganador + equipo perdedor
		aux4 = equipos[1].substr(0) + equipos[2].substr(0);
		aux5 = equipos[2].substr(0) + equipos[1].substr(0);
		// Si el enfrentamiento de estos 2 equipos termina en empate, el token tendrá un "0" de por medio
		aux6 = equipos[1].substr(0) + "0" + equipos[2].substr(0);
		aux7 = equipos[2].substr(0) + "0" + equipos[1].substr(0);
		// Se buscará en el array win[] el token en cuestion
		for(i=1; i<=34; i=i+1){
			// Si el equipo 1 le gana al 2 no hay cambio (Criterio 2)
			if(aux4 == win[i]){
				break;
			}else if(aux5 == win[i]){ // Si el equipo 2 le gana al 1 se intercambian los datos (Criterio 2)
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
			}else if(aux6 == win[i] or aux7 == win[i]){ // En caso de empate POR PUNTOS se compara por DIF (Criterio 3)
				if(puntos[1][7] > puntos[2][7]){ // Si el equipo 1 tiene mejor DIF queda igual
					break;
				}else if(puntos[1][7] < puntos[2][7]){ // Si el equipo 2 tiene mejor DIF se cambian los datos
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
				}else if(puntos[1][7] == puntos[2][7]){ // En caso de empate POR DIF se compara por GF (Criterio 4)
					if(puntos[1][5] > puntos[2][5]){	// Si el equipo 1 tiene mejor GF queda igual
						break;
						}else if(puntos[1][5] < puntos[2][5]){ // Si el equipo 2 tiene mejor GF se cambian los datos
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
	//Empate 2do equipo vs 3er equipo
	if(puntos[2][8] == puntos[3][8]){
		//Cada aux almacena un "token" que indica si un equipo ganó el enfrentamiento o empató, el token consiste en Nombre equipo ganador + equipo perdedor
		aux4 = equipos[2].substr(0) + equipos[3].substr(0);
		aux5 = equipos[3].substr(0) + equipos[2].substr(0);
		// Si el enfrentamiento de estos 2 equipos termina en empate, el token tendrá un "0" de por medio
		aux6 = equipos[2].substr(0) + "0" + equipos[3].substr(0);
		aux7 = equipos[3].substr(0) + "0" + equipos[2].substr(0);
		// Se buscará en el array win[] el token en cuestion
		for(i=1; i<=34; i=i+1){
			// Si el equipo 2 le gana al 3 no hay cambio (Criterio 2)
			if(aux4 == win[i]){
				break;
			}else if(aux5 == win[i]){ // Si el equipo 3 le gana al 2 se intercambian los datos (Criterio 2)
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
			}else if(aux6 == win[i] or aux7 == win[i]){ // En caso de empate POR PUNTOS se compara por DIF (Criterio 3)
				if(puntos[2][7] > puntos[3][7]){	// Si el equipo 2 tiene mejor DIF queda igual
					break;
				}else if(puntos[2][7] < puntos[3][7]){ // Si el equipo 3 tiene mejor DIF se cambian los datos
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
					}else if(puntos[2][7] == puntos[3][7]){ // En caso de empate POR DIF se compara por GF (Criterio 4)
						if(puntos[2][5] > puntos[3][5]){  // Si el equipo 2 tiene mejor GF queda igual
							break;
						}else if(puntos[2][5] < puntos[3][5]){ // Si el equipo 3 tiene mejor GF se cambian los datos
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
	//Empate 3er equipo vs 4to equipo
	if(puntos[3][8] == puntos[4][8]){
		//Cada aux almacena un "token" que indica si un equipo ganó el enfrentamiento o empató, el token consiste en Nombre equipo ganador + equipo perdedor
		aux4 = equipos[3].substr(0) + equipos[4].substr(0);
		aux5 = equipos[4].substr(0) + equipos[3].substr(0);
		// Si el enfrentamiento de estos 2 equipos termina en empate, el token tendrá un "0" de por medio
		aux6 = equipos[3].substr(0) + "0" + equipos[4].substr(0);
		aux7 = equipos[4].substr(0) + "0" + equipos[3].substr(0);
		// Se buscará en el array win[] el token en cuestion
		for(i=1; i<=34; i=i+1){
			// Si el equipo 3 le gana al 4 no hay cambio (Criterio 2)
			if(aux4 == win[i]){
				break;
			}else if(aux5 == win[i]){	// Si el equipo 4 le gana al 3 se intercambian los datos (Criterio 2)
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
			}else if(aux6 == win[i] or aux7 == win[i]){ // En caso de empate POR PUNTOS se compara por DIF (Criterio 3)
				if(puntos[3][7] > puntos[4][7]){	// Si el equipo 3 tiene mejor DIF queda igual
					break;
				}else if(puntos[3][7] < puntos[4][7]){	// Si el equipo 4 tiene mejor DIF se cambian los datos
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
					}else if(puntos[3][7] == puntos[4][7]){	// En caso de empate POR DIF se compara por GF (Criterio 4)
						if(puntos[3][5] > puntos[4][5]){	// Si el equipo 3 tiene mejor GF queda igual
							break;
						}else if(puntos[3][5] < puntos[4][5]){	// Si el equipo 4 tiene mejor GF se cambian los datos
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
	// despues de que todos los partidos hayan sido pasados por cada unos de los criterios, se imprimira la tabla segun el orden correspondiente
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
