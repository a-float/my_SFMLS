#include<iostream>
using namespace std;

int main(){
   int digits[10] = {};
   int a,b;
   cin>>a>>b;
   while(a != 0){
      digits[a%10]++;
      a/=10;
   }
   while(b != 0){
      digits[b%10]--;
      b/=10;
   }
   bool f = true;
   for(int i = 0; i < 10; i++){
      if(digits[i] != 0){
         f = false;
         break;
      }
   }
   if(f)cout<<"Identico";
   else cout<<"No identico";
   return 0;
}
