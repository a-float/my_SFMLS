#include<stdio.h>
#include<stdlib.h>

int main(){
  int n = 0;
  scanf("%d", &n);
  int a; /*number holder*/
  short b = 0; /*Found the answer flag*/
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &a);
      if(j > i && a != 0 && !b){
	b = 1;
      }
    }
  }
  if(b)printf("%s", "NO\n");
  else printf("%s", "YES\n");
  return 0;
}
