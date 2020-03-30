#include<stdio.h>
#include<stdlib.h>
//poprawka na zajecia Polaka
#ifdef WRITE_TIME
    #include<time.h>
    #ifdef APPEND
        char *mode = "a";
    #else
        char *mode = "w";
    #endif
#endif


static inline
void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int arr[], int s, int e){
    int pivot = arr[e-1];
    int wall = s;
    for(int i = s; i < e-1; i++){
        if(arr[i] <	 pivot){
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

double timetest(int* arr, int s, int e){
    clock_t start,end;
    double cpu_time_used;

    start = clock();
    quicksort(arr,s,e);
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    return cpu_time_used;
}
void printArray(int *arr, int n){
    for(int j = 0; j < n; j++){
        printf("%d ", arr[j]);
    }
    printf("\n");
}

int main()
{
    FILE *fptr = NULL;
    #ifdef WRITE_TIME
        fptr = fopen("./wyniki.txt", mode); 
    #endif
    int Z;
    scanf("%d", &Z);
    for(int z = 0; z < Z; z++){ 
        int n;
        scanf("%d", &n);
        int* arr = calloc(n, sizeof(int));
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }
        double t = timetest(arr,0,n);
        printArray(arr,n);
        if(fptr != NULL){
            fprintf(fptr,"%s %d: %.2e [s]\n", "Pomiar", z, t);
        }
        else{
            quicksort(arr, 0, n);
        }
        free(arr);
    }
    #ifdef WRITE_TIME
        fclose(fptr);
    #endif
    return 0;
}
