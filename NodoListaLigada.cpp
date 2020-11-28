#include "NodoListaLigada.h"
#include <iostream>

NodoListaLigada::NodoListaLigada() {
	sig = NULL;
}
NodoListaLigada::NodoListaLigada(int _dato) {
	dato = _dato;
	sig = NULL;
}

int NodoListaLigada::getDato() {
	return dato;
}
void NodoListaLigada::setDato(int _dato) {
	dato = _dato;
}

NodoListaLigada* NodoListaLigada::getSig() {
	return sig;
}
void NodoListaLigada::setSig(NodoListaLigada* _sig) {
	sig = _sig;
}

NodoListaLigada::~NodoListaLigada() {}