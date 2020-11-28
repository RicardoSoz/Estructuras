#include "Abb.h"
#include <iostream>

using namespace std;

Abb::Abb() {
	root = NULL;
}

Abb::~Abb() { 
}

NodoArbol* Abb::getRoot() {
	return root;
}

void Abb::setRoot(NodoArbol* _root) {
	root = _root;
}

void Abb::Inserta(string num) {

	NodoArbol* nuevo = new NodoArbol(num);
	NodoArbol* aux = root;
	NodoArbol* antes = root;

	if (root == NULL)
	{
		root = nuevo;
	}

	else {

		while (aux != NULL && nuevo->getDato() != aux->getDato())
		{
			antes = aux;
			if (aux->getDato() > num)
			{
				aux = aux->getIzquierda();
			}
			else
				aux = aux->getDerecha();
		}

		if (aux != NULL) {
			cout << "Repetido" << endl;
		}
		else {
			if (antes->getDato() > num)
				antes->setIzquierda(nuevo);
			else
				antes->setDerecha(nuevo);
		}
	}
}

int Abb::contarNodos(NodoArbol* aux, int cont) {

	if (aux != NULL) {
		cont++;
		cont = contarNodos(aux->getIzquierda(), cont);
		cont = contarNodos(aux->getDerecha(), cont);
	}
	return cont;
}

int Abb::contarInternos(NodoArbol* aux, int cont) {

	if (aux != NULL)
	{
		if (aux->getIzquierda() != NULL || aux->getDerecha() != NULL)
			cont++;
		cont = contarInternos(aux->getIzquierda(), cont);
		cont = contarInternos(aux->getDerecha(), cont);
	}
	return cont;
}

int Abb::contarHojas(NodoArbol* aux, int& cont) {
	
	if (aux != NULL) {
		if (aux->getIzquierda() == NULL && aux->getDerecha() == NULL)
			cont++;
		cont = contarHojas(aux->getIzquierda(), cont);
		cont = contarHojas(aux->getDerecha(), cont);
	}
	return cont;
}

void Abb::contarNodosIH(NodoArbol* aux, int& internos, int& hojas) {

	internos = 0;
	hojas = 0;
	internos = contarInternos(aux, internos);
	hojas = contarHojas(aux, hojas);
}

void Abb::preorden(NodoArbol* aux)
{

	if (aux != NULL) {
		cout << aux->getDato() << endl;
		preorden(aux->getIzquierda());
		preorden(aux->getDerecha());
	}
}

void Abb::posorden(NodoArbol* aux)
{

	if (aux != NULL) {
		posorden(aux->getIzquierda());
		posorden(aux->getDerecha());
		cout << aux->getDato() << endl;
	}
}

void Abb::inorden(NodoArbol* aux)
{

	if (aux != NULL) {
		inorden(aux->getIzquierda());
		cout << aux->getDato() << endl;
		inorden(aux->getDerecha());
	}
}

void Abb::definir(string str) {

	NodoArbol* antes = root;
	NodoArbol* aux = root;
	while (aux != NULL && str != aux->getDato()) {
		antes = aux;
		if (str < aux->getDato()) {
			aux = aux->getIzquierda();
		}
		else {
			aux = aux->getDerecha();
		}
	}
	if (aux != NULL) {
		cout << "Dato encontrado" << endl;
		if (aux->getDerecha() == NULL && aux->getIzquierda() == NULL) {
			cout << "Dato HOJA" << endl;
		}
		else if (aux->getDerecha() == NULL && aux->getIzquierda() != NULL || aux->getDerecha() != NULL && aux->getIzquierda() == NULL)
		{
			cout << "Dato 1 HIJO" << endl;
		}
		else
		{
			cout << "Dato 2 HIJOS" << endl;
		}
	}
	else {
		cout << "Dato NO encontrado" << endl;
	}
}

void Abb::borrar(string str) {

	NodoArbol* antes = root;
	NodoArbol* aux = root;
	while (aux != NULL && str != aux->getDato()) {
		antes = aux;
		if (str < aux->getDato()) {
			aux = aux->getIzquierda();
		}
		else {
			aux = aux->getDerecha();
		}
	}
	if (aux != NULL) {
		cout << "Dato encontrado" << endl;
		if (aux->getDerecha() == NULL && aux->getIzquierda() == NULL) {
			
			if (aux == root) {
				root = BorrarSinHijos(antes, aux);
			}
			else
				antes = BorrarSinHijos(antes, aux);
			
		}
		else if (aux->getDerecha() == NULL && aux->getIzquierda() != NULL || aux->getDerecha() != NULL && aux->getIzquierda() == NULL)
		{
			
			BorrarUnHijo(antes, aux);
		}
		else
		{
			
			BorrarDosHijos(antes, aux);
		}
	}
	else {
		cout << "Dato NO encontrado" << endl;
	}
}

void Abb::buscar(string str)
{
	NodoArbol* antes = root;
	NodoArbol* aux = root;
	while (aux != NULL && str != aux->getDato()) {
		antes = aux;
		if (str < aux->getDato()) {
			aux = aux->getIzquierda();
		}

		else {
			aux = aux->getDerecha();
		}
	}
	if (aux != NULL) {
		cout << str << " Encontrado " << endl;
	}
	else {
		cout << str << " NO encontrado" << endl;
	}
}

NodoArbol* Abb::BorrarSinHijos(NodoArbol* antes, NodoArbol* aux) {
	if (aux == root)
		return NULL;
	else {
		if (antes->getDerecha() == aux)
			antes->setDerecha(NULL);
		else
			antes->setIzquierda(NULL);
		return antes;
	}
}

NodoArbol* Abb::BorrarUnHijo(NodoArbol* antes, NodoArbol* aux) {
	if (aux == root) {
		if (root->getIzquierda() == NULL)
			root = root->getDerecha();
		else
			root = root->getIzquierda();
		delete aux;
		return root;
	}
	else {
		NodoArbol* hijo; 
		if (aux->getDerecha() == NULL)
			hijo = aux->getIzquierda();
		else
			hijo = aux->getDerecha();
		if (antes->getDerecha() == aux)
			antes->setDerecha(hijo);
		else
			antes->setIzquierda(hijo);
		delete aux;
		return antes;
	}
}

NodoArbol* Abb::BorrarDosHijos(NodoArbol* antes, NodoArbol* aux) {
	NodoArbol* antesd = aux->getDerecha(), * auxd = antesd;
	while (auxd->getIzquierda() != NULL) { 
		antesd = auxd;
		auxd = auxd->getIzquierda();
	}
	if (aux == root) {
		if (auxd != antesd) {
			antesd->setIzquierda(auxd->getDerecha());
			auxd->setDerecha(antesd);
		}
		auxd->setIzquierda(aux->getIzquierda());
		delete aux;
		root = auxd;
		return auxd;
	}
	else {
		if (auxd == antesd)
			auxd->setIzquierda(aux->getIzquierda());
		else {
			antesd->setIzquierda(auxd->getDerecha());
			auxd->setIzquierda(aux->getIzquierda());
			auxd->setDerecha(aux->getDerecha());
		}
		if (antes->getDerecha() == aux)
			antes->setDerecha(auxd);
		else
			antes->setIzquierda(auxd); 
		delete aux;
		return antes;
	}
}