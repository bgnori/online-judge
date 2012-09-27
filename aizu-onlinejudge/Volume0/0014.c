
#include<stdio.h>



int f(int x){
  return x*x;
}

int main(){
  int i;
  int count, d;
  int s;

  while (scanf("%d", &d)==1){
    s = 0;
    count = 600/d;
    for(i=1; i<count; i++){
      s += f(i*d)*d;
    }
    printf("%d\n", s);
  }
  return 0;
}

