#include "funciones.h"

void eliminar(const string& codigo, const string& ruta) {
	vector<Pelicula> peliculas = leer(ruta);
	
	auto it = remove_if(peliculas.begin(), peliculas.end(), 
						[&codigo](const Pelicula& p) { 
							return p.codigo == codigo; 
						});
	if (it != peliculas.end()) {
		peliculas.erase(it, peliculas.end());
		
		guardar(peliculas, ruta);
		
		cout << "Pelicula con codigo '" << codigo << "' eliminada exitosamente." << endl;
	} else {
		cout << "Error: No se encontro ninguna pelicula con el codigo '" << codigo << "'." << endl;
	}
}
