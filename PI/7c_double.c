#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct User{
	char* num;
	char* name;
	struct User* next;
}User;

typedef struct DictItem{
	int flag;
	User* data;
}DictItem;

int check_prime(int x){
	if(x%2 == 0)return 0;
	for(int i = 3; i < x/2; i+=2){
		if(x%i == 0)return 0;
	}
	return 1;
}

int hash(char* x, int n){
	return x[0]%n;
}
int hash2(char* x, int n){
	return (13 - x[0]%13)%(n-1) + 1;
}

void print_user(User* u){
	printf("[%s - %s]\n", u->name, u->num);
}

void rem(DictItem *d, int n, char* name){
	int index = hash(name,n);
	int index2 = hash2(name,n);
	int curr;
	for(int j = 0; j < n; j++){
		curr = (index + j * index2)%n;
		if(d[curr].flag == 0)return;
		if(d[curr].flag == 1){
			if(strcmp(d[curr].data->name, name) == 0){
				d[curr].flag = 2;
				free(d[curr].data->name);
				free(d[curr].data->num);
				free(d[curr].data);
				return;
			}
		}
	}
}

void get(DictItem *d, int n, char* name){	
	int index = hash(name,n);
	int index2 = hash2(name,n);
	int curr;
	for(int j = 0; j < n; j++){
		curr = (index + j * index2)%n;
		if(d[curr].flag == 0)break;
		if(d[curr].flag == 1){
			if(strcmp(d[curr].data->name, name) == 0){
				printf("%s\n", d[curr].data->num);
				return;
			}
		}
	}
	printf("\n");
}

void add(DictItem *d, int n, char* name, char* num){
	int index = hash(name,n);
	int curr = index;
	// printf("checking %d and its %d\n", curr, d[curr].flag);
	if(d[curr].flag == 1){ //collision
		int i = 1;
		int index2 = hash2(name,n);
		curr = (index + i*index2)%n;
		while(d[curr].flag == 1){ // 1 for taken 2 for deleted
			// printf("checked %d\n",curr);
			i++;
			curr = (index + i*index2)%n;
			if(curr == index){
				// printf("index %d index2 %d i %d curr %d\n",index,index2, i, curr);
				// printf("can't add it's full\n");
				return;
			}
		}
	}
	//can add
	User *u = malloc(sizeof(User));
	u->name = malloc(31*sizeof(char));
	u->num = malloc(31*sizeof(char));
	strcpy(u->name, name);
	strcpy(u->num, num);
	d[curr].data = u;
	d[curr].flag = 1;
	// printf("%s is added to index %d\n", name, curr);
}

int main(){
	int Z,N,K;
	scanf("%d", &Z);
	for (int z = 0; z < Z; ++z){
		scanf("%d %d", &N, &K);
		//find smalles prime > 2*N
		N = N;
		while(check_prime(N) == 0){N++;}
		DictItem *dict = malloc(N*sizeof(DictItem));
		for (int i = 0; i < N; ++i){
			dict[i].flag = 0; //its free
		}
		char op;
		char* tmp_num = malloc(31*sizeof(char));
		char* tmp_str = malloc(31*sizeof(char));
		for (int k = 0; k < K; ++k){
			scanf(" %c", &op);
			if(op == 'a'){
				scanf("%s %s", tmp_str, tmp_num);
				add(dict, N, tmp_str, tmp_num);
			}
			else if(op == 'g'){
				scanf("%s", tmp_str);
				get(dict, N, tmp_str);
			}
			else if(op == 'r'){
				scanf("%s", tmp_str);
				rem(dict, N, tmp_str);
			}
			// for (int i = 0; i < N; ++i)
			// {
			// 	printf("--%d-- :", i);
			// 	if(dict[i].flag == 1)print_user(dict[i].data);
			// 	else printf("[f = %d]\n", dict[i].flag);
			// }
			// printf("\n");

		}
		for (int i = 0; i < N; ++i){
			if(dict[i].flag == 1){
				free(dict[i].data->name);
				free(dict[i].data->num);
				free(dict[i].data);
			}
		}
		free(tmp_str);
		free(tmp_num);
		free(dict);
	}
	return 0;
}