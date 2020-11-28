#pragma once
class NodoAVL
{
public: 
	NodoAVL();
	NodoAVL(int);
	virtual ~NodoAVL();
	NodoAVL* getIzquierda();
	NodoAVL* getDerecha(); 
	int getDato(); 
	int getFe(); 
	void setIzquierda(NodoAVL*); /
	void setDerecha(NodoAVL*);
	void setDato(int);
	void setFe(int); 

private: 
	int dato, fe;
	NodoAVL* derecha;
	NodoAVL* izquierda;
};

