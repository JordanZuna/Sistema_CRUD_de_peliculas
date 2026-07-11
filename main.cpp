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
			mostrarPeliculas(ruta);
			break;
		case 2:
			// funcion buscar pelicula
		case 3:
			cout << "Codigo pelicula: "; cin >> peliculaNueva.codigo;
			cin.ignore();
			cout << "Titulo de la pelicula: "; getline(cin, peliculaNueva.nombrePelicula);
			cout << "Genero: "; getline(cin, peliculaNueva.genero);
			cout << "Duracion: "; getline(cin, peliculaNueva.duracion);
			agregar(peliculaNueva, ruta);
			break;
		case 4:
			// funcion actualizar			
		case 5:
			//funcion eliminar
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
