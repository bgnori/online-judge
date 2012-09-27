/* AOJ 0052
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0052
 *
 */

#include <stdio.h>

/* ただし、n は 2,000,000,000 以下の正の整数とします。*/


#define DEBUG 0


int main(){
    int n, i, j;
    int twoes;
    int fives;

    while(scanf("%d", &n)==1 && n){
        if(DEBUG)
            printf("%d\n", n);
        twoes = 0;
        fives = 0;
        for(i=1; i<=n; i++){
            j = i;
            while(!(j%2)){
                j = j/2;
                twoes += 1;
            }
            while(!(j%5)){
                j = j/5;
                fives+= 1;
            }
        }
        if(twoes > fives){
            printf("%d\n", fives);
        }else{
            printf("%d\n", twoes);
        }
    }
    return 0;
}
