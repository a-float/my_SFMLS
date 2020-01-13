#include<iostream>
using namespace std;

int get_len(int x){
    int len = 0;
    do {
        len++;
        x/=10;
    }while(x!=0);
    return len;
}

int *add_big(int *a, int sa, int*b, int sb){
    int *tmp = new int[max(sa,sb)+1];
    int *other;
    int m;
    if(sa > sb){
        other = b;
        for(int i = 0; i < sa; i++){
            tmp[i] = tmp[i];
        }
        m = sb;
    }
    else{
        other = a;
        for(int i = 0; i < sb; i++){
            tmp[i] = b[i];
        }
        m = sa;
    }
    int i = 0;
    int pass = 0;
    while(i<m){
        int sum = tmp[i] + other[i] + pass;
        pass = sum/10;
        tmp[i] = sum%10;
        i++;
    }
    tmp[i] += pass;
    return tmp;
}

int *mult_big_by_num(int *a, int sa, int mult){
    int *tmp = new int[sa+1];
    for(int i = 0; i < sa; i++){
        tmp[i] = a[i];
    }

    int i = 0;
    int pass = 0;
    while(i<sa){
        int sum = tmp[i]*mult + pass;
        pass = sum/10;
        tmp[i] = sum%10;
        i++;
    }
    tmp[i] += pass;
    return tmp;
}

int *sub_big(int *a,int*b){
    int *tmp = new int[n+1];
    int *other;
    for(int i = 0; i < n; i++){
        tmp[i] = a[i];
    }

    int i = 0;
    int pass = 0;
    while(i<n){
        int sum = tmp[i] - b[i] + pass;
        if(sum < 0){
            pass = -1;
        }
        else if(sum > 10){
            pass = 1;
        }
        else{
            pass = 0;
        }
        tmp[i] = sum%10;
        i++;
    }
    tmp[i] += pass;
    return tmp;
}

int main(){
    int x = 3;
    int n = 10;
    //cin>>n;
    int a[3] = {3,2,3};
    int b[3] = {1,2,8};
    int *c = add_big(a,3,b,3);
    for(int i = 3; i >= 0; i--){
        cout<<c[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
