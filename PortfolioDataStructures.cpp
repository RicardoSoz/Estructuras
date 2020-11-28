#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "ListaLigada.h"
#include "Pila.h"
#include "Fila.h"
#include "NodoArbol.h"
#include "Abb.h"
#include "AVL.h"
#include <fstream>
#include <string>
#include <algorithm>

//Ricardo Solis
//27 noviembre 2020
//Portafolio
//Fuentes: Ejercicios y temas vistos en clase, GeeksForGeeks y trabajos con compañeros

using namespace std;

const int MAX = 20; 

int LinkedList();
int Stack();
int Queue();
int BinaryTree();
int avl();
int Graphs();
void grafoDirigido(int matrix[][20], int nodos);
void grafoNoDirigido(int matrix[][20], int nodos);
void printGrafo(int matrix[][20], int nodos);
void limpiar(int matrix[][20], int nodos) ;

int main()
{
    int option;

    cout << endl
    << " 1 - Linked List.\n"
    << " 2 - Stacks.\n"
    << " 4 - Queue.\n"
    << " 5 - Binary Tree.\n"
    << " 6 - Graphs.\n"
    << " 0 - EXIT: ";

    cin >> option;

	switch (option)
	{
	case 1:
        LinkedList();
		break;
	case 2:
        Stack();
		break;
	case 3:
        Queue();
		break;
	case 4:
        BinaryTree();
		break;
	case 5:
        avl();
		break;
	case 6:
        Graphs();
		break;
	case 0:
		exit(0);
		break;
	default:
		break;
	}
}

void limpiar(int matrix[][20], int nodos) {
    for (int i = 0; i < nodos; i++)
        for (int j = 0; j < nodos; j++)
            matrix[i][j] = -1;
}

void printGrafo(int matrix[][20], int nodos){

    for (int h = 0; h < nodos; h++)
        cout << "[" << h + 1 << "] ";

    cout << endl;

    for (int i = 0; i < nodos; i++){
        cout << "[" << i + 1 << "] ";
        for (int j = 0; j < nodos; j++)
            cout << matrix[i][j] << "   ";

        cout << endl;
    }
}

void grafoNoDirigido(int matrix[][20], int nodos) {

    for (int i = 0; i < nodos; i++)
    {
        int nodo = 0;

        for (int j = 0; j < nodos; j++)
        {
            if (matrix[i][j] != 1 && matrix[i][j] != 0)
            {
                cout << i + 1 << "," << j + 1 << " " << "1 conectados -  0  no conectados";
                cin >> nodo;

                matrix[i][j] = nodo;

                if (nodo == 1)
                    matrix[j][i] = 1;
                else {
                    matrix[j][i] = 0;
                }
            }
        }
    }
}

void grafoDirigido(int matrix[][20], int nodos){
    for (int i = 0; i < nodos; i++)
    {
        for (int j = 0; j < nodos; j++)
        {
            cout << i + 1 << "," << j + 1 << " " << "1 conectados -  0  no conectados";
            cin >> matrix[i][j];
        }
    }
}

int Stack() {
    Pila miPila;

    char d;        
    int index = 1;
    bool c = true, m, cierre = false;

    while (c) {
        m = false;
        cout << index << ": ";
        cin >> d;

        if (d == '{' || d == '[' || d == '(') {
            miPila.Push(index, d);
            cierre = false;
            index++;
        }
        else if (d == '}' || d == ']' || d == ')') {
            cierre = true;
            index++;
            if (miPila.getTop() == NULL)
                cout << "No hay ningun elemento a cerrar";
            else {
                switch (miPila.getTop()->getInfo()) {
                case '(':
                    if (d == ')') {
                        cout << "m " << miPila.getTop()->getDato() << endl;
                        miPila.Pop();
                        m = true;
                    }
                    break;
                case '[':
                    if (d == ']') {
                        cout << "Match " << miPila.getTop()->getDato() << endl;
                        miPila.Pop();
                        m = true;
                    }
                    break;
                case '{':
                    if (d == '}') {
                        cout << "Match " << miPila.getTop()->getDato() << endl;
                        miPila.Pop();
                        m = true;
                    }
                    break;
                default:
                    cout << "No contemplado.";
                    break;
                }
            }
        }
        else {
            cout << "No valido\n";
        }

        if (!m && cierre) {
            cout << "No hay elemento para cerrar.";
            c = false;
        }

    }

    return 0;
}

int LinkedList()
{
    ListaLigada lista;

    lista.Inserta(4);
    lista.Inserta(7);
    lista.Inserta(9);

    lista.getInicio();
    cout << lista;

    lista.Despliega();

    cout << "List Elements" << endl;

    lista += 6;
    lista += 9;
    lista += 7;
    lista += 89;
    lista += 67;
    cout << lista << endl;

    cout << "Concatenation" << endl;
    ListaLigada lista2;
    ListaLigada lista3;

    lista2 += 3;
    lista2 += 77;
    lista2 += 3;
    lista2 += 23;
    lista2 += 20;
    cout << "List 2" << endl;
    lista2.Despliega();

    lista3 += 43;
    lista3 += 62;
    lista3 += 98;
    lista3 += 9;
    lista3 += 9;
    cout << "List 3" << endl;
    lista3.Despliega();

    lista2 += lista3;
    cout << "Cancatenation of both lists" << endl;
    lista2.Despliega();

    cout << "Mixed" << endl;
    ListaLigada lista7;
    ListaLigada lista8;

    lista7 += 1;

    lista7.Despliega();

    cout << "Mixed List" << endl;
    lista7.MezclarLista(lista8);
    lista7.Despliega();


    cout << "Inverted" << endl;
    ListaLigada listaInvertida;
    ListaLigada lista10;

    lista10 += 24;
    lista10 += 87;

    cout << "Elementos lista 9" << endl;

    lista10.Despliega();

    cout << "Lista inverida" << endl;
    listaInvertida = lista10.InvierteLista();
    listaInvertida.Despliega();

    return 0;
}

int Queue() {
    Fila fila1;
    fila1.inserta(4);
    fila1.inserta(5);
    fila1.inserta(6);
    cout << fila1;
    fila1.borra();
    cout << fila1;

    return 0;
}

int BinaryTree() {
    int cont = 0;
    int hojas = 0;
    int internos = 0;

    Abb arbolito;
    string resp = "anita lava la tina";

    do {
        cout << "Ingrese la palabra para buscar D y palabra para borrar I y palabra para insertar C para imprimir las palabras 0 salir" << endl;
        getline(cin, resp);
        string data = resp;

        for_each(data.begin(), data.end(), [](char& c) {
            c = ::tolower(c);
            });

        if (data[0] == 'd' && data[1] == ' ') {
            string s = data;
            string delimiter = " ";

            size_t pos = 0;
            string token;
            while ((pos = s.find(delimiter)) != (string::npos)) {
                token = s.substr(0, pos);
                s.erase(0, pos + delimiter.length());
            }
            arbolito.borrar(s);
            cout << endl;
        }

        else if (data[0] == 'i' && data[1] == ' ') {
            string s = data;
            string delimiter = " ";

            size_t pos = 0;
            string token;
            while ((pos = s.find(delimiter)) != (string::npos)) {
                token = s.substr(0, pos);
                s.erase(0, pos + delimiter.length());
            }
            if (s.size() > 3)
            {
                arbolito.Inserta(s);
            }
            else {
                cout << "Ingrese una palabra mayor de 3 caracteres" << endl;
            }

            cout << endl;
            system("pause");
        }

        else if (data[0] == 'c' && data[1] == ' ')
        {

            cout << "\nTotal de palabras: ";
            cout << arbolito.contarNodos(arbolito.getRoot(), cont) << endl;
            arbolito.preorden(arbolito.getRoot());
            cout << endl;
        }
        else {
            arbolito.buscar(data);
        }
    } while (resp != "0");

    return 0;
}

int avl(){
    AVL arbolito;
    bool bo = false;

    arbolito.setRaiz(arbolito.insertAvl(arbolito.getRaiz(), 34, bo));
    bo = false;

    arbolito.setRaiz(arbolito.insertAvl(arbolito.getRaiz(), 24, bo));
    bo = false;

    arbolito.setRaiz(arbolito.insertAvl(arbolito.getRaiz(), 45, bo));
    bo = false;

    arbolito.setRaiz(arbolito.insertAvl(arbolito.getRaiz(), 35, bo));
    bo = false;

    cout << "PREORDEN" << endl;
    arbolito.preorden(arbolito.getRaiz());
    cout << "POSORDEN" << endl;
    arbolito.posorden(arbolito.getRaiz());
    cout << "INORDEN" << endl;
    arbolito.inorden(arbolito.getRaiz());

    return 0;
}

int Graphs()
{
    int resp_men;
    int N = 0;
    int grafo[20][20];

    do {

        int resp;
        cout << "Numero de nodos";
        cin >> N;

        if (N <= 20 && N >= 2) {

            cout << "1 grafo dirigido, 0 no dirigido: ";
            cin >> resp;

            if (resp == 1) {
                grafoDirigido(grafo, N);
            }

            else if (resp == 0) {
                grafoNoDirigido(grafo, N);
            }

            printGrafo(grafo, N);
        }
        else
            cout << "Fuera de rango" << endl;

        limpiar(grafo, N);


        cout << "1 para empezar -  0 salir" << endl;
        cin >> resp_men;

    } while (resp_men != 0);

    return 0;
}

