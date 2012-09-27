/* AOJ 0033
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0033
 */

#include<stdio.h>
#define DEBUG 1


#define true 1
#define false 0



int orderable(int*x, int a, int b){

  if(DEBUG){
    printf("%d %d %d\n", *x, a, b);
  }
  if(*x == 0){
    return true;
  }else{
    if(((a < *x) && orderable(x+1, *x, b))||((b < *x) && orderable(x+1, a, *x))){
      return true;
    }else{
      if(DEBUG){
        printf("backtrack... ");
        printf("%d %d %d\n", *x, a, b);
      }
      return false;
    }
  }
}


int main(){
  int i;
  int n;
  int input[11];

  scanf("%d", &n);
  for (;n>0;n--){
    for(i=0; i< 10; i++){
      scanf("%d", input+i);
    }
    input[10] = 0;
    if(DEBUG){
      for(i=0; i< 10; i++){
        printf("%d,", input[i]);
      }
      printf("\n");
    }
    if(orderable(input, 0,0)){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }
  return 0;
}
