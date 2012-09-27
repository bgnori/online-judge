


#include <stdio.h>
#include <stdlib.h>


#define DEFAULTSIZE 1024


int comp_int(const void*a, const void*b)
{
  return *(int*)a-*(int*)b;
}

typedef struct TPair Pair;
struct TPair {
  int fValue;
  int fCount;
};

int comp_pair(const void*a, const void*b)
{
  return ((Pair*)b)->fCount - ((Pair*)a)->fCount;
}


int main(){
  /* The mode value is the element which occurs most frequently */

  int n;
  int *p;
  int used;
  int size;
  int i,j;
  int last;
  int count;
  Pair *q;

  size = DEFAULTSIZE * sizeof(int);

  used = 0;
  p = (int*)malloc(size);

  while(scanf("%d", &n)==1){
    p[used] = n;
    used+=1;
    if(used >= size){
      size = size*2;
      p = (int*)realloc(p, size);
    }
  }
  qsort(p, used, sizeof(int), comp_int);

  q = (Pair*)malloc(sizeof(Pair)*used);

  last = *p;
  count = 1;
  j = 0;
  for(i = 1; i<used; i++){
    if(*(p+i)==last){
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

  last = q->fValue;
  count = q->fCount;
  for(i=1; i < j ; i++){
    if((q+i)->fCount==count){
      printf("%d\n", last);
      last = (q+i)->fValue;
      count = (q+i)->fCount;
    }else{
      printf("%d\n", last);
      break;
    }
  }

  return 0;
}
