#include<iostream>
#include<math.h>
using namespace std;

void sito(bool * arr, int s){
   for(int i = 0; i < sqrt(s)+1; i++){
      if(arr[i] == 0){
         for(int j = i+i; j<s; j+=i){
            arr[j] = 1;
         }
      }
   }
}

int main(){
   int N;
   cin>>N;
   bool arr[N+1] = {1,1,0};
   sito(arr,N+1);
   for(int i = 0; i < N+1; i++){
      if(arr[i] == 0)cout<<i<<endl;
   }
return 0;
}
