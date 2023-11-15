#include<iostream>
#include<cstdio>
#include "słownik.h"
using namespace std;

dictionary::dictionary(){
for (int i=0;i<B;i++)
D[i]=NULL;
}

bool dictionary::Member(elementtype x){
position current;
current=D[H(x)];
	while (current!=NULL){
		if (current->element==x) return true;
		else current=current->next;
	}
	return false;
}

void dictionary::Insert(elementtype x){
	int bucket;
	position oldheader;
	if (!Member(x)){
		bucket=H(x);
		oldheader=D[bucket];
		D[bucket]=new celltype;
		D[bucket]->element=x;
		D[bucket]->next=oldheader;
	}
}

void dictionary::Delete(elementtype x){
	position p,current;
	int bucket;
	bucket=H(x);
	if (D[bucket]!=NULL){
	//x jest w pierwszej komórce
	 	if (D[bucket]->element==x){
			p=D[bucket];
			D[bucket]=D[bucket]->next;
			delete p;
		}
		//jeśli x występuje w zbiorze, to nie w pierwszej komórce
		else {
			current=D[bucket];
			while (current->next!=NULL)
				if ( (current->next->element)==x ){
					p=current->next;
					current->next=current->next->next;
					delete p;
					break;//natychmiastowe wyjście z pętli while
				}
				else current=current->next;
		} 
	} 
}


dictionary::~dictionary(){
	position p;
	for (int i=0;i<B;i++){
		while (D[i]!=NULL) {
			p=D[i];
			D[i]=D[i]->next;
 			delete p;
 		}
	 }
}

void dictionary::Makenul(){
	position p;
	for (int i=0;i<B;i++){
		while (D[i]!=NULL){
			p=D[i];
			D[i]=D[i]->next;
 			delete p;
 		}	
	}	
}

int dictionary::H(elementtype x){
	return (int(x[0]))%B;
}