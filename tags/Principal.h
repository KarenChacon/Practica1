#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Nodo.h"
#include "Pila.h"

class Principal
{
	public:
		
		Principal();
		Pila datos; 
		char Variables[20];
		void LeerArchivo();
		void verificarParrafos(char* );
		void GuardarPila_variables(char ,int );
		void GuardarCierres(char ,int );
		void verificarEtiqueta(char );
		void Salida(int );
		void etiquetaIncorrecta(char ,char );
		void imprimirEtiquetas(int );
		
		bool verificar(bool ,char* ,int );
		
};

#endif
