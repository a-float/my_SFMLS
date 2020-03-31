#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//a queue implemented as a linked list with guardian
typedef struct Node{
	char* number;
	int sec;
	struct Node* next;
}Node;

void push(Node *p, int t, char *num){
	Node *c = p;
	while(c->next != NULL){
		c = c->next;
	}
	c->next = malloc(sizeof(Node));
	c->next->sec = t;
	c->next->number = malloc(20*sizeof(char));
	strcpy(c->next->number, num);
	c->next->next = NULL;
}
//returns the sec of the matching call
int pop(Node *p){
    Node *c = p->next;
    Node *c2 = p;
    while(c->next != NULL){
        c2 = c;
        c=c->next;
    }
    int res = c->sec;
    free(c);
    c2->next = NULL;
    return res;
}

int pop_front(Node *p, char* num){
    if(p->next != NULL){
    	strcpy(num, p->next->number);
    	int res = p->next->sec;
    	Node *tmp;
        tmp = p->next->next;
        free(p->next->number);
        free(p->next);
        p->next = tmp;
    	return res;
    }
    else{
        printf("The queue is empty\n");
        return 9999;
    }
}

void printList(Node *p){
	Node *c = p;
	while(c->next != NULL){
		c = c->next;
		printf("[%d %s %p]->", c->sec, c->number, c->next);
	}
	printf("\n");
	//printf("[%d %s %p]\n", c->sec, c->number, c->next);
}

void free_all(Node *p){
    Node *tmp;
    while(p->next != NULL){
    	//printf("freeing the next one\n");
        tmp = p->next->next;
        //printf("%p %p\n", tmp, p->next->next);
		free(p->next->number);
        free(p->next);
        p->next = tmp;
    }
    //printf("freeing the p\n");
    free(p);
}

int main(){
	struct Node* p = malloc(sizeof(Node));
	p->next = NULL;
	int N;
	scanf("%d", &N);
	int sec;
	char *number = malloc(20*sizeof(char));
	for(int n = 0; n < N; n++){
		char op;
		scanf(" %c", &op);
		if(op == 'a'){
			scanf("%d %s",&sec ,number);
			push(p, sec, number);
			//printList(p);
		}
		else if(op =='r'){
			scanf("%d", &sec);
			int sec_before = pop_front(p, number);
			//printList(p);
			printf("%s %d\n", number, sec - sec_before);
		}
		//printList(p);
	}
	free(number);
	free_all(p);
	return 0;
}