#pragma once
#include "NodoPila.h"
#include <ostream>
using namespace std;

class Pila
{
private:
	NodoPila* _top;

public:

	Pila();
	~Pila();



	NodoPila* getTop();


	void Push(int);

	
	void Push(int, char);


	void Pop();
};
