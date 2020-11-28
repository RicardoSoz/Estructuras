#include "NodoAVL.h"

#include <iostream>

NodoAVL::NodoAVL() {
	derecha = NULL;
	izquierda = NULL;
	fe = 0;
	dato = 0;
}
NodoAVL::NodoAVL(int _dato) {
	dato = _dato;
	fe = 0;
	derecha = NULL;
	izquierda = NULL;
}

int NodoAVL::getDato() { 
	return dato;
}
void NodoAVL::setDato(int _dato) {
	dato = _dato;
}

int NodoAVL::getFe() { 
	return fe;
}
void NodoAVL::setFe(int _fe) {
	fe = _fe;
}

NodoAVL* NodoAVL::getDerecha() {
	return derecha;
}
void NodoAVL::setDerecha(NodoAVL* _derecha) {
	derecha = _derecha;
}

NodoAVL* NodoAVL::getIzquierda() {
	return izquierda;
}
void NodoAVL::setIzquierda(NodoAVL* _izquierda) {
	izquierda = _izquierda;
}

NodoAVL::~NodoAVL() {

}
