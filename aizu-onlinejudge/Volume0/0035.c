/* AOJ 0035 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0035
 */

#include<stdio.h>
#define DEBUG 0


#define true 1
#define false 0


float inner_product(float ux, float uy, float vx, float vy){
  return ux*vx + uy*vy;
}

float outer_product(float ux, float uy, float vx, float vy){
  return ux*vy -vx*uy;
}


int main(){
  int i;
  int n;
  float input[8];
  int sign[4];
  int prev;
  int terminate = false;
  int flag;
  float x1, x2, x3;
  float y1, y2, y3;

  while(true){
    for(i=0; i< 8; i++){
      if(scanf("%f,", input+i)!=1){
        terminate = true;
      }
    }
    if(terminate)
      break;

    if(DEBUG){
      for(i=0; i< 8; i++){
        printf("%f,", input[i]);
      }
      printf("\n");
    }

    x1 = input[4];
    y1 = input[5];
    x2 = input[6];
    y2 = input[7];
    for(i=0; i< 4; i++){
      x3 = input[i*2];
      y3 = input[i*2+1];
      sign[i]= (outer_product(x2-x1, y2-y1, x3 - x2,y3 - y2) > 0);
      x1=x2;
      y1=y2;
      x2=x3;
      y2=y3;
    }
    flag = true;
    prev = sign[3];
    for(i=0; i< 4; i++){
      if(prev != sign[i]){
        flag = false;
      }
    }
    if(flag){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }
  return 0;
}

