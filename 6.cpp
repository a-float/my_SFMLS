#include<iostream>
using namespace std;

/*Napisa� program wypisuj�cy podzielniki liczby.*/

int main(){
   int n;
   cin>>n;
   for(int i = 1; i < n/2+1; i++){
      if(n%i == 0)cout<<i<<" ";
   }
   cout<<n;
return 0;
}
