#include<iostream>
using namespace std;

int main(){
   while(1){
int tmp=0,a=1,b=2;
int x;
cin>>x;
int c = 0;
while(b<=x){
   if(x%b == 0){
      x/=b;
      c++;
      if(c > 2){
         cout<<'nie';
         break;
      }
      if(x == 1){
         cout<<"tak";
         break;
      }
   }
   tmp = a;
   a = b;
   b+=tmp;
}
   }
return 0;
}

