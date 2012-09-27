#include<stdio.h>
#include<string.h>

#define BUFSIZE 81

#define s_plen(STR) STR,strlen(STR)

#define test_the(p, len) test_xxx((p), (len),s_plen("the"))
#define test_that(p, len) test_xxx((p), (len), s_plen("that"))
#define test_this(p, len) test_xxx((p), (len), s_plen("this"))

#define DEBUG 0

int readline(char*buf, int len){
  char *s;
  s = fgets(buf, BUFSIZE, stdin);
  return strlen(s);
}


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
  while (*src){
    printf("%c", rotate(*src, shift));
    src++;
  }
  printf("\n");
}

void println_plen(char* p, int l){
  int i;
  for(i=0;i<l;i++){
    printf("%c", *(p+i));
  }
  printf("\n");
}

int match_xxx_with(char* srcp, int srclen, char* tp, int tlen, int n){
  int i;
  if(DEBUG){
    printf("match_xxx_with\n");
    println_plen(srcp, srclen);
    println_plen(tp, tlen);
  }
  for(i=0; i<srclen; i++){
    if (rotate(*srcp, n)!=*tp)return 0;
  }
  return 1;
}


int test_xxx(char* srcp, int srclen, char* tp, int tlen){
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
    if(DEBUG){
      printf("%c\n", **(srcp));
    }
    switch (**srcp){
      case ' ':
        return *toklen;
      case '.':
        return *toklen;
      default:
        break;
    }

    /* consume */
    (*toklen)++;
    (*srcp)++; 
    (srclen)--;
  }
  return 0;
}


int main(){
  char buf[BUFSIZE];
  char *p;
  int len;
  char *tokp;
  int toklen;
  int key;

  while (readline(buf, BUFSIZE)){
    key = -1;
    p = buf;
    len = strlen(buf);
    if (DEBUG){
      printf("==>%s\n", p);
    }
    while(chop_slen(&p, &len, &tokp, &toklen)){
      if (DEBUG){
        println_plen(tokp, toklen);
        println_plen(p, len);
      }
      if ((key = test_the(tokp, toklen)) > -1) break;
      if ((key = test_this(tokp, toklen)) > -1) break;
      if ((key = test_that(tokp, toklen)) > -1) break;
    }
    if (DEBUG){
      printf("key =>%d\n", key);
    }
    decode_line(buf, key);
  }
  return 0;
}

