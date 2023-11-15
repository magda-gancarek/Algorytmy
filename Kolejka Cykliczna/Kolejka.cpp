#include<iostream>
#include<cstdio>
#include "Kolejka.h"
using namespace std;


Kolejka::Kolejka(){
	Front=0;
	Rear= maxlength-1;
}

int Kolejka::AddOne(int i){
 return ((i + 1) % maxlength);
}

//wstawia element x na początek kolejki
void Kolejka::Enqueue(elementtype x){
 if ( AddOne(AddOne(Rear)) != Front) {
 		Rear = AddOne(Rear);
 		Queue[Rear] = x;
	}
}

//usuwa pierwszy element
void Kolejka ::Dequeue(){
 if (!Empty()) {
 		Front= AddOne(Front);
	}
}

//sprawdza czy kolejka jest pusta
bool Kolejka::Empty(){
 return (AddOne(Rear) == Front);
}

//zwraca pierwszy element
elementtype Kolejka::FrontElem(){
 if (!Empty()) 
 return Queue[Front];
}

//usuwa wszytskie elementy
void Kolejka::Makenull(){
	Front=0;
	Rear= maxlength-1;
}
