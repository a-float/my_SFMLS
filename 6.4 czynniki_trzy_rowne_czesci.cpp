#include<iostream>
using namespace std;

const int N = 5;

bool czy_pierwsza(int a){
    for(int i = 2; i<a/2; i++){
        if(a%i == 0)return false;
    }
    return true;
}

int get_weight(int a){
    int w = 0;
    for(int i = 2; i<=a; i++){
        if(czy_pierwsza(i) && a%i == 0){
            w++;
            while(a%i == 0){
                a/=i;
            }
            if(a == 1 || a == 0)break;
        }
    }
    return w;
}

int sum(int arr[]){
    int s = 0;
    for(int i = 0; i < N; i++){
        s+=arr[i];
    }
    return s;
}

void show(int arr[], int wynik[]){
    cout<<"[ ";
    for(int i = 0; i < N; i++){
        if(wynik[i] > 0)cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    cout<<"[ ";
    for(int i = 0; i < N; i++){
        if(wynik[i] < 0)cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    cout<<"[ ";
    for(int i = 0; i < N; i++){
        if(wynik[i] == 0)cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
}

bool check(int arr[], int wynik[], int target){
    int s = 0;
    for(int i = 0; i < N; i++){
        if(wynik[i] == 0)s+=arr[i];
    }
    if(s==target)return true;
    else return false;
}

bool search_weight_3(int arr[], int target, int s, int e, int wynik[], int check_target){
    if(target == 0 && s == e){
        if(check(arr, wynik, check_target)){
            show(arr,wynik);
            return true;
        }
    }
    if(s != e){
        wynik[s] = arr[s];
        if(search_weight_3(arr, target-arr[s], s+1, e, wynik, check_target)==false){
            wynik[s] = -arr[s];
            if(search_weight_3(arr, target+arr[s], s+1, e, wynik, check_target) == false){
                wynik[s] = 0;
                return search_weight_3(arr, target, s+1, e, wynik, check_target);
            }
            else return true;
        }
        else return true;
    }
    else return false;
}

bool czy_na_trzy_rowna_waga(int arr[], const int n){
    int s = sum(arr);
    if(s%3 != 0)return false;
    int wynik[n]{0};
    return search_weight_3(arr,0,0,n,wynik, s/3);
}


int main(){
    int arr[N] = {13,53,30,6,12};
    for(int i = 0; i < N; i++){
        arr[i] = get_weight(arr[i]);
    }
    cout<<czy_na_trzy_rowna_waga(arr,N);

return 0;
}
