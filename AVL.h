#pragma once
#include "NodoAVL.h"
class AVL
{
public:
	AVL();
	virtual ~AVL();
	NodoAVL* getRaiz();
	void setRaiz(NodoAVL*);
	NodoAVL* insertAvl(NodoAVL*, int, bool&);
	void preorden(NodoAVL*);
	void inorden(NodoAVL*);
	void posorden(NodoAVL*);

private:
	NodoAVL* raiz;
};

