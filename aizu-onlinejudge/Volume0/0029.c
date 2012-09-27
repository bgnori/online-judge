/* AOJ 0029
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

#define DEFAULTSIZE 1024


int comp_x(const void*a, const void*b)
{
  char* x = *(char**) a;
  char* y = *(char**) b;

  while (*x && *y && *x==*y){
    x++; y++;
  }
  if(*x && *y){
    return *x - *y;
  }
  if(*x){ /* x is longer */
    return -1;
  }
  if(*y){/* y is longer */
    return 1;
  }
  return 0; /* same! */
}

typedef struct TPair Pair;
struct TPair {
  char* fValue;
  int fCount;
};

int comp_pair(const void*a, const void*b)
{
  return ((Pair*)b)->fCount - ((Pair*)a)->fCount;
}


int main(){
  /* The mode value is the element which occurs most frequently */

  char buf[33];
  int n;
  char* p[1024];
  int used;
  int size;
  int i,j;
  char* last;
  int count;
  Pair *q;
  char * tmp;
  char* longest;
  int len;


  used = 0;
  while(scanf("%s", buf)==1){
    if(DEBUG)
      printf("[%s]\n", buf);
    *(p+used) = (char*)malloc(strlen(buf)+1);
    strcpy(*(p+used), buf);
    used++;
  }
  qsort(p, used, sizeof(char*), comp_x);
  if(DEBUG)
    printf("=======\n");

  if(DEBUG)
    for(i=0; i< used; i++){
      printf("%s\n", *(p+i));
    }

  q = (Pair*)malloc(sizeof(Pair)*used);

  last = *p;
  longest = *p;
  count = 1;
  j = 0;
  for(i = 1; i<used; i++){
    if(strlen(*(p+i)) > strlen(longest)){
      longest = *(p+i);
    }
    if(comp_x((p+i), &last)==0){
      count +=1;
    }else{
      (q+j)->fCount = count;
      (q+j)->fValue = last;
      j++;
      last = *(p+i);
      count = 1;
    }
  }
  (q+j)->fCount = count;
  (q+j)->fValue = last;
  j++;

  qsort(q, j, sizeof(Pair), comp_pair);

  printf("%s", q->fValue);/*mostfreq*/
  printf(" ");
  printf("%s\n", longest);

  return 0;
}

