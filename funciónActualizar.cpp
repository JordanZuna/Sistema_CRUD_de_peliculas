#include <iostream>
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
	string ruta = "peliculas.txt";
	
	cout << "--- ESTADO INICIAL DEL ARCHIVO ---" << endl;
	mostrarPeliculas(ruta);
	cout << "----------------------------------" << endl;

	string codigoBuscar = "P001"; 

	Pelicula datosNuevos;
	datosNuevos.codigo = codigoBuscar; 
	datosNuevos.nombrePelicula = "Interestelar (Edicion Especial)";
	datosNuevos.genero = "Ciencia Ficcion / Drama";
	datosNuevos.duracion = "169 min";
	
	cout << "\nIntentando actualizar la pelicula con codigo: " << codigoBuscar << "..." << endl;
	
	actualizar(codigoBuscar, datosNuevos, ruta);
	
	cout << "\n--- ESTADO FINAL DEL ARCHIVO ---" << endl;
	mostrarPeliculas(ruta);
	cout << "--------------------------------" << endl;
	
	return 0;
}
