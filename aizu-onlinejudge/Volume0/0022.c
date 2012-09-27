#include<stdio.h>
#include<limits.h>


#define DEBUG 0


int buf [5001];

/*
  100kx5k= 500M
  2^20 = 1M
*/

int find_max_sum(int count){
  int i, j;
  int max, s;
  int sum;
  max = INT_MIN;

  for(i = 0; i < count; i++){
    s = 0;
    for(j = i; j < count; j++){
      s += buf[j];
      if(s>=max) max =s ;
    }
  }
  return max;
}


int main(){
  int count;
  int i;
  while((scanf("%i", &count) == 1) && count){
    if(DEBUG)
      printf("count: %d\n", count);
    for(i=0; i<count;i++){
      scanf("%i", buf+i);
      if(DEBUG)
        printf("data: %d\n", *(buf+i));
    }
    printf("%d\n", find_max_sum(count));
  }
  return 0;
}
