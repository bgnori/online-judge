#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void reverse(char *s, int len){
  char tmp;
  if (len > 1){
    tmp = s[0];
    s[0] = s[len-1];
    s[len-1] = tmp;
    reverse(s+1, len-2);
  }
}

int main(){
  char buf[21];
  
  while(scanf("%s", buf) == 1){
    reverse(buf, strlen(buf));
    printf("%s\n", buf);
  }
  return 0;
}

