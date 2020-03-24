#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int arr[], int s, int e){
    int pivot = arr[e-1];
    int wall = 0;
    for(int i = s; i < e-1; i++){
        if(arr[i] < pivot){
            swap(&arr[i], &arr[wall]);
            wall++;
        }
    }
    swap(&arr[e-1], &arr[wall]);
    return wall;
}

/* sorts up to the n-th element */
void quicksort(int arr[], int s, int e){
    int m = partition(arr, s, e);
    if(m>s+1)quicksort(arr,s,m);
    if(e>m+2)quicksort(arr,m+1,e);
}

int main()
{
    int Z;
    scanf("%d", &Z);
    for(int i = 0; i < Z; i++){
        int n;
        scanf("%d", &n);
        int* arr = calloc(n, sizeof(int));
        for(int j = 0;j < n; j++){
            scanf("%d", &arr[j]);
        }
        quicksort(arr,0, n);
        for(int j = 0;j < n; j++){
            printf("%d\n", arr[j]);
        }
        free(arr);
    }
    return 0;
}
