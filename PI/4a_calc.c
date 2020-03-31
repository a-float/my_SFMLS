#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	int *tab = malloc(N*sizeof(int));
	char *input = malloc(K*sizeof(char));
	int curr_size = 0;
	while(scanf(" %s", input)){
		//printf("input here %s\n", input);
		if(strcmp("+", input) == 0){
			curr_size--;
			tab[curr_size - 1] = tab[curr_size-1] + tab[curr_size];
		}
		else if(strcmp("-", input) == 0){
			curr_size--;
			tab[curr_size - 1] = tab[curr_size-1] - tab[curr_size];
		}
		else if(strcmp("*", input) == 0){
			curr_size--;
			tab[curr_size - 1] = tab[curr_size-1] * tab[curr_size];
		}
		else if(strcmp("/", input) == 0){
			curr_size--;
			tab[curr_size - 1] = tab[curr_size-1] / tab[curr_size];
		}
		else{
			tab[curr_size] = atoi(input);
			curr_size++;
			N--;
		}
		if(N == 0 && curr_size == 1){
			printf("%d\n",tab[0]);
			break;
		}
		// for(int j = 0; j < curr_size; j++){
		// 	printf("%d ", tab[j]);
		// }
		// printf("\n");
	}
	free(tab);
	free(input);
	return 0;
}