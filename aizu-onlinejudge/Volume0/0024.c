

#include<stdio.h>
#include<math.h>

int main(){
  float v;
  float y;

  while(scanf("%f", &v)==1){
    y = 4.9 * v * v / (9.8 * 9.8); 
    printf("%d\n", (int)ceil((y+5)/5));
  }
  return 0;
}
