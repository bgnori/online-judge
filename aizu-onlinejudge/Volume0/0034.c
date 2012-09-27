/* AOJ 0034
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0034
 */

#include<stdio.h>
#define DEBUG 0


#define true 1
#define false 0



int meetat(int* input, int v1, int v2){

  int total;
  int i;
  float fat;
  int d;

  total = 0;
  for(i=0;i<10;i++)
    total += input[i];

  fat = total*1.0 / (v1+v2) * v1;


  i = 0;
  d = 0;
  while(fat > d){
    d += input[i];
    i++;
  }
  return i;
}


int main(){
  int i;
  int n;
  int input[11];
  int v1, v2;

  while(true){
    for(i=0; i< 10; i++){
      scanf("%d,", input+i);
    }
    scanf("%d,", &v1);
    if(scanf("%d", &v2)!=1)
      break;

    input[10] = 0;
    if(DEBUG){
      for(i=0; i< 10; i++){
        printf("%d,", input[i]);
      }
      printf("%d.",v1);
      printf("%d", v2);
      printf("\n");
    }

    printf("%d\n", meetat(input, v1,v2));
  }
  return 0;
}

