#include <stdio.h>
#include <stdbool.h>

bool check(int a){
    while(a/10 != 0){
        if((a/10)%10 > a%10)return false;
        a/=10;
    }
    return true;
}
int getNextNumber(int a, int b){
    a++;
    while(a < b){
        if(check(a))return a;
        a++;
    }
    return -1;
}
bool checkPrime(int a){
    if(a<2)return false;
    if(a == 2)return true;
    if(a%2 == 0)return false;
    for(int i = 3; i < a/2 + 1; i+=2){
        if(a%i == 0)return false;
    }
    return true;
}
void printAllPrimes(int n){
    int a = 1;
    while(a != -1){
        //printf("%d ", a);
        a = getNextNumber(a,n);
        if(checkPrime(a))printf("%d\n", a);
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    printAllPrimes(n);
    return 0;
}