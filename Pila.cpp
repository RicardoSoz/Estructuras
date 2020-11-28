#include "Pila.h"
#include "NodoPila.h"
#include <iostream>

Pila::Pila() {	
	_top = NULL;
}

Pila::~Pila() {
}

NodoPila* Pila::getTop() {
	return _top;
}


void Pila::Pop() {
	if (_top == NULL)
		std::cout << "No hay elementos en la pila para borrar.\n";
	else {
		NodoPila* aux = _top;
		_top = _top->getSig();
		delete aux;
	}
}

void Pila::Push(int dato) {
	NodoPila* nuevo = new NodoPila(dato);
	
	if (_top == NULL)
		_top = nuevo;
	else {
		nuevo->setSig(_top);
		_top = nuevo;
	}
}
void Pila::Push(int id, char dato) {
	NodoPila* nuevo = new NodoPila(id, dato);
	if (_top == NULL)
		_top = nuevo;
	else {
		nuevo->setSig(_top);
		_top = nuevo;
	}
}