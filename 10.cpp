#include<iostream>
using namespace std;

/*Napisaæ program wyznaczaj¹cy najwiêkszy wspólnydzielnik 3 zadanych liczb.*/

int NWD(int a, int b){
   while(a*b!=0){
      a=a%b;
      if(a==0)break;
      b=b%a;
   }
   return a+b;
}

int main(){
   int a,b,c;
   cin>>a>>b>>c;
   cout<<NWD(a,NWD(b,c));
return 0;
}
