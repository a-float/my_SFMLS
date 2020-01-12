#include<iostream>
using namespace std;

/*Napisaæ program generuj¹cy elementy ci¹gu Fibonaciego mniejsze od miliona.*/

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
