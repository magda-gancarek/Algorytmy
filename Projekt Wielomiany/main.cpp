#include<iostream>
#include<cstdio>
#include "wielomiany.h"
using namespace std;

int main(){
	int d1,d2;
  int choice;
	int wartosc;

  cout<<"\n Implementacja wielomianów na bazie tablic ";

	cout<<"\n Wpisz stopien pierwszego wielomianu: ";
  cin>>d1;
	cout<< d1 << endl;								
	double *arr1 = new double[d1+1];
	for(int i = d1; i >= 0; i--){
		cout << "Wpisz współczynnik przy x^" << i <<":";
		cin >> arr1[i];
	}
	Polynominal p(arr1, d1+1);
	p.displayPoly();

	cout<<"\n Wpisz stopien drugiego wielomianu: ";
  cin>>d2;
	double *arr2 = new double[d2+1];
	for(int i = d2; i >= 0; i--){
		cout << "Wpisz współczynnik przy x^" << i <<":";
		cin >> arr2[i];
	}
		
	Polynominal q(arr2, d2+1);
	q.displayPoly();

  while(1) {

  	cout<<"\n\n Menu";
  	cout<<"\n 1. Dodaj wielomiany";
  	cout<<"\n 2. Odejmnij wielomiany";
  	cout<<"\n 3. Pomnóż wielomiany";
 		cout<<"\n 4. Oblicz wartości wielomianu (Algorytm Hornera)";
    cout<<"\n 5. Wyjście";
    cout<<"\n Wpisz wybór:  ";
    cin>>choice;
		cout<<endl;        

    switch(choice){
			
			case 1:
				p.Add(q).displayPoly();                
				break;
      case 2:
				p.Substract(q).displayPoly();
        break;
      case 3:
       	p.Multyply(q).displayPoly();
				break;
      case 4:
				p.Reverse(p.degree());
				cout<<"Wpisz dla jakiej wartości ma zostać obliczony pierwszy wielomian:  ";
    		cin>>wartosc;
				p.displayPoly();
				p.Horner(wartosc, p.degree());
				break;               
      case 5:
        exit(0);
        break;                    
    }
  }
     
	return 0;

}