#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

const int max_size = 3;

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

int sum_row(int b, int arr[max_size][max_size]){
    int s = 0;
    for(int i = 0; i < max_size; i++){
        s += arr[b][i];
    }
    return s;
}
int sum_col(int b, int arr[max_size][max_size]){
    int s = 0;
    for(int i = 0; i < max_size; i++){
        s += arr[i][b];
    }
    return s;
}

void get_quotient(int arr[max_size][max_size] , int &x, int &y){
    int biggest = sum_col(0,arr);
    int biggest_col = 0;
    int smallest = sum_row(0,arr);
    int smallest_row = 0;

    for(int i = 1; i < max_size; i++){
        int s = sum_col(i,arr);
        if(s>biggest){
            biggest = s;
            biggest_col = i;
        }
        s = sum_row(i, arr);
        if(s < smallest){
            smallest = s;
            smallest_row = i;
        }
    }
    x = biggest_col;
    y = smallest_row;
}

int main(){
    srand(time(NULL));
    int arr[max_size][max_size];
    fill_array(arr);
    show_table(arr);
    int x,y;
    get_quotient(arr,x,y);
    cout<<endl<<x<<" "<<y<<" "<<arr[x][y]<<endl;
}
