#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int val;
	struct Node* next;
}Node;

typedef struct Town{
	int area;
	Node* cons; //connected to
}Town;

void printList(Node *p){
	Node *c = p;
	printf("start->");
	while(c->next != NULL){
		c = c->next;
		printf("[%d %p]->", c->val, c->next);
	}
	printf("\n");
}

void push(Node* p, int x){
	Node* q = malloc(sizeof(Node));
	q->val = x;
	q->next = p->next;
	p->next = q;
}

void DNF(int curr, int area, Town* towns){
	if(towns[curr].area == 0){ //not assigned an area = not visited
		towns[curr].area = area;
		Node *q = towns[curr].cons->next;
		while(q!=NULL){
			// printf("Going to town %d with area %d\n", q->val, area);
			DNF(q->val, area, towns);
			q = q->next;
		}
	}

}void free_list(Node *p){
    Node *tmp;
    while(p->next != NULL){
    	//printf("freeing the next one\n");
        tmp = p->next->next;
        //printf("%p %p\n", tmp, p->next->next);
        free(p->next);
        p->next = tmp;
    }
    //printf("freeing the p\n");
    free(p);
}

int main(){
	int N,K,P;
	scanf("%d %d %d", &N, &K, &P);
	Town* towns = malloc(N*sizeof(Town));
	for(int i = 0; i < N; i++){
		towns[i].area = 0;
		towns[i].cons = malloc(sizeof(Node));
		towns[i].cons->next = NULL;
	}
	for(int i = 0; i < K; i++){
		int a,b;
		scanf("%d %d",&a, &b);
		push(towns[a].cons, b);
		push(towns[b].cons, a);
	}
	// for(int i = 0; i < N; i++){
	// 	printList(towns[i].cons);
	// }
	for(int i = 0; i < N; i++){
		//printf("Going to town %d with area %d\n", i, i+1);
		DNF(i, i+1, towns);
	}
	// for(int i = 0; i < N; i++){
	// 	printf("Town %d is in area %d\n", i, towns[i].area);
	// }
	for(int i = 0; i < P; i++){
		int a,b;
		scanf("%d %d",&a, &b);
		if(towns[a].area == towns[b].area)printf("YES\n");
		else printf("NO\n");
	}
	for(int i = 0; i < N; i++){
		free_list(towns[i].cons);
	}
	free(towns);
	return 0;
}