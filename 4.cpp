#include<iostream>
using namespace std;

/*Napisa� program sprawdzaj�cy czy istnieje
podci�g ci�gu Fibonacciegoo sumie
r�wnej numerowi bie��cego roku.*/

int num = 19;

int fib(int k){
   int a = 0;
   int b = 1;
   int tmp;

   if(k < 2)return k;
   for(int i = 0; i < k-1; i++){
      tmp = b;
      b+=a;
      a = tmp;
   }
   return b;
}
int main(){

return 0;
}
