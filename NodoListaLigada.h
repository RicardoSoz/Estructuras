#pragma once
class NodoListaLigada
{
public: 
	NodoListaLigada(); 
	NodoListaLigada(int); 

	int getDato();
	void setDato(int); 
	NodoListaLigada* getSig(); 
	void setSig(NodoListaLigada*); 

	virtual ~NodoListaLigada(); 

private: 
	int dato; 
	NodoListaLigada* sig; 
};

