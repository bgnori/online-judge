#include<stdio.h>

int main(){
  int i;
  int x;
  int first;
  int second;
  int third;

  first = second = third = 0;

  for(i = 0; i< 10; i++){
    scanf("%d", &x);
    if(x>first){
      third = second;
      second = first;
      first = x;
    }else{
      if(x>second){
      third = second;
      second = x;
      }else{
      if(x>third){
      third = x;
      }
    }
  }
  }
  printf("%d\n", first);
  printf("%d\n", second);
  printf("%d\n", third);
  
  return 0;
}


