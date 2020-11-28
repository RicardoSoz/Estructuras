#include "AVL.h"
#include "NodoAVL.h"

#include <iostream>
using namespace std;

AVL::AVL() {
	raiz = NULL;
}

AVL::~AVL() {

}
NodoAVL* AVL::getRaiz() {
	return raiz;
}
void AVL::setRaiz(NodoAVL* _raiz) {
	raiz = _raiz;
}

NodoAVL* AVL::insertAvl(NodoAVL* nodo, int info, bool& bo) {
	NodoAVL* nodo1 = new NodoAVL(info);
	NodoAVL* nodo2 = new NodoAVL(info);
	if (nodo != NULL) {
		if (info < nodo->getDato()) { 

			cout << "Avanzo a la izquierda" << endl;
			nodo->setIzquierda(insertAvl(nodo->getIzquierda(), info, bo));
			if (bo == true) {
				if (nodo->getFe() == 1) {
					nodo->setFe(0);
					bo = false;
				}
				else if (nodo->getFe() == 0) {
					nodo->setFe(-1);
				}
				else if (nodo->getFe() == -1) {
					nodo->getIzquierda() == nodo1;
					if (nodo1->getFe() < 0) {
						nodo->getIzquierda() == nodo1->getDerecha();
						nodo1->setDerecha(nodo);
						nodo->setFe(0);
						nodo = nodo1;
					}
					else {
						nodo2 = nodo1->getDerecha();
						nodo->setIzquierda(nodo2->getDerecha());
						nodo2->setDerecha(nodo);
						nodo1->setDerecha(nodo2->getIzquierda());
						nodo2->setIzquierda(nodo1);

						if (nodo2->getFe() == -1) {
							nodo->setFe(1);
						}
						else {
							nodo->setFe(0);
						}

						if (nodo2->getFe() == 1) {
							nodo1->setFe(-1);
						}
						else {
							nodo1->setFe(0);
						}
						nodo = nodo2;
					}
				}
				nodo->setFe(0);
				bo = false;
			}
		}
		else if (info > nodo->getDato()) {
			cout << "Avanzo a la derecha" << endl;
			nodo->setDerecha(insertAvl(nodo->getDerecha(), info, bo));
			if (bo == true) {
				if (nodo->getFe() == -1) {
					nodo->setFe(0);
					bo = false;
				}
				else if (nodo->getFe() == 0) {
					nodo->setFe(1);
				}
				else if (nodo->getFe() == 1) {
					nodo1 = nodo->getDerecha();
					if (nodo1->getFe() > 0) {
						nodo->setDerecha(nodo1->getIzquierda());
						nodo1->setIzquierda(nodo);
						nodo->setFe(0);
						nodo = nodo1;
					}
					else {
						nodo2 = nodo1->getIzquierda();
						nodo->setDerecha(nodo2->getIzquierda());
						nodo2->setIzquierda(nodo);
						nodo1->setIzquierda(nodo2->getDerecha());
						nodo2->setDerecha(nodo1);

						if (nodo2->getFe() == 1) {
							nodo->setFe(-1);
						}
						else {
							nodo->setFe(0);
						}

						if (nodo2->getFe() == -1) {
							nodo1->setFe(1);
						}
						else {
							nodo1->setFe(0);
						}
						nodo = nodo2;
					}
				}
				nodo->setFe(0);
				bo = false;
			}
		}
		else {
			cout << " El dato es repetido" << endl;
		}
	}
	else {
		nodo = new NodoAVL(info);
		bo = true;
	}
	return nodo;
}
void AVL::preorden(NodoAVL* aux) {
	if (aux != NULL) {
		cout << aux->getDato() << endl;
		preorden(aux->getIzquierda());
		preorden(aux->getDerecha());
	}
}
void AVL::inorden(NodoAVL* aux) {
	if (aux != NULL) {
		inorden(aux->getIzquierda());
		cout << aux->getDato() << endl;
		inorden(aux->getDerecha());
	}
}
void AVL::posorden(NodoAVL* aux) {
	if (aux != NULL) {
		posorden(aux->getIzquierda());
		posorden(aux->getDerecha());
		cout << aux->getDato() << endl;
	}
}
