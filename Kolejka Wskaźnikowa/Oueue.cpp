#include<iostream>
#include<cstdio>
#include "Queue.h"
using namespace std;

//konstruktor
Queue::Queue(){
	Front = new celltype; // tworzy głowę
	Rear = Front; //aktualizyje wartości front i rear
	Front->next = NULL;
}

Queue::~Queue(){
	position temp;

	while(Front->next != NULL){
		temp = Front;
		Front = Front->next;
		delete temp; 
	}
	delete Front;
}

//wstawia element x na koniec kolejki 
void Queue::Enqueue(elementtype x){
	position p = new celltype; //stworzeniu nowej komórki: 
	p->element = x; //wstawieniu nowostworzonej komórki na koniec kolejki
	p->next = NULL;
	Rear->next = p; //uaktualnieniu wartości zmiennej rear tak, aby wskazywała na  nowo utworzoną  komórkę
	Rear = p;

} 


void Queue::Dequeue(){
//jeśli kolejka nie jest pusta 
	if(!Empty()){
		position p = Front; //zapamiętujemy dotychczasową głowę
		Front = Front->next; //głowę ustawia na następny element 
		delete p; //usuwa dotychczasową głowę
	}
} 
  
elementtype Queue::FrontElem(){
	//jeśli kojejka nie jest pusta
	if(!Empty()){
		return (Front->next->element); //zwraca pierwszy element
	}
} 

bool Queue::Empty(){
	return (Front->next == NULL); //jeśli głowa wskazuje na null to jest pusta
} 