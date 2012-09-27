/* AOJ 0030
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0030
 */

#include <stdio.h>

#define DEBUG 0

#define MAX 1024


int sumbits(int bits){
  int i;
  int r = 0;

  for(i=0;i<10;i++){
    if(0x1 & bits){
      if(DEBUG)
        printf("%d %d\n", 0x1 & bits, i);
      r += i;
    }
    bits = bits >> 1;
  }
  if(DEBUG)
    printf("sum %d \n", r);
  return r;
}

int upbits(int bits){
  int i;
  int r = 0;

  for(i=0;i<10;i++){
    if(0x1 & bits){
      r += 1;
    }
    bits = bits >> 1;
  }
  if(DEBUG)
    printf("bits %d \n", r);
  return r;
}

int main(){
  int n, s;
  int bits;
  int count;

  while(scanf("%d %d", &n, &s)==2 && n && s){
    count = 0;
    for(bits=0;bits<MAX;bits++){
      if (sumbits(bits) == s && upbits(bits) == n)
        count++;
    }
    printf("%d\n", count);
  }
  return 0;
}

