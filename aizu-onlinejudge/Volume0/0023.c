
#include<stdio.h>
#include<math.h>


/*
 * A  xa ya ra
 *
 * B  xb yb rb
 *
 */

#define DEBUG 0

int main(){
  int n;
  float xa, ya, ra;
  float xb, yb, rb;
  float d;


  scanf("%d", &n);
  for (;n>0;n--){
    scanf(" %f %f %f %f %f %f", &xa, &ya, &ra, &xb, &yb, &rb);
    if(DEBUG)
      printf(" %f %f %f %f %f %f\n", xa, ya, ra, xb, yb, rb);
    
    d = sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));

    if (ra+rb < d){
      printf("0\n");
      continue;
    }
    if (d+ra < rb ){
      printf("-2\n");
      continue;
    }
    if (d+rb < ra ){
      printf("2\n");
      continue;
    }
    printf("1\n");
  }
}

