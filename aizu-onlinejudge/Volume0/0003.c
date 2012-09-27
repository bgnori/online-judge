#include<stdio.h>
#include<stdlib.h>


int main(){
  int n;
  int a;
  int b;
  int c;
  
  scanf("%d", &n);
  for (;n>0;n--){
    scanf("%d %d %d", &a, &b, &c);
    if (a < b){
      if ( b < c){
        if (a*a + b*b == c*c){
          printf("YES\n");  
          continue;
        }
      }else{
        if (a*a + c*c == b*b){
          printf("YES\n");  
          continue;
        }
      }
    }else{
      if (a < c){
        if (a*a + b*b == c*c){
          printf("YES\n");  
          continue;
        }
      }else{
        if (c*c + b*b == a*a){
          printf("YES\n");  
          continue;
        }
      }
    }
    printf("NO\n");  
  }
  return 0;
}


