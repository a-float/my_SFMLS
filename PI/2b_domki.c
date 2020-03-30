#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int* arr = (int*)calloc(n, sizeof(int));
    int sum = 0;
    for(int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int left_sum = 0;
    for(int i = 0; i < n; i++){
        if(left_sum == sum - arr[i]){
            printf("%d", i);
            return 0;
        }
        else{
            left_sum+= arr[i];
            sum -= arr[i];
        }
    }
    printf("%s", "Index does not exist");
    return 0;
}