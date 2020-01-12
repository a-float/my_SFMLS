#include<iostream>
using namespace std;

/*Dany jest ci¹g okreœlony wzorem:
 A(n+1) = (A(n)%2)*(3*A(n)+1)+(1-A(n)%2)*A(n)/2
 Startuj¹c z dowolnej liczby naturalnej >1
 ci¹g ten osi¹ga wartoœæ 1. Napisaæ program,
 który znajdzie wyraz pocz¹tkowy z przedzia³u
 2-10000 dla którego wartoœæ 1 jest osi¹galna
 po najwiêkszej liczbie kroków.*/

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
