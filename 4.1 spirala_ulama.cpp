#include<iostream>
using namespace std;
const int max_size = 9;

void show_table(int arr[max_size][max_size]){
    for(int i = max_size-1; i >= 0; i--){
        for(int j = 0; j < max_size; j++){
            cout<<arr[j][i]<<" ";
        }
    cout<<endl;
    }
}
void fill_array(int arr[max_size][max_size]){
    for(int i = 0; i < max_size; i++){
        for(int j = 0; j < max_size; j++){
            arr[i][j] = 0;
        }
    }
}

void turn(int &xd, int &yd){
    static int dir = 0;
    dir = (dir+1)%4;
    if(dir==0){
        xd = 1;
        yd = 0;
    }
    else if(dir==1){
        xd = 0;
        yd = 1;
    }
    else if(dir==2){
        xd = -1;
        yd = 0;
    }
    else{
        xd = 0;
        yd = -1;
    }
}

void spirala(int arr[max_size][max_size]){
    int x = (max_size-1)/2;
    int y = (max_size-1)/2;
    int curr = 1;
    int xd = 1;
    int yd = 0;

    for(int i = 1; i < max_size; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < i; k++){
                arr[x][y] = curr;
                curr++;
                x+=xd;
                y+=yd;
            }
            turn(xd,yd);
        }
    }
    for(int i = 0; i<max_size;i++){
        arr[x][y] = curr;
        curr++;
        x+=xd;
        y+=yd;
    }
}

int main(){
    int arr[max_size][max_size];
    //fill_array(arr);
    spirala(arr);
    show_table(arr);
}
