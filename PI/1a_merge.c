#include<stdio.h>
#include<stdlib.h>

void print_array(int arr[], int n){
  for(int i = 0; i < n; i++){
    printf("%d\n",arr[i]);
  }
}

int* merge_unique(int t1[], int n1, int t2[],
		  int n2, int* n3){
  int* tmp = calloc(n1+n2, sizeof(int));
  int a = 0;
  int b = 0;
  int c = 0;
  if(t1[a] < t2[a]){
    tmp[c] = t1[a];
    a++;
    c++;
  }
  else{
    tmp[c] = t2[b];
    b++;
    c++;
  }
  /*skiping repeating values at the front*/
  while(t1[a] == tmp[c-1])a++;
  while(t2[b] == tmp[c-1])b++;
  while(a < n1 && b < n2){
    if(t1[a] < t2[b]){
      tmp[c] = t1[a];
      a++;
      c++;
    }
    else{
      tmp[c] = t2[b];
      b++;
      c++;
    }
    /*skipping repeating values*/
    while(t1[a] == tmp[c-1])a++;
    while(t2[b] == tmp[c-1])b++;
  }
    while(a < n1){
      if(t1[a] != tmp[c-1]){
	tmp[c] = t1[a];
	c++;
      }
      a++;
    }
    while(b < n2){
      if(t2[b] != tmp[c-1]){
	tmp[c] = t2[b];
	c++;
      }
      b++;
    }
    int* t3 = calloc(c, sizeof(int));
    for(int i = 0; i < c; i++){
      t3[i] = tmp[i];
    }
    free(tmp);
    *n3 = c;
    return t3;
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
  int n1, n2;
  scanf("%d %d", &n1, &n2);
  int* t1 = calloc(n1, sizeof(int));
  for(int i = 0; i < n1; i++){
    scanf("%d", &t1[i]);
  }
  int* t2 = calloc(n2, sizeof(int));
  for(int i = 0; i < n2; i++){
    scanf("%d", &t2[i]);
  }
  mergeSort(t1, 0, n1-1);
  mergeSort(t2, 0, n2-1);
  //print_array(t1,n1);
  //print_array(t2,n2);
  int n3;
  int* t3 = merge_unique(t1,n1,t2,n2,&n3);
  print_array(t3, n3);
  free(t1);
  free(t2);
  free(t3);
  return 0;
}
