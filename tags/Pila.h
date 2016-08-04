#ifndef PILA_H
#define PILA_H
#include "Nodo.h"

class Pila
{
	public:
		Pila();
		void insertar(Nodo );
		Nodo* recorrerPila(char ,Nodo* );
    	void eliminar();
    	
		Nodo *tope;
	
};

#endif
