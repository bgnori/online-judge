

#include<stdio.h>
#include<math.h>

#define DEBUG 0
#define E 0.000001

int main(){
  int n;
  float x1, y1, x2, y2, x3, y3 ,x4, y4;
  float ux, uy, vx, vy, u2, v2, uv;
  float outer;

  scanf("%d", &n);
  for (;n>0;n--){
    scanf(" %f %f %f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3 ,&x4, &y4);
    if(DEBUG)
      printf("%f %f %f %f %f %f %f %f\n", x1, y1, x2, y2, x3, y3 ,x4, y4);
    ux = x2 - x1;
    uy = y2 - y1;
    vx = x4 - x3;
    vy = y4 - y3;

    outer = ux*vy - uy*vx;
    if(DEBUG)
      printf("%f\n", outer);
    if (outer*outer < E){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
  return 0;
}

