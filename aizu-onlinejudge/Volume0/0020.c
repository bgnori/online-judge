
#include<stdio.h>


char toUpper(char c){
  char r;
  if( ('a' <= c) && (c <='z')){
    return c - 'a' + 'A';
  }
  return c;

};

int main(){
  char buf[80];
  char *p;

  while(scanf("%s", buf) != EOF){
    p = buf;
    while(*p){
      printf("%c", toUpper(*p));
      p++;
    }
    printf(" ");
  };
  return 0;
}


