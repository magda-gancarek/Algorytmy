#ifndef DRZEWO_H
#define DRZEWO_H
#include <iostream>
using namespace std;

typedef int Telement;
struct Node{
 Telement info;
 Node * left;
 Node * right;
};
typedef Node *PNode;


class BinaryTree{
protected:
PNode T;
public:
BinaryTree();
~BinaryTree(); //wywołuje MAKENULL(T)

PNode PARENT(PNode n); //zwraca rodzica węzła n w drzewie
PNode PARENT1(PNode n,PNode T);//
PNode LEFT_CHILD(PNode n); //zwraca lewe dziecko węzła n
PNode RIGHT_CHILD(PNode n); //zwraca prawe dziecko węzła
Telement GetLabel(PNode n); //zwraca etykiete węzła n

PNode BuildTree1(int m);
void BuildTree(int m);

PNode ROOT(); //węzeł który jest korzeniem lub NULL jeśli drzewo jest puste
void MAKENULL(PNode p); //zwalnia pamięć zajętą przez poddrzewo o korzeniu n

void PreOrder(PNode t);
void InOrder(PNode t);
void PostOrder(PNode t);
};


#endif