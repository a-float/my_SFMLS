#include<iostream>
using namespace std;

struct Node{
    int val;
    Node *next;
};

void add(Node *&v, int x){
    Node* r= new Node;
    r->val = x;
    Node *p = v;
    while(p->next->val!=-1){
        p=p->next;
    }
    r->next = p->next;
    p->next = r;
}

void show(Node*v){
    v=v->next;
    while(v->next != NULL && v->val != -1){
        cout<<v->val<<" ";
        v=v->next;
    }
}

int main(){
    Node *v = new Node;
    v->val=-1;
    v->next = new Node;
    v->next->val = -1;
    add(v,3);
    add(v,5);
    add(v,8);
    add(v,7);
    add(v,10);
    show(v);
    v->next->next->next->next=v->next->next;
    Node *slow = v->next;
    Node *fast = v->next->next;

    while(slow != fast){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"They met at "<<(*slow).val<<" "<<endl;
    int i = 1;
    slow=slow->next;
    fast=fast->next->next;
    while(slow != fast){
        slow=slow->next;
        fast=fast->next->next;
        i++;
    }
    cout<<"the cycle length is "<<i<<endl;
}
