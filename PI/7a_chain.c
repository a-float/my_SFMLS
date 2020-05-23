#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct User{
	char* num;
	char* name;
	struct User* next;
}User;

int curr_size = 0;
int coll_count = 0;

int hash(char* x, int n){
	return x[0]%n;
}
void print_user(User* u){
	printf("[%s - %s]", u->name, u->num);
}

void printList(User *p){
	User *c = p;
	while(c != NULL){
		print_user(c);
		c = c->next;
	}
	printf("\n");
}

void rem(User **d, int n, char* name){
	int h = hash(name, n);
	User *c = d[h];
	if(strcmp(c->name, name) == 0){
		if(c->next == NULL){
			d[h] = NULL;
		}
		else{
			d[h] = c->next;
		}
		free(c->name);
		free(c->num);
		free(c);
		curr_size--;
		return;
	}
	User *prev = d[h];
	while(c != NULL){
		if(strcmp(c->name, name) == 0){
			prev->next = c->next;
			free(c->name);
			free(c->num);
			free(c);
			curr_size--;
			return;
		}
		prev = c;
		c = c->next;
	}
}

void get(User **d, int n, char* name){
	int h = hash(name, n);
	User *c = d[h];
	while(c != NULL){
		if(strcmp(c->name, name) == 0){
			//printf("%s\n", c->num);
			return;
		}
		c = c->next;
		coll_count++;
	}
	//printf("\n");
}

	// for (int i = 0; i < N; ++i)
	// 		{
	// 			printf("--%d-- :", i);
	// 			if(dict[i].flag == 1)print_user(dict[i].data);
	// 			else printf("[f = %d]\n", dict[i].flag);
	// 		}

void add(User **d, int n, char* name, char* num){
	User *u = malloc(sizeof(User));
	u->name = malloc(31*sizeof(char));
	u->num = malloc(31*sizeof(char));
	strcpy(u->name, name);
	strcpy(u->num, num);
	int h = hash(name,n);
	u->next = d[h];
	d[h] = u;
	curr_size++;
}
double cpu_time_used = 0;
int main(int argc, char *argv[]){
	int Z,N,K;
	scanf("%d", &Z);
	float load_fac = strtof(argv[1], NULL);
	printf("load_factor is %f\n",load_fac);

	for (int z = 0; z < Z; ++z){
		scanf("%d %d", &N, &K);
		User **dict = malloc(N*sizeof(User*));
		for (int i = 0; i < N; ++i){
			dict[i] = NULL;
		}
		char op;
		char* tmp_num = malloc(31*sizeof(char));
		char* tmp_str = malloc(31*sizeof(char));

		for (int k = 0; k < K; ++k){
			//printf("instruction number %d\n", k);
			scanf(" %c", &op);
			//printf("op is %c\n", op);
			if(op == 'a'){
				scanf("%s %s", tmp_str, tmp_num);
				// printf("adding %s %d\n", tmp_str, tmp_num);
				add(dict, N, tmp_str, tmp_num);
				if((double)curr_size/(double)N >= load_fac){
					printf("%d / %d",curr_size, N);
					printf("relocating %d to %d\n", N, 2*N);
					User **newDict = malloc((N*2)*sizeof(User*));
					for (int i = 0; i < 2*N; ++i){
						newDict[i] = NULL;
					}
					printf("before %d\n",curr_size);
					curr_size = 0;
					for(int i = 0; i < N; i++){
						User *p = dict[i];
						while(p != NULL){
							add(newDict, 2*N, p->name, p->num);
							p = p->next;								
						}
					}
					printf("after %d\n",curr_size);
					free(dict);
					N = N*2;
					dict = newDict;

				}
			}
			else if(op == 'g'){
				scanf("%s", tmp_str);
				clock_t start,end;
			    start = clock();
				get(dict, N, tmp_str);
				end = clock();
			    cpu_time_used += ((double)(end-start))/CLOCKS_PER_SEC;
			}
			else if(op == 'r'){
				scanf("%s", tmp_str);
				// printf("removing %s\n", tmp_str);
				rem(dict, N, tmp_str);
			}
		}
		for (int i = 0; i < N; ++i){
			User *c = dict[i];
			User *p;
			while(c != NULL){
				p = c;
				c = c->next;
				free(p->name);
				free(p->num);
				free(p);
			}			
		}
		free(tmp_str);
		free(dict);
	}
	printf("total get time:%lf collisions:%d\n", cpu_time_used, coll_count);

	return 0;
}