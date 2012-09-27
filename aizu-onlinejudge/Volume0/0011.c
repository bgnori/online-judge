
#include<stdio.h>


int wires[31];

void swap(int nth, int mth){
  int tmp;
  tmp = wires[nth];
  wires[nth] = wires[mth];
  wires[mth] = tmp;
  return;
}

int main(){
  int w;
  int n;
  int i;
  int a, b;

  scanf("%d", &w);
  for (i=1; i<=w;i++){
    wires[i] = i;
  }

  scanf("%d", &n);
  for (i = 0; i<n ;i++){
    scanf("%d,%d", &a, &b);
    swap(a, b);
  }
  

  for (i=1; i<=w;i++){
    printf("%d\n", wires[i]);
  }
  return 0;
}
