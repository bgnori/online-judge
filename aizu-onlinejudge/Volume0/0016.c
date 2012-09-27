
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){
  double rad;
  double x;
  double y;
  int done;
  int d;
  int t;
  double pi;

  done = 0;
  pi = M_PI;
  
  rad = pi/2.0;
  x = 0.0;
  y = 0.0;
  while(!done){
    scanf("%d,%d", &d, &t);
    if ((d == 0) && (t == 0)){
      break;
    }
    x += d*cos(rad);
    y += d*sin(rad);
    rad -= pi*t/180; //input is clockwise. rad is ccw
  }
  printf("%d\n", (int)x);
  printf("%d\n", (int)y);
  
  return 0;
}
