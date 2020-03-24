#include<iostream>
#include<cmath>
using namespace std;

/*Napisac program sprawdzajacy czy zadana liczba jest pierwsza*/

bool pierw(int n){
   if(n > 0 && n <= 2)return n-1;
   else{
      for(int i = 2; i < sqrt(n)+1; i++){
         if(n%i == 0)return false;
      }
      return true;
   }
}

int main(){
   for(int i = 0; i <100; i++){
      if(pierw(i))cout<<i<<endl;
   }

return 0;}
