#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "funciones.h"
using namespace std;

ostream& operator<<(ostream& os, const Pelicula& peli){
	os << peli.codigo << ";" << peli.nombrePelicula << ";" << peli.genero
	<< ";" << peli.duracion << endl;
	return os;
}

ostream& operator<<(ostream& os, const vector<Pelicula>& pelicula) {
	for(const auto& p : pelicula){
		os << p;
	}
	return os;
}

istream& operator>>(istream& is, Pelicula& peli){
	if(
	   getline(is, peli.codigo, ';')&&
	   getline(is, peli.nombrePelicula, ';')&&
	   getline(is, peli.genero, ';')&&
	   getline(is, peli.duracion)
	   ){
		if (!peli.duracion.empty() && peli.duracion.back() == '\r') {
           peli.duracion.pop_back();
       	}
	   }
	return is;
}

istream& operator>>(istream& is, vector<Pelicula>& pelicula){
	Pelicula peli;
	while(is >> peli){
		pelicula.push_back(peli);
	}
	return is;
}

void guardar(vector<Pelicula> listaPeliculas, string ruta){
	ofstream archivo(ruta);
	if(archivo.is_open()){
		archivo << listaPeliculas;
		archivo.close();
	} else {
		cerr << "No se pudo guardar el archivo!" << endl;
	}
}

vector<Pelicula> leer(const string ruta){
	vector<Pelicula> listaPeliculas;
	ifstream archivo(ruta);
	if(archivo.is_open()){
		archivo >> listaPeliculas;
		archivo.close();
	} else {
		cerr << "No se pudo leer el archivo!" << endl;
	}
	return listaPeliculas;
}

void mostrarPeliculas(const string& ruta){
	for(auto& peli : leer(ruta)){
		cout << peli.mostrar() << endl;
	}
}

Pelicula buscar(const string& codigo, const string& ruta){
	Pelicula peliB;
	peliB.codigo = "No encontrado";
	for(const auto& peli : leer(ruta)){
		if(codigo == peli.codigo){
			peliB = peli;
			break;
		}
	}
	return peliB;
}

void agregar(const Pelicula& nuevaPelicula, const string& ruta){
	vector<Pelicula> listaPeliculas = leer(ruta);
	auto it = find_if(listaPeliculas.begin(), listaPeliculas.end(),
					  [&](const Pelicula& peli){return peli.codigo == nuevaPelicula.codigo;});
	
	if(it == listaPeliculas.end()){
		listaPeliculas.push_back(nuevaPelicula);
		cout << "Pelicula con codigo " << nuevaPelicula.codigo << " registrada exitosamente\n";
	} else {
		cout << "Pelicula con codigo " << nuevaPelicula.codigo << " ya esta registrada!\n";
	}
	guardar(listaPeliculas, ruta);
}

void actualizar(const string& codigo, const Pelicula& nuevaPeli, const string& ruta) {
	vector<Pelicula> peliculas = leer(ruta);
	
	auto it = find_if(peliculas.begin(), peliculas.end(), 
					  [&codigo](const Pelicula& p) { 
						  return p.codigo == codigo; 
					  });
	
	if (it != peliculas.end()) {
		it->nombrePelicula = nuevaPeli.nombrePelicula;
		it->genero = nuevaPeli.genero;
		it->duracion = nuevaPeli.duracion;
		
		guardar(peliculas, ruta);
		
		cout << "Pelicula con codigo '" << codigo << "' actualizada exitosamente." << endl;
	} else {
		cout << "Error: No se encontro ninguna pelicula con el codigo '" << codigo << "'." << endl;
	}
}

void eliminar(const string& codigo, const string& ruta) {
	vector<Pelicula> listaPeliculas = leer(ruta);
	auto it = remove_if(listaPeliculas.begin(), listaPeliculas.end(), 
						[&codigo](const Pelicula& peli) {
							return peli.codigo == codigo;
						});
	if (it != listaPeliculas.end()) {
		listaPeliculas.erase(it, listaPeliculas.end());
		guardar(listaPeliculas, ruta);
		cout << "Pelicula con codigo '" << codigo << "' eliminada exitosamente." << endl;
	} else {
		cout << "Error: No se encontro ninguna pelicula con el codigo '" << codigo << "'." << endl;
	}
}
