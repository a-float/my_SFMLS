#include<iostream>
using namespace std;

/*Napisaæ program wypisuj¹cy podzielniki liczby.*/

int main(){
   int n;
   cin>>n;
   for(int i = 1; i < n/2+1; i++){
      if(n%i == 0)cout<<i<<" ";
   }
   cout<<n;
return 0;
}
