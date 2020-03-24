#include<iostream>
#include<cmath>
using namespace std;

int length(int x){
   int number_of_digits = 0;
   do {
        ++number_of_digits;
        x /= 10;
   } while(x);
   return number_of_digits;
}
/*checks if a number is a palindrome*/
bool check(int a){
   int b = a;
   int k = 0;
   int len = length(a);
   for(int i = 0; i < len; i++){
      k*=10;
      k+=a%10;
      a=(a-a%10)/10;
   }
   if(b == k)return true;
   else return false;
}
/*returns number in binary*/
int bin(int a){
   int k = 0;
   int i = 0;
   while(pow(2,i) < a){
      i++;
   }
   while(i > 0){
      k*=10;
      if(pow(2,i-1)<=a){
         k+=1;
         a-=pow(2,i-1);
      }
      i--;
   }
   return k;
}

int main(){
   int x;
   cin>>x;
   if(check(x))cout<<"jest w 10"<<endl;
   else cout<<"nie jest w 10"<<endl;

   if(check(bin(x)))cout<<"jest w 2"<<endl;
   else cout<<"nie jest w 2"<<endl;
   return 0;
}
