
#include<stdio.h>

int main(){
    int i;
    int j;
    for (i=1; i<10; i++){
      for (j=1; j<10; j++){
        printf("%dx%d=%d\n", i,j, j*i);
      }
    }
    return 0;
}

