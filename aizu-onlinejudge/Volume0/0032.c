/* AOJ 0032
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0032
 */

#include <stdio.h>


int main(){
  int first, second, diagonal;
  int rect, loze;

  rect = 0;
  loze = 0;
  while(scanf("%d,%d,%d", &first, &second, &diagonal)==3){
    if(diagonal < first + second){
      if(diagonal*diagonal == first*first + second*second){
        rect += 1;
      }else{
        if(second == first){
          loze += 1;
        }
      }
    }
  }
  printf("%d\n", rect);
  printf("%d\n", loze);
  return 0;
}
