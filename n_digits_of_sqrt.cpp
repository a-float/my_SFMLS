#include<iostream>
using namespace std;

#define N 3

struct big_num{
    int *arr;
    int len;
    big_num(int n){
        arr = new int[3*n];
        len = 0;
    }
};

int get_len(int x){
    int len = 0;
    do {
        len++;
        x/=10;
    }while(x!=0);
    return len;
}

big_num* to_big(int x){
    big_num *res = new big_num(N);
    while(x!=0){
        res->arr[res->len] = x%10;
        x/=10;
        res->len++;
    }
    return res;
}

int is_bigger(big_num b){         //true is plus false is negative
    if(b.len < N*2+1)return -1;
    else if(b.len > N*2+1)return 1;
    else if(b.arr[b.len-1] < 2)return -1;
    else if(b.arr[b.len-1] > 2)return 1;
    else{
        for(int i = b.len-2; i>-1; i--){
            if(b.arr[i] > 0)return 1;
        }
        return 0;
    }
}

void del(big_num b){
    delete[] b.arr;
    delete &b;
}

void show(big_num b){
    cout<<"len is "<<b.len<<endl;
    cout<<"arr is ";
    for(int i = b.len-1; i > -1; i--){
        cout<<b.arr[i]<<" ";
    }
    cout<<endl;
}


big_num add(big_num &a, big_num &b, int displ=0, bool del_both = false){       //displacement(works like multiplying b times 10^displ
    big_num res = *(new big_num(N));                //displ <= a.len
    int *other;
    int m;
    if(a.len > b.len){
        other = b.arr;
        for(int i = 0; i < a.len; i++){         //mozna tylko bo b.len
            res.arr[i] = a.arr[i];
        }
        res.len=a.len;
        m = b.len;
    }
    else{
        other = a.arr;
        for(int i = 0; i < b.len; i++){             //mozna tylko po a.len
            res.arr[i] = b.arr[i];
        }
        res.len=b.len;
        m = a.len;
    }
    int i = 0;
    int pass = 0;
    int M = max(a.len, b.len);
    while(i<m && i+displ < M){
        int sum = res.arr[i+displ] + other[i] + pass;
        pass = sum/10;
        res.arr[i+displ] = sum%10;
        i++;
    }
    while(i<m){     // if i > m skip all right
        int sum = other[i] + pass;
        res.arr[i+displ] = sum%10;
        pass = sum/10;
        i++;
        res.len++;
    }
    while(i+displ<M){     // if i > m skip all right
        int sum = res.arr[i+displ] + pass;
        res.arr[i+displ] = sum%10;
        pass = sum/10;
        i++;
    }

    if(pass != 0){      //the last additional digit
        res.len++;
        //cout<<pass<<" "<<i<<endl;
        res.arr[i+displ] = pass;
    }
    if(del_both){
        del(a);
        del(b);
    }
    return res;
}

big_num mult_by_int(big_num &b, int k){ // do not mult by 0
    big_num res = *(new big_num(N));
    res.len = b.len;
    int pass = 0;
    for(int i = 0; i < b.len; i++){
        int sum = b.arr[i]*k + pass;
        res.arr[i] = sum%10;
        //cout<<i<<" "<<sum<<endl;
        pass = sum/10;
    }
    while(pass != 0){
        res.len++;
        res.arr[res.len-1] = pass%10;
        pass/=10;
    }
    del(b);
    return res;
}

big_num square(big_num b){
    big_num res = *to_big(0);
    show(res);
    for(int i = 0; i < b.len; i++){
        if(b.arr[i] == 0)continue;
        big_num k = mult_by_int(b, b.arr[i]);
        cout<<i<<" k ";
        show(k);
        if(k.len > 0)res = add(res, k, i, true);
        show(res);
    }
    return res;
}

big_num bisect(big_num b){
    big_num res = *(new big_num(N));
    int pass = 0;         //can only be 0 or 10
    if(b.arr[b.len-1]>1){
            res.len = b.len;
    }
    else{
            res.len = b.len-1;
    }
    for(int i = b.len-1; i > -1; i--){
        res.arr[i] = (b.arr[i]+pass)/2; //(flored)
        pass = b.arr[i]%2 * 10;
    }
    return res;
}

int main(){
    big_num x = *to_big(100);
    show(x);
    //x = square(x);
    x = square(x);
    show(x);
    del(x);
    return 0;
}
