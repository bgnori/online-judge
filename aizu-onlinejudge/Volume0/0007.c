#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int sennen(double x, int up){
  double k;
  k = x / 1000;
  if (up){
    return ((int)ceil(k))* 1000;
  }else{
    return ((int)floor(k)) * 1000;
  }
}

int perweek(int x, double rate){
  double charged;
  int high, low;

  charged = x * rate;
  high = sennen(charged, 1);
  return high;
}


int main(){
  int week;
  int amount = 100000;
  double rate = 1.05;
  
  while(scanf("%i", &week) == 1){
    for(;week > 0; week--){
      amount = perweek(amount, rate);
    }
    printf("%d\n", amount);
  }
  return 0;
}

