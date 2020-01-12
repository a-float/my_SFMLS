#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int max_size = 10;

void show_table(int arr[max_size][max_size]){
    for(int i = 0; i < max_size; i++){
        for(int j = 0; j < max_size; j++){
            cout<<arr[i][j]<<" ";
        }
    cout<<endl;
    }
}

void fill_array(int arr[max_size][max_size]){
    for(int i = 0; i < max_size; i++){
        for(int j = 0; j < max_size; j++){
            arr[i][j] = rand() % 10;
        }
    }
}

bool check_num(int a){
    if(a == 0)return false;
    while(a>0){
        if((a%10)%2 == 0)return false;
        a/=10;
    }
    return true;
}

bool check_row(int row[]){
    for(int i = 0; i < max_size; i++){
        if(check_num(row[i]))return true;
    }
    return false;
}

bool check_table(int arr[max_size][max_size]){
    for(int i = 0; i < max_size; i++){
        if(!check_row(arr[i]))return false;
    }
    return true;
}

int main(){
    srand(time(NULL));
    int arr[max_size][max_size];
    fill_array(arr);
    show_table(arr);
    cout<<check_table(arr);
}
