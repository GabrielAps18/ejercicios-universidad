#include <iostream>
using namespace std;

struct musica_cds{
	string titulo;
	string agrupacion;
	int numero_tracks;
	double costo;
	string fecha;
}DVD[200];

main(){
//	struct musica_cds DVD[200];
	
	DVD[1].titulo="Bohemian Rapsody";
	DVD[1].agrupacion="Queen";
	DVD[1].numero_tracks=12;
	DVD[1].costo=15;
	DVD[1].fecha="Enero 1975";
	
	string hola = DVD[1].titulo;
	cout << hola << endl;
	system("pause");

	
}
