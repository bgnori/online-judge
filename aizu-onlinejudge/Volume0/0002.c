#include<stdio.h>
#include<stdlib.h>


int main(){
  int a;
  int b;
  int m;
  int d;
  
  while(scanf("%d %d", &a, &b) == 2){
    m = a+b;
    if(m){
      d = 0;
      while(m>0){
        m = m/10;
        d++;
      }
    }else{
      d = 1;
    }
    printf("%d\n", d);  
  };
  return 0;
}

