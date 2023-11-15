#include<iostream>
#include<cstdio>
#include "Drzewo.h"
using namespace std;


int main() {

BinaryTree drzewo;
drzewo.BuildTree(9);
/*
					1
		2							6
	3 	5  				7   9
4							8
*/
PNode korzeń =  drzewo.ROOT();
cout << korzeń << endl;
cout << "Wartość korzenia: " << drzewo.GetLabel(korzeń) << endl;

PNode lewe_dziecko = drzewo.LEFT_CHILD(korzeń);
cout << "Wartość lewego dziecka: " << drzewo.GetLabel(lewe_dziecko) << endl;

PNode prawe_dziecko = drzewo.RIGHT_CHILD(korzeń);
cout << "Wartość prawego dziecka: "  << drzewo.GetLabel(prawe_dziecko) << endl;

PNode rodzic_prawego =  drzewo.PARENT(prawe_dziecko);
cout << "Wypisać wartość węzła, który jest rodzicem węzła będącego prawym dzieckiem korzenia: " << drzewo.GetLabel(rodzic_prawego) << endl;

PNode prawe_lewego = drzewo.RIGHT_CHILD(lewe_dziecko);
cout << "Prawe dziecko, lewego dziecka od korzenia: " << drzewo.GetLabel(prawe_lewego) << endl;

PNode rodzic_lewe_prawe =  drzewo.PARENT(prawe_lewego);
cout << "Wypisać wartość węzła, który jest rodzicem węzła będącego prawym dzieckiem lewego dziecka korzenia: " << drzewo.GetLabel(rodzic_lewe_prawe) << endl;

PNode p_p_k = drzewo.PARENT(drzewo.RIGHT_CHILD(prawe_dziecko));
cout << drzewo.GetLabel(p_p_k) << endl;;

drzewo.PreOrder(korzeń);
cout << endl;
drzewo.InOrder(korzeń);
cout << endl;
drzewo.PostOrder(korzeń);
cout << endl;


}