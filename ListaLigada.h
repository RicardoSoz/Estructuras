#pragma once
#include "NodoListaLigada.h"
#include<iostream>

using namespace std;

class ListaLigada
{
private:
	NodoListaLigada* inicio; 

public:
	ListaLigada(); 
	~ListaLigada(); 

	NodoListaLigada* getInicio(); 
	void setInicio(NodoListaLigada*); 

	void Despliega(); 
	void Inserta(int);
	void InsertaFinal(int); 
	void Borrar(int);
	void InsertaOrden(int);
	int LongitudLista(); 
	void MezclarLista(ListaLigada); 
	ListaLigada InvierteLista(); 

	void operator += (ListaLigada);
	void operator += (int); 
	void operator--(int); 
	void operator--(); 

	friend ostream& operator<< (ostream& output, ListaLigada& p);
};

