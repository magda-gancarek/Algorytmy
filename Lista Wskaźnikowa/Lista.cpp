#include<iostream>
#include<cstdio>
#include "Lista.h"
using namespace std;


Lista::Lista(){ 
	l=new celltype;
	l->next=NULL;
}

Lista::~Lista(){
	position tmp;
	if ((l!=NULL)&& (l->next!=NULL))
		while (l->next!=NULL){ 
			tmp=l->next;
 			l->next=tmp->next;
			delete tmp;
		}
}


void Lista::Insert(elementtype x, position p){
 position tmp;
 tmp = p->next;
 p->next = new celltype;
 p->next->element = x;
 p->next->next = tmp;
}

void Lista::Delete(position p){
	position tmp;
	tmp = p->next;
	p->next = p->next->next;
	delete tmp;
}

elementtype Lista::Retrieve(position p){
	if (p->next!=NULL){
  	return p->next->element;
	}
}

position Lista::Locate(elementtype x){
	position tmp;
	tmp = l;
	while (tmp->next!=NULL){
 		if (tmp->next->element==x){
			return tmp;
		}
 		tmp=tmp->next;
	}
 	return tmp; 
}


position Lista::First(){
	return l;
}

position Lista::Next(position p){
 return p->next;
}

position Lista::Previous(position p){
	position tmp;
 	tmp=l;
 	while (tmp->next!=p) {
		tmp=tmp->next;
	}	
 return tmp;
}

position Lista::END(){
	position tmp = l;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	return tmp;
}
