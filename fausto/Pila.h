#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
class Pila
{
	public:
		
		Pila();
		void insertar(Nodo );
		void recorrerPosiciones();
    	void eliminar();
    	
		Nodo *tope;
	
};

#endif
