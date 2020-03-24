#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void heapify(int arr[], int n, int p){
    int largest = p;
    int l = 2*p + 1;
    int r = 2*p + 2;
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != p){
        swap(&arr[p], &arr[largest]);
        heapify(arr,n,largest);
    }
}

void bulid_heap(int arr[], int n){
	/*max index of the no leaf node*/
    int p = n/2 - 1; 
    for(int i = p; i>=0; i--){
        heapify(arr,n,i);
    }
}

void heapsort(int arr[], int n){
    bulid_heap(arr, n);
    for(int i = 0; i < n; i++){
        swap(&arr[0], &arr[n-1-i]);
        heapify(arr,n-i-1,0);
    }
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
        heapsort(arr, n);
        for(int j = 0;j < n; j++){
            printf("%d\n", arr[j]);
        }
        free(arr);
    }
    return 0;
}