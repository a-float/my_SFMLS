#include<stdio.h>
#include<stdlib.h>

int main(){
	int N;
	scanf("%d",&N);
	int **tab = malloc(N*sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		tab[i] = malloc(N*sizeof(int));
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d",&tab[i][j]);
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			int sum = 0;

			for (int y = -1; y <= 1; y++){//looping over offsets
				for (int x = -1; x <= 1; x++){
					if(x==0 && y == 0)continue; //just the neighbours
					if(i+y > -1 && i+y < N){
						if(j+x > -1 && j+x < N){
							sum += tab[i+y][j+x];
						}
					}
				}
			}
			printf("%d ", sum);
		}
		printf("\n");
	}
	for (int i = 0; i < N; ++i)
	{
		free(tab[i]);
	}
	free(tab);

	return 0;
}