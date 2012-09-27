#include<stdio.h>
#include<stdlib.h>


#define DEBUG 0

int mycomp(const void* ap, const void* bp){
  int a = *(int*)ap;
  int b = *(int*)bp;
  return b - a;
}

int main(){
  int data[5];

  if (scanf("%d %d %d %d %d", data, data+1, data+2, data+3, data+4) == 5){
    if(DEBUG){
      printf("%d %d %d %d %d\n", data[0], data[1], data[2], data[3], data[4]);
    }
    qsort(data, 5, sizeof(int), mycomp);
    printf("%d %d %d %d %d\n", data[0], data[1], data[2], data[3], data[4]);
  }

  return 0;
}
