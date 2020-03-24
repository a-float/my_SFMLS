#include<iostream>
using namespace std;
const int N = 5;

void show(int wynik[]){
    for(int i = 0; i < N; i++){
        cout<<wynik[i]<<" ";
    }
    cout<<endl;
}

void search_weight(int arr[], int target, int s, int e, int wynik[]){
    if(target == 0 && s == e){
        show(wynik);
    }
    if(s != e){
        wynik[s] = arr[s];
        search_weight(arr, target-arr[s], s+1,e, wynik);
        wynik[s] = -arr[s];
        search_weight(arr, target+arr[s], s+1, e, wynik);
        wynik[s] = 0;
        search_weight(arr, target, s+1, e, wynik);
    }
}

int main(){
    int tab[] = {1,6,2,5,3};
    /*for(int i = 1; i < 20; i++){
        cout<<i<<":"<<endl;
        int wynik[N]{0};
        search_weight(tab,i,0,N, wynik);
    }*/
    int wynik[N]{0};
    search_weight(tab,3,0,N, wynik);
    return 0;
}
