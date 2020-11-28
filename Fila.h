#pragma once
#include "NodoFila.h"
#include<iostream>
using namespace std;
class Fila
{

	NodoFila* inicio, * fin;
	int cuantos;

public:
	Fila() :inicio(NULL), fin(NULL), cuantos(0) {} 
	~Fila() {};

	void inserta(int);
	void borra();
	NodoFila* getInicio() { return inicio; }

	void setinicio(NodoFila* i) { inicio = i; }
	NodoFila* getFin() { return fin; }

	friend ostream& operator<< (ostream& output, Fila& n);
};

