#include<iostream>
#include<cmath>
using namespace std;

bool czy_pierwsza(int a){
    if(a<2)return false;
    for(int i = 2; i < a/2+1; i++){
        if(a%i==0)return false;
    }
    return true;
}

int bin_arr2int(int arr[], int s, int e){
    int len = e-s;
    int ans = 0;
    for(int i = s; i < e; i++){
        ans+=arr[i]*pow(2,len-i-1);
    }
    return ans;
}

bool check_ciag(int arr[], int s, int e){
    cout<<s<<" "<<e<<endl;
    if(s == e)return true;
    for(int i=s; i <= e; i++){
            cout<<"Checking "<<i<<endl;
        if(czy_pierwsza(bin_arr2int(arr,s,i))){
                cout<<"Entering "<<s<<" "<<i<<endl;
           return(check_ciag(arr,i,e));
        }
    }
    return false;
}

int main(){
    int arr[6] = {1,1,0,1,0,0};
    cout<<check_ciag(arr,0,6);

    return 0;
}
