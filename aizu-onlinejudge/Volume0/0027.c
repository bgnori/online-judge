

#include <stdio.h>

char* days[7] = {
 "Monday",
"Tuesday",
"Wednesday",
"Thursday",
"Friday",
"Saturday",
"Sunday"};

                 /*  1   2   3   4   5    6   7   8   9  10  11  12 */
int Month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int main(){
  int i;
  int n, m, d;

  while(scanf("%d %d", &m, &d)==2){
    if(m==0&&d==0)
      break;
    n = 0;
    for(i=0;i<m;i++)
      n += Month[i];
    printf("%s\n", days[(n+d+2)%7]);
  }
  return 0;
}
