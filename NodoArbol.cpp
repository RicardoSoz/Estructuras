#include "NodoArbol.h"
#include <iostream>
#include <string>

using namespace std;

NodoArbol::NodoArbol() { 
	derecha = NULL;
	izquierda = NULL;
}
NodoArbol::NodoArbol(std::string _dato) {
	dato = _dato;
	derecha = NULL;
	izquierda = NULL;
}

std::string NodoArbol::getDato() { 
	return dato;
}
void NodoArbol::setDato(std::string _dato) {/
	dato = _dato;
}

NodoArbol* NodoArbol::getDerecha() {
	return derecha;
}
void NodoArbol::setDerecha(NodoArbol* _derecha) {
	derecha = _derecha;
}

NodoArbol* NodoArbol::getIzquierda() {
	return izquierda;
}
void NodoArbol::setIzquierda(NodoArbol* _izquierda) {
	izquierda = _izquierda;
}

NodoArbol::~NodoArbol() {
}