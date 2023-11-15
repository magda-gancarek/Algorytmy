#include<iostream>
#include<cstdio>
#include "słownik.h"
using namespace std;

int main() {


dictionary s;

s.Insert("Ala");

cout << s.Member("Ala") << endl;
cout << s.H("Ala") << endl;

s.Insert("As");

cout << s.Member("As") << endl;
cout << s.H("As") << endl;
cout << s.Member("Ala") << endl;
cout << s.H("Ala") << endl;

s.Insert("Gancarek");

cout << s.H("Gancarek") << endl;
cout << s.Member("Gancarek") << endl;


s.Delete("Ala");
cout << s.Member("As") << endl;
cout << s.Member("Ala") << endl;

s.Makenul();
//cout << "Makenull" << endl;

cout << s.Member("As") << endl;
cout << s.Member("Gancarek") << endl;



} 