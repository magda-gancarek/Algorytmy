#ifndef STOS_H
#define STOS_H
#include <iostream>
using namespace std;

const int maxlegth=3;
typedef int elementtype; 
typedef int position;

class Stos{
protected : 
	int S[maxlegth] ;
	position Top;//szczyt stosu
public:
	Stos();
	void Push(elementtype x);
	void Pop();
	bool Empty();
	elementtype TopElem();
	void Makenull(); 
};

#endif
