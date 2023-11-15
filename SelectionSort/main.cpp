#include <iostream>
using namespace std;

int main() {

int k,x,n; //k-indeks minimalnego elementu; x-obiekt minimalny
int a[10] = {0,1,2,3,4,5,6,7,8,9};
//int a[10] = {9,8,7,6,5,4,3,2,1,0};
//int a[10] = {6,7,3,9,2,0,4,5,1,8};
//int a[10] = {7,1,2,0,3,5,6,9,8,4};
//int a[10] = {1,4,7,9,0,2,3,8,5,6};
//int a[10] = {3,8,9,6,7,4,5,2,1,0};
//int a[10] = {8,4,6,7,9,1,0,3,2,5};
//int a[10] = {5,1,2,7,3,5,9,8,6,4};
//int a[10] = {9,4,8,3,7,2,6,1,5,0};
//int a[10] = {5,6,4,7,3,8,2,9,1,0};
//int a[10] = {2,4,0,1,3,5,8,6,9,7};
//int a[10] = {0,1,9,2,8,3,7,6,4,5};



n = 10; //liczba elementów
int wejscie = 0;
int porownanie = 0;

	for (int i=0;i< n;i++){ //O(n)
 	k=i;
	x=a[i]; 
 		for (int j=i+1;j<n;j++){ //O(n-1)

			porownanie++; //zmienna zlicza ilość porównań - operacja dominująca
			 if (a[j]<x){
				wejscie++; // jak wejdziemy do pętli
 				k=j;
 				x=a[j];
				}
		}

/*wyświetlenie działania		 
 cout << "Przed posortowaniem: ";
 for(int i = 0; i < n ; i++){
 cout << a[i] << " " ;
	}
 cout << endl;*/

 a[k] = a[i];
 a[i] = x; //zamieniamy element i-ty z min
	}


cout << "Po posortowaniu: ";
for(int i = 0; i < n ; i++){
	cout << a[i] << " " ;
	}

cout << "\nLiczba wejsc do if: " << wejscie << endl;	
cout << "\nLiczba porownań: " << porownanie << endl;	

}

/*
W(n) = O(n^2)
A(n) = O(n^2)
/\(n) = 0

Liczba operacji:
peymistyczna: 45 porównań, 25 wejść do 
optymistyczna: 0 wejść
test 1: 14
test 2: 7
test 3: 11
test 4: 17
test 5: 16
test 6: 9
test 7: 14
test 8: 19
test 9: 7
test 10: 10
*/
