#include<iostream>
using namespace std;
const int N = 8;

bool search_weight(int arr[], int target, int s, int e, int lvl){
    if(target == 0){
        return true;
    }
    if(s == e){
        return false;
    }
    cout<<s<<" "<<e<<" "<<target<<"  picked: "<<arr[s]<<" "<<lvl<<endl;
    if(target - arr[s] < 0 || search_weight(arr, target-arr[s],s+1,e,lvl+1) == false){
        return search_weight(arr, target, s+1, e, lvl+1);
    }
    else return true;
}

int main(){
    int tab[] = {0, 29, 9, 18, 22, 17, 14, 4};
    cout<<search_weight(tab,30,0,N,0);
    return 0;
}
