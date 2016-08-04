#include "Pila.h"
#include <iostream>
#include "fstream"
#include <string.h>
#include <cstdlib>
using namespace std;

Pila::Pila(){
	
	this->tope=NULL;
}

void Pila::insertar(Nodo dato){
    
	Nodo *nuevo;
    nuevo = new Nodo;
    
	if(nuevo){
        
		(*nuevo)=dato;
        nuevo->enl=tope;
        tope=nuevo;
    }
	else
        cout << "\nNo hay Memoria";
}

void Pila::recorrerPosiciones(){
	
	Nodo *recor;
	recor=tope;
	
	while(recor){
		
		cout<<" X: "<<recor->X<<" Y: "<<recor->Y<<endl;
		recor=recor->enl;
		
	}
}
