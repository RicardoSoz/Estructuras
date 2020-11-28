#include "NodoPila.h"
#include <iostream>



NodoPila::NodoPila() {
	dato = 0;
	info = ' ';
	sig = NULL;	
}

NodoPila::~NodoPila() {
}


NodoPila::NodoPila(int d) {
	dato = d;
	sig = NULL;
}


NodoPila::NodoPila(int id, char data) {
	dato = id;
	info = data;
	sig = NULL;
}

int NodoPila::getDato() {
	return dato;
}

char NodoPila::getInfo() {
	return info;
}

void NodoPila::setDato(int d) {
	dato = d;
}

void NodoPila::setDato(char inf) {
	info = inf;
}

NodoPila* NodoPila::getSig() {
	return sig;
}

void NodoPila::setSig(NodoPila* Sig) {
	sig = Sig;
}