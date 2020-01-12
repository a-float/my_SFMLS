#include<iostream>
using namespace std;

int* dupl(int *a, int *b, int asize, int bsize, int &csize){
    int ia = 0;
    int ib = 0;
    int ic = 0;
    int c[asize + bsize];
    while(a[ia] > b[ib]){
        ib++;
        if(ib >= bsize)break;
    }
    while(a[ia] < b[ib]){
        ia++;
        if(ia >= asize)break;
    }
    if(a[ia] = b[ib]){
        c[ic] = a[ia];
    }
}

int main(){
    int a={1,3,5,7,9};
    int b={2,4,5,6,8};
    int csize;
    int *c = dupl(a,b,5,5,csize);
    for(int i = ; i < csize; i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
return 0;
}
