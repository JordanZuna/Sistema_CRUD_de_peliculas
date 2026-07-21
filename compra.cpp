#include "compra.h"

void simularCompra(const string& ruta) {
	string codigoBuscar;
	cout << "Ingrese el codigo de la pelicula que desea comprar: ";
	cin >> codigoBuscar;

	Pelicula peli = buscar(codigoBuscar, ruta);

	if (peli.codigo != "No encontrado") {
		string nombreCliente, cedula;
		int cantidad = 0;
		double precioUnitario = 5.50;

		cout << "\n--- Pelicula Encontrada: " << peli.nombrePelicula << " ---" << endl;
		cin.ignore();

		cout << "Nombre del cliente: ";
		getline(cin, nombreCliente);
		cout << "Cedula / ID del cliente: ";
		getline(cin, cedula);
		cout << "Cantidad a comprar: ";
		cin >> cantidad;

		if (cantidad > 0) {
			double subtotal = cantidad * precioUnitario;
			double iva = subtotal * 0.15;
			double total = subtotal + iva;

			cout << "\n========================================" << endl;
			cout << "           FACTURA DE COMPRA            " << endl;
			cout << "========================================" << endl;
			cout << "Cliente: " << nombreCliente << endl;
			cout << "Cedula:  " << cedula << endl;
			cout << "Pelicula: " << peli.nombrePelicula << " (" << peli.genero << ")" << endl;
			cout << "Cantidad: " << cantidad << " x $" << precioUnitario << endl;
			cout << "----------------------------------------" << endl;
			cout << "Subtotal: $" << subtotal << endl;
			cout << "IVA (15%): $" << iva << endl;
			cout << "Total a Pagar: $" << total << endl;
			cout << "========================================" << endl;
		} else {
			cout << "Error: La cantidad debe ser mayor a 0.\n";
		}
	} else {
		cout << "Error: No se encontro ninguna pelicula con el codigo '" << codigoBuscar << "'.\n";
	}
}
