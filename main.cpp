#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include "funciones.h"

using namespace std;

string leerNoVacio(string mensaje) {
    string entrada;
    do {
        cout << mensaje;
        getline(cin, entrada);
        if (entrada.empty()) {
            cout << "Este campo no puede estar vacio. Intente de nuevo." << endl;
        }
    } while (entrada.empty());
    return entrada;
}

int main(int argc, char** argv) {
	string codigoPelicula = "";
	string ruta = "archivoPeliculas.txt";
	Pelicula peliculaNueva;
	int opcion = -1;
	Pelicula peli;
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
		cout << "Elija una opcion: ";
		if(!(cin >> opcion)) {
			cout << "Error. Por favor, ingrese un numero entero." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			opcion = -1;
		} else {
		}

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
			cout << "Codigo: "; cin >> peliculaNueva.codigo;
			cin.ignore(); 
			peliculaNueva.nombrePelicula = leerNoVacio("Nombre de la pelicula: ");
			peliculaNueva.genero = leerNoVacio("Genero: ");
			peliculaNueva.duracion = leerNoVacio("Duracion: ");
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
				
				peliculaActualizada.nombrePelicula = leerNoVacio("Nombre de la pelicula: ");
				peliculaActualizada.genero = leerNoVacio("Genero: ");
				peliculaActualizada.duracion = leerNoVacio("Duracion: ");
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
