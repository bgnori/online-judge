#include<stdio.h>

int main(){
  int x;
  int y;
  int a, b, c, d;
  
  while(scanf("%i", &x) == 1){
    y = 0;
    for (a = 0; a < 10; a++){
      for (b = 0; b < 10; b++){
        for (c = 0; c < 10; c++){
          for (d = 0; d < 10; d++){
            if (x == a + b+ c+ d){
              y++;
            }
          }
        }
      }
    }
    printf("%d\n", y);
  }
  return 0;
}

