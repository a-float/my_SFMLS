#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
	int col;
	int x;
	int y;
	struct Node* next;
}Node;

void push(Node *p, int x, int y, int col){
	Node *c = p;
	while(c->next != NULL){
		c = c->next;
	}
	c->next = malloc(sizeof(Node));
	c->next->col = col;
	c->next->x = x;
	c->next->y = y;
	c->next->next = NULL;
}

Node pop_front(Node *p){
	Node res = *(p->next);
    Node* tmp = p->next->next;
    free(p->next);
    p->next = tmp;
	return res;
}

void printList(Node *p){
	Node *c = p;
	while(c->next != NULL){
		c = c->next;
		printf("[%d %d %d %p]->", c->x, c->y, c->col, c->next);
	}
	printf("\n");
}

bool is_empty(Node* p){
	if(p->next == NULL)return true;
	else return false;
}

void color(int *tab, Node cell, int n, Node *p){
	int x = cell.x;
	int y = cell.y;
	int c = cell.col;
	if(tab[y*n + x] != 0)return;
	else{
		tab[y*n + x] = c;
		if(y > 0)push(p, x, y-1, c);
		if(y < n-1)push(p, x, y+1 , c);
		if(x > 0)push(p, x-1, y , c);
		if(x < n-1)push(p, x+1, y , c);
	}
}

int main(){
	Node* p = malloc(sizeof(Node));
	p->next = NULL;
	int N,K;
	scanf("%d %d", &N, &K);
	int *tab = malloc(N*N*sizeof(int));
	for(int n = 0; n < N*N; n++){
		scanf("%d", &tab[n]);
	}
	for(int k = 0; k < K; k++){
		int x,y,c;
		scanf("%d %d %d", &y, &x, &c);
		push(p, x, y, c);
	}
	while(is_empty(p) == false){
		Node to_color = pop_front(p);
		//printList(p);
		color(tab, to_color, N, p);
		//printf("what i popped: %d %d %d\n",to_color.x, to_color.y, to_color.col);
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%d ", tab[i*N + j]);
		}
		printf("\n");
	}
	free(p);
	free(tab);
	return 0;
}