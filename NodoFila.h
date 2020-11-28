#pragma once
#include <iostream>
class NodoFila
{
public: 
	NodoFila(); 
	NodoFila(int, char); 
	NodoFila(int);

	int getDato(); 
	void setDato(int); 

	NodoFila* getSig(); 
	void setSig(NodoFila*); 

	virtual ~NodoFila(); 

private: 
	int dato; 
	char caracter;
	NodoFila* sig; 
};
