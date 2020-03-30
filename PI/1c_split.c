#include<stdio.h>
#include<stdlib.h>

void print_array(int arr[], int n){
  for(int i = 0; i < n; i++){
    printf("%d\n", arr[i]);
  }
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; // first subarray 
    j = 0; // second subarray 
    k = l; // merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
}

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
   
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}

int main(){
  int n_all;
  int n_odd = 0;
  int n_even = 0;
  scanf("%d", &n_all);
  int* arr = calloc(n_all, sizeof(int));
  int tmp = 0;
  for(int i = 0; i < n_all; i++){
    scanf("%d", &tmp);
    if(tmp%2 == 0)n_even++;
    else n_odd++;
    arr[i] = tmp;
  }
  /*printf("odd %d even %d\n", n_odd, n_even);*/
  int e = 0;
  int o = 0;
  int* even_arr = calloc(n_even, sizeof(int));
  int* odd_arr  = calloc(n_odd,  sizeof(int));
  for(int i = 0; i < n_all; i++){
    if(arr[i]%2 == 0){
      even_arr[e] = arr[i];
      e++;
    }
    else{
      odd_arr[o] = arr[i];
      o++;
    }
  }
  free(arr);
  mergeSort(odd_arr, 0, o-1);
  mergeSort(even_arr, 0, e-1);
  printf("%d %d\n", e, o);
  print_array(even_arr, e);
  print_array(odd_arr, o);
  free(even_arr);
  free(odd_arr);
  return 0;
}
