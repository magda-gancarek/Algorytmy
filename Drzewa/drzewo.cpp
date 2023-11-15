#include<iostream>
#include<cstdio>
#include "Drzewo.h"
using namespace std;

BinaryTree::BinaryTree()
{T=NULL;}

//destruktor usuwa wszystkie węzły drzewa
BinaryTree::~BinaryTree(){
	MAKENULL(T);
}

PNode BinaryTree::BuildTree1(int m){
	if (m==0) return NULL; //jeżeli m = 0 to zwróć wartość NULL

	int m_lewe, m_prawe;
	Telement x;
	PNode tmp; //utwórz korzeń

	m_lewe = m / 2; //zbuduj lewe poddrzewo z m/2 węzłami
	m_prawe = m - m_lewe - 1; //zbuduj prawe poddrzewo z m-(m/2) -1 węzłami
	cout <<"Podaj wartość do wstawienia:";
	cin >> x;
	tmp = new Node;
	tmp->info = x;
	tmp->left = BuildTree1(m_lewe);//rekurencyjnie tworzymy
	tmp->right = BuildTree1(m_prawe);
	return tmp;
}

void BinaryTree::BuildTree(int n){
	T=BuildTree1(n);
}



void BinaryTree::MAKENULL(PNode p){
	if (p!=NULL){
		if (p->left!=NULL) MAKENULL(p->left);
		if (p->right!=NULL) MAKENULL(p->right);
		delete p;
		p=NULL;
	}
}

PNode BinaryTree::ROOT(){
return T;
}

PNode BinaryTree::PARENT(PNode n){
	if (n==T) return NULL;
	else return PARENT1(n,T);
}

PNode BinaryTree::PARENT1(PNode n ,PNode T){
	if ((T->left==n) || (T->right==n)){
		return T;
	}
	else {
		PNode tmp1=NULL;
		PNode tmp2=NULL;
		if (T->left!=NULL) tmp1=PARENT1(n,T->left);
		if (T->right!=NULL) tmp2=PARENT1(n,T->right);
		return (tmp1!=NULL)?tmp1 :tmp2;
	}
}

PNode BinaryTree::LEFT_CHILD(PNode n){
	return n->left;
}

PNode BinaryTree::RIGHT_CHILD(PNode n){
	return n->right;
}

Telement BinaryTree::GetLabel(PNode n){
	if (n!=NULL) return n->info ;
}


void BinaryTree::PreOrder(PNode t) {
	if (t!= NULL) {
		cout << t->info << " ";
		PreOrder(t->left);
		PreOrder(t->right);
	}
}



void BinaryTree::InOrder(PNode t){
	if (t!= NULL){
		InOrder(t->left);
		cout << t->info << " " ;
		InOrder(t->right);
	}
}

void BinaryTree::PostOrder(PNode t){
	if (t!= NULL){
		PostOrder(t->left);
		PostOrder(t->right);
		cout << t->info << " ";
	}
}