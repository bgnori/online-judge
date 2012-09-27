/* AOJ 0031
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0031
 */

#include <stdio.h>
#define MAX 1024

int main(){
  int w;
  int i;
  int u;
  int isfirst;
  while(scanf("%d", &w)==1){
    u = 1;
    isfirst = 1;
    for(i=0;i<10;i++){
      if(0x1&w){
        if(isfirst){
          isfirst = 0;
        }else{
          printf(" ");
        }
        printf("%d", u);
      }
      w = w >> 1;
      u=u*2;
    }
    printf("\n");
  }
  return 0;
}

