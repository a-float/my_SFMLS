#include<stdio.h>
#include<stdlib.h>

void countsort(int arr[], int n, int expo){
    int* out = calloc(n, sizeof(int));
    int* count = calloc(10, sizeof(int));
    
    int num;
    /*count digits*/
    for(int i = 0; i < n; i++){
        num = arr[i]/expo;
        count[num%10]++;
    }
    /*make them real indexes*/
    for(int i = 0; i < 10-1; i++){
        count[i+1] += count[i];
    }
    /* assign correct numbers to the out array*/
    int i = n-1;
    while(i >= 0){
        num = arr[i]/expo;
        out[count[num%10]-1] = arr[i];
        count[num%10]--;
        i--;
    }
    /* copy the answer to the main array*/
    for(int i = 0; i < n; i++){
        arr[i] = out[i];
    }
    free(out);
    free(count);
}

void radixsort(int arr[], int n, int k){
    int expo = 1;
    for(int i = 0; i < k; i++){
        countsort(arr, n, expo);
        expo*=10;
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
        int* arr = calloc(n, sizeof(int));
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }
        radixsort(arr,n,k);
        for(int j = 0; j < n; j++){
            printf("%d\n", arr[j]);
        }
        free(arr);
    }
    return 0;
}