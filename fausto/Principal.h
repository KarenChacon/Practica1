#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Nodo.h"
#include "Pila.h"

class Principal
{
	public:
		
		char **Mapa;
		int Fila;
		int Columna;
		int MovimientoX,MovimientoY;
		int contadorMovimiento;
		
		Pila datos;
		
		Principal();
		void leerDatos();
		void crearMemoria(int Fila,int Colum);
		void mostrar();
		void BuscarFausto();
		void recorrerCamino(int ,int ,int , int );
		void marcarRecorrido();
		void NuevaPosicion();
		void guardarPosiciones();
		void Multiposicion();
		void salida_archivo();
		
		int CrearMapa(char* auxiliar,int iter);
		
		bool verificarLLegada();
		
};

#endif
