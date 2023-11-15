#ifndef KOLEJKA_H
#define KOLEJKA_H
#include <iostream>
using namespace std;

const int maxlength=4;
typedef int position;
typedef int elementtype;

class Kolejka{
protected :
	elementtype Queue[maxlength];
	position Front; // Indeks elementu czołowego
	position Rear; // Indeks ostatniego elementu
public:
	Kolejka();
	int AddOne(int i);
	void Enqueue(elementtype x);
	void Dequeue();
	elementtype FrontElem();
	void Makenull();
	bool Empty();
};

#endif