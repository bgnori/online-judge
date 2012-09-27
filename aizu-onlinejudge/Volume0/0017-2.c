#include<stdio.h>
#include<string.h>


#define s_plen(STR) STR,strlen(STR)

#define test_the(xs) test_xxx((xs), s_plen("the"))
#define test_that(xs) test_xxx((xs), s_plen("that"))
#define test_this(xs) test_xxx((xs), s_plen("this"))

char rotate(char t, int i){
  int r;
  if (t == '.') return t;
  if (t == ' ') return t;
  r = t+i;
  if (r > 'z'){
    return (char)(r - 'z' + 'a' - 1);
  }
  return (char)r;
}


void decode_line(char * src, int shift){
  while (*src++){
    printf("%c", rotate(*src, shift));
  }
  printf("\n");
}


int match_xxx_with(char* srcp, int srclen, char* tp, int tlen, int n){
  int i;
  for(i=0; i<srclen; i++){
    if (*srcp!=*tp)return 0;
  }
  return 1;
}


int test_xxx(char* srcp, int srclen, char* tp, int, tlen){
  /*
   * found .. shift
   * fail .. < 0
   */
  int i;
  int guess;

  if (srclen != tlen) return -1;

  for (guess=0; guess < ('z' - 'a'); guess++){
    if (match_xxx_with(srcp, srclen, tp, tlen, guess)){
      return guess;
    }
  }
  return -1;
}


int chop_slen(char** srcp, int* srclen, char**tokp, int*toklen){
  *tokp = *srcp;
  *toklen = 0;
  while (strlen){
    switch (**srcp){
      case: ' '
        return *toklen;
      case: '.'
        return *toklen;
      default:
        break;
    }
    (*toklen)++;
    (*srcp)++;
    (srclen)--;
  }
  return 0;
}


int main(){
  char buf[80];
  char *p;
  int head;
  int key;
  char *tokp;
  int toklen;

  while (gets(buf)){
    head = 0;
    key = -1;
    p = buf;
    printf("==>%s\n", p);
    while(chop_slen(&p, &len, &tokp, &toklen)){
      if (key = test_the(tokp, toklen) > -1) break;
      if (key = test_this_(tokp, toklen) > -1) break;
      if (key = test_that_(tokp, toklen) > -1) break;
      if (key = test_this(tokp, toklen) > -1) break;
      if (key = test_that(tokp, toklen) > -1) break;
    }
    decode_line(buf, key);
  }
  return 0;
}

