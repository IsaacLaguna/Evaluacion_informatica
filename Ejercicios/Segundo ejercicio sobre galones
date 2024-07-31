// Isaac Laguna 31.028.102
#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>
#include <cmath>
// Librerias
using namespace std; //Permite el uso de espacios de nombres std

struct datoscliente{ // Declaracion de estructura de datos
	string nombre;
	int galones_aceite_comprados;
	int galones_caucho_comprados;
	int galones_satinada_comprados;
	int galones_aceite_total = 6200;
	int galones_caucho_total = 5400;
	int galones_satinada_total = 10500;
	int Monto_galones_total;
	int Descuento_pintura_total;
	int Neto_total;
}; // Fin de declaracion de estructura de datos

datoscliente Clientes;
int opcion;

// Uso de metodos
void ingresar_datos(){
	cout << "Ingrese nombre del cliente:" << endl;
	cin >> Clientes.nombre;
	cout << "Ingrese cuantos galones de aceite compro:" << endl;
	cin >> Clientes.galones_aceite_comprados;
	cout << "Ingrese cuantos galones de caucho compro:" << endl;
	cin >> Clientes.galones_caucho_comprados;
	cout << "Ingrese cuantos galones de satinada compro:" << endl;
	cin >> Clientes.galones_satinada_comprados;
}

int descuento_pintura_aceite_total(){
	return Clientes.galones_aceite_total * 0.20;
}

int descuento_pintura_caucho_total(){
	if (Clientes.galones_caucho_comprados > 3 && Clientes.galones_caucho_comprados <= 6){
		 return Clientes.galones_caucho_total * 0.07;
	}
	if (Clientes.galones_caucho_comprados > 6 && Clientes.galones_caucho_comprados <= 10){
		return Clientes.galones_caucho_total * 0.10;
	}
	if (Clientes.galones_caucho_comprados > 10){
		return Clientes.galones_caucho_total * 0.15;
	}
}

int descuento_pintura_satinada_total(){
	if (Clientes.galones_satinada_comprados > 5){
		return Clientes.galones_satinada_total * 0.12;
	}
}
// Fin de uso de metodos

int main(){ // Inicio de main
	queue <datoscliente> colaClientes; // Declaracion de cola queue
	datoscliente clienteNuevo;
	do{ //Inicio de bucle do while
		cout << "-----------COMPRAS DE CLIENTES-----------" << endl;
		cout << "|1. Ingresar cliente                    |" << endl;
		cout << "|2. Compras hechas por cliente          |" << endl;
		cout << "|3. Monto y descuento de compras        |" << endl;
		cout << "|4. Recibo por compra                   |" << endl;
		cout << "|5. Salir del programa                  |" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "Ingrese una opcion" << endl;
		cin >> opcion;
		system ("cls");
		switch (opcion){ // Inicio de switch
			case 1:
				if (!colaClientes.empty()){
					cout << "No se puede realizar ninguna compra ya que se esta haciendo una..." << endl;
					}
				else{
					ingresar_datos();
					colaClientes.push({Clientes.nombre, Clientes.galones_aceite_comprados, Clientes.galones_caucho_comprados, Clientes.galones_satinada_comprados, Clientes.galones_aceite_total, Clientes.galones_caucho_total, Clientes.galones_satinada_total, Clientes.Monto_galones_total, Clientes.Descuento_pintura_total, Clientes.Neto_total});
					clienteNuevo = colaClientes.front();
				}
				system ("cls");
			// Realizar la acción correspondiente a la opción 1
			break;
			
			case 2:
				if (!colaClientes.empty()){
					cout << "COMPRAS DE CLIENTE" << endl;
					cout << "------------------------------" << endl;
					cout << "Cliente: " << clienteNuevo.nombre << endl;
					cout << "------------------------------" << endl;
					cout << "Galones de aceite comprados: " << clienteNuevo.galones_aceite_comprados << endl;
					cout << "------------------------------" << endl;
					cout << "Galones de caucho comprados: " << clienteNuevo.galones_caucho_comprados << endl;
					cout << "------------------------------" << endl;
					cout << "Galones de satinada comprados: " << clienteNuevo.galones_satinada_comprados << endl;
					cout << "------------------------------" << endl;
				}
				else{
					cout << "No se ha realizado ninguna compra..." << endl;
				}
			// Realizar la acción correspondiente a la opción 2
			break;
			
			case 3:
				if (!colaClientes.empty()){
					clienteNuevo.galones_aceite_total = clienteNuevo.galones_aceite_comprados * clienteNuevo.galones_aceite_total;
					cout << "El Monto total por galones de aceite comprados es de: " << "Bs. " << clienteNuevo.galones_aceite_total << endl;
					cout << "Mientras que el descuento total por galones de aceite comprados es de: " << "Bs. " << descuento_pintura_aceite_total() << endl;
					
					clienteNuevo.galones_caucho_total = clienteNuevo.galones_caucho_comprados * clienteNuevo.galones_caucho_total;
					cout << "El Monto total por galones de caucho comprados es de: " << "Bs. " << clienteNuevo.galones_caucho_total << endl;
					cout << "Mientras que el descuento total por galones de caucho comprados es de: " << "Bs. " << descuento_pintura_caucho_total() << endl;
					
					clienteNuevo.galones_satinada_total = clienteNuevo.galones_satinada_comprados * clienteNuevo.galones_satinada_total;
					cout << "El Monto total por galones de satinada comprados es de: " << "Bs. " << clienteNuevo.galones_satinada_total << endl;
					cout << "Mientras que el descuento total por galones de satinada comprados es de: " << "Bs. " << descuento_pintura_satinada_total() << endl;
				}
				else{
					cout << "No se ha realizado ninguna compra..." << endl;
				}
			// Realizar la acción correspondiente a la opción 3
			break;
			
			case 4:
				if (!colaClientes.empty()){
					clienteNuevo.Monto_galones_total = clienteNuevo.galones_aceite_total + clienteNuevo.galones_caucho_total + clienteNuevo.galones_satinada_total;
					clienteNuevo.Descuento_pintura_total = descuento_pintura_aceite_total() + descuento_pintura_caucho_total() + descuento_pintura_satinada_total();
					clienteNuevo.Neto_total = clienteNuevo.Monto_galones_total - clienteNuevo.Descuento_pintura_total;
					cout << "FACTURA:" << endl;
					cout << "------------------------------" << endl;
					cout << "Cliente: " << clienteNuevo.nombre << endl;
					cout << "------------------------------" << endl;
					cout << "Monto total a pagar: " << "Bs. " << clienteNuevo.Monto_galones_total << endl;
					cout << "------------------------------" << endl;
					cout << "Monto total de descuentos a pagar: " << "Bs. " << clienteNuevo.Descuento_pintura_total << endl;
					cout << "------------------------------" << endl;
					cout << "Neto a pagar: " << "Bs. " << clienteNuevo.Neto_total << endl;
					cout << "------------------------------" << endl;
				}
				else{
					cout << "No se ha realizado ninguna compra..." << endl;
				}
				colaClientes.pop();
			// Realizar la acción correspondiente a la opción 4
			break;
				
			case 5:
				cout << "Saliendo del programa..." << endl;
			// Realizar la acción correspondiente a la opción 5
			break;
		} // Fin de switch
	} while (opcion != 5); // Fin de bucle do while
return 0;
} // Fin de main
