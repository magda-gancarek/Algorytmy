#ifndef WIELOMIAN_H
#define WIELOMIAN_H
#include <iostream>
using namespace std;


class Polynominal{
	private:
	double* tablica_współczynników;
	int rozmiar_tablicy;

	public:
	Polynominal();
	Polynominal(int degree);
	Polynominal(double* tab_wsp, int rozmiar);
	~Polynominal();
	Polynominal Add(Polynominal & other);
	Polynominal Substract(Polynominal & other);
	Polynominal Multyply(Polynominal & other);
	int degree();
	void displayPoly();
	int Horner(int a, int rozmiar);
	double* Reverse(int degree);


};


#endif