#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "funciones.h"

using namespace std;
int main(int argc, char** argv) {
	string codigoPelicula = "";
	string ruta = "archivoPeliculas.txt";
	Pelicula peliculaNueva;
	int opcion = -1;
	Pelicula peli = buscar(codigoPelicula,ruta);
	string codigoEliminar = "";
	string codigoActualizar = "";
	Pelicula peliculaActualizada;
	
	while (opcion!=0){
		cout << "Registro de Peliculas " << endl;
		cout << "Menu de opciones" << endl;
		cout << "1. Ver peliculas" << endl;
		cout << "2. Buscar pelicula por id" << endl;
		cout << "3. Agregar nueva pelicula" << endl;
		cout << "4. Actualizar pelicula" << endl;
		cout << "5. Eliminar pelicula" << endl;
		cout << "0. salir" << endl;
		cout << "Elija una opcion: "; cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "\n--- LISTADO DE PELICULAS ---" << endl;
			mostrarPeliculas(ruta);
			break;
	
			
		case 2:
		cout << "Ingrese el codigo de la pelicula a buscar: ";
			cin >> codigoPelicula;
			
			peli = buscar(codigoPelicula, ruta);
			
			if (peli.codigo != "No encontrado") {
				cout << "Pelicula encontrada:\n";
				cout << peli.mostrar() << endl;
			} else {
				cout << "Error: No se encontro ninguna pelicula con el codigo '" << codigoPelicula << "'." << endl;
			}
			break;
			
		case 3:
		cout << "\n--- AGREGAR NUEVA PELICULA ---" << endl;
			cout << "Codigo: ";
			cin >> peliculaNueva.codigo;
			
			cin.ignore(); 
			
			cout << "Nombre de la pelicula: ";
			getline(cin, peliculaNueva.nombrePelicula);
			
			cout << "Genero: ";
			getline(cin, peliculaNueva.genero);
			
			cout << "Duracion: ";
			getline(cin, peliculaNueva.duracion);
			
			agregar(peliculaNueva, ruta);
		
			break;
		case 4:
			cout << "Ingrese el codigo de la pelicula a actualizar: ";
			cin >> codigoActualizar;
			
			peli = buscar(codigoActualizar, ruta);
			if (peli.codigo != "No encontrado") {
				cout << "Pelicula encontrada: " << peli.nombrePelicula << endl;
				cout << "--- Ingrese los NUEVOS datos ---" << endl;
				
				cin.ignore(); 
				
				cout << "Nuevo Nombre: ";
				getline(cin, peliculaActualizada.nombrePelicula);
				
				cout << "Nuevo Genero: ";
				getline(cin, peliculaActualizada.genero);
				
				cout << "Nueva Duracion: ";
				getline(cin, peliculaActualizada.duracion);
				peliculaActualizada.codigo = codigoActualizar; 
				
				actualizar(codigoActualizar, peliculaActualizada, ruta);
			} else {
				cout << "Error: No se encontro ninguna pelicula con el codigo '" << codigoActualizar << "'." << endl;
			}
			break;			
		case 5:
			cout << "Ingrese el codigo de la pelicula a eliminar: ";
			cin >> codigoEliminar;
			eliminar(codigoEliminar, ruta);		
			break;
		case 0:
			cout << "--- SALIENDO DEL SISTEMA ---" << endl;
			break;
			
		default:
			cout << "Opcion no valida. Vuelva a intentarlo!\n";
			break;
		}
	}
	return 0;
}
