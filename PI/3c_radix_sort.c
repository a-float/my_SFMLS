#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* the array its length and the position of digit to sort by*/
void countsort(char** arr, int n, int k){
    char** out = calloc(n, sizeof(char*));
    for(int i = 0; i < n; i++){
        out[i] = calloc(k+5, sizeof(char));
    }
    int* count = calloc(10, sizeof(int));
    
    int num;
    /*count digits*/
    for(int i = 0; i < n; i++){
        num = arr[i][k] - '0';
        count[num]++;
    }
    /*make them real indexes*/
    for(int i = 0; i < 10-1; i++){
        count[i+1] += count[i];
        //printf("%d ",count[i]);
    }
    //printf("%d\n",count[9]);
    /*assign correct numbers to the out array*/
    int i = n-1;
    while(i >= 0){
        num = arr[i][k] - '0';
        strcpy(out[count[num]-1], arr[i]);
        count[num]--;
        i--;
    }
    /* copy the answer to the main array*/
    for(int i = 0; i < n; i++){
        strcpy(arr[i],out[i]);
    }
    for(int i = 0; i < n; i++){
        free(out[i]);
    }
    free(out);
    free(count);
}

void radixsort(char** arr, int n, int k){
    for(int i = k-1; i >= 0; i--){
        countsort(arr, n, i);
    }
}

int main()
{
    int Z;
    scanf("%d", &Z);
    for(int i = 0; i < Z; i++){
        int n;
        int k;
        scanf("%d %d", &n, &k);
        char** arr = calloc(n, sizeof(char*));
        for(int j = 0; j < n; j++){
            arr[j] = calloc(k+5, sizeof(char));
        }
        for(int j = 0; j < n; j++){
            scanf("%s", arr[j]);
        }
        radixsort(arr,n,k);
        for(int j = 0; j < n; j++){
            printf("%s\n", arr[j]);
        }
        for(int j = 0; j < n; j++){
            free(arr[j]);
        }
        free(arr);
    }
    return 0;
}