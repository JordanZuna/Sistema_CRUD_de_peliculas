#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pelicula {
	string codigo;   
	string nombrePelicula;
	string genero;
	string duracion;
	
	string mostrar() const{
		ostringstream oss;
		oss << "Codigo: " << codigo << ", Pelicula: " << nombrePelicula << ", Genero: " << genero
		<< ", Duracion: " << duracion;
		return oss.str();
	}
};

ostream& operator<<(ostream& os, const Pelicula& peli);
ostream& operator<<(ostream& os, const vector<Pelicula>& pelicula);
istream& operator>>(istream& is, Pelicula& peli);
istream& operator>>(istream& is, vector<Pelicula>& pelicula);

void guardar(vector<Pelicula> listaPeliculas, string ruta);
vector<Pelicula> leer(const string ruta);
void agregar(const Pelicula& nuevaPelicula, const string& ruta);
void mostrarPeliculas(const string& ruta);
Pelicula buscar(const string& codigo, const string& ruta);
void actualizar(const string& codigo, const Pelicula& nuevaPeli, const string& ruta);
void eliminar(const string& codigo, const string& ruta);

#endif
