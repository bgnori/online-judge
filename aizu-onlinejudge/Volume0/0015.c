#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXDIGIT 80
#define BUFSIZE (MAXDIGIT+1)


void init(int *dst){
  int i;
  for(i=0;i<BUFSIZE;i++){
    dst[i] = 0;
  }
}

void bigint(char*src, int*dst){
  int i, j;
  int len;
  j = 0;
  len = strlen(src);
  for(i=len-1; i>=0;i--){
    dst[j] = atoi(src+i);
    *(src+i)= '\0';
    j++;
  }
}

void add(int*ax, int*bx, int*dst){
  int carry;
  int i;
  carry = 0;
  for(i=0; i<BUFSIZE; i++){
    dst[i] = ax[i] + bx[i] + carry;
    carry = 0;
    if (dst[i] > 9){
      dst[i] -= 10;
      carry = 1;
    }
  }
}


void print(int*src){
  int started = 0;
  int j;
  if (src[MAXDIGIT] == 0){
    for(j=MAXDIGIT-1; j>=0; j--){
      if (src[j]||started){
        started = 1;
        printf("%d", src[j]);
      }
    }
    printf("\n");
  }else{
    printf("overflow\n");
  }
}

void dump(int*src){
  int j;
  printf("[ ");
  for(j=0; j<BUFSIZE; j++){
    printf("%d, ", src[j]);
  }
  printf("]\n");

}


int main(){
  int first[BUFSIZE];
  int second[BUFSIZE];
  int ans[BUFSIZE];
  char _buf[BUFSIZE];
  int i;
  int n;
  char * buf;
  buf = _buf;

  init(first);
  init(second);
  init(ans);

  scanf("%d", &n);
  for (i = 0; i<n ;i++){
    scanf(" %[1234567890]", buf);
    bigint(buf, first);
    //dump(first);
    //print(first);
    scanf(" %[1234567890]", buf);
    bigint(buf, second);
    //print(second);
    //dump(second);
    add(first, second, ans);
    //dump(ans);
    print(ans);
  }
  return 0;
}

