#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

typedef int  elementtype; 

struct celltype  { 
   elementtype element; 
   celltype * next; 
}; 
 
typedef celltype * position;  
 
class Queue { 
protected: 
  position Front;      // wskaźnik do głowy listy 
  position Rear;    // wskaźnik do ostatniego elementu 
 
public: 
  Queue();    //konstruktor 
  ~Queue();  //destruktor 
  void Enqueue(elementtype x); 
  void Dequeue(); 
  elementtype FrontElem(); 
  bool Empty(); 
}; 

#endif