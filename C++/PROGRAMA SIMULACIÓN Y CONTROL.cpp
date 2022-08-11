// PROGRAMA SIMULACIÓN Y CONTROL ELABORADO POR: CARLOS FERRER
// Rev Enero 2022

#include<iostream> // Mostrar datos en pantalla
#include<fstream> // leer y escribir en un archivo de texto
#include<windows.h> // Control de ejecución (tiempo de refrescamiento de pantalla)
using namespace std;

int main()
{
 string bomba="APAGADA";
 double presion=38;
 string pantalla="ON";
 string valvula_d="CERRADA";
 int aux=1;
string a_nivel="ON";
string b_nivel="ON"; 
int nivel=50;
 
 
 // Leemos los datos del archivo de texto prueba a través de la función
 // Casabe (Puede ser cualquier nombre)
 
 inicio:
 
 ifstream casabe("d:\\prueba.txt"); 
  
 
 string valvula;
 string modobomba;

  
 casabe >>valvula>>modobomba; 
 
 
 //CHEQUEO EL MODO DE OPERACIÓN DE LA BOMBA
 
 if (modobomba=="REMOTO")
 	{
  	aux=0;
  	pantalla="ON";
 	}
 if (modobomba=="LOCAL")
 	{
  	aux=1;
  	pantalla="ON";
	}
 
 
 
 // HACEMOS TODOS LOS CÁLCULOS PARA EL MODO REMOTO AUTOMÁTICO
  
 if (aux==0)
 	{
  
 // imprimimos los valores en pantalla para el modo Remoto
 
 
 	if(pantalla=="ON")
 		{
		system("cls");
 		cout <<"El nivel del tanque (%)= "<<nivel<<endl;
		cout <<"La Presion= "<<presion<<endl;
 		cout <<" - Tu bomba esta= "<<bomba<<endl; 
 		cout <<" - El Switch Alto de nivel= "<<a_nivel<<endl;
 		cout <<" - El Switch bajo de nivel= "<<b_nivel<<endl;
 		cout <<" - La valvula de operacion esta= "<<valvula<<endl;
 		cout <<" - La valvula de desvio esta= "<<valvula_d<<endl;  
    	cout <<" - **** MODO AUTOMATICO REMOTO *****";
 		pantalla ="OFF"; 
   		}	

//  Establecemos un tiempo de 1 de segundo para ver los cambios de la pantalla

    Sleep (1000);
    
    
// Simulamos la Presión    
// Tabla de la verdad de la presión fila 1    
	if (valvula_d=="ABIERTA" and valvula=="ABIERTA" and bomba=="ENCENDIDA")
    	{
    	 if (presion<28)
			{
	 		presion=presion+1;
	 		pantalla ="ON";
	 		}	
	 	if (presion>28)
	 		{
	 		presion=presion-1;
	 		pantalla ="ON";
	 		}
		}
// Tabla de la verdad de la presión fila 2   	  
	if (valvula_d=="ABIERTA" and valvula=="ABIERTA" and bomba=="APAGADA")
    	{
	 	presion=presion-2;
	 	pantalla ="ON";
    	}
 
// Tabla de la verdad de la presión filas 3 y 5  
		if ((valvula_d=="ABIERTA" and valvula=="CERRADA" and bomba=="ENCENDIDA") or (valvula=="ABIERTA" and valvula_d=="CERRADA" and bomba=="ENCENDIDA")  ) 
 	 	{	  
	  		if (presion<32)
	 			{
	 			presion=presion+1;
	 			pantalla ="ON";
	 			}
	 		if (presion>32)
	 			{
	 			presion=presion-1;
	 			pantalla ="ON";
				}
    	}
    
// Tabla de la verdad de la presión filas 4 y 6      
		if ((valvula_d=="ABIERTA" and valvula=="CERRADA" and bomba=="APAGADA") or (valvula=="ABIERTA" and valvula_d=="CERRADA" and bomba=="APAGADA"))
  			{
			presion=presion-1;
	 		pantalla ="ON";
  			}  
// Tabla de la verda de la presión filas 7 
 		if (valvula_d=="CERRADA" and valvula=="CERRADA" and bomba=="ENCENDIDA")
    		{
	 		presion=presion+1;
	 		pantalla ="ON";
    		}
 
 
 //impedimos que la presión de negativo
  
     	if (presion<0)
    		{
     		presion=0;
     		pantalla ="OFF";
     		}

    // Controlamos el encendido y apagado de la bomba
    
 //Tabla de la verdad de la bomba filas 6,8,14,16,22 y 24
     
     	if (b_nivel=="OFF" and bomba=="ENCENDIDA")
    		{
     		bomba="APAGADA";
        	pantalla ="ON";
 			} 
//Tabla de la verdad de la bomba filas 18 y 20

      	if (presion>40 and bomba=="ENCENDIDA")
    		{
     		bomba="APAGADA";
        	pantalla ="ON";
			} 
//Tabla de la verdad de la bomba fila 1    
        if (b_nivel=="ON" and a_nivel=="ON" and presion<20 and bomba=="APAGADA")
    		{
     		bomba="ENCENDIDA";
        	pantalla ="ON";
			} 

//Tabla de la verdad de la bomba fila 3  
         if (b_nivel=="ON" and a_nivel=="OFF" and presion<20 and bomba=="APAGADA")
    		{
     		bomba="ENCENDIDA";
        	pantalla ="ON";
 			} 
 
//Tabla de la verdad de la bomba fila 11   
          if (b_nivel=="ON" and a_nivel=="OFF" and presion>20 and presion<40 and bomba=="APAGADA")
    		{
     		bomba="ENCENDIDA";
        	pantalla ="ON";
 			} 
  
 //controlamos la válvula de desvió
 
 //Tabla de la verdad de la válvula de desvió fila 2  
         if (b_nivel=="OFF" and a_nivel=="OFF" and valvula_d=="CERRADA")
    		{
     		valvula_d="ABIERTA";
        	pantalla ="ON";
 			} 
 
  //Tabla de la verdad de la válvula de desvió fila 4  
        if (b_nivel=="ON" and a_nivel=="OFF" and valvula_d=="CERRADA")
    		{
     		valvula_d="ABIERTA";
        	pantalla ="ON";
 			}    
 
  //Tabla de la verdad de la válvula de desvió fila 5
        if (b_nivel=="OFF" and a_nivel=="ON" and valvula_d=="ABIERTA")
    		{
     		valvula_d="CERRADA";
        	pantalla ="ON";
 			} 
     
 //Agregamos la simulación de nivel

 //Tabla de la verdad fila Nro 1
 if (bomba=="APAGADA" and valvula=="ABIERTA" and valvula_d=="ABIERTA")
 		{
 			nivel=nivel-1;
 			pantalla ="ON";
	 	}

 //Tabla de la verdad filas Nro 4 y 8	
 if ((bomba=="APAGADA" and valvula=="CERRADA" and valvula_d=="CERRADA")or(bomba=="ENCENDIDA" and valvula=="CERRADA" and valvula_d=="CERRADA"))
 		{
 			nivel=nivel+1;
 			pantalla ="ON";
	 	} 
 //Tabla de la verdad filas Nro 6 y 7	
 if (bomba=="ENCENDIDA" and valvula!=valvula_d)
 		{
 			nivel=nivel-2;
 			pantalla ="ON";
	 	} 

 //Tabla de la verdad fila Nro 5
 if (bomba=="ENCENDIDA" and valvula=="ABIERTA" and valvula_d=="ABIERTA")
 		{
 			nivel=nivel-3;
 			pantalla ="ON";		 	 
     }
  

 //Anclamos el nivel para que no presente valores mayores a 100 y menores a 0   
 if (nivel>100)
     {
     	nivel=100;
	 }    
	 
 if (nivel<0)
     {
     	nivel=0;
	 }  	 
     
     //Simulamos el Switch de Alto nivel
    
 //Tabla de la verdad fila Nro 2 
     if (a_nivel=="ON" and nivel>80)
     {
     a_nivel="OFF";
	 pantalla ="ON";		
	 }
 //Tabla de la verdad fila Nro 3
     if (a_nivel=="OFF" and nivel<70)
     {
     a_nivel="ON";
	 pantalla ="ON";		
	 }     

      //Simulamos el Switch de bajo nivel

 //Tabla de la verdad fila Nro 2     
     if (b_nivel=="ON" and nivel<20)
     {
     b_nivel="OFF";
	 pantalla ="ON";		
	 }
 //Tabla de la verdad fila Nro 3
     if (b_nivel=="OFF" and nivel>30)
     {
     b_nivel="ON";
	 pantalla ="ON";		
	 }     
         
	}
 
  // PRESENTAMOS LOS DATOS DEL MODO LOCAL
  
 if (aux==1)
 	{	
  	// imprimimos los valores en pantalla para el modo Local
  	if(pantalla=="ON")
 		{	
 		system("cls");
    	cout <<" **** MODO LOCAL - EL PROGRAMA NO CONTROLA LA BOMBA*****";
 		pantalla ="OFF"; 
   		} 
    }
 
 goto inicio;
 
}