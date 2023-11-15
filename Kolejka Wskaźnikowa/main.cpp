#include<iostream>
#include<cstdio>
#include "Queue.h"
using namespace std;

int main() {

Queue kolejka;

cout << "pusta: " << kolejka.Empty() << endl;
kolejka.Enqueue(5);
cout << "pusta: " << kolejka.Empty() << endl;
cout << kolejka.FrontElem()  << endl;
kolejka.Dequeue(); //usunięcie pierwszgeo elementu
cout << "pusta: " << kolejka.Empty() << endl;
kolejka.Enqueue(4);
kolejka.Enqueue(3);
kolejka.Enqueue(2);
//4 3 2
cout << kolejka.FrontElem() << endl;
kolejka.Enqueue(1);
//4 3 2 1
cout << kolejka.FrontElem() << endl;
kolejka.Dequeue(); //3 2 1
cout << kolejka.FrontElem() << endl;
kolejka.Enqueue(6); //3 2 1 6
cout << kolejka.FrontElem() << endl;
kolejka.Dequeue(); //2 1 6
kolejka.Dequeue(); //1 6
cout << kolejka.FrontElem() << endl;
cout << "pusta: " << kolejka.Empty() << endl;
kolejka.Dequeue(); //6
kolejka.Dequeue(); //
cout << "pusta: " << kolejka.Empty() << endl;

} 