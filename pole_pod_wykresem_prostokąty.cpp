#include<iostream>
using namespace std;

float f(float x){
   return 1/x;
}

int main(){
   float k;
   float e = 0.001;
   float area = 0;
   cin>>k;
   for(float i = 1; i < k; i+=e){
      area += e*(f(i)+f(i+e))/2;
   }
   cout<<area<<endl;
return 0;
}
