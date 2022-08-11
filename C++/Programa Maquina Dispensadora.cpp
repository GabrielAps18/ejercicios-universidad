/* Programa elaborado por */

using namespace std;
#include <iostream> 	// Mostrar datos en pantalla
#include <fstream> 		// Leer y escribir en un archivo de texto
#include <windows.h>	// Control de ejecucion (tiempo de refrescamiento de pantalla)
#include <ctime>		//Tiempo
#include <ctype.h>

int pago(float costo, int disp, int cent1, int cent5, int cent10, int cent25, int cent50, int dolar, string tipo);

int main(){
	int cent1, cent5, cent10, cent25, cent50, dolar, op, res, i;
	string PASS = "USM", trypass, tipo, tiempo[10];
	int coke = 5, casera = 5, rade = 5, water = 5;
	float usm_coke = 1.15;
	float usm_casera = 1.25;
	float usmrade = 1.35;
	float usm_water = 0.95;
	string fecha_hora[10], producto[10];
	
	inicio:
	//Imprimimos el menu
	system("cls");
	time_t tiempoahora;
    time(&tiempoahora);
    ctime(&tiempoahora);

	cout << "\t\t************************" <<endl;
	cout << "\t\t* Bienvenido a USM Dry *" << endl;
	cout << "\t\t************************" <<endl << endl;
	cout << "\t(1) USM COKE\t\t1.15$ (" << coke << " disp)" <<endl <<"\t(2) USM CASERA LIMON\t1.25$ (" << casera << " disp)" <<endl << "\t(3) USMRADE\t\t1.35$ (" << rade << " disp)" <<endl << "\t(4) USM WATER\t\t0.95$ (" << water << " disp)" <<endl << "\t(5) REPORTE";
	
	//Solicitamos la opcion que desea comprar
	cout << endl << endl << "Seleccione una bebida: "; cin >> op;
	
	//Leemos archivo
	ifstream monedas("archivo de texto monedas.txt");
	monedas >> cent1 >> cent5 >> cent10 >> cent25 >> cent50 >> dolar;
	
	//Opciones de compra
	if(op == 1){
		tipo = "USM Coke";
		res = pago(usm_coke, coke, cent1, cent5, cent10, cent25, cent50, dolar, tipo);
		if(res == 1){
			coke = coke - 1;
			for(i = 9; i >= 1; i--){
				producto[i] = producto[i-1];
				tiempo[i] = tiempo[i-1];
			}
			producto[0] = tipo;
			time_t tiempoahora;
		    time(&tiempoahora);
		    ctime(&tiempoahora);
			tiempo[0] = ctime(&tiempoahora);
		}
		if(res == 0){
			
		}
		goto inicio;
	}
	if(op == 2){
		tipo = "USM Casera Limon";
		res = pago(usm_casera, casera, cent1, cent5, cent10, cent25, cent50, dolar, tipo);
		if(res == 1){
			casera = casera - 1;
			for(i = 9; i >= 1; i--){
				producto[i] = producto[i-1];
				tiempo[i] = tiempo[i-1];
			}
			producto[0] = tipo;
			time_t tiempoahora;
		    time(&tiempoahora);
		    ctime(&tiempoahora);
			tiempo[0] = ctime(&tiempoahora);
		}
		if(res == 0){
			
		}
		goto inicio;
	}
	if(op == 3){
		tipo = "USMRADE";
		res = pago(usmrade, rade, cent1, cent5, cent10, cent25, cent50, dolar, tipo);
		if(res == 1){
			rade = rade - 1;
			for(i = 9; i >= 1; i--){
				producto[i] = producto[i-1];
				tiempo[i] = tiempo[i-1];
			}
			producto[0] = tipo;
			time_t tiempoahora;
		    time(&tiempoahora);
		    ctime(&tiempoahora);
			tiempo[0] = ctime(&tiempoahora);
		}
		if(res == 0){
			
		}
		goto inicio;
	}
	if(op == 4){
		tipo = "USM Water";
		res = pago(usm_water, water, cent1, cent5, cent10, cent25, cent50, dolar, tipo);
		if(res == 1){
			water = water - 1;
			for(i = 9; i >= 1; i--){
				producto[i] = producto[i-1];
				tiempo[i] = tiempo[i-1];
			}
			producto[0] = tipo;
			time_t tiempoahora;
		    time(&tiempoahora);
		    ctime(&tiempoahora);
			tiempo[0] = ctime(&tiempoahora);
		}
		if(res == 0){
			
		}
		goto inicio;
	}
	if(op == 5){
		system("cls");
		cout << endl << "\tIngrese la password para poder acceder: "; cin >> trypass;
		if(trypass == PASS){
			system("cls");
			cout << "\t\t\tTRANSACCIONES EJECUTADAS" << endl << endl;
			cout << "\tPRODUCTO VENDIDO\t\tHORA DE LA TRANSACCION" << endl << endl;
			for (i = 0; i <= 9; i++){
				cout << "\t" << i + 1 << "-. " << producto[i] << "\t\t\t" << tiempo[i] << endl;
			}
		}else{
			cout << endl << endl << "ERROR La password ingresada es erronea";
		}
	}
	
}

int pago(float costo, int disp, int cent1, int cent5, int cent10, int cent25, int cent50, int dolar, string tipo){
	int salir = 0, agg, opvuelto, v1 = 0, v5 = 0, v10 = 0, v25 = 0, v50 = 0, vdolar = 0, i;
	float monto = 0, cal_vuelto = 0, vuelto = 0;
	if(disp == 0){
		system("cls");
		cout << endl << "\tEsa bebida NO esta disponible" << endl <<endl;
		system("pause");
		return 0;
	}
	do{
		agg = 0;
		system("cls");
		cout << "\t\tMonedas disponiples para el cambio:" << endl << endl;
		cout << cent1 << " de 1 centavo - " << cent5 << " de 5 centavos - " << cent10 << " de 10 centavos - " << cent25 << " de 25 centavos - " << cent50 << " de 50 centavos - " << dolar << " de 1 dolar" << endl;
		cout<< endl << "\tMONTO INGRESADO: " << monto << endl;
		cout << endl << "\t(1) = 1 Centavo";
		cout << endl << "\t(2) = 5 Centavos";
		cout << endl << "\t(3) = 10 Centavos";
		cout << endl << "\t(4) = 25 Centavos";
		cout << endl << "\t(5) = 50 Centavos";
		cout << endl << "\t(6) = 1 Dolar";
		cout << endl << "\t(7) = CONTINUAR";
		cout << endl << endl << "Que moneda desea ingresar? "; cin >> agg;
		
		if(agg == 1){
			cent1 = cent1 + 1;
			monto = monto + 0.01;
		}
		if(agg == 2){
			cent5 = cent5 + 1;
			monto = monto + 0.05;
		}
		if(agg == 3){
			cent10 = cent10 + 1;
			monto = monto + 0.10;
		}
		if(agg == 4){
			cent25 = cent25 + 1;
			monto = monto + 0.25;
		}
		if(agg == 5){
			cent50 = cent50 + 1;
			monto = monto + 0.50;
		}
		if(agg == 6){
			dolar = dolar + 1;
			monto = monto + 1;
		}
		if(agg == 7){
			salir = 7;
		}
		
	} while (salir != 7);
	
	//Verificamos que el dinero este completo
	if(monto < costo){
		system("cls");
		cout << endl << "\tMonto insuficiente, compra CANCELADA!" << endl << endl;
		fin:
		cout << "\t\tSe le ha regresado " << monto << "$" << endl << endl << "\t";
		system("pause");
		return 0;
	}else{
		cal_vuelto = monto - costo;
		do{
			//Verificamos tener vuelto disponible
			if((cent1 * 0.01 + cent5 * 0.05 + cent10 * 0.1 + cent25 * 0.25 + cent50 * 0.5 + dolar) < cal_vuelto){
				system("cls");
				cout << endl << "\tLo sentimos, no podemos darle vuleto";
				cout << endl << endl << "Pulse (1) para CANCELAR la compra o (2) para entregarle el cambio hasta donde sea posible: "; cin >> opvuelto;
				if(opvuelto = 1){
					goto fin;
				}else{
					
				}
			}
		again:
		//Calculamos el vuelto
			if(cal_vuelto > 0){
				if(cal_vuelto >= 1 && dolar > 0){
					vuelto = vuelto + 1;
					cal_vuelto = cal_vuelto - 1;
					dolar = dolar - 1;
					vdolar = vdolar + 1;
					goto again;
				}
				if(cal_vuelto >= 0.5 && cent50 > 0){
					vuelto = vuelto + 0.5;
					cal_vuelto = cal_vuelto - 0.5;
					cent50 = cent50 - 1;
					v50 = v50 + 1;
					goto again;
				}
				if(cal_vuelto >= 0.25 && cent25 > 0){
					vuelto = vuelto + 0.25;
					cal_vuelto = cal_vuelto - 0.25;
					cent25 = cent25 - 1;
					v25 = v25 + 1;
					goto again;
				}
				if(cal_vuelto >= 0.1 && cent10 > 0){
					vuelto = vuelto + 0.1;
					cal_vuelto = cal_vuelto - 0.1;
					cent10 = cent10 - 1;
					v10 = v10 + 1;
					goto again;
				}
				if(cal_vuelto >= 0.05 && cent5 > 0){
					vuelto = vuelto + 0.05;
					cal_vuelto = cal_vuelto - 0.05;
					cent5 = cent5 - 1;
					v5 = v5 + 1;
					goto again;
				}
				if(cal_vuelto >= 0.01 && cent1 > 0){
					vuelto = vuelto + 0.01;
					cal_vuelto = cal_vuelto - 0.01;
					cent1 = cent1 - 1;
					v1 = v1 + 1;
					goto again;
				}
				if(cent1 == 0 && cal_vuelto >= 0.01 && cal_vuelto < 0.05){
					system("cls");
					cout << endl << "\tLo sentimos, no podemos mas darle vuleto";
					cout << endl << endl << "Pulse (1) para CANCELAR la compra o (2) para entregarle el cambio hasta donde sea posible: "; cin >> opvuelto;
					if(opvuelto == 1){
						cout << endl;
						goto fin;
					}else{
						goto fin2;
					}
				}
				if(cent5 == 0 && cal_vuelto >= 0.05 && cal_vuelto < 0.1){
					system("cls");
					cout << endl << "\tLo sentimos, no podemos mas darle vuleto";
					cout << endl << endl << "Pulse (1) para CANCELAR la compra o (2) para entregarle el cambio hasta donde sea posible: "; cin >> opvuelto;
					if(opvuelto == 1){
						cout << endl;
						goto fin;
					}else{
						goto fin2;
					}
				}
				if(cent10 == 0 && cal_vuelto >= 0.1 && cal_vuelto < 0.25){
					system("cls");
					cout << endl << "\tLo sentimos, no podemos mas darle vuleto";
					cout << endl << endl << "Pulse (1) para CANCELAR la compra o (2) para entregarle el cambio hasta donde sea posible: "; cin >> opvuelto;
					if(opvuelto == 1){
						cout << endl;
						goto fin;
					}else{
						goto fin2;
					}
				}
				if(cent25 == 0 && cal_vuelto >= 0.25 && cal_vuelto < 0.5){
					system("cls");
					cout << endl << "\tLo sentimos, no podemos mas darle vuleto";
					cout << endl << endl << "Pulse (1) para CANCELAR la compra o (2) para entregarle el cambio hasta donde sea posible: "; cin >> opvuelto;
					if(opvuelto == 1){
						cout << endl;
						goto fin;
					}else{
						goto fin2;
					}
				}
				if(cent50 == 0 && cal_vuelto >= 0.50 && cal_vuelto < 1){
					system("cls");
					cout << endl << "\tLo sentimos, no podemos mas darle vuleto";
					cout << endl << endl << "Pulse (1) para CANCELAR la compra o (2) para entregarle el cambio hasta donde sea posible: "; cin >> opvuelto;
					if(opvuelto == 1){
						cout << endl;
						goto fin;
					}else{
						goto fin2;
					}
				}
				if((cent1 * 0.01 + cent5 * 0.05 + cent10 * 0.1 + cent25 * 0.25 + cent50 * 0.5 + dolar) == 0 && opvuelto == 2){
					cal_vuelto = 0;
				}
			}
		}while(cal_vuelto > 0.01);
		fin2:
		system("cls");
		//Imprimimos mensaje de espera
		for (i = 7; i > 0; i--){
			system("cls");
			cout << endl << "\tSu " << tipo << " sera entregado en " << i << " segundos" << endl;
			Sleep(1000);
			system("cls");
		}
		
		//Imprimimos resultado de la operacion
		cout<< endl << "\tDinero ingresado: " << monto << "$" << endl;
		cout << endl << "Se le entregara " << vuelto << "$ de vuelto." << endl << endl;
		if(v1 > 0)cout << v1 << " monedas de 1 centavo " << endl;
		if(v5 > 0) cout << v5 << " monedas de 5 centavos "<< endl;
		if(v10 > 0) cout << v10 << " monedas de 10 centavos "<< endl;
		if(v25 > 0) cout << v25 << " monedas de 25 centavos "<< endl;
		if(v50 > 0) cout << v50 << " monedas de 50 centavos "<< endl;
		if(vdolar > 0) cout << vdolar << " monedas de 1 dolar"<< endl;
		cout << endl << endl;
		system("pause");
		
		//Actualizamos documento
		ofstream act_monedas("archivo de texto monedas.txt");
		act_monedas << cent1 << "\t" << cent5 << "\t" << cent10 << "\t" << cent25 << "\t" << cent50 << "\t" << dolar;
		
		return 1;
	}
	
}