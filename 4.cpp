#include<iostream>
using namespace std;

/*Napisaæ program sprawdzaj¹cy czy istnieje
podci¹g ci¹gu Fibonacciegoo sumie
równej numerowi bie¿¹cego roku.*/

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
