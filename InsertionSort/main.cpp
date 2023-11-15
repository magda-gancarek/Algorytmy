#include <iostream>
using namespace std;

int main() {

int j,x;
int p;

int a[10] = {0,1,2,3,4,5,6,7,8,9};
//int a[10] = {9,8,7,6,5,4,3,2,1};
//int a[10] = {6,9,4,3,7,0,2,1,5,8};

int n = 10;

 for (int i=2;i<=n;i++){
 	x=a[i]; 
	a[0]=x;
	j=i-1;
	p++;
	 while (x<a[j]){
		 a[j+1]=a[j];
 		 j=j-1; //przesuwamy w prawo, robimy miejsce na
 	 }
 a[j+1]=x;
 }


for(int i = 0; i < n ; i++){
	cout << a[i] << " " ;
	}
cout << p;

}
