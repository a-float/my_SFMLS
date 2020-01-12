#include<iostream>
using namespace std;
#define SIZE 10

void append(int x, int * arr){
   int i = 1;
   while(arr[i] < x){
      arr[i-1] = arr[i];
      arr[i] = x;
      i++;
      if(i == 10)break;
   }

   for(int i = 0; i < SIZE; i++){
         cout<<arr[i]<<" ";
   }
   cout<<endl;
}

int main(){
   int c;
   int nums[SIZE] = {0};
   while(cin>>c){
      if(c == 0)break;
      else if(c>nums[0]){
         append(c, nums);
      }
   }
   cout<<nums[0];
return 0;
}
