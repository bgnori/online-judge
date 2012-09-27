#include<stdio.h>
#include<stdlib.h>


int main(){
  int a, b, c, d, e, f;
  double x ,y;
  

  while(scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f) == 6){
    x = 0.0;
    y = 0.0;
    if (c*e - b*f){
      x = (e*a - b*d)/(1.0 * (c*e - b*f));
    }
    if (b*d - e*a){
      y = (c*d - a*f)/(1.0 * (b*d - e*a));
    }
    printf("%1.3f %1.3f\n", x, y);
  }
  return 0;
}



