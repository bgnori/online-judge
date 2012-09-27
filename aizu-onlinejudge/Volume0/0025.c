

#include <stdio.h>

/*
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0025
 *
 */



int main(){
  int i, j;
  int hit, blow;
  int a[4];
  int b[4];
  int x[4];
  int isa;
  isa = 1;

  while(scanf("%d %d %d %d", x, x+1, x+2, x+3) == 4){
    hit = 0;
    blow = 0;
    if(isa){
      for(i=0; i< 4;i++){
        a[i]=x[i]; 
      }
      isa = 0;
    }else{
      for(i=0; i< 4;i++){
        b[i]=x[i]; 
      }
      isa = 1;
      for(i=0; i<4;i++){
        for(j=0;j<4;j++){
          if(a[i] == b[j])
            if (i==j){
              hit+=1;
            }else{
              blow+=1;
            }
        }
      }
      printf("%d %d\n", hit, blow);
    }
  }
  return 0;
}

