#pragma once
class NodoPila
{
public:
	NodoPila();		
	NodoPila(int);	
	NodoPila(int, char);
	int getDato();			
	char getInfo();
	void setDato(int);
	void setDato(char);


	NodoPila* getSig();		
	void setSig(NodoPila*);	


	virtual ~NodoPila();

private:
	int dato;
	char info;
	NodoPila* sig;
};

