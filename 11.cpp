#include<iostream>
using namespace std;

/*Napisa� program wyznaczaj�cy najmniejsz� wsp�ln� wielokrotno�� 3 zadanych liczb*/

int NWD(int a, int b){
   while(a*b!=0){
      a=a%b;
      if(a==0)break;
      b=b%a;
   }
   return a+b;
}

int NWW(int a, int b){
   return a*b/(NWD(a,b));
}
int main(){
   int a,b,c;
   cin>>a>>b>>c;
   cout<<NWW(NWW(a,b),c);
return 0;
}
