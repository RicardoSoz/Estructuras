#pragma once
#include <iostream>
using namespace std;

class NodoArbol
{
public: 
	NodoArbol(); 
	NodoArbol(string);


	string getDato(); 
	void setDato(string);  

	NodoArbol* getDerecha(); 
	void setDerecha(NodoArbol*); 

	NodoArbol* getIzquierda(); 
	void setIzquierda(NodoArbol*); 


	virtual ~NodoArbol();

private: 
	string dato; 
	NodoArbol* derecha;
	NodoArbol* izquierda;

};

