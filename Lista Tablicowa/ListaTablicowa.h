#ifndef LISTA_TABLICOWA_H
#define LISTA_TABLICOWA_H
#include <iostream>
using namespace std;

typedef int elementtype, position ;
const int maxlength=10;
struct List{
	elementtype elements[maxlength];
	int last;     
};

position END(List l);
position First(List l) ;
position Next(position p,List l);
position Previous(position p,List l) ;
position Locate(elementtype x, List l) ;
elementtype Retrieve(position p, List l) ;
bool Insert(int x, position p, List &l);
bool Delete(position p, List &l);
void Copy(List & l);
void print(List l);
void DeleteDuplicates (List & l);


#endif