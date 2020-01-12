#include<iostream>
using namespace std;

/*Dany jest ci�g okre�lony wzorem:
 A(n+1) = (A(n)%2)*(3*A(n)+1)+(1-A(n)%2)*A(n)/2
 Startuj�c z dowolnej liczby naturalnej >1
 ci�g ten osi�ga warto�� 1. Napisa� program,
 kt�ry znajdzie wyraz pocz�tkowy z przedzia�u
 2-10000 dla kt�rego warto�� 1 jest osi�galna
 po najwi�kszej liczbie krok�w.*/

int A(int n){
   return((n%2)*(3*n+1)+(1-n%2)*n/2);
}

int main(){
   int maxi = 2;
   int maxx = 0;
   for(int i = 2; i < 10000; i++){
      int a = i;

      int c = 0;
      while(a != 1){
         a = A(a);
         c++;
      }
      if(c>maxx){
         maxx = c;
         maxi = i;
      }
      cout<<i<<" "<<c<<endl;
   }
   cout<<maxi<<" "<<maxx<<endl;
return 0;
}
