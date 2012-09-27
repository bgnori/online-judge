#include<stdio.h>
#include<stdlib.h>


int gcd(int m, int n){
  int mi, ni;

  while(n){
    mi = n;
    ni = m%n;
    m = mi;
    n = ni;
  };//m is gcd
  return m;
}

int main(){
  int a, b;
  int found;

  while(scanf("%d %d", &a, &b) == 2){
    if (a >= b){
      found = gcd (a, b);
      printf("%d %d\n", found, a/found*b);
    }else{
      found = gcd (b, a);
      printf("%d %d\n", found, b/found*a);
    }
  }
  return 0;
}



