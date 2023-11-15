#include<iostream>
#include<cstdio>
#include "Lista.h"
using namespace std;

int main() {

Lista lista;
//Wstaw 5 na początek
lista.Insert(5,lista.First() );

//wypisz pierwszy element
position poczatek = lista.First(); 
cout <<"Pierwszy element: " <<lista.Retrieve(poczatek) << endl;

//wstaw 2 na początek
lista.Insert(2,lista.First() );
//wypisz pierwszy element
cout << "Pierwszy element: " << lista.Retrieve(poczatek) << endl;
//wypisz drugi element
cout << "Drugi element: " <<lista.Retrieve(poczatek->next) << endl;
//wstaw 1 za pierwszym elementem
lista.Insert(1,lista.First()->next );

cout << endl;
//wypisz pierwszy element
//wypisz drugi element
//wypisz trzeci element
for(position poczatek = lista.First(); poczatek!=lista.END(); poczatek=poczatek->next) {
	cout << lista.Retrieve(poczatek) << " ";
}

cout << endl;
lista.Delete(lista.Locate(2));
for(position poczatek = lista.First(); poczatek!=lista.END(); poczatek=poczatek->next) {
	cout << lista.Retrieve(poczatek) << " ";
}



} 

