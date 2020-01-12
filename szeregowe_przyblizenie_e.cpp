#include<iostream>
using namespace std;
#define E 10

void divide(int a, int b, int * arr){
  arr[0] = a/b;
  a = (a % b) * 10;
  for(int i = 0; i < E-1; i++) {
    arr[i+1] = a / b;
    a = (a % b) * 10;
  }
}

int main(){
   int sum[E] = {0};
   int next_ele[E] = {0};
   divide(10,3,arr);
   cout<<arr[0]<<".";
   for(int i = 1; i < E; i++){
      cout<<arr[i];
   }
return 0;
}
