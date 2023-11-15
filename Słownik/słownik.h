#ifndef DRZEWO_H
#define DRZEWO_H
#include <iostream>
using namespace std;

int const B=65;
typedef char * elementtype;
struct celltype{
elementtype element;
celltype * next;
};
typedef celltype * position; 

class dictionary
{
protected :
 position D[B];
public:
 dictionary();
 ~dictionary();
 void Makenul();
 bool Member(elementtype x);
 void Insert(elementtype x);
 void Delete(elementtype x);
 int H(elementtype x);
};


#endif