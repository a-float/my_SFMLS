#include<iostream>
using namespace std;

int step(int a,int b){
   return(a + 2*b + 2);
}

int main(){
   int a = 3; //A(b) = a
   int b = 1;
   int x;
   cin>>x;
   while(a < x){
      cout<<a<<" "<<b<<endl;
      if(x%a == 0){
         cout<<x<<" = A("<<b<<")*"<<x/a<<" = "<<a;
         return 0;
      }
      a = step(a,b);
      b++;
   }
   cout<<"nie jest";
   return 0;
}

