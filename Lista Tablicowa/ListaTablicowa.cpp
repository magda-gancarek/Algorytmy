#include<iostream>
#include<cstdio>
#include "ListaTablicowa.h"
using namespace std;
int minim =-10000000;

void print(List l){
 position i = First(l);
 while (i != END(l)){
  	printf(" %d,", Retrieve(i, l));
  	i = Next(i, l);
 	}
 printf("\n");
}


void Copy(List & l){
	position i = First(l);
	position koniec = END(l);
	while (i != koniec){
		Insert(Retrieve(i, l), END(l), l);
  	//print(l);
  	i++;
 	}
	//print(l);
}

void DeleteDuplicate(List & l){
 position bieżąca = First(l);
 position testowana = Next(bieżąca,l);
//cout << bieżąca << " " << testowana << endl;

 while(bieżąca != END(l)-1){
	 cout << Retrieve(bieżąca, l) << " t " << Retrieve(testowana, l) << endl;
	 if(Retrieve(testowana, l) == Retrieve(bieżąca, l)){
			position do_us = Next(testowana,l);
			testowana = Next(do_us,l);
			testowana = Next(testowana,l);
			Delete(do_us,l);
	  }
		else{
			cout << "tu" << endl;
			testowana = Next(testowana,l);
		}
	 
	 bieżąca = Next(bieżąca,l);
 }
}


void DeleteDuplicates(List & l){
	position bieżąca = First(l);
	position testowana = Next(bieżąca,l);

 for( int i = bieżąca; i < END(l); i++ ){
	
    for( int j = testowana; j < END(l); j++ ){
			if(Retrieve(testowana, l) == Retrieve(bieżąca, l)){
				position do_us = testowana;
				//print(l);
				Delete(do_us,l);
				//print(l);
				testowana = do_us;
			}
			else{
				testowana = Next(testowana,l);
			}
		}
	bieżąca = Next(bieżąca,l); //następny sprawdzany element
	testowana = Next(bieżąca,l); //wyczyszczenie
	}	
}

position END(List l){
	return l.last + 1;
}
 
position First(List l){
	return 0;
}
 
position Next(position p, struct List l){
	if ((p>l.last) || (p<0))
		return -1;
	else
		return p+1;
}
 
position Previous(position p, struct List l){
	if ((p>l.last+1) || (p<0)) 
		return -1;
	else
		return p-1;
}
 
 
position Locate(elementtype x, List l){ 
	for (int i = 0; i<END(l); i++){
		if (l.elements[i] == x)
			return i;
	}
	return END(l);
}
 
elementtype Retrieve(position p, List l){
	if ((p >= 0) || p <= END(l)){
		return l.elements[p];
	}
	else
		return minim;
}

 
bool Insert(int x, position p, List &l) {
	if ((p<0) || (p > l.last+1)) 
		return false;
	else if (l.last>=maxlength) 
		return false;
	else if (p <= END(l)){
		for (position k = END(l); k>p; k--){
			l.elements[k] = l.elements[k - 1];
		}
		l.elements[p] = x;
		l.last = l.last + 1;
		return true;
	}
	else
		return false;
}

bool Delete(position p, List &l){
	while (p<END(l) - 1){
		l.elements[p] = l.elements[p + 1];
		p++;
	}
	l.last--;
	return false;
}

/* 
bool Delete(position p, List &l){
	if ((p>l.last) || (p<0)) 
		return false;
	else{
 		for (int i=p; i< l.last;i++){
			l.elements[i]=l.elements[i+1];
 			l.last--;
 		}
		return true;
	}
}*/


