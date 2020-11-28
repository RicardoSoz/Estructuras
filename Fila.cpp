#include "Fila.h"
#include "NodoFila.h"
#include <iostream>
using namespace std;

void Fila::inserta(int num) {
	int numero;
	NodoFila* nuevo = new NodoFila(num);
	if (inicio == NULL) {
		inicio = nuevo;
		fin = nuevo;
	}
	else {
		fin->setSig(nuevo);
		fin = nuevo;
	}
}

void Fila::borra() {
	if (inicio == NULL) {
		cout << "Lista vacia" << endl;
	}
	else {
		NodoFila* aux = inicio;
		if (inicio == fin) {
			inicio = NULL;
			fin = NULL;
		}
		else {
			inicio = inicio->getSig();
		}
		delete aux;
	}
}

std::ostream& operator<< (std::ostream& salida, Fila& p) { 
	if (p.getFin() == NULL) {
		cout << "No hay elementos en la fila" << endl;
	}
	else {
		salida << p.getInicio()->getDato() << " " << p.getFin()->getDato() << endl;

	}
	return salida;
}