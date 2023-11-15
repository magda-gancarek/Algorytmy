#include<iostream>
#include<cstdio>
#include "Stos.h"
using namespace std;


int main() {
	Stos stos;

stos.Empty();
cout << "Czy stos jest pusty " << stos.Empty() << endl;
stos.Push(5);
cout << "Element na szczycie stosu: " << 
stos.TopElem() << endl;
cout << "Czy stos jest pusty " << stos.Empty() << endl;
stos.Pop();
cout << "Czy stos jest pusty po pop " << stos.Empty() << endl;
stos.Push(2);
stos.Push(3);
cout << "Element na szczycie stosu: " << 
stos.TopElem() << endl;
//stos.Makenull();

stos.Push(6);
stos.Push(7);
cout << "Element na szczycie stosu: " << 
stos.TopElem() << endl;

cout << "Czy stos jest pusty po makenull " << stos.Empty() << endl;

} 

