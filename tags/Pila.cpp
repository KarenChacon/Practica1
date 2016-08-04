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

Nodo* Pila::recorrerPila(char comparar,Nodo* recor){
	
	if(recor->apertura==comparar){
		recor=recor->enl;
		return recor; 	
	}
	
}

void Pila::eliminar(){
	
	while(tope){
		
        Nodo *aux;
        aux=tope;
        tope=tope->enl;
        free(aux);
    }
}
