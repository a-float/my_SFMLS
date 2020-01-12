#include<iostream>
using namespace std;

bool isPrime(int n){
  if(n <=1 )return false;
  for(int i = 2; i <= n / 2; ++i){
      if(n % i == 0)
      {
          return false;
      }
  }
  return true;
}


void check(int arr[9], bool f[9], int s, int e){
    if(s == e){
        for(int i = 0; i < 9; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = 2; i < 10; i++){
        if(f[i-1] && abs(i-arr[s-1])>=2){       //num available and difference greater than 2
            if(!(isPrime(i) && isPrime(arr[s-1]))){     //no adjacent primes
                arr[s] = i;
                f[i-1] = false;
                check(arr,f,s+1,e);
                f[i-1] = true;
                arr[s]= 0;
            }
        }
    }
}

int main(){
    int t[9]     = {1,0,0,0,0,0,0,0,0}; //answer
    bool free[9] = {0,1,1,1,1,1,1,1,1}; //was this number used already

    check(t,free,1,9);

return 0;
}
