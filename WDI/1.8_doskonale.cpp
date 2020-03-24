#include<iostream>
#include<cmath>
using namespace std;

/*Napisac program wyszukujacy liczby doskonale mniejsze od miliona.*/

bool pierw(long n){
   if(n<0)return false;
   else if(n <= 2)return n-1;
   else{
      for(long i = 2; i < sqrt(n)+1; i++){
         if(n%i == 0)return false;
      }
      return true;
   }
}

int main(){
   long k = 0;
   long i = 2;
   long limit = 10000000;
   while(k<limit){
      if(pierw(i)){
         k=pow(2,i-1)*(pow(2,i)-1);
         cout<<"Checking "<<k<<endl;
         if(k<0)break; //genialny fix - sprawdza a¿ dojdzie do overflow'u
         long s = 0;
         for(long j = 1; j < k/2+1; j++){
            if(k%j == 0)s+=j;
         }
         if(k == s)cout<<k<<endl;
      }
      i++;
   }

return 0;}
