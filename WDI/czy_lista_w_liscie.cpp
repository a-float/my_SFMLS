#include<iostream>
using namespace std;

struct Node{
    int val;
    Node *next;
};

void add(Node* &v, int x){
    Node*r = new Node;
    r->val = x;
    Node*p = v;
    while(p->next->val!=-1){
        p=p->next;
    }
    r->next = p->next;
    p->next = r;
}

void show(Node*v){
    v = v->next;
    while(v->val != -1){
        cout<<v->val<<" ";
        v=v->next;
    }
    cout<<endl;
}

bool check(Node*a, Node*b){
    a = a->next;
    b = b->next;
    Node *bc = b;
    while(a->val != -1){
        if(a->val == b->val){
            b = b->next;
            if(b->val == -1)return true;
        }
        else{
            b = bc; //od poczatku
        }
        a = a->next;
    }
    return false;
}

bool check_both(Node *a, Node*b){
    return (check(a,b) || check(b,a));
}

int main(){
    Node *v = new Node;
    v->val = -1;
    v->next = new Node;
    v->next->val = -1;
    add(v,3);
    add(v,2);
    add(v,9);
    add(v,8);
    add(v,2);
    add(v,6);
    add(v,4);
    show(v);

    Node * w = new Node;
    w->val = -1;
    w->next = new Node;
    w->next->val = -1;
    add(w,2);
    add(w,6);
    add(w,4);
    show(w);

    cout<<check_both(v,w)<<endl;
}
