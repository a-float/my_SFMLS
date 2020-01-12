#include<iostream>
using namespace std;

int multiply(int * arr, int x, int len){
   int carry = 0;
   int prod;
   for(int i = 0; i < len; i++){
      prod = arr[i] * x + carry;
      arr[i] = prod%10;
      carry = prod / 10;
   }
   while(carry>0){
      arr[len] = carry%10;
      carry /= 10;
      len++;
   }
   return len;
}

void factorial(int * arr, int n){
   int len = 1;
   for(int i = 2; i <= n; i++){
      len = multiply(arr,i,len);
   }
   cout<<n<<"! = ";
   for(int i = len-1; i >=0; i--){
      cout<<arr[i];
   }
   cout<<endl;
}

int main(){
   const int M_SIZE = 10000;
   int f;
   cin>>f;
   int arr[M_SIZE] = {1};
   factorial(arr, f);
return 0;
}

