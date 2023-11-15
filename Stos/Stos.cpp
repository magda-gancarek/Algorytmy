#include<iostream>
#include<cstdio>
#include "Stos.h"
using namespace std;

Stos::Stos(){
 Top=-1;
}

void Stos::Push(elementtype x){
	if (Top <maxlegth-1) {
 		Top++;
 		S[Top]= x;
	}
}

void Stos::Pop(){
	if (Top >= 0){
		Top--;
	}
}
	
bool Stos::Empty(){
	return (Top==-1);
}

elementtype Stos::TopElem(){
	if (Top>=0) return S[Top];
}

void Stos::Makenull(){
	Top=-1;
} 