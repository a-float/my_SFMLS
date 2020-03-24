#include<iostream>
using namespace std;

/*Napisac program sprawdzaj¹cy czy istnieje
spojny podci¹g ci¹gu Fibonacciego o zadanej sumie..*/

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
   cout<<"Enter the sum: ";
   int sum;
   cin>>sum;

   int s = 0;
   int e = 0;
   int tmpsum = 0;
   while(tmpsum != sum || fib(s) > sum){
      while(tmpsum < sum){
         e++;
         tmpsum+=fib(e);
      }
      while(tmpsum > sum){
         tmpsum-=fib(s);
         s++;
      }
   }
   cout<<s<<" "<<e<<endl;
   if(tmpsum == sum){cout<<"true";}
   else cout<<"false";

   return 0;
}
