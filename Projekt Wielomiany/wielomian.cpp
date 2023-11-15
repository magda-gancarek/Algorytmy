#include<iostream>
#include<cstdio>
#include "wielomiany.h"
using namespace std;

Polynominal::Polynominal(){
	rozmiar_tablicy = 1;
	tablica_współczynników = new double[1];
	tablica_współczynników[0] = 0;
}

Polynominal::Polynominal(int degree){
	rozmiar_tablicy = degree + 1;
	tablica_współczynników = new double[rozmiar_tablicy];
	for (int i =0; i < rozmiar_tablicy; i++){
		tablica_współczynników[i] = 0;
	}
}

Polynominal::Polynominal(double* tab_współ, int rozmiar){
	rozmiar_tablicy = rozmiar;
	tablica_współczynników = new double [rozmiar];
	for(int i =0; i < rozmiar ; i ++){
		tablica_współczynników[i] = tab_współ[i];

	}
}


Polynominal::~Polynominal(){
	delete[] tablica_współczynników;
	rozmiar_tablicy = 0;
	tablica_współczynników = nullptr;
}

Polynominal Polynominal::Add(Polynominal & other){
	int sizeOfAnswer = (rozmiar_tablicy >= other.rozmiar_tablicy) ? rozmiar_tablicy : other.rozmiar_tablicy;

	Polynominal answer(sizeOfAnswer - 1);
	if(rozmiar_tablicy >= other.rozmiar_tablicy){
		for(int i =0; i < other.rozmiar_tablicy; i++){
			answer.tablica_współczynników[i] = tablica_współczynników[i] + other.tablica_współczynników[i];
		}
		for(int j = other.rozmiar_tablicy; j < rozmiar_tablicy; j++){
			answer.tablica_współczynników[j] = tablica_współczynników[j];
		}
	}
	else{
		for(int i =0; i < rozmiar_tablicy; i++){
			answer.tablica_współczynników[i] = tablica_współczynników[i] + other.tablica_współczynników[i];
		}
		for(int j = rozmiar_tablicy; j < other.rozmiar_tablicy; j++){
			answer.tablica_współczynników[j] = other.tablica_współczynników[j];
		}
		
	}
return answer;

}

Polynominal	Polynominal::Substract(Polynominal & other){
	int sizeOfAnswer = (rozmiar_tablicy >= other.rozmiar_tablicy) ? rozmiar_tablicy : other.rozmiar_tablicy;

	Polynominal answer(sizeOfAnswer - 1);
	//gdy tablica pierwsza jest większa od drugiej
	if(rozmiar_tablicy >= other.rozmiar_tablicy){
		for(int i =0; i < other.rozmiar_tablicy; i++){
			answer.tablica_współczynników[i] = tablica_współczynników[i] - other.tablica_współczynników[i];
		}
		for(int j = other.rozmiar_tablicy; j < rozmiar_tablicy; j++){
			answer.tablica_współczynników[j] = tablica_współczynników[j];
		}
	}
	else{
		for(int i =0; i < rozmiar_tablicy; i++){
			answer.tablica_współczynników[i] = tablica_współczynników[i] - other.tablica_współczynników[i];
		}
		for(int j = rozmiar_tablicy; j < other.rozmiar_tablicy; j++){
			answer.tablica_współczynników[j] = other.tablica_współczynników[j];
		}
		
	}

return answer;
}

Polynominal Polynominal::Multyply(Polynominal& other){

	int degreeOfAnswer = rozmiar_tablicy + other.rozmiar_tablicy - 2;

	Polynominal answer(degreeOfAnswer);

	for(int i = 0 ; i < rozmiar_tablicy; i++){

		for(int j = 0 ; j < other.rozmiar_tablicy; j++){

			answer.tablica_współczynników[i+j] += (tablica_współczynników[i] * other.tablica_współczynników[j]);
		}
	}

return answer;
}

int Polynominal::degree(){
	return rozmiar_tablicy - 1;
}

void Polynominal::displayPoly(){
	for(int i = rozmiar_tablicy-1 ; i >= 0; i--){
	
	
		if(i==0){
			cout <<tablica_współczynników[i]<< "*x^" << i;
		}
		else{
			cout <<tablica_współczynników[i]<< "*x^" << i << " + ";
		}
	}
}


double * Polynominal::Reverse(int n){
int temp;
n = rozmiar_tablicy-1;       
int j = n;
int zlozonosc = 0;
    for(int i=0; i<j; i++, j--)
    {
        temp = tablica_współczynników[i];
        tablica_współczynników[i] = tablica_współczynników[j];
        tablica_współczynników[j] = temp;
				
    }


return tablica_współczynników;
}



int Polynominal::Horner(int a, int n){

	int result = tablica_współczynników[0]; 
 	cout << "\n" <<n << endl;

    for (int i=1; i<rozmiar_tablicy; i++) {
        result = result * a + tablica_współczynników[i]; 
		}
 		cout <<"Wynik " <<  result << endl;
    return result;

}

