#include<iostream>
using namespace std;

/*Napisa� program generuj�cy elementy ci�gu Fibonaciego mniejsze od miliona.*/

int main(){
   int a = 0;
   int b = 1;
   int tmp;
   while(1){
      tmp = b;
      b += a;
      if(b > 1000000)break;
      a = tmp;
      cout<<b<<endl;
   }
   return 0;
}
