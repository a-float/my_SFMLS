#include<iostream>
using namespace std;

/*Znalezc najmniejsze wyrazy pocz¹tkowe zamiast 1,1
aby w ci¹gu analogicznym do ciagu Fibonacciego
wystapil w nim wyraz rowny numerowi bie¿¹cego roku.
*/

int main(){
   int tmp;
   int limit = 40;
   for(int i = 1; i < limit; i++){
      for(int j = i; j < limit; j++){
         cout<<"checking: "<<i<<" "<<j<<endl;
         int a = i;
         int b = j;
         while(1){
            tmp = b;
            b += a;
            if(b > 2019)break;
            a = tmp;
            if(b == 2019){
               cout<<"found a pair: "<<i<<" "<<j<<endl;
               cin.get();
            }
         }
      }
   }
   return 0;
}