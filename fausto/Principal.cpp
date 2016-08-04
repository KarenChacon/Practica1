#include "Principal.h"
#include <iostream>
#include "fstream"
#include <string.h>
#include <cstdlib>
using namespace std;


Principal::Principal(){
	
	MovimientoX=0;
	MovimientoY=0;
	contadorMovimiento=0;
}

void Principal::leerDatos(){
	
	ifstream leer("fausto.txt");
	char aux[100],auxMatriz;
	int Fil=0,colum=0,iteraciones=0;
	
	if(leer.is_open()){
		
		while(!leer.eof()){
			
			leer.getline(aux,100,'\n');
			Fil=strlen(aux);
			colum++;
		}
			
	}
	
	leer.close();
	leer.open("fausto.txt");
	crearMemoria(Fil,colum);
	
	if(leer.is_open()){
		
		while(!leer.eof()){
			
			leer>>aux;	
			CrearMapa(aux,iteraciones);
			iteraciones++;
			
		}	
	}
	
	leer.close();
	BuscarFausto();
//	mostrar();
}

void Principal::crearMemoria(int Fil,int colum){
	
	Mapa=new char*[Columna];
	Fila=Fil;
	Columna=colum;
	
	for(int i=0;i<Columna;i++){
		
		Mapa[i]=new char[Fila];	
		
	}

}

int  Principal::CrearMapa(char* auxiliar,int iter){
	
	
	for(int j=0;j<Fila;j++){
			
			Mapa[iter][j]=auxiliar[j];
			
	}
	
}

void Principal::mostrar(){
	
	for(int i=0;i<Columna;i++){
       
	   for(int j=0;j<Fila;j++)
         	cout <<Mapa[i][j];
       		
			   cout << "\n";
    }
}

void Principal::BuscarFausto(){
	
	int arriba=0,abajo=0,izquierda=0,derecha=0;
	
	for(int i=0;i<Columna;i++){
       
	   for(int j=0;j<Fila;j++){
			
			if(Mapa[i][j]=='*'){
				
				MovimientoX=i;
				MovimientoY=j;
				guardarPosiciones();
				recorrerCamino(arriba,abajo,izquierda,derecha);
				
			}   	
	   }
	}
	
	contadorMovimiento;
	if(verificarLLegada()){
		
		contadorMovimiento++;
			
	}
	
	datos.recorrerPosiciones();
	salida_archivo();
	mostrar();
}

void Principal::recorrerCamino(int arriba,int abajo,int izquierda,int derecha){
	
	if(Mapa[MovimientoX+1][MovimientoY]=='.' && arriba==0){ //abajo
		
		marcarRecorrido();
		MovimientoX++;
		Multiposicion();
		recorrerCamino(0,1,0,0);
	}
	
	if(Mapa[MovimientoX-1][MovimientoY]=='.' && abajo==0 ){// arriba
	
		marcarRecorrido();
		MovimientoX--;
		Multiposicion();
		recorrerCamino(1,0,0,0);
	}	
	
	if(Mapa[MovimientoX][MovimientoY-1]=='.' && derecha==0 ){ // izquierrda
	
		marcarRecorrido();		
		MovimientoY--;
		Multiposicion();
		recorrerCamino(0,0,1,0);
	}
	
	if(Mapa[MovimientoX][MovimientoY+1]=='.' && izquierda==0){ // derecha
		
		marcarRecorrido();
		MovimientoY++;
		Multiposicion();	
		recorrerCamino(0,0,0,1);
	}
		
}

void Principal::guardarPosiciones(){
	
	Nodo dato;
	
	dato.X=MovimientoX;
	dato.Y=MovimientoY;	
	datos.insertar(dato);
	
}

void Principal::Multiposicion(){
	
	NuevaPosicion();
	guardarPosiciones();
	contadorMovimiento++;
	
}

void Principal::NuevaPosicion(){
	
	Mapa[MovimientoX][MovimientoY]='H';
	
}
void Principal::marcarRecorrido(){
	
	Mapa[MovimientoX][MovimientoY]='-';
}

bool Principal::verificarLLegada(){
	
	if(Mapa[MovimientoX][MovimientoY+1]=='O' ){ //derecha 
		
		MovimientoY++;
		guardarPosiciones();
		return true;
		
	}
	if(Mapa[MovimientoX][MovimientoY-1]=='O' ){ // izquierda
		
		MovimientoY--;
		guardarPosiciones();
		return true;
		
	}
	if(Mapa[MovimientoX+1][MovimientoY]=='O' ){ //abajo
		
		MovimientoX++;
		guardarPosiciones();
		return true;
		
	}
	if(Mapa[MovimientoX-1][MovimientoY]=='O' ){ //arriba
		
		MovimientoX--;
		guardarPosiciones();
		return true;
		
	}
	
	return false;
}

void Principal::salida_archivo(){
	
	ofstream salida("llegada.txt");
	Nodo *recor;
	recor=datos.tope;
	
	if(salida.is_open()){
		
		salida<<"Movimientos: "<<contadorMovimiento<<endl;
		while(recor){
			
			salida<<"X : "<<recor->X<<" Y: "<<recor->Y<<endl;
			recor=recor->enl;
		}
	}
	
}
