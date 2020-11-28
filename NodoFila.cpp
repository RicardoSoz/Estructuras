#include "NodoFila.h"
#include <iostream>
using namespace std;

NodoFila::NodoFila() {
	
	dato = 0;
	sig = NULL;
}

NodoFila::NodoFila(int _dato) {
	
	dato = _dato;
	sig = NULL;
}

NodoFila::NodoFila(int _dato, char _caracter) {
	dato = _dato;
	caracter = _caracter;
	sig = NULL;
}

int NodoFila::getDato() {
	return dato;
}
void NodoFila::setDato(int _dato) {
	dato = _dato;
}


NodoFila* NodoFila::getSig() {
	return sig;
}
void NodoFila::setSig(NodoFila* _sig) {
	sig = _sig;
}

NodoFila::~NodoFila() {

}