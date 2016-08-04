#include "Principal.h"
#include <iostream>
#include <ctype.h>
#include "fstream"
#include <string.h>
#include <cstdlib>

using namespace std;

Principal::Principal(){
	
}

void Principal::LeerArchivo(){
	
	ifstream leer("etiquetas.txt");
	char aux[200];
	
	if(leer.is_open()){
		
		while(!leer.eof()){
			
			leer.getline(aux,200,'\n');
			verificarParrafos(aux);
		}
		
	}
}

void Principal::verificarParrafos(char* auxiliar){
	
	int V_I=0;
	bool bandera=false,reci=false;
	char aux_variables;
	Nodo *recor;
	recor=datos.tope;
	int iter=0,iteracion=0;

	for(int i=0;i<strlen(auxiliar);i++){
	
		if(auxiliar[i]=='<' && auxiliar[i+1]!='/'){
			
			V_I=i;
			
			bandera=verificar(bandera,auxiliar,V_I);
			
			if(bandera){
				
				if(isupper(auxiliar[i+1])){
					
					GuardarPila_variables(auxiliar[i+1],iter);	
					iter++;
				}
				
				bandera=false;
			}		
		}
		
		if(auxiliar[i]=='<' && auxiliar[i+1]=='/'){
			
			if(isupper(auxiliar[i+2])){
				
				GuardarCierres(auxiliar[i+2],iteracion);
				iteracion++;
			}
		}
		
	}
	
	Salida(iteracion);
}

bool Principal::verificar(bool bandera,char* auxiliar,int v){ // verifica si hay cierre de >
	
	while(!bandera){
				
		if(auxiliar[v]=='>'){
					
			bandera=true;
		}
				
		v++;
	}
	
	return bandera;
	
}


void Principal::Salida(int iter){

	Nodo *recor,*aux;
	int i=0,j=0,k=0,valor=0,numero=0;
	char variableauxiliar,variableaux;
	bool bandera;
	
	recor=datos.tope;
	aux=recor;
	
	while(recor){
		
		while(aux){ // creo un auxiliar de recorrido
		
			valor++;
			aux=aux->enl; // busco cuantos Nodos poseo en la pila 
				
		}
		
		if(valor==iter){ // si son iguales, tengo el mismo valor de ambos para comparar la etiqueta
			
			if(i<iter){
				
				if(recor->apertura==Variables[i]){ // orden de las etiquetas
				
					i++;	
					numero=1;
				}	
				else{
					
					variableauxiliar=recor->apertura; // etiquetas con orden incorrectas
					numero=2;
					break;	
				}
			}	
		}
		
		if(valor>iter){ // mayor apertura
			
			if(j<iter){
				
				if(recor->apertura==Variables[j]){ 
			
					j++;		
					numero=4;
				}
						
			}
			else{
				
				variableaux=recor->apertura;
			}	
			
		}
		
		if(valor<iter){ // menor apertura
			
			if(recor->apertura==Variables[k]){
				
				k++;
				numero=3;
			}
		}
		
		recor=recor->enl;
	}		
	
	switch(numero){
		
		case 1: cout<<"Correctly tagged paragraph"<<endl; 
		break;
		case 2: cout<<"Expected </"<<variableauxiliar<<"> found </"<<Variables[i]<<">"<<endl; 
		break;
		case 3: cout<<"Expected # "<<" found </"<<Variables[k]<<">"<<endl; 
		break;
		case 4:	cout<<"Expected </"<<variableaux<<"> found #"<<endl; 
		break;
		
	}
	
	datos.eliminar();
}

void Principal::GuardarCierres(char auxiliar,int i){
	
	Variables[i]=auxiliar;
	
}

void Principal::GuardarPila_variables(char auxiliar,int i){
	
	Nodo dato;
	
	dato.apertura=auxiliar;
	datos.insertar(dato);
	
} 
