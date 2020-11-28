#include "ListaLigada.h" 
#include <iostream>
using namespace std;

ListaLigada::ListaLigada()
{

	inicio = NULL;
}

ListaLigada::~ListaLigada()
{
}

NodoListaLigada* ListaLigada::getInicio() {
	return inicio;
}

void ListaLigada::setInicio(NodoListaLigada* inicio) {
	this->inicio = inicio;
}

void ListaLigada::Despliega() {
	if (inicio == NULL) {
		cout << "ListaLigadaLigada vacia" << endl;
	}
	else {
		NodoListaLigada* aux = inicio;
		while (aux != NULL) {
			cout << aux->getDato() << endl;
			aux = aux->getSig();
		}
	}
}

void ListaLigada::Inserta(int num) {
	NodoListaLigada* nodoNuevo = new NodoListaLigada(num);
	if (inicio == NULL)
	{
		inicio = nodoNuevo;
	}
	else {
		nodoNuevo->setSig(inicio);
		inicio = nodoNuevo;
	}
}

void ListaLigada::InsertaOrden(int numero) {
	NodoListaLigada* nuevo = new NodoListaLigada(numero);
	NodoListaLigada* actual = inicio;
	NodoListaLigada* anterior = inicio;

	if (inicio == NULL) { 
		inicio = nuevo;
	}
	else {
		while (actual != NULL && numero < actual->getDato()) {
			anterior = actual;
			actual = actual->getSig();
		}
		if (actual == NULL) {
			anterior->setSig(nuevo);
		}
		else if (anterior == actual) { 
			nuevo->setSig(inicio);
			inicio = nuevo;
		}
		else {
			anterior->setSig(nuevo);
			nuevo->setSig(actual);
		}
	}
}

void ListaLigada::Borrar(int numero) {
	NodoListaLigada* actual = inicio;
	NodoListaLigada* anterior = inicio;

	if (inicio == NULL)
		cout << "ListaLigada vacia";
	else {
		while (actual != NULL && actual->getDato() != numero) {
			anterior = actual;
			actual = actual->getSig();
		}
		if (actual == NULL)
			cout << "El elemento no est� en la lista";
		else if (actual == anterior) {
			inicio = actual->getSig();
			delete actual;
		}
		else {
			anterior->setSig(actual->getSig());
			delete    actual;
		}
	}
}

void ListaLigada::InsertaFinal(int num) {
	NodoListaLigada* nodoNuevo = new NodoListaLigada(num);
	if (inicio == NULL)
		inicio = nodoNuevo;
	else {
		NodoListaLigada* actual;
		NodoListaLigada* previo;
		actual = inicio;
		previo = inicio;

		while (actual != NULL) {
			previo = actual;
			actual = actual->getSig();
		}
		previo->setSig(nodoNuevo);
	}
}

void ListaLigada::operator +=(ListaLigada lista2) {
	NodoListaLigada* actual = inicio;
	NodoListaLigada* previo = inicio;
	NodoListaLigada* siguiente = lista2.getInicio();

	if (actual == NULL && siguiente == NULL) { 

	}
	else if (actual == NULL) {
		inicio = siguiente;
	}
	else {
		while (actual != NULL) 
		{
			previo = actual;
			actual = actual->getSig();
		}
		previo->setSig(siguiente);
	}

}

void ListaLigada::operator +=(int incremento) {
	NodoListaLigada* nuevo = new NodoListaLigada(incremento);
	NodoListaLigada* actual = inicio;
	NodoListaLigada* anterior = inicio;

	if (inicio == NULL) {
		inicio = nuevo;
	}
	else {
		while (actual != NULL && incremento < actual->getDato()) { 
			anterior = actual;
			actual = actual->getSig();
		}
		if (actual == NULL) { 
			anterior->setSig(nuevo);
		}
		else if (anterior == actual) { 
			nuevo->setSig(inicio);
			inicio = nuevo;
		}
		else {
			anterior->setSig(nuevo); 
			nuevo->setSig(actual);
		}
	}
}

void ListaLigada::operator--() {
	NodoListaLigada* actual = inicio;

	if (inicio == NULL)
		cout << "ListaLigada vacia\n";
	else {
		inicio = actual->getSig();
		delete actual;
	}
}

void ListaLigada::operator--(int i) {
	NodoListaLigada* actual = inicio;
	NodoListaLigada* anterior = inicio;

	if (inicio == NULL)
		cout << "ListaLigada vacia";
	if (actual->getSig() == NULL) {
		inicio = actual->getSig();
		delete actual;
	}
	else {
		anterior = actual;
		while (anterior->getSig()->getSig() != NULL) {
			anterior = anterior->getSig();
		}
		delete anterior->getSig();
		anterior->setSig(NULL);
	}
}

void ListaLigada::MezclarLista(ListaLigada lista2) {
	NodoListaLigada* ptr1, * ptr2, * dup;
	ptr1 = inicio;

	*this += lista2; 
	while (ptr1 != NULL && ptr1->getSig() != NULL)
	{
		ptr2 = ptr1;

		while (ptr2->getSig() != NULL) 
		{
			if (ptr1->getDato() == ptr2->getSig()->getDato()) 
			{
				dup = ptr2->getSig();
				ptr2->setSig(ptr2->getSig()->getSig());
				delete(dup);
			}
			else
				ptr2 = ptr2->getSig();
		}
		ptr1 = ptr1->getSig();
	}
}

ListaLigada ListaLigada::InvierteLista() {
	NodoListaLigada* actual = inicio;
	NodoListaLigada* anterior = NULL;
	NodoListaLigada* siguiente = NULL;

	while (actual != NULL) {
		siguiente = actual->getSig();
		actual->setSig(anterior);
		anterior = actual;
		actual = siguiente;
	}
	inicio = anterior;
	return *this;
}

int ListaLigada::LongitudLista() {
	NodoListaLigada* actual = inicio;
	int cont = 0;
	while (actual != NULL) {
		actual = actual->getSig();
		cont++;
	}
	return cont;
}

std::ostream& operator<< (std::ostream& salida, ListaLigada& p) {

	NodoListaLigada* actual = p.getInicio();
	NodoListaLigada* anterior = p.getInicio();

	if (p.getInicio() == NULL)
	{
		salida << "|| Contenido de la lista ligada ||\n" << "==================================\n";
	}
	else
	{
		salida << "|| Contenido de la lista ligada ||\n" << "==================================\n";
		while (actual != NULL) {
			anterior = actual;
			actual = actual->getSig();
			if (anterior->getSig() != NULL)
				salida << "<" << anterior->getDato() << ", " << actual->getDato() << ">" << endl;
			else {
				salida << "<" << anterior->getDato() << ", " << "NULL" << ">" << endl; 
			}
		}
	}
	return salida;
}
